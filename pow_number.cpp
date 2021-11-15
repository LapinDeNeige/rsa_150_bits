#include "pow_number.h"

mpz_class pow_number(mpz_class number, mpz_class exponent, mpz_class mod)
{
	mpz_class result;
	if(exponent == 1)
		return number;
	
	if(exponent == 0)
	{
		result = 1;
		return result;
	}
	
	if(mod != 0)
		mpz_powm(result.get_mpz_t(),number.get_mpz_t(),exponent.get_mpz_t(),mod.get_mpz_t());
	
	else
		mpz_pow_ui(result.get_mpz_t(),number.get_mpz_t(),exponent.get_ui());
	
	return result;
	
}

