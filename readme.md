# CCALK-PP
(when) CVA6 Cache Associativity Leaks the Key - Codes related to the paper

## About the attack
This attack is a covert channel based on a Prime & Probe method. It works on the [**CVA6 heart**](https://github.com/openhwgroup/cva6), an open-source CPU that implement a RISC-V architecture.
présentation attaque
blablabla
  
## Content
This repository contains:
- A tutorial on how to set the environement in order to reproduce the attack.
- Source codes (C, Python and Bash scripts) located in the [**AES**](https://github.com/CCALK-work/CCALK/tree/main/AES) folder.


## Attack Results
Two Python scripts located in [**AES**](https://github.com/CCALK-work/CCALK/tree/main/AES) can be used to perform the attack analisys.
- One script, *analysis.py* is used to retrieve automatically secret value from a trace
- The other, *graphical.py* is used to plot trace that we can inspect with the naked eye

The two figures below give an example of the outputs obtained using the *graphical.py* script. Figure 1 represents the raw output of the script. Figure 2 depicts a zoom on one of the 8 distinct patterns observed on Figure 1.

![fig3](https://user-images.githubusercontent.com/108535913/176914938-ac5c12d5-455f-4283-b305-2368087d40ae.jpeg)
Figure 1 - Output of the *graphical.py* script

![fig4](https://user-images.githubusercontent.com/108535913/176915852-5ff89025-6cfe-4e2c-8226-33f04ffa98a9.jpeg)
Figure 2 - Zoom on one of the 8 patterns observed on Figure 1
  
## Setup

### HW & SW requirements
- [**Genesys2 FPGA**](https://digilent.com/reference/programmable-logic/genesys-2/reference-manual)
- [**Vivado ML edition 2021.1**](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/2021-1.html)
- [**CVA6 bitstream**](https://github.com/openhwgroup/cva6#generating-a-bitstream)
- [**Linux image on SD card**](https://github.com/openhwgroup/cva6-sdk#linux)
- [**Python3**](https://www.python.org/downloads/release/python-3105/)


### Run the CVA6 with his Linux OS
**1) Generate from [**the Github project**](https://github.com/openhwgroup/cva6#generating-a-bitstream)**

**2) Flash the bitstream on the Genesys2 FPGA**
- Open Vivado Hardware Manager
- Connect FPGA through JTAG port
- Click on *Open target* then *Auto connect*. Vivado should recognize the FPGA
- Right click on the target board who has appeared and click on *Add configuration memory device*
- Select *s25fl256xxxxxx0* as the memory configuration device and select the *.mcs* file
- Click *Apply* and *Ok* and wait for a few minutes
- Right click again on the target board and click on *Boot from configuration memory device*
- Click on *Program device* and select the *.bit* file

**3) Insert the Micro SD card which contains Linux image on the micro SD port**

**4) Restart the FPGA**

**5) Connect the FPGA through his UART port, start a terminal connected to the USB Serial Port with 115200 as baud rate**

**6) Assign manual IP value to 192.168.0.15 for your computer ethernet interface connected to the FPGA**

**7) Setup the correct SSH configuration suiting your setup by using this [**script**](https://github.com/CCALK-work/CCALK/blob/main/FPGA_set_ssh)**