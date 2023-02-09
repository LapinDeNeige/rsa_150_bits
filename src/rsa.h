#include "gen_prm.h"
#include "gen_bits.h"
#include "pow_number.h"
#include "get_number_bits.h"
#include "../include/gmpxx.h"


#ifndef RSA_H
#define RSA_H

#define BITS_EXP 17

using namespace std;
/***
RSA key
@author
@param e exponent mod modulus
*/
struct key //keys
{
    mpz_class e; //exponent
    mpz_class mod; //modululs
};
/***
Encrypted message
@author
@param char message block
*/
struct msg_char
{
  char m[128];
};

/***
Encrypted message
@author
@param string message
*/
struct msg_string
{
    string m;
};



/**
Generates RSA open key of length from bits_min to bits_max
@author
@param bits minimal length bits maximal length
*/
key rsa_generate_open_key(unsigned short bits_min, unsigned short bits_max); //void rsa_generate_open_key(key *k);

/**
Generates RSA close key based on open key
@author
@param open key
*/
key rsa_generate_closed_key(key op_k);//void rsa_generate_closed_key(key *cls_k,key op_k);

/**
Encrypts text message in RSA
@author
@param message to encrypt, open key, resultig message
*/
void rsa_encrypt(char *message_to_encrypt,key open_key,msg_char *result_message);
void rsa_encrypt (string message_to_encrypt, key open_key, msg_string* result_message);


/**
Encrypts big number in RSA
@author
@param message to encrypt, open key
*/
mpz_class rsa_encrypt(mpz_class ms,key open_key);

/**
Decrypts RSA text message
@author
@param encrypted message encrypted message size close key resulting message
*/
void rsa_decrypt(msg_char *message_to_decrypt,size_t ms_sz,key closed_key, char *result_message);
string rsa_decrypt(msg_string *message_to_decrypt ,size_t ms_sz,key closed_key);

/**
Decrypts RSA big number message
@author
@param encrypted message encrypted message size close key
*/
mpz_class rsa_decrypt(mpz_class ms, key cls_key);

unsigned int rsa_get_key_size(key k);

#endif
