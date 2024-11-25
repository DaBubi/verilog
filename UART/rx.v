module rx(
    input wire rx_Clk,
    input wire i_RX_Serial,
    output reg o_RX_Valid,
    output reg [7:0] o_RX_Byte
);

reg [3:0] bit_counter = 4'b0;
reg [3:0] oversample_counter = 4'b0;
reg [7:0] o_RX_buffer = 8'b0; 

initial begin
    i_RX_Byte = 8'b0;
end

always @(posedge rx_Clk)
begin
    if(oversample_counter == 4'd7 && i_RX_Serial == 1'b0) begin
        if(bit_counter <= 4'd8) begin
        oversam
        end
    end
    oversample_counter <= 4'b0;
end
endmodule
