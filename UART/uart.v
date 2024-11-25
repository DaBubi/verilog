
module uart (
    input wire i_Clk
    // inne porty
);
    // Deklaracja instancji

    /* verilator lint_off UNUSED */
    wire rxClk, txClk;
    /* verilator lint_on UNUSED */
    
    baud_rate_gen #(
        .Clock_rate(100000000),
        .Baud_rate(9600)
    ) baud_gen (
        .i_Clk(i_Clk),
        .rx_Clk(rxClk),
        .tx_Clk(txClk)
    );

    // Inne moduły i logika UART

endmodule
