#include "rsa.h"
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
    bool rt=0;

    for(unsigned int a=3;a<llg;a=a+2) //O(lg/2)
    {
        if((num%a==0))
            return 0;
    }


   mpz_class mn((num-1)/2);

   for(size_t i=0;i< (llg/2);i++) //O(lg/2)*
   {
   unsigned int rnd=rand()%15; //rand number
   mpz_class m_rnd(rnd);

   mpz_class rst; //result

//rand number ^ (num-1)/2 mod num must be -1
//
   mpz_powm(rst.get_mpz_t(),m_rnd.get_mpz_t(),mn.get_mpz_t(),num.get_mpz_t());  //rand ^ (num-1)/2 % num


   if((rst+1)%num==0)
   {
       rt=1;
       break;
   }


   }
    return rt;
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
{
    srand(time(0));

     mpz_class aa;


     bool ii=0;
     short bts;

     unsigned int a=rand()%20;
     unsigned short k=rand()%15;

     do
        bts=rand()%bts_to;
        while(bts<bts_frm);


     if(k%2==0)
        k++;

     aa=a;

     aa=gn_prt(bts,k);//k *2^n+1
     ii=is_prt(aa);//verify if number is prime

     while(!ii) //until the number is not prime
    {
     aa=gn_prt(bts,k);
     ii=is_prt(aa);
     k=k+2;

    }


 return aa;
}




////////////////////////////////////////////////////////////////////////////////////////////////
mpz_class gn_nm(mpz_class nm,unsigned short bts) //generate big number
{
    //printf("current bts in\n");
    //printf("%d",bts);

    for(size_t i=0;i<bts;i++)
        nm=nm*2;


    nm=nm+1;

    return nm;
}



bool is(mpz_class num,mpz_class os)
{
    if(num%2==0)
        return 0;

    unsigned int lg=_lg(num);

    for(unsigned int a=3;a<lg;a=a+2)
    {
        if(num%a==0)
            return 0;
    }



    for( int i=0;i<22;i++)
    {

    unsigned int nm=rand()%lg;
    if(nm==1)
        nm=3;

    mpz_class mm(nm);

//    unsigned short lg=log2();

    mpz_class pt;
    mpz_powm(pt.get_mpz_t(),mm.get_mpz_t(),os.get_mpz_t(),num.get_mpz_t()); //num ^ st % mod

    for(short i=1;i<=lg;i++)
    {
        pt=(pt*pt)%num;
        if(pt==1 || pt==(num-1))
        {

            return 1;
        }

    }
    }

    return 0;
}



mpz_class bg_num(unsigned short bts_frm,unsigned short bts_to) //find Big random number
{                                                              //in range from_bts to to_bts
	srand(time(0));

	bool iz=0;

	mpz_class nm;
	mpz_class os;

while(!iz)
{
unsigned int bts=0;
unsigned int num=rand()%bts_frm;

if(num%2==0)
	num++;

    while(bts<bts_frm)
        bts=rand()%bts_to;


    nm=num;
    os=num;

    unsigned int llg=_lg(os);


    nm=gn_nm(nm,(bts-llg)); //generate number
    iz=is(nm,os);//check if number is prime

	if(!iz)
	{
		while(_lg(nm)<bts_to)
		{
			nm=((nm-1)*2)+1;


			if((iz=is(nm,os))==1)
				break;
		}


	}

//    std::cout<<"number: "<<nm.get_str()<<"\n";



}

    return nm;
}


/*
int main()
{



mpz_class bg=gn_big_prm(350,512);
mpz_class tt=gn_big_prm(350,512);
//mpz_class bg=bg_num(250,512);

unsigned int l=_lg(bg);
unsigned int ll=_lg(tt);

std::cout<<"number 1\t"<<bg.get_str()<<"\t";
std::cout<<"\tbits\t"<<l<<"\n\n";

std::cout<<"number 2"<<tt.get_str()<<"\t"<<"\tbits\t"<<ll<<"\n\n\n";

mpz_class rt=bg*tt;
unsigned int rt_l=_lg(rt);

std::cout<<rt.get_str()<<"\n";
std::cout<<"bits of result\t"<<rt_l;

///////////////////////////////////////////////////////////////////////////////////////


mpz_class dd=bg_num(350,512);   //generate first big  number
mpz_class qq=bg_num(350,512);  //generate second big nmber

mpz_class rr=dd*qq; //multiply them

unsigned int gl=_lg(dd);
unsigned int ll=_lg(qq);
unsigned int l_rr=_lg(rr);

std::cout<<dd.get_str()<<"\n";
std::cout<<"bits\t"<<gl<<"\n\n";


std::cout<<qq.get_str()<<"\n";
std::cout<<"bits\t"<<ll<<"\n\n";

std::cout<<"result\t"<<rr.get_str()<<"\n";
std::cout<<"bits\t"<<l_rr<<"\n";


    return 0;
}
*/


