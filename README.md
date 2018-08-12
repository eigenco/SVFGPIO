# SVFGPIO
Relatively standalone uploading of SVF to FPGAs using JTAG and GPIO of Raspberry Pi (based on code by Chris McClelland)


Tested with Raspberry Pi 3 and Xilinx Artix-7 XC7A35T.


Generate svf-file from tcl console:

create_hw_target -svf true svftarget_0

open_hw_target [get_hw_targets */svftarget_0]

create_hw_device -part xc7a35t

set_property PROGRAM.FILE {D:/FPGA/plainled/plainled.runs/impl_1/main.bit} [get_hw_devices xc7a35t_0_1]

program_hw_devices -disable_eos_check [get_hw_devices xc7a35t_0_1]

write_hw_svf -force D:/FPGA/svftarget.svf
