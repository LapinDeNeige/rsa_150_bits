#include "gen_bits.h"

#define MX 99999999

void _usleep(TIME t) //halt current executing thread for some number of milliseocnds
{
                    //depending on the OS
#ifdef _WIN32
Sleep(t);
#elif (linux ||__linux || __linux__)
usleep(t);
#endif // _WIN32_

}


//generate bbits by count
unsigned int  gen_bits_cnt(unsigned short bit_cnt)
{
unsigned int ret=0;
unsigned short y=0;

if(bit_cnt > 32)
    bit_cnt=32;

for(unsigned short i=0;i<bit_cnt;i++)
{
ret=ret<<1;

struct timeval vl;
gettimeofday(&vl,0); //get time
unsigned short o=(short)vl.tv_usec; //time

unsigned short cl=clock();
unsigned short y=0;

if(o&1==0) //if number is not odd
    y=((cl&0b1111)<<4)|(o&0b1111);    //first clock then time
else
    y=((o&0b1111)<<4)|(cl&0b1111);            //first time then clock

y=(y&1);
ret=ret|y;

_usleep(5);
}
return ret;

}

mpz_class gen_bits_cnt(short bts)
{
    mpz_class b_num=0;
    std::string st_num;
    unsigned int num;

unsigned short bits=0;
if(bts>31)
    bits=31;
else
    bits=bts;

for(int i=0;i<bts;i=i+bits)
{
 unsigned int temp_num=gen_bits_cnt(bits);


 std::stringstream ss;
 ss<<temp_num; //convert to string
 st_num.append(ss.str());

 //b_num=st_num;
}
b_num=st_num;

return b_num;

}



unsigned int gen_rand(unsigned int nm)
{
if(nm==0)
    nm=2;

struct timeval vl;
unsigned short h=0;
unsigned short tmp;

gettimeofday(&vl,0);

tmp=(short)vl.tv_usec;
unsigned short cl=(unsigned short)clock(); //take current milliseconds value

if(cl&1==0) //if number is odd
	h=(tmp<<16)|(cl&0b1111111111111111); //first time then clock
else
	h=(cl<<16)|(tmp&0b111111111111111); //first clock then time

h=h%nm;

_usleep(10);

return h;

}




mpz_class gen_rand(mpz_class nm)  //generate big random number
{
std::string st_num;
unsigned int num;
mpz_class b_num=0;

while(b_num < nm)
{
 unsigned int temp_num=gen_rand(MX);

 std::stringstream ss;
 ss<<temp_num; //convert to string
 st_num.append(ss.str());

 b_num=st_num;
}

if(b_num > nm)
    b_num = (b_num%nm);

return b_num;
}



/*
BigInt gen_rand(BigInt rng)
{
BigInt on;

while(on<=(rng.lg()))
{
unsigned int nm=gen_rand(MX);

std::string st=on.conv_int_to_str(nm);
on.app_str(st);
}

on=on%rng;
return on;
}
*/


/*
BigInt gen_bits(BigInt rng) //generate random bits for bigint
{

BigInt on;
BigInt tw(2);

while(on<=rng)
{
unsigned int tm=gen_bits(MX); //generate bits in range of BigInt


std::string sr=on.conv_int_to_str(tm);
on.app_str(sr);

}
BigInt qq=tw.pow(rng,"0");
on=on%qq;

return on ;
}
*/

/*
BigInt gen_bits_cnt(unsigned int bit_cnt)
{
BigInt ret;
unsigned int i=0;
for(i;i<bit_cnt;i=i+16)
{
int tmp=gen_bits_cnt((unsigned short)16); //16 bits
std::string st=ret.conv_int_to_str(tmp);
ret.app_str(st);
}

i=(i-bit_cnt);

unsigned int val=pow(2,i);

ret=ret/val;//delete last bits

return ret;
}
*/



