## AES attack replication

The covert-channel targets an implementation of the [**Tiny-AES**](https://github.com/kokke/tiny-AES-c) encryption algorithm with a key size of 128 bits. We further consider that the library itself is compromised and contains a Trojan. The attacker (spy) calls the victim process to request for an encryption. The victim then uses the library containing the Trojan leading to a leakage through the data cache.

**1) On your computer, execute the *sendProgFPGA.sh* script to compile C programs and upload binary files and mesurement script to the FPGA**

**2) Execute the *mesure.sh* script on the Linux running on the CVA6 to run the spy program and start trace acquisition. The acquisition time depends on the number of samples mesured by the spy and ends when *End probing* appears on the terminal. The trace file is located in the *out* created repository**

**3) Execute the *getMesure.sh* script on your computer to download the trace. You must specify a folder used to contain the file**

**4) You can use either the *analysis.py* to retrieve automatically the covert-channel's scret or *graphical.py* script to perform a more graphical analysis. For this analysis, in order to facilitate the visualization of results, you need the spy to make more samples. You need to specify the location of the trace to analyse when running these scripts** 
