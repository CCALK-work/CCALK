#!/bin/bash

spy=spy.c
victim=victim.c
client=client.c

#Compile programs with RISC-V toolchain cross-compilation
riscv64-unknown-linux-gnu-gcc -pthread $spy aes.c victim.c -O0 -o spyProcess
riscv64-unknown-linux-gnu-gcc -pthread $client aes.c victim.c -O0 -o clientProcess

#Upload binary files and script to CVA6 linux
scp mesure.sh spyProcess clientProcess root@192.168.0.16:/