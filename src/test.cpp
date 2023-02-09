#include "gen_bits.h"
#include "gen_prm.h"
#include <math.h>
#include <unistd.h>
#include "rsa_file_crypt.h"
#include "rsa.h"
#include "gen_prm.h"
#include "gen_bits.h"
#include "pow_number.h"
#include <iostream>
#include <stdio.h>


FILE  *fil; 

short open_file(char *file_path)
{
	//FILE *fil;
	fil=fopen(file_path, "r");
	if(!fil) //error file open
		return 0;
		
	//fclose(fil);
	return 1;
	
}

short get_file_size()
{
	short ret = 0;
	
	if(!fseek(fil,0,SEEK_END)) //success
	{
		ret = ftell(fil);
		rewind(fil);
		
	}
	
	else
		ret = -1;
		
	return ret;
}



int main()
{
	key open_key;
	key closed_key;
	
    char * file_path = "/home/usr/Documents/2gis";
		
    char *message ="hayvan abili";
    char result_message[9]={0};

    msg_char encrypted_message[strlen(message)+1];
	
    open_key = rsa_generate_open_key(100,200);
    closed_key = rsa_generate_closed_key(open_key);
   	unsigned int key_size_open=rsa_get_key_size(open_key);
   	unsigned int key_size_closed=rsa_get_key_size(closed_key);

   	rsa_encrypt(message,open_key,encrypted_message);
   	rsa_decrypt(encrypted_message,strlen(message),closed_key,result_message);

   	print_encrypted_message(encrypted_message,strlen(message));
    
//	short ret = encrypt_from_file(file_path, open_key, encrypted_message);
	//if(ret <=0)
		//printf("errpr ");

    
	
    return 0;
}

//compare the speed of two algorithms
