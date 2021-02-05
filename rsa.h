#include "gen_prm.h"
#include "gen_bits.h"
//#include "rsa.h"

#ifndef RSA_H
#define RSA_H


#define BITS_MIN 150 //bits of exponent
#define BITS_MAX 1024

#define BITS_EXP 60

using namespace std;
struct key //keys
{
    mpz_class e; //exponent
    mpz_class mod; //modululs
};

struct msg //encrypted message
{
  char m[300];
};

struct mms
{
    string m;
};




void generate_open_key(struct key *k);
void generate_closed_key( key *cls_k,key*op_k);
void rsa_init_key( key *k);

void encr(char *ms,key open_key,msg *rs); //encrypt message
void encr (string ms, key open_key, mms* mq);

void decr(msg *encr_ms, size_t ms_sz,key cls_key, char *msg); //decrypt message
string decr(mms *encr_ms ,size_t ms_sz,key cls_key);

void print_encr_msg(msg *ms,size_t sz); //print encrypted message
void print_encr_msg(mms *ms,size_t sz);

void print_decr_msg(char *msg); //print decrypted message
void print_decr_msg(string msg,size_t sz);


#endif
