# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Patrick\Documents\GitHub\PSoC 5LP FIles\C-CAN_PSoC_DevKit\C-CAN.cydsn\C-CAN.cyprj
# Date: Thu, 01 Sep 2016 04:47:05 GMT
#set_units -time ns
create_clock -name {ADC_SAR_1_theACLK(routed)} -period 55.55555555555555 -waveform {0 27.7777777777778} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {Clock_1(routed)} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {Clock_3(routed)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/dclk_3}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 13.888888888888888 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 13.888888888888888 -waveform {0 6.94444444444444} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 13.888888888888888 -waveform {0 6.94444444444444} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 7} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_SAR_1_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 5 9} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 7 13} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Clock_3} -source [get_pins {ClockBlock/clk_sync}] -edges {1 73 145} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 79 157} [list [get_pins {ClockBlock/dclk_glb_4}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\Patrick\Documents\GitHub\PSoC 5LP FIles\C-CAN_PSoC_DevKit\C-CAN.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Patrick\Documents\GitHub\PSoC 5LP FIles\C-CAN_PSoC_DevKit\C-CAN.cydsn\C-CAN.cyprj
# Date: Thu, 01 Sep 2016 04:46:57 GMT
