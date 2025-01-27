
module uart (
    input wire i_Clk,
    input Input_Bit,

    output reg [9:0] Output_Byte,
    output reg [2:0] rx_error
);

    /* verilator lint_off UNUSED */
    /* verilator lint_on UNUSED */

    wire rxClk, txClk;
    wire en_rec, en_tx;

    //Value readed by TX submodule
    wire reg[9:0] rx_value;

    //Submodules status
    wire rx_status;
    wire tx_status;
    
    baud_rate_gen #(
        .Clock_rate(100000000),
        .Baud_rate(9600)
    ) baud_gen (
        .i_Clk(i_Clk),
        .rx_Clk(rxClk),
        .tx_Clk(txClk)
    );

    rx rxc (
        .rx_Clk(rxClk),
        .i_RX_serial(Input_Bit),
        .enable(en_rec),

        .o_RX_valid(en_tx),
        .o_RX_active(rx_status),
        .o_RX_byte(rx_value),
        .error(rx_error)
    );

    assign en_rec = 1'b0;

    tx trn (     
        .tx_Clk(txClk),
        .i_tx_byte(rx_value),
        .tx_enable(en_tx),

        .out_tx_byte(Output_Byte),
        .tx_active(tx_status)

    );


endmodule
