module baud_rate_gen #(
    parameter Clock_rate = 100000000, // 100 Mhz for simulation purposes
    parameter Baud_rate = 9600 // standard baud rate on UART
)
(
    input wire i_Clk,
    output reg rx_Clk,
    output reg tx_Clk
);

    // Calculating what maximum baud rate we need for RX clock and TX clock, RX
    // with oversampling. Its in decimal, like baud_rate above
    parameter MAX_RX = Clock_rate / (2 * Baud_rate * 16);
    parameter MAX_TX = Clock_rate / (2 * Baud_rate);


    // Calculating the width of register for a counter
    // That will count INPUT CLOCK cycles to generate 
    // ONE RX CLOCK cycle and ONE TX CLOCK cycle
    parameter RX_CNT_WIDTH = $clog2(MAX_RX);
    parameter TX_CNT_WIDTH = $clog2(MAX_TX);

    //assign MAX_RX_OUT = MAX_RX;
    //assign MAX_TX_OUT = MAX_TX;

    reg [RX_CNT_WIDTH - 1:0] rxCounter = 0;  
    reg [TX_CNT_WIDTH - 1:0] txCounter = 0;

    initial begin
        rx_Clk = 1'b0;
        tx_Clk = 1'b0;
    end

    always @(posedge i_Clk)
    begin
        if(rxCounter == MAX_RX[RX_CNT_WIDTH - 1:0]) begin
            rxCounter <= 0;
            rx_Clk <= ~rx_Clk;
        end else begin
            rxCounter <= rxCounter + 1'b1;
        end
        
        if(txCounter == MAX_TX[TX_CNT_WIDTH - 1:0]) begin
            txCounter <=0;
            tx_Clk <= ~tx_Clk;
        end else begin
            txCounter <= txCounter + 1'b1;
        end
    end

endmodule
