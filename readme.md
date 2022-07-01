# CCALK-PP
(when) CVA6 Cache Associativity Leaks the Key - Codes related to the paper

## About the attack
This attack is a covert channel based on a Prime & Probe method. It works on the [**CVA6 heart**](https://github.com/openhwgroup/cva6), an open-source CPU that implement a RISC-V architecture.
présentation attaque

  
## Content
This repository contains:
- A tutorial on how to set the environement in order to reproduce the attack.
- Source codes (C, Python and Bash scripts) located in the [**AES**](https://github.com/CCALK-work/CCALK/tree/main/AES) folder.
- Linux image and CVA6 bitstream and configuration memory file used for the attack environment 


## Reproduce the attack

### AES
The attack is conducted on a Linux running on a CVA6 CPU integrated to a Genesys2 FPGA. 
presentation attaque aes



## Attack Results
Two Python scripts located in [**AES_results**](https://github.com/CCALK-work/CCALK/tree/main/AES) can be used to perform the attack analisys.
- One script, *analysis.py* is used to retrieve automatically secret value from a trace
- The other, *graphical.py* is used to plot trace that we can inspect with the naked eye

![fig3](https://user-images.githubusercontent.com/108535913/176914938-ac5c12d5-455f-4283-b305-2368087d40ae.jpeg)

## HW & SW requirements
- [**Genesys2 FPGA**](https://digilent.com/reference/programmable-logic/genesys-2/reference-manual)
- [**Vivado ML edition 2021.1**](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/2021-1.html)
- [**CVA6 bitstream**](https://github.com/openhwgroup/cva6#generating-a-bitstream)
- [**Linux image on SD card**](https://github.com/openhwgroup/cva6-sdk#linux)
- [**Python3**](https://www.python.org/downloads/release/python-3105/)


## Setup

### Run the CVA6 with his Linux OS
**1) Generate or get the bitstream from [**the Github project**](https://github.com/openhwgroup/cva6)**

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

**7) Once the Linux started, execute the script to change the Linux SSH interface**

**8) Start an SSH connection between your computer and the Linux running on the CVA6**


## Attack replication

**1) On your computer, execute the first script to compile C programs and upload binaries file and mesurement script**

**2) Execute the mesurement script on the Linux running on the CVA6**
