#include "gen_bits.h"
#include "gen_prm.h"
#include <math.h>
#include <unistd.h>
//#include "rsa.h"
#include "rsa.h"
#include "gen_prm.h"
#include "gen_bits.h"
#include "pow_number.h"
#include "get_number_bits.h"
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

short encrypt_from_file(char *file_path,key open_key, msg_char *encrypted_msg)
{
	char buf[35] = {0};
	
	short ret = open_file(file_path);
	if(ret <= 0) //error
		return ret;
	else
	{
		int file_size = get_file_size();
		
		if(file_size <= 0)
			return -1;
		std::cout<<"file size" << file_size << "\n";
		//
		std::cout << "null";
		for(int i = 0; i < file_size; i= i+31)
		{
			//rst = 32;
			std::cout << "zero";
			size_t rst = fread(buf,8,31,fil);
			
			if(rst != 31)
			{
				ret = -1;
				break;
			}
			else
			{
				std::cout << "one";
			//	std::cout<<buf;
				std::cout << "two";
			//	memset(buf,0,31);
			//	std::cout << "three";
			}
			
	    }
	    fclose(fil);
	    
	}
	return ret;
}

void print_encrypted_message(msg_string *en_mes)
{
	for(int i = 0;i < sizeof(en_mes); i++)
		std::cout<<en_mes[i].m << "\n";
}

int main()
{
	key open_key;
	key closed_key;
	
	char * file_path = "/home/usr/Documents/2gis";
		
	char *message ="CocaCola";
	msg_char encrypted_message[strlen(message)+1];
	
    open_key = rsa_generate_open_key(100,200);
    closed_key = rsa_generate_closed_key(open_key);
   
    std::cout << "open key" << open_key.e.get_str()  << " "<< open_key.mod.get_str() << endl;
    std::cout << "bits " << get_number_bits(open_key.e)  <<" + "<< get_number_bits(open_key.mod)<< endl ;
    std::cout << "closed key" << closed_key.e.get_str() <<  " " <<closed_key.mod.get_str() << endl; 
    std::cout << "bits " << get_number_bits(closed_key.e)<<"+" << get_number_bits(closed_key.mod) << endl;
    
    std::cout<<"message "<<message<<endl;
    std::cout << "\n\n\n";
    
    rsa_encrypt(message,open_key,encrypted_message);
    std::cout<<"message encrypted\n\n";
    
    
    
    
    
//	short ret = encrypt_from_file(file_path, open_key, encrypted_message);
	//if(ret <=0)
		//printf("errpr ");

    
	
    return 0;
}

//compare the speed of two algorithms
