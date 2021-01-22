#include "rsa.h"

mpz_class eul_m;

mpz_class get_d(mpz_class a, mpz_class b) //find NOD of two numbers
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




mpz_class ext_d(mpz_class a, mpz_class b) //extended Euclidian alogrithm
{

mpz_class t,nt,r,nr,q,tmp;
if(b<0)
    b=-b;
if(a<0)
    a=b-(-a%b);

    t=0;nt=1;r=b;nr=a%b;

while(nr!=0)
{
    q=r/nr;
    tmp=nt; nt=t-q*nt;t=tmp;
    tmp=nr; nr=r-q*nr; r=tmp;

}
if(r>1)
    return -1;
if(t<0)
    t=t+b;

    return t;
}



void generate_open_key(struct key *k)
{
    k->e=gn_big_prm((BITS_EXP-2),BITS_EXP); //generate exponent

//const char *u=k->e.get_str().c_str();

    mpz_class q=::eul_m;

    while(get_d(q,k->e)!=1) //must be coprime with (p-1)*(q-1)
    {
        k->e=bg_num((BITS_EXP-2),BITS_EXP);
    }

}




void generate_closed_key( key *cls_k,key*op_k)
{
cls_k->mod=op_k->mod;

mpz_class c=ext_d(op_k->e,eul_m);

//std::cout<<"eul\t"<<eul_m<<"\n";
//std::cout<<"open e\t"<<op_k->e<<"\n";
//std::cout<<"result\t"<<c<<"\n";

cls_k->e=c;

}

void rsa_init_key( key *k)
{
    mpz_class p=gn_big_prm((BITS_MIN/2),(BITS_MAX/2)); //generate first prime number
    mpz_class q=gn_big_prm((BITS_MIN/2),(BITS_MAX/2)); //generate second prime nmber

    k->mod=p*q;
    ::eul_m=(p-1)*(q-1);

}

void encr(char *ms,key open_key,msg *rs) //encrypt message
{
    mpz_class res; //copies to the result structure

for(size_t i=0;i< strlen(ms);i++)
{
    short tt=ms[i];
    mpz_class cr(tt);

   mpz_powm(res.get_mpz_t(),cr.get_mpz_t(),open_key.e.get_mpz_t(),open_key.mod.get_mpz_t()); // encrypt message mes^ e mod m

   strcpy(rs[i].m,res.get_str().c_str()); //copy to the result structure

   /////////////////////////////
   char *pt=(char*)rs[i].m;
}

}

void encr (string ms, key open_key, mms* mq)
{
    mpz_class res; //copies to the result structure

    //string rs; //encrypted message to return
for(size_t i=0;i< ms.size();i++)
{
    unsigned short tt=(unsigned short)ms.at(i);
    mpz_class cr(tt);

    tt=cr.get_ui();

    mpz_powm(res.get_mpz_t(),cr.get_mpz_t(),open_key.e.get_mpz_t(),open_key.mod.get_mpz_t()); // encrypt message mes^ e mod m
   //res=pmod(cr,open_key.e,open_key.mod);
   const char *y=res.get_str().c_str();

   //rs.append(res.get_str()); //append to the result


   mq[i].m.append(res.get_str());
}
}




mpz_class encr(mpz_class ms,key open_key)
{
    mpz_class res;

   // mpz_powm(res.get_mpz_t(),ms.get_mpz_t(),open_key.e.get_mpz_t(),open_key.mod.get_mpz_t());
    res=pmod(ms,open_key.e,open_key.mod);

    return res;
}










void decr(msg *encr_ms, size_t ms_sz,key cls_key, char *msg) //decrypt message
{
    /////////////////////////
    char ch[1]={0};             // sry didn't find any other solution ^_^
    ///////////////////


    for(int i=0;i< ms_sz ;i++)
    {
        char *ptr=(char*)encr_ms[i].m;
        mpz_class cr((char*)encr_ms[i].m);
        mpz_class res;

        mpz_powm(res.get_mpz_t(),cr.get_mpz_t(),cls_key.e.get_mpz_t(),cls_key.mod.get_mpz_t()); //decrypt message

        unsigned int nn=res.get_ui();

        ch[0]=(char)nn;
        ch[1]='\0';

        strcat(msg,ch);
    }

}

string decr(mms *encr_ms ,size_t ms_sz,key cls_key)
{
    string rs; //decrypted message to return


    /////////////////////////
    char ch[1]={0};             // sry didn't find any other solution ^_^
    ///////////////////



    for(int i=0;i< ms_sz ;i++)
    {
        string tmp;
        tmp=encr_ms[i].m;
        //const char *lr=tmp.c_str();

        mpz_class cr(tmp.c_str());
        mpz_class res;



        //res=pmod(cr,cls_key.e,cls_key.mod);
        mpz_powm(res.get_mpz_t(),cr.get_mpz_t(),cls_key.e.get_mpz_t(),cls_key.mod.get_mpz_t()); //decrypt message

        unsigned short u=res.get_ui();

        ch[0]=(char)u;
        ch[1]='\0';


        rs.append(ch);


        ///////////////////////
       const char *mpt=rs.c_str();

    }

    return rs;

}

mpz_class decr(mpz_class ms, key cls_key)
{
    mpz_class res;

    //res=pmod(ms,cls_key.e,cls_key.mod);
    mpz_powm(res.get_mpz_t(),ms.get_mpz_t(),cls_key.e.get_mpz_t(),cls_key.mod.get_mpz_t());

    return res;



}


void print_encr_msg(msg *ms,size_t sz)
{
    for(int i=0;i<sz;i++)
    {
        char *pt=(char*)ms[i].m;
        cout<<pt;
        printf("\n\n");


    }
    printf("\n\n");
}

void print_encr_msg(mms *ms,size_t sz)
{
    for(int i=0;i< sz;i++)
    {
        std::cout<< ms[i].m;
        printf("\n\n");

    }
    printf("\n\n\n");
}

void print_decr_msg(char *msg)
{
    for(size_t i=0;i<strlen(msg);i++)
        cout<<msg[i];

cout<<"\n\n";
}


void print_decr_msg(string msg,size_t sz)
{

for(size_t i=1;i<=sz;i++)
{
const char y=msg[i-1];
cout<<y;
}
//cout<<msg;

std::cout<<"\n";

}



/*
int main()
{
struct key open_k; //open key
struct key cls_key; //closed ket

rsa_init_key(&open_k);
generate_open_key(&open_k);
generate_closed_key(&cls_key,&open_k);

//////////////////////////////////////////////////////////
std::cout<<"open key\n";
std::cout<<open_k.mod<<"\n\n";
std::cout<<open_k.e;
std::cout<<"\n\n";

std::cout<<"closed key\n";
std::cout<<cls_key.mod<<"\n\n";
std::cout<<cls_key.e<<"\n\n";
////////////////////////////////////////////////////////////



string mm="London is the capital of Great Britain";
std::cout<<"\nmessage\t "<<mm<<"\n";

mms en[mm.size()]; //encrypted message

encr(mm,open_k,en);
std::cout<<"encrypted message \n\n";

unsigned int zs=(sizeof(en)/sizeof(mms));//mm.size();
print_encr_mess(en,zs);



mm.clear();//memset(m,0,sizeof(m));

//decr(ras,5,cls_key,m);
mm=decr(en,zs,cls_key);

std::cout<<"\n\n decrypted message";
print_decr_msg(mm,mm.size());




 return 7;
}
*/
