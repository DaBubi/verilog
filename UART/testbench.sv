`timescale 1ns / 1ps

module rx_tb;

   
    reg rx_Clk;
    reg i_RX_serial;
    reg enable;
    
    wire o_RX_valid;
    wire o_RX_active;
  	wire [9:0] o_RX_byte;
    wire error;
    wire [3:0] bit_counter;
  	wire [3:0] oversample_counter;
  	wire [9:0] o_RX_buffer;

    rx uut (
        .rx_Clk(rx_Clk),
        .i_RX_serial(i_RX_serial),
        .enable(enable),
        .o_RX_valid(o_RX_valid),
        .o_RX_active(o_RX_active),
        .o_RX_byte(o_RX_byte),
        .error(error),
      	.bit_counter(bit_counter),
      	.oversample_counter(oversample_counter),
      	.o_RX_buffer(o_RX_buffer)
    );


    always begin
        #5 rx_Clk = ~rx_Clk;
    end

    initial begin
  
        rx_Clk = 0;
        i_RX_serial = 1;
        enable = 0;

 
        #10 enable = 1; 


        #20 i_RX_serial = 0; 
        #160 i_RX_serial = 1; 
        #160 i_RX_serial = 0; 
        #160 i_RX_serial = 1; 
        #160 i_RX_serial = 0; 
        #160 i_RX_serial = 1; 
        #160 i_RX_serial = 0; 
        #160 i_RX_serial = 1;
        #160 i_RX_serial = 0;
        #160 i_RX_serial = 1;


        #1000 $finish;
    end

    initial begin
      $monitor("Time:%t o_RX_valid:%b o_RX_active:%b o_RX_byte:%b error:%b bit_counter:%b oversample_counter: %b o_RX_buffer: %b", 
                 $time, o_RX_valid, o_RX_active, o_RX_byte, error, bit_counter, oversample_counter, o_RX_buffer);
    end

endmodule