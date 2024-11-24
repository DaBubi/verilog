module uart (
    input wire i_Clk
);

    always @(posedge i_Clk)
    begin
        $display("Clock cycle: %b", i_Clk);
    end

endmodule

module Baud_rate_gen(
    parameter Clock_rate = 100000000, // 100 Mhz
    parameter Baud_rate = 9600 // standard baud rate on UART
)(
    input wire i_Clk,
    output rx_Clk,
    output tx_Clk
);
    // Oversampling
    parameter MAX_RX = Clock_rate / (2 * Baud_rate * 16);
    parameter MAX_TX = Clock_rate / (2 * Baud_rate);

    parameter RX_CNT_WIDTH = $clog2(MAX_RATE_RX);
    parameter TX_CNT_WIDTH = $clog2(MAX_RATE_TX);

    reg [RX_CNT_WIDTH - 1:0] rxCounter = 0;
    reg [TX_CNT_WIDTH - 1:0] txCounter = 0;

    initial begin
        rxClk = 1'b0;
        txClk = 1'b0;
    end

    always @(posedge i_Clk)
    begin
        if(rxCounter == RX_CNT_WIDTH[RX_CNT_WIDTH - 1:0]) begin
            rxCounter <= 0;
            rx_Clk = ~rx_Clk;
        end else begin
            rxCounter <= rxCounter + 1'b1;
        end
        
        if(txCounter == TX_CNT_WIDTH[TX_CNT_WIDTH - 1:0]) begin
            txCounter <=0;
            tx_Clk = ~tx_Clk;
        end else begin
            txCounter <= txCounter + 1'b1;
        end
    end

endmodule
