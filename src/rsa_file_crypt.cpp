//#include "gen_bits.h"

#include "rsa_file_crypt.h"

bool open_file(char *file_path,FILE **fil,bool mod)
{
	char md[2]={0};
	if(mod==WRITE_FILE_MODE)
        strcpy(md,"w");
    else
        strcpy(md,"r");

	if((*fil=fopen(file_path, md))==NULL)
        return false;

	return true;

}

void close_file(FILE **f)
{
    if(*f)
    {
        fclose(*f);
    }
}

unsigned int get_file_size(FILE* fil )
{
	unsigned int ret = 0;
	if(fil<=0)
        return  -1;

	if(!fseek(fil,0,SEEK_END)) //success
	{
		ret = ftell(fil);
		rewind(fil);
	}

	else
		ret = -1;

	return ret;
}

unsigned int get_size_of_encrypted_mesasge(msg_char *en_mes,unsigned int full_size)
{
    unsigned int ret_cnt=0;
    char cur_mes[CHUNK_SIZE]={0};

    while(ret_cnt< full_size)
    {
        char *ptr=en_mes[ret_cnt].m;
        if(strlen(ptr)==0)
            break;
        strncpy(cur_mes,ptr,strlen(ptr));

        ret_cnt++;
    }

    return ret_cnt;
}

bool read_message_from_file(FILE *fil,char *buf,unsigned int size_to_read)
{
    size_t rst = fread(buf,sizeof(char),size_to_read,fil);

    if(rst<0)
        return false;
    return true;

}


bool write_encrypted_message_to_file(FILE *fil,msg_char *buf,unsigned int sz_buf)
{
    bool ret_result=true;

    for(size_t i=0;i<sz_buf;i++)
    {
        char *ptr=buf[i].m;
        size_t rst=fwrite(ptr,sizeof(char),strlen(ptr),fil);
        if(rst<0)
        {
            ret_result=false;
            break;
        }
        fprintf(fil,"\n");
           // if(i==5)
            //    fprintf(fil,"\n"); //new line
    }

    return ret_result;
}

bool read_encrypted_message(FILE *fil, msg_char *buf,unsigned int sz) //until line
{

    char line_str[CHUNK_SIZE]={0};//one line chunk of encrypted message
    char cur_str='\0';
    int state=0;
    bool ret=true;

    if(fil<=0)
        return false;

    for(int i=0;i<sz;i++)
    {

        while(cur_str!='\n')
        {
            state=fread(&cur_str,sizeof(char),1,fil);

            if(feof(fil))
                break;
            if(state!=1)
            {
                ret=false;
                break;
            }
            if(cur_str!='\n')
                strncat(line_str,&cur_str,1);
        }

        if(strlen(line_str)>0)
            strcpy(buf[i].m,line_str);

        cur_str='\0';
        memset(line_str,0,CHUNK_SIZE);
        if(state<=0)
            break;

    }


    return ret;
}


bool write_message(FILE *fil,char *buf, unsigned int sz_to_write)
{
    size_t ret_rst=fwrite(buf,sizeof(char),sz_to_write,fil);
    if(ret_rst<0)
        return false;

    return true;
}

void print_encrypted_message(msg_string *en_mes,size_t siz)
{
    for(int i=0;i<siz;i++)
        std::cout<<en_mes[i].m;

}

void print_encrypted_message(msg_char *en_mes,size_t siz)
{
	for(int i = 0;i < siz; i++)
	{
       // if(strcmp(en_mes[i].m,"")==0)
        //    break;
        std::cout<<en_mes[i].m << "\n";
    }
}


short encrypt_from_file(char *file_path,key open_key, char *file_path_result)
{

    char buf[CHUNK_SIZE] = {0};
	msg_char encrypted_buf[CHUNK_SIZE*2]={0};

	FILE  *fil=0x0;
	FILE *fil_res=0x0;

    unsigned int file_size;
	short ret = open_file(file_path,&fil,READ_FILE_MODE);
	short ret_wr=open_file(file_path_result,&fil_res,WRITE_FILE_MODE);

	if(ret <= 0 || ret_wr <=0)
	{
        close_file(&fil);
        close_file(&fil_res);
		return ERROR_OPEN_FILE;
    }
	file_size=get_file_size(fil);


    if(file_size <= 0 || file_size >(CHUNK_SIZE*2))
    {
        close_file(&fil);
        close_file(&fil_res);

        if(file_size<=0)
            return ERROR_GET_FILE_SIZE;

        return ERROR_FILE_SIZE_LARGE;
    }

    unsigned short a = 0;
    while(a < file_size)
    {

        bool is_successfull=read_message_from_file(fil,buf,CHUNK_SIZE*2);

        if(!is_successfull)
        {
            ret = ERROR_READ_FILE;
            break;
        }



        rsa_encrypt(buf,open_key,encrypted_buf);
        unsigned short sz=get_size_of_encrypted_mesasge(encrypted_buf,CHUNK_SIZE*2);

        is_successfull=write_encrypted_message_to_file(fil_res,encrypted_buf,sz);

        if(!is_successfull)
        {
            ret=ERROR_WRITE_FILE;
            break;
        }

        memset(buf,0,CHUNK_SIZE);  //clear encrypted buf
        a=a+CHUNK_SIZE;

	}


	if(a%file_size!=0 && file_size >=CHUNK_SIZE)
	{
        a=(a-file_size);
        memset(buf,0,strlen(buf));

        bool is_successfull=read_message_from_file(fil,buf,a);
        if(!is_successfull)
            ret = ERROR_READ_FILE;

        rsa_encrypt(buf,open_key,encrypted_buf);
        size_t sz=get_size_of_encrypted_mesasge(encrypted_buf,CHUNK_SIZE);
        is_successfull=write_encrypted_message_to_file(fil_res,encrypted_buf,sz);


        if(!is_successfull)
            ret=ERROR_WRITE_FILE;
	}


   // print_encrypted_message(encrypted_buf,get_size_of_encrypted_mesasge(encrypted_buf,100));
 //   file_size= get_file_size(fil_res);

	close_file(&fil);
	close_file(&fil_res);

	return ret;
}



short decrypt_from_file(char *file_path,key close_key,char *result_path)
{
    FILE  *fil=0x0;
    FILE *fil_result=0x0;

    short ret=open_file(file_path,&fil,READ_FILE_MODE);
    short ret_result=open_file(result_path,&fil_result,WRITE_FILE_MODE);

    msg_char encr_buf[CHUNK_SIZE*2]={0};

    char result_buf[CHUNK_SIZE*2]={0};

    if(ret <=0 || ret_result <=0)
    {
        close_file(&fil);
        close_file(&fil_result);
        return ERROR_OPEN_FILE;
    }

   // unsigned int file_size=get_file_size(fil);

    bool is_successfull= read_encrypted_message(fil,encr_buf,CHUNK_SIZE*2);
    unsigned int sz=get_size_of_encrypted_mesasge(encr_buf,CHUNK_SIZE*2);

    if(sz>=(CHUNK_SIZE*2))
    {
        close_file(&fil);
        close_file(&fil_result);
        return ERROR_FILE_SIZE_LARGE;
    }

    if(!is_successfull)
    {
        close_file(&fil);
        close_file(&fil_result);
        return ERROR_READ_FILE;
    }


    rsa_decrypt(encr_buf,sz,close_key,result_buf);

    is_successfull=write_message(fil_result,result_buf,strlen(result_buf));
    if(!is_successfull)
    {
        close_file(&fil);
        close_file(&fil_result);
        return ERROR_WRITE_FILE;
    }


    close_file(&fil);
    close_file(&fil_result);

  //  std::cout<<"encrypted message read from file\n";
  //  print_encrypted_message(encr_buf,get_size_of_encrypted_mesasge(encr_buf,100));

    return 1;
}


/* int main*/
