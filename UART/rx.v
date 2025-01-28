// Code your design here
module rx(
    input wire      rx_Clk, //Clk input signal
    input wire      i_RX_serial, // Data signal
    input wire      enable, // Start receiving signal

    output reg      o_RX_valid, // Vaild data received
    output reg      o_RX_active, // RX is working
 
    output reg  [9:0]o_RX_byte, // Received data
    output reg  [2:0]error // Error reading the data

    // For the use of verilator debugging:  
  	// output reg	[3:0]bit_counter,
  	// output reg  [3:0]oversample_counter,
  	// output reg  [9:0]o_RX_buffer,
	// output reg	[2:0]state
);

// states of state machine
reg [2:0] RESET = 3'b000;
reg [2:0] IDLE = 3'b001;
reg [2:0] START_BIT = 3'b010;
reg [2:0] DATA_BITS = 3'b011;
reg [2:0] STOP_BIT = 3'b100;

reg [1:0] input_negedge = 2'b0; // To detect start_bit
reg [3:0] bit_counter = 4'b0; 
//Data bits counter reg Bits ID
reg [3:0] oversample_counter = 4'b0; // oversampling counter 16x
reg [9:0] o_RX_buffer = 10'b0; // Data bits storage
reg [2:0] state;


initial begin
  	state = IDLE;
    o_RX_byte = 10'b0;
    o_RX_valid = 1'b0;
    o_RX_active = 1'b0;
    error = 3'b000; // Error messages storage??
end

//If top-level module would read from error reg will there be any blocking
// if posedge rx_Clk when saving to error reg will take place would overlap
// with top-module Clk??

always @(posedge rx_Clk)
begin
    input_negedge <= {input_negedge[0], i_RX_serial};

    // !!!!!!!!
    if(!enable) begin
        state <= RESET; // Check if =, <= ???
    end
    
    case (state)
        RESET: begin
            o_RX_buffer <= 10'b0;
            o_RX_valid <= 1'b0;

            o_RX_active <= 1'b0;
            error <= 3'b000;
            bit_counter <= 4'b0000;
            oversample_counter <= 4'b0000;


            // invalid logic:
            if (enable) begin
                state <= IDLE;
            end
        end


        IDLE: begin

            if (input_negedge == 2'b10) begin

                // Changing state to data_bits 
                state <= START_BIT;
                // RX is now active and collecting data
                o_RX_active <= 1'b1;
              	oversample_counter <= 4'b0;

            end
        end
        
        START_BIT:  begin
          if (oversample_counter == 4'b1000) begin
              if (i_RX_serial == 1'b0) begin
					state <= DATA_BITS;
                	bit_counter <= 4'b0;
                	oversample_counter <= 4'b0;
                	o_RX_buffer <= {o_RX_buffer[9:1], i_RX_serial};
              end else begin
                	state <= RESET;
                	error <= 3'b001;
              end
            end else begin
              oversample_counter <= oversample_counter + 4'b0001;
            end
        end

        DATA_BITS: begin
          
            // Checking the value in half of bit
            if (oversample_counter == 4'b1000 & bit_counter == 4'b1000) begin
                state <= STOP_BIT;
                o_RX_buffer <= {o_RX_buffer[9:1], i_RX_serial};
                bit_counter <= bit_counter + 4'b0001;
                oversample_counter <= 4'b0000;

            end
            else if (oversample_counter == 4'b1000) begin
                o_RX_buffer <= {o_RX_buffer[9:1], i_RX_serial};
                bit_counter <= bit_counter + 4'b0001;
                oversample_counter <= 4'b0000;

            end else begin
                oversample_counter <= oversample_counter + 4'b0001;
            end
        end

        STOP_BIT: begin
            if (oversample_counter == 4'b1000 & bit_counter == 4'b1001 & i_RX_serial == 1'b1 & o_RX_buffer[8] == 0) begin
                state <= RESET;
                o_RX_byte <= o_RX_buffer;
              	o_RX_valid <= 1'b1;
            end
            else if (bit_counter != 4'b1001)begin
                state <= RESET;
                error <= 3'b010;
            end
            else if (oversample_counter == 4'b1000 & (i_RX_serial != 1'b1 | o_RX_buffer[8] != 1'b0)) begin
                state <= RESET;
                error <= 3'b100;
            end
        end

    endcase

end

endmodule
