#include "gen_bits.h"

#define DEFAULT_NUMBER 4294967295 //32 BITS NUMBER


void _usleep(TIME t) //halt current executing thread for some number of milliseocnds
{
                    //depending on the OS
	#ifdef _WIN32    //if windows 
	Sleep(t);
	#elif (linux ||__linux || __linux__)
	usleep(t);
	#endif // _WIN32_

}


//generate bits by count

unsigned int  gen_bits_cnt(unsigned short bit_cnt)
{
	unsigned int ret=0;
	unsigned short y = 0;

	if(bit_cnt > 32)
		bit_cnt = 32;

	for(unsigned short i = 0;i < bit_cnt;i++)
	{
		ret=ret << 1;

		struct timeval vl;
		gettimeofday(&vl,0); //get time
		unsigned short o = (short)vl.tv_usec; //time

		unsigned short cl = clock();
		unsigned short y = 0;

		if(o & 1 == 0) //if number is not odd
			y = ((cl&0b1111)<<4)|(o&0b1111);    //first clock then time
		else
			y = ((o&0b1111)<<4)|(cl&0b1111);            //first time then clock

		y = ( y& 1);
		ret = ret | y;

		_usleep(5);
	}
	return ret;
}

mpz_class gen_bits_cnt_big(unsigned short bit_cnt)
{
    mpz_class b_num=0;
    std::string st_num;
    unsigned int num;
	
	mpz_class mpz_bits_cnt=bit_cnt;
	const mpz_class two = 2;
	mpz_class standart_num;
	
	unsigned short bits = 0;
	if(bit_cnt > 32)
		bits = 32;
	else 
		bits=bit_cnt;
		
//	standart_num = pow_number(two,mpz_bits_cnt,0); //2^n
	mpz_pow_ui(standart_num.get_mpz_t(),two.get_mpz_t(),bit_cnt); //
	int i;
	
	
	for(i=0;i<bit_cnt;i=i+bits)
	{
		unsigned int temp_num=gen_bits_cnt(bits);
	
		std::stringstream ss;
		ss<<temp_num; //convert to string
		st_num.append(ss.str());

	}


	b_num=st_num;
	if(b_num > standart_num)
		b_num=(b_num%standart_num);
		
	return b_num;

}



unsigned int gen_rand(unsigned int nm_min,unsigned int nm_max)
{
	if( (nm_max==0))
		return 0;
    
	if(nm_min> nm_max)
	{
		unsigned int nm_tmp=nm_min;
		nm_min=nm_max;
		nm_max=nm_tmp;
	}

	struct timeval vl;
	unsigned short current_num=0;
	unsigned short tmp;

	gettimeofday(&vl,0);

	tmp=(short)vl.tv_usec;
	unsigned short cl=(unsigned short)clock(); //take current milliseconds value

	if(cl&1==0) //if number is odd
		current_num=(tmp<<16)|(cl&0b1111111111111111); //first time then clock
	else
		current_num=(cl<<16)|(tmp&0b111111111111111); //first clock then time


	if(current_num > nm_max)
		current_num=current_num % nm_max;

	if(current_num < nm_min)
		current_num=nm_min;


	_usleep(30);

	return current_num;

}




mpz_class gen_rand(mpz_class nm_min,mpz_class nm_max)  //generate big random number
{
	std::string string_num;
	unsigned int num;
	mpz_class current_num=0;

	unsigned int rand_num_min;
	unsigned int rand_num_max;


	if(nm_min> nm_max)
	{
		mpz_class nm_tmp=nm_min;
		nm_min=nm_max;
		nm_max=nm_tmp;
	}


	if(nm_max > DEFAULT_NUMBER)
		rand_num_max=DEFAULT_NUMBER;

	else if(nm_min > DEFAULT_NUMBER)
		rand_num_min=DEFAULT_NUMBER-2;
			
	else if((nm_max > DEFAULT_NUMBER) && (nm_min <DEFAULT_NUMBER))
	{
		rand_num_max=DEFAULT_NUMBER;
		rand_num_min=nm_min.get_ui();
	}

	else 
	{
		rand_num_min=nm_min.get_ui();
		rand_num_max=nm_max.get_ui();
	}
		
	while(current_num < nm_max)
	{
	 
	 unsigned int temp_num=gen_rand(rand_num_min,rand_num_max);

	 std::stringstream ss;
	 ss<<temp_num; //convert to string
	 string_num.append(ss.str());

	 current_num=string_num;
	}

	if(current_num> nm_max)
		current_num=current_num%nm_max;

	if(current_num < nm_min)
		current_num=nm_min;

	return current_num;
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



