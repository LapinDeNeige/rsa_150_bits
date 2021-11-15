#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <gmpxx.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

#include "gen_bits.h"
#include "get_number_bits.h"
//#include "pow.h"

mpz_class get_big_prote_number(unsigned short bits_min,unsigned short bits_max); //
mpz_class generate_big_prime(unsigned int bits_min,unsigned int bits_max);
	
bool is_prime(mpz_class num,mpz_class ground_number);
mpz_class gen_big_num(mpz_class num,unsigned short bits);
bool is_prote_prime(mpz_class num); 
#endif // MAIN_H_INCLUDED



/*
TODO
evaluate these two function on the weak processor
*/
