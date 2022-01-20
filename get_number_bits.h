#include <gmpxx.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#ifndef GET_NUMBER_BITS_H
#define GET_NUMBER_BITS_H

/**
Gets bit count of the big number
@author
@param number to get bits counts from
*/

unsigned int get_number_bits(mpz_class num);

#endif

