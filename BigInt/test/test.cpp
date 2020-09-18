
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>


#include "BigInt-lib/BigInt.h"

/*

Manual test of BigInt library

*/


   
int main()
{


srand(time(0));

unsigned int lw=100000; //min first number
unsigned int up=900000; //max 

unsigned int sc=90000; //second number
unsigned int tw=10000;

unsigned int on[10]={0};
unsigned int to[10]={0};

unsigned int lim=0; //limiy of size of each array to be tested 
unsigned int lm=0;
short cod; //code of getchar


for(lim;lim<5;) 
{
 //each 10 times increase limit of each array digits count 
if(up>=1000000)
{
lim++;
up=9;
lw=1;
sc=9;
tw=1;
lm=0;
}

if(sc>=1000000&&lm<lim)
{
lm++;
sc=9;
tw=1;

}

if(sc>up&&lm==lim) //second nmuber reached the limit of first one
{
up=up*10;
lw=lw*10;
sc=9;
tw=1;
lw=0;
lm=0;
}

int y=lm;

while(y<=lm) //second number
{
int tmp=rand()%(sc-tw)+tw;


to[y]=tmp;
y++;
}
y=lim;

while(y<=lim) //generating arrays of BigNums
{
int tmp=rand()%(up-lw)+lw;

on[y]=tmp;
y++;
}
              //generate numbres array



BigInt od(on,lim+1);
BigInt dv(to,lm+1);

if(od<dv) //first number must be bigger than second
{
BigInt tmp=od;
od=dv;    //swap
dv=tmp;
}

std::cout<<"first number= "<<od.gt_str()<<"\n";
std::cout<<"second number= "<<dv.gt_str()<<"\n\n";

BigInt tr="0"; //third number

printf("\n");
getchar();




std::cout<<"\n\n<=======plus=======>\n\n";
getchar();
tr=od+dv;

std::cout<<od.gt_str()<<"+"<<dv.gt_str();
std::cout<<"="<<tr.gt_str();
printf("\n");
getchar();

std::cout<<"\n\n<=======minus=======>\n\n";
getchar();
tr=od-dv;

std::cout<<od.gt_str()<<"-"<<dv.gt_str();
std::cout<<"="<<tr.gt_str();
printf("\n");
getchar();

std::cout<<"\n\n<=======divivion=======>\n\n";
tr=od/dv;
std::cout<<od.gt_str()<<'/'<<dv.gt_str();
std::cout<<'='<<tr.gt_str()<<"\n";
getchar();

std::cout<<"\n\n<=======multiplication=======>\n\n";
tr=od*dv;
std::cout<<od.gt_str()<<'*'<<dv.gt_str();
std::cout<<'='<<tr.gt_str();
getchar();

std::cout<<"\n\n<=======square=======>\n\n";
tr=od.sqrt();
std::cout<<"sqrt "<<od.gt_str()<<'='<<tr.gt_str()<<"\n";
tr=dv.sqrt();
std::cout<<"sqrt "<<dv.gt_str()<<'='<<tr.gt_str()<<"\n";
getchar();

std::cout<<"\n\n<=======modulus=======>\n\n";
tr=od%dv;
std::cout<<od.gt_str()<<"mod"<<dv.gt_str()<<'='<<tr.gt_str()<<"\n";
getchar();



sc=sc*10;
tw=tw*10;
memset(to+lm,0,lm+1);
}


   
return 0;

}
