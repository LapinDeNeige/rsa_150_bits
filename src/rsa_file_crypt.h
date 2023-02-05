#include "gen_prm.h"
#include <math.h>
#include <unistd.h>
#include "rsa.h"
#include "gen_bits.h"
#include "pow_number.h"
#include "get_number_bits.h"
#include <iostream>
#include <stdio.h>
#include <string>

#define ERROR_OPEN_FILE -1
#define ERROR_GET_FILE_SIZE -2
#define ERROR_READ_FILE -3
#define ERROR_WRITE_FILE -4
#define ERROR_FILE_SIZE_LARGE -5

#define KEY_SIZE 100
#define KEY_SIZE_END 200

#define WRITE_FILE_MODE 1
#define READ_FILE_MODE 0

#define CHUNK_SIZE 180

 /**
 Encrypts message from file path and saves result in file_path_result with open key
 Note: file must'n be larger than CHUNK_SIZE
 @author
 @param file path of file to read a message to encrypt open key to encrypt with file
 path to write encrypted message in
 @returns by success error code not null
 by error check ERROR_CODES
 */
short encrypt_from_file(char *file_path,key open_key, char *file_path_result);

/**
Decrypts encrypted message from file with close key path and saves it in result path
@autor
@param file path to read ecrypted message in  close key to decrypt file path to write
decrypted message in
@returns by success error code not null
 by error check ERROR_CODES
*/
short decrypt_from_file(char *file_path,key close_key,char *result_path);

/**
Prints encrypted message of size siz into stdout
@autor
@param array of encrypted messages, size to print into stdout
(can be got with get_size_of_encrypted_message)
*/
void print_encrypted_message(msg_char *en_mes,size_t siz);
void print_encrypted_message(msg_string *en_mes,size_t siz);

/**
Gets size of encrypted message array of type msg_char
@autor
@param array of encrypted message  msg_char  full size of
encrypted message  array
@return size of encrypted message
*/
unsigned int get_size_of_encrypted_mesasge(msg_char *en_mes,unsigned int full_size);

