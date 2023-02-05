#include "get_number_bits.h"

unsigned int get_number_bits(mpz_class num)//find logarithm
{
    unsigned int cnt=0;
	
	if(num<1)
		return 0;
    while(num!=0)
    {
        num=num>>1;
        cnt++;
    }

    return cnt;
}


