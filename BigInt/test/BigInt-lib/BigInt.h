#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>


/*
BigInt Library implementation
(c)
*/

using namespace std;
class BigInt
{
private:


string in_str;

BigInt sum (BigInt two);
string sum (string two); //summary

BigInt mult(BigInt two); //multiply


BigInt sub(BigInt two); //substract
string sub(string two);

BigInt div(BigInt two); //divide
BigInt div(int two);
bool les(BigInt two); //on less than two
bool equ(BigInt two); //on is equal two

//bool equ(string tw);

string conv_int_to_str(unsigned int i);
string conv_int_to_str(unsigned int *out,const int siz);


public:

BigInt sqrt(BigInt two); //get square

BigInt operator +( BigInt two);

BigInt operator - (BigInt two);

BigInt operator * (BigInt two);

BigInt operator / (BigInt two);
BigInt operator / (int two);

BigInt operator % (BigInt two);

BigInt sqrt();

void conv_str_to_int(unsigned int *out,const int siz);

bool operator < (BigInt two);
bool operator == (BigInt one);
bool operator !=(BigInt one);

//bool operator == (string one);

void operator = (string in);
bool operator <= (BigInt two);


void ins_str (string in);

char get_str_pos(short pos);
string gt_str();





long long get_num_siz();

void app_str(string in);

BigInt(char *in); //char
BigInt(string in); //string

BigInt(unsigned int *in,const int sz);
BigInt(unsigned int in);

BigInt();
};






