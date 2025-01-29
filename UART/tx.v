module tx(
    input wire tx_Clk,
    input wire [9:0]i_tx_byte,
    input wire tx_enable,

    output reg out_bit,
    output reg tx_done
    //output o_TX_active
);

// Machine states:
reg [1:0] state;

reg [1:0] IDLE = 2'b00;
reg [1:0] RESET = 2'b01;
//reg [1:0] START = 2'b10;
reg [1:0] DATA = 2'b11;

// We need to address RX readed data from the opposite site
reg [3:0] bits_counter = 4'd10;

initial begin
    state = IDLE;
    out_bit = 1'b1;
    tx_done = 1'b0;
    //o_TX_active = 1'b0;
end

always @(posedge tx_Clk)
begin

    case(state)

        RESET: begin
            out_bit <= 1'b1;
            bits_counter <= 4'd10;
            state <= IDLE;
        end

        IDLE: begin
            //o_TX_active <= 1'b0;
            if(tx_enable) begin
                state <= RESET;
            end
        end

        DATA: begin
            //o_TX_active <= 1'b1;
            if (bits_counter == 4'd0) begin
                tx_done <= 1'b1;
                state <= IDLE;
            end
            else begin
            out_bit <= i_tx_byte[bits_counter];
            bits_counter <= bits_counter - 4'd1;
            end
        end


    endcase
end

endmodule

