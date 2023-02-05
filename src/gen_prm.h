#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <time.h>
#include <math.h>
#include <stdio.h>

#include "../include/gmpxx.h"
#include "gen_bits.h"
#include "get_number_bits.h"
//#include "pow.h"

/**
Generates big prime Prote number
@author
@param minimal size of number in bits  maximal size of number in bits
*/
mpz_class get_big_prote_number(unsigned short bits_min,unsigned short bits_max);

/**
Generates big number
@author
@param minimal size of number in bits  maximal size of number in bits
*/
mpz_class generate_big_prime(unsigned int bits_min,unsigned int bits_max);

/**
Performs modified Miller Rabin prime number checking
@author
@param number to be checked initial exponent to be verified from
*/
bool is_prime(mpz_class num,mpz_class ground_number);

/**
Generates big number of specified size
@author
@param initial number to be generated from size in bits of number to be generated
*/
mpz_class gen_big_num(mpz_class num,unsigned short bits);

/**
Checks Prote number prime
@author
@param Prote number to be checked
*/
bool is_prote_prime(mpz_class num);
#endif // MAIN_H_INCLUDED



/*
TODO
evaluate these two function on the weak processor
*/
