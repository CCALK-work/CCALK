## AES attack replication

The covert-channel targets an implementation of the [**Tiny-AES**](https://github.com/kokke/tiny-AES-c) encryption algorithm. We chose a key size of 128 bits. The victim code in this implementation calls some of the “Tiny-AES” functions when required. We further consider that the library itself is compromised and contains a Trojan. The attacker (spy) calls the victim process to request for an encryption. The victim then uses the library containing the Trojan leading to a leakage through the data cache.

**1) On your computer, execute the first script to compile C programs and upload binaries file and mesurement script**

**2) Execute the mesurement script on the Linux running on the CVA6**

bla bla bla
argument
blablabla lancement script
