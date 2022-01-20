#include <math.h>
#include <iostream>
#include <gmpxx.h>


#ifndef POW_NUMBER_H
#define POW_NUMBER_H
//unsigned int pow_number

/**
Raises number in power degree divided modulus
@author
@param number to be raised exponent modulus
*/
mpz_class pow_number(mpz_class number, mpz_class exponent, mpz_class mod );

#endif
