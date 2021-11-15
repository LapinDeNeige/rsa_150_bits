#include "gen_prm.h"
#include "gen_bits.h"
#include "pow_number.h"
//#include "rsa.h"

#ifndef RSA_H
#define RSA_H

#define BITS_EXP 15

using namespace std;
struct key //keys
{
    mpz_class e; //exponent
    mpz_class mod; //modululs
};

struct msg_char //encrypted message
{
  char m[620];
};

struct msg_string
{
    string m;
};




key rsa_generate_open_key(unsigned short bits_min, unsigned short bits_max); //void rsa_generate_open_key(key *k);
key rsa_generate_closed_key(key op_k);//void rsa_generate_closed_key(key *cls_k,key op_k);
  
void rsa_encrypt(char *message_to_encrypt,key open_key,msg_char *result_message);
void rsa_encrypt (string message_to_encrypt, key open_key, msg_string* result_message);

void rsa_decrypt(msg_char *message_to_decrypt,size_t ms_sz,key closed_key, char *result_message);
string rsa_decrypt(msg_string *message_to_decrypt ,size_t ms_sz,key closed_key);


#endif
