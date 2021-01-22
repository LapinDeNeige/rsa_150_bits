#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <gmpxx.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

#include "gen_bits.h"

mpz_class gn_big_prm(unsigned  short bts_frm,unsigned short bts_to); //Prote big prime number
mpz_class bg_num(unsigned short bts_frm,unsigned short bts_to); //

unsigned int _lg(mpz_class num); //get bit count of the big number

mpz_class pmod(mpz_class nm,mpz_class ex,mpz_class md);

#endif // MAIN_H_INCLUDED


/*
TODO
evaluate these two function on the weak processor
*/
