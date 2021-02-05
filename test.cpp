#include "gen_bits.h"
#include "gen_prm.h"


#include <math.h>
#include <unistd.h>
//#include "rsa.h"
#include "gen_prm.h"
#include <iostream>


int main()
{

    clock_t st=clock();
    for(size_t i=0;i< 10;i++)
    {
        mpz_class a=bg_num(500,800);
      // mpz_class a=gn_big_prm(70,150);
        std::cout<<a<<"\t";
        std::cout<<"bits "<<_lg(a)<<"\n\n";
    }
    clock_t en=clock();

    std::cout<<"time took "<<(en-st)/CLOCKS_PER_SEC<<"\n";

    st=clock();

    for(size_t i=0;i<10;i++)
    {
       mpz_class a=gn_big_prm(500,900);
       std::cout<<a<<"\t";
       std::cout<<"bits "<<_lg(a)<<"\n\n";
    }

    en=clock();
    std::cout<<"time took "<<(en-st)/CLOCKS_PER_SEC;
    return 0;
}

//compare the speed of two algorithms
