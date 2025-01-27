module tx(
    input wire tx_Clk,
    input wire [9:0]i_tx_byte,
    input wire tx_enable,

    output reg [9:0] out_tx_byte,
    output tx_active
);

reg [1:0] state;

reg [1:0] IDLE = 2'b00;
reg [1:0] RESET = 2'b01;
reg [1:0] START = 2'b10;

initial begin
    state = IDLE;
    out_tx_byte = 10'b0;
    tx_active = 1'b0;
end

always @(posedge tx_Clk)
begin
    if(tx_enable) begin
        state <= RESET;
    end

    case(state)

        RESET: begin
            out_tx_byte = 10'b0;
            state <= START;
        end

        START: begin
            out_tx_byte = 10'b0;
        end

    endcase
end

endmodule

