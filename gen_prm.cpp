#include "gen_prm.h"
#define BS 10
using namespace std;

bool is_prote_prime(mpz_class num)  //if Prote number is prime 
{
    unsigned int bits=get_number_bits(num);


    for(unsigned int a=3;a<bits;a=a+2) //O(lg/2)
    {
        if((num%a==0))
            return 0;
    }


   mpz_class exp((num-1)/2);
   unsigned int rand_number=gen_rand(0,15); //rand number
   mpz_class m_rand(rand_number);

   mpz_class result; 

//rand number ^ (num-1)/2 mod num must be -1
//

	result = pow_number(m_rand,exp,num);
   //mpz_powm(result.get_mpz_t(),m_rand.get_mpz_t(),exp.get_mpz_t(),num.get_mpz_t());  //rand ^ (num-1)/2 % num


   if((result+1) % num == 0) //if result  mod num is num-1 number is prime 
        return 1;



    return 0;
}

mpz_class generate_prote_number(unsigned short bits,unsigned int k) //generate Prote number
{                                                   //k*(2^n)+1
    if(k%2 == 0)                                      //where k is odd
        k++;

    mpz_class p_k(k);
    mpz_class p_num;
    mpz_class p_two(2);
    mpz_class p_result; //result

	mpz_class mpz_bits = bits;
	
	p_result = pow_number(p_two,bits,0); //2^n
    //mpz_pow_ui(p_rst.get_mpz_t(),p_tw.get_mpz_t(),bits); //2^n
    p_num=(k * p_result) + 1; //(k*2^n)+1

    return p_num;


}






mpz_class generate_big_prime(unsigned int bits_min,unsigned int bits_max) //generate random big prime number
{
	
	bool is_prm = false;
	unsigned short bits_rand;
	const mpz_class four = 4;
	mpz_class x;
	mpz_class big_num;
	
	bits_rand = gen_rand(bits_min,bits_max);
	x = gen_bits_cnt_big(bits_rand);
	
	if((x % 2) == 0)
		x=x + 1;
		
	while(!is_prm)
	{
		big_num = (four *x )+1; //4x+1
		is_prm = is_prime(big_num,x);
		x =  x + 2;
	}
	
     
     return big_num;
}




////////////////////////////////////////////////////////////////////////////////////////////////
mpz_class gen_big_num(mpz_class num,unsigned short bits) //generate big number
{
    if(bits == 1)
        return (num - 1);
	 if(num == 0)
		return 0;
	
    for(size_t i=1;i<=bits;i++)
    {
		unsigned int bits_of_cur_number = get_number_bits(num);
		
		if(bits_of_cur_number == bits)
			break;
		
		num=num * 2;
	}
	
    return num;
}



bool is_prime(mpz_class num,mpz_class ground_number)
{
    if(num%2==0||num==1) //number is not odd
        return 0;

    unsigned int lg=(get_number_bits(num));
  
    for(unsigned int a=3;a<(lg);a=a+2) //check for the dividers
    {
        if((num % a) == 0)
            return 0;
    }



    for( int i=0;i < 3;i++)
    {
  //generate random number num
  //and check by making ((num^os)^2) %num
  //must be 1 or num-1

		mpz_class number_to_verify = gen_rand(0,5); //generate random number to be verified

		if(number_to_verify == 1)
			number_to_verify = 3;

		mpz_class tmp_result;
		
	//	tmp_result = pow_number(number_to_verify,ground_number,0);
		mpz_powm(tmp_result.get_mpz_t(),number_to_verify.get_mpz_t(),ground_number.get_mpz_t(),num.get_mpz_t()); //num ^ ground_num % mod
		if(tmp_result == 1)
			return 1;
		if(tmp_result == (num-1))
			return 1;
		
		mpz_class two(2);
        
        unsigned int bits_number = get_number_bits(num);
        unsigned int cnt = 1;
        
		while(cnt < (bits_number/2)) 
		{
			tmp_result = (tmp_result * tmp_result) % num;  //(num^ground_num)^2 % mod
			
			if(tmp_result == (num - 1)) //number is prime
				return 1;
			
			
			if(tmp_result == 1)
				return 1;

			cnt=cnt*2;
		}
		
    }
    
	
    return 0;
}



mpz_class get_big_prote_number(unsigned short bits_min,unsigned short bits_max) //find Big random number
{                                                              //generate number 2^n*k k is odd
                                                               //generate random big prime number                            //k*2^n+1 where k is odd                                               //and verify with modified miller test
	bool is_prime = 0;

	mpz_class os;
    mpz_class big_prote_number;; 


	unsigned int bts=0;
    unsigned int k=gen_rand(1,15); //find ground number k

    if(k == 0)
        k = 2;

    if(k%2 == 0)
        k++;

    
    bts=gen_rand(bits_min,bits_max); //find the bits size of the future number
    

    os=k; // ground number k
    
    while(!is_prime)
    {
		
        big_prote_number = generate_prote_number(bts,k); //(2^n)*k +1
        is_prime = is_prote_prime(big_prote_number);
        k= k + 2;
        os = k;
    }

    return big_prote_number;
}





/*
int main()
{

}
*/
