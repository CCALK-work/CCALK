# CCALK-PP
(when) CVA6 Cache Associativity Leaks the Key - Codes related to the paper

## About the attack
This attack is a covert channel based on the Prime & Probe technique. It has been developed on [**CVA6**](https://github.com/openhwgroup/cva6), an open-source CPU implementing a RISC-V architecture.
présentation attaque
blablabla
  
## Content
This repository contains:
- A tutorial on how to setup the environement in order to reproduce the attack.
- Source codes (C, Python and Bash scripts) located in the [**AES**](https://github.com/CCALK-work/CCALK/tree/main/AES) folder.


## Attack Results
Two Python scripts located in [**AES**](https://github.com/CCALK-work/CCALK/tree/main/AES) can be used to perform the attack analysis.
- The first script, *analysis.py* is used to automatically retrieve the secret value from a trace obtained after running the covert-channel
- The second script, *graphical.py* plots a trace that we can inspect with the naked eye to observe the results of the covert-channel

The two figures below give an example of the outputs obtained using the *graphical.py* script. Figure 1 represents the raw output of the script. Figure 2 depicts a zoom on one of the 8 distinct patterns observed on Figure 1, where the recovered values of the key can be inferred with the naked eye.

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
**1) Generate a bitstream by following the instructions given on [**the OpenHardware Group's CVA6 Github project**](https://github.com/openhwgroup/cva6#generating-a-bitstream)**

**2) Flash the bitstream on the Genesys2 FPGA**
- Open Vivado Hardware Manager
- Connect FPGA through JTAG port
- Click on *Open target* then *Auto connect*. Vivado should recognize the FPGA
- Right click on the target board who has appeared and click on *Add configuration memory device*
- Select *s25fl256xxxxxx0* as the memory configuration device and select the *.mcs* file
- Click *Apply* and *Ok* and wait for a few minutes
- Right click again on the target board and click on *Boot from configuration memory device*
- Click on *Program device* and select the *.bit* file

**3) Insert the Micro SD card containing a Linux image on the micro SD port**
- You can refer to the [**CVA6 SDK GitHub repository**](https://github.com/openhwgroup/cva6-sdk#linux) for the detailled procedure on how to generate an appropriate Linux image and place it inside your SD card.

**4) Restart the FPGA**

**5) Connect the FPGA through his UART port, start a terminal connected to the USB Serial Port with a baud rate of 115200**

**6) Assign manual IP value to 192.168.0.15 to your computer ethernet interface connected to the FPGA**

**7) Setup the correct SSH configuration suiting your setup. We proceeded by using this [**script**](https://github.com/CCALK-work/CCALK/blob/main/FPGA_set_ssh)**
