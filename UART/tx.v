module tx(
    input wire tx_Clk,
    input wire [9:0]i_tx_byte,
    input wire tx_enable,

    output reg out_bit,
    output o_TX_active
);

// Machine states:
reg [1:0] state;

reg [1:0] IDLE = 2'b00;
reg [1:0] RESET = 2'b01;
reg [1:0] START = 2'b10;
reg [1:0] DATA = 2'b11;

reg [3:0] bits_counter = 4'b0;

initial begin
    state = IDLE;
    out_bit = 1'b1;
    o_TX_active = 1'b0;
end

always @(posedge tx_Clk)
begin
    if(tx_enable) begin
        state <= RESET;
    end

    case(state)

        RESET: begin
            o_TX_out <= 10'b0;
            state <= START;
        end

        START_BIT: begin
            out_bit <= 0;
        end

    endcase
end

endmodule

