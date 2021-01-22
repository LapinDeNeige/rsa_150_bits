#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <gmpxx.h>

#include <string>
#include <sstream>

#ifdef _WIN32 //if os is windowd
#include <Windows.h>
#endif // _WIN32

#ifndef __GEN_BTS
#define __GEN_BTS


typedef unsigned short TIME;

unsigned int  gen_bits_cnt(unsigned short bit_cnt);
mpz_class gen_bits_cnt( short bts);

unsigned int gen_rand(unsigned int nm);
mpz_class gen_rand(mpz_class nm);

//BigInt gen_bits_cnt(unsigned int bit_cnt);
//BigInt gen_rand(BigInt rng);



#endif
