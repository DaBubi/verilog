module uart (
    input wire i_Clk,
    input reg Input_Bit,

    output reg [9:0] Output_Byte,
    output reg [2:0] rx_error
);

    // Warnings turn off:
    /* verilator lint_off UNUSED */
    /* verilator lint_on UNUSED */

    //Wires bruh
    //Clock wires
    wire rxClk, txClk;

    // RX wires
    wire o_RX_valid;
    wire o_RX_active;

    // TX wires
    wire o_TX_active;
    wire en_tx;

    // Start of TX
    assign en_tx = o_RX_valid;
    // RX module listening
    reg en_rec = 1'b0;
    // Data from RX submodule to TX submodule
    wire data_read;

    //Value readed by TX submodule
    //reg[9:0] rx_value;
    
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

        .o_RX_valid(o_RX_valid),
        .o_RX_active(o_RX_active),
        .o_RX_byte(data_read),
        .error(rx_error)
    );

    assign en_rec = 1'b0;

    tx trn (     
        .tx_Clk(txClk),
        .i_tx_byte(data_read),
        .tx_enable(en_tx),

        .out_tx_byte(Output_Byte),
        .o_TX_active(o_TX_active)

    );

endmodule

