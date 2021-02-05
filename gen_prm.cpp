#include "gen_prm.h"
#define BS 10
using namespace std;


unsigned int _lg(mpz_class num)//find logarithm
{
    unsigned int cnt=0;
    while(num!=1)
    {
        num=num/2;
        cnt++;
    }

    return cnt;
}



bool is_prt(mpz_class num)  //test of Prote numbers
{
    unsigned int llg=_lg(num);


    for(unsigned int a=3;a<llg;a=a+2) //O(lg/2)
    {
        if((num%a==0))
            return 0;
    }


   mpz_class mn((num-1)/2);


   unsigned int rnd=gen_rand(15); //rand number
   mpz_class m_rnd(rnd);

   mpz_class rst; //result

//rand number ^ (num-1)/2 mod num must be -1
//
   mpz_powm(rst.get_mpz_t(),m_rnd.get_mpz_t(),mn.get_mpz_t(),num.get_mpz_t());  //rand ^ (num-1)/2 % num


   if((rst+1)%num==0)
        return 1;



    return 0;
}

mpz_class gn_prt(unsigned short bts,unsigned int k) //generate Prote number
{                                                   //k*(2^n)+1
    if(k%2==0)                                      //where k is odd
        k++;

    mpz_class p_k(k);
    mpz_class p_num;
    mpz_class p_tw(2);
    mpz_class p_rst; //result

    mpz_pow_ui(p_rst.get_mpz_t(),p_tw.get_mpz_t(),bts); //2^n
    p_num=(k*p_rst)+1; //(k*2^n)+1

    return p_num;


}






mpz_class gn_big_prm(unsigned short bts_frm,unsigned short bts_to) //generate random big prime number
{                                                                 //k*2^n+1 where k is odd
    srand(time(0));                                               //and verify with modified miller test

     mpz_class aa;


     bool ii=0;
     short bts;


        unsigned int a=(20);
        unsigned short k=gen_rand(15);


        bts=gen_rand(bts_to); //generate bits
        if(bts<bts_frm)
            bts=bts+bts_frm;


        if(k%2==0)
            k++;

        aa=a;
        bts=bts-_lg(aa);

        aa=gn_prt(bts,k);//k *2^n+1
        ii=is_prt(aa);//verify if number is prime

   // std::cout<<aa<<"\n";

            while(!ii)
            {
                aa=gn_prt(bts,k);
                ii=is_prt(aa);
                k=k+2;
             //   std::cout<<aa<<"\n";
            }




 return aa;
}




////////////////////////////////////////////////////////////////////////////////////////////////
mpz_class gn_nm(mpz_class nm,unsigned short bts) //generate big number
{
    if(bts==1)
        return (nm-1);

    for(size_t i=1;i<bts;i++)
        nm=nm*2;



    nm=nm-1;

    return nm;
}



bool is(mpz_class num,mpz_class os)
{
    if(num%2==0||num==1) //number is not odd
        return 0;

    unsigned int lg=(_lg(num));
    bool is=0; //result

    for(unsigned int a=3;a<(lg);a=a+2) //check for the dividers
    {
        if(num%a==0)
            return 0;
    }



    for( int i=0;i<(3);i++)
    {
  //generate random number num
  //and check by making ((num^os)^2) %num
  //must be 1 or num-1

  unsigned int nm=gen_rand(lg*lg); //generate random number to be verified

    if(nm==1)
        nm=3;

    mpz_class mm(nm);




//    unsigned short lg=log2();

    mpz_class pt;
    mpz_powm(pt.get_mpz_t(),mm.get_mpz_t(),os.get_mpz_t(),num.get_mpz_t()); //num ^ ground_num % mod
    if(pt==1 || pt==(num-1))
    {
        return 1;
    }

    mpz_class cnt=(os*2); //counter
    while(cnt<num) //(num^ground_num)^2 % mod
    {
        pt=(pt*pt)%num;

        if(pt==(num-1)) //number is prime
        {
            return 1;
            break;
        }
        if(pt==1)
            return 0;

        cnt=cnt*2;
    }


    if(is)
        break;
    }

    return 0;
}



mpz_class bg_num(unsigned short bts_frm,unsigned short bts_to) //find Big random number
{                                                              //generate number 2^n*k k is odd

	bool iz=0;

	mpz_class nm;
	mpz_class os;

	mpz_class r_nm;

	unsigned int bts=0;
    unsigned int num=gen_rand(10); //find ground number k
if(num==0)
    num=2;

if(num%2==0)
    num++;

bts=gen_rand(bts_to); //find the bits size of the future number
if(bts< bts_frm )
    bts=bts+bts_frm;


os=num; // ground number k
mpz_class mn=gn_prt(bts,num); //(2^n)*k +1
iz=is(mn,os);
//std::cout<<mn<<"\n";

while(!iz)
{
    num=num+2;
    os=num;
    mn=gn_prt(bts,num);
    iz=is(mn,os);

 //   std::cout<<mn<<"\n";



}

    return mn;
}





/*
int main()
{

}
*/
