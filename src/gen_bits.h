#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include "../include/gmpxx.h"
#include "get_number_bits.h"
#include  "pow_number.h"


#ifdef _WIN32 //if os is windowd
#include <Windows.h>
#elif (linux ||__linux || __linux__)
#include <unistd.h>
#endif // _WIN32


#ifndef __GEN_BTS //ability to be included with a lot of programs
#define __GEN_BTS


typedef unsigned short TIME;

unsigned int  gen_bits_cnt(unsigned short bit_cnt);
mpz_class gen_bits_cnt_big(unsigned short bit_cnt);
unsigned int gen_rand(unsigned int nm_min,unsigned int nm_max);
mpz_class gen_rand(mpz_class nm_min,mpz_class nm_max);


//BigInt gen_bits_cnt(unsigned int bit_cnt);
//BigInt gen_rand(BigInt rng);



#endif
