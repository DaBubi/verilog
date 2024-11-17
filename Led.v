module Led (
    input i_Clk,
    input i_Switch,
    output o_led1
);
    reg r_led1 = 1'b0;
    reg r_Switch = 1'b0;
    always @(posedge i_Clk)
    begin
        r_Switch <= i_Switch;
        $display("r_Switch: %b, i_Switch: %b, i_CLK: %b", r_Switch, i_Switch, i_Clk);
        if (i_Switch == 1'b0 && r_Switch == 1'b1)
        begin
            r_led1 <= ~r_led1;
        end
    end
    assign o_led1 = r_led1;
endmodule
