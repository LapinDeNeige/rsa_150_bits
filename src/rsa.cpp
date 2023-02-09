#include "rsa.h"

mpz_class eul_m;

unsigned int bits_exp;
unsigned int min_bits;
unsigned int max_bits;

unsigned int exp_bits;


mpz_class rsa_get_d(mpz_class a, mpz_class b) //find NOD of two numbers
{
    mpz_class c(1);

    while(c!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }

    return a;
}



mpz_class rsa_ext_d(mpz_class a, mpz_class b) //extended Euclidian alogrithm
{

	mpz_class t,nt,r,nr,q,tmp;
	if(b<0)
		b=b-b;

	if(a<0)
		a=b-(-a%b);

	t=0;nt=1;
	r=b;nr=a%b;

	while(nr!=0)
	{
		q=r/nr;
		tmp=nt;
		nt=t-q*nt;
		t=tmp;
		tmp=nr;
		nr=r-q*nr;
		r=tmp;
	}

	if(r>1)
		return -1;
	if(t<0)
		t=t+b;

    return t;
}




key rsa_generate_open_key(unsigned short bits_min, unsigned short bits_max)
{

    mpz_class p  = generate_big_prime((bits_min/2),(bits_max/2)); //generate first prime number
	//get_big_prote_number((bits_min/2),(bits_max/2))
    mpz_class q =  generate_big_prime((bits_min/2),(bits_max/2)); //generate second prime nmber
   // get_big_prote_number((bits_min/2),(bits_max/2))
	key open_key;

    open_key.mod=(p*q); //modulus

    ::eul_m = (p-1)*(q-1);

    mpz_class eul = ::eul_m;

    if(exp_bits <=20)
        exp_bits = exp_bits+20;

    do //must be coprime with (p-1)*(q-1)
    {
	//	std::cout<<open_key.e.get_str() <<"\n";
        open_key.e = generate_big_prime((BITS_EXP-1),BITS_EXP); //get_big_prote_number((BITS_EXP-1),BITS_EXP);
    }while( rsa_get_d(eul,open_key.e) != 1 );

	return open_key;
}



key rsa_generate_closed_key(key op_k)
{
	key closed_key;
	closed_key.mod=op_k.mod;
	unsigned int bits;

    mpz_class c = rsa_ext_d(op_k.e,eul_m);
	closed_key.e=c;

	return closed_key;
}



void rsa_encrypt(char *message_to_encrypt,key open_key,msg_char *result_message) //encrypt message
{
    mpz_class result;

	for(size_t i=0;i< strlen(message_to_encrypt);i++)
	{
		short message_number=message_to_encrypt[i];
		mpz_class message(message_number);

		result = pow_number(message,open_key.e,open_key.mod); // encrypt message mes^ e mod m
	   //mpz_powm(res.get_mpz_t(),cr.get_mpz_t(),open_key.e.get_mpz_t(),open_key.mod.get_mpz_t());

	   string encrypted_current = result.get_str();
	   strcpy(result_message[i].m,encrypted_current.c_str()); //copy to the result structure
	}

}


void rsa_encrypt (string message_to_encrypt, key open_key, msg_string* result_message)
{
	 mpz_class result; //copies to the result structure

		//string rs; //encrypted message to return
	for(size_t i = 0;i< message_to_encrypt.size();i++)
	{
		unsigned short message_number = (unsigned short)message_to_encrypt.at(i);
		mpz_class message(message_number);

	//	message_number = message.get_ui();
		result = pow_number(message,open_key.e,open_key.mod); 		// encrypt message mes^ e mod m
		//mpz_powm(res.get_mpz_t(),cr.get_mpz_t(),open_key.e.get_mpz_t(),open_key.mod.get_mpz_t());
		string encrypted_current = result.get_str();
	   result_message[i].m.append(encrypted_current);
  }
}


mpz_class rsa_encrypt(mpz_class ms,key open_key)
{
    mpz_class res;

    res = pow_number(ms,open_key.e,open_key.mod);
    //mpz_powm(res.get_mpz_t(),ms.get_mpz_t(),open_key.e.get_mpz_t(),open_key.mod.get_mpz_t());
//    res=pmod(ms,open_key.e,open_key.mod);

    return res;
}




void rsa_decrypt(msg_char *message_to_decrypt, size_t ms_sz,key closed_key, char *result_message) //decrypt message
{
    /////////////////////////
    char ch[1]={0};             // sry didn't find any other solution ^_^
    ///////////////////


    for(int i=0;i< ms_sz ;i++)
    {
        char *ptr=(char*)message_to_decrypt[i].m;
        mpz_class message(message_to_decrypt[i].m);
        string str=message.get_str();

        mpz_class result;

		result = pow_number(message,closed_key.e,closed_key.mod);
        //mpz_powm(res.get_mpz_t(),cr.get_mpz_t(),cls_key.e.get_mpz_t(),cls_key.mod.get_mpz_t()); //decrypt message

        unsigned int res_int=result.get_ui();

        ch[0]=(char)res_int;
        ch[1]='\0';

        strcat(result_message,ch);
    }

}

string rsa_decrypt(msg_string *message_to_decrypt ,size_t ms_sz,key closed_key)
{
    string result;

    /////////////////////////
    char ch[1]={0};             // sry didn't find any other solution ^_^
    ///////////////////////

    for(int i=0;i< ms_sz ;i++)
    {
        string message_to_decrypt_str = message_to_decrypt[i].m;
        //const char *lr=tmp.c_str();

        mpz_class message(message_to_decrypt_str.c_str());
        mpz_class result_number;

        result_number = pow_number(message,closed_key.e,closed_key.mod);

        //mpz_powm(res.get_mpz_t(),cr.get_mpz_t(),cls_key.e.get_mpz_t(),cls_key.mod.get_mpz_t()); //decrypt message

        unsigned short u = result_number.get_ui();

        ch[0]=(char)u;
        ch[1]='\0';


        result.append(ch);

    }

    return result;

}


mpz_class rsa_decrypt(mpz_class ms, key cls_key)
{
    mpz_class res;

    res=pow_number(ms,cls_key.e,cls_key.mod);
    //res=pmod(ms,cls_key.e,cls_key.mod);
   // mpz_powm(res.get_mpz_t(),ms.get_mpz_t(),cls_key.e.get_mpz_t(),cls_key.mod.get_mpz_t());


    return res;



}


unsigned int rsa_get_key_size(key k)
{
    unsigned int result=0;
    unsigned int size_e=get_number_bits(k.e);
    unsigned int size_mod=get_number_bits(k.mod);
    result=size_e+size_mod;

    return result;
}


