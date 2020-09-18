#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>

//#include "../BigInt/BigInt.h"



unsigned int bin (unsigned int nm,unsigned int dg,unsigned int mod)
{
unsigned int tmp=1;

while(dg!=1)
{
	if(dg%2!=0)
	{
		tmp=(tmp*nm)%mod;
		dg=dg-1;
	}

	nm=(nm*nm)%mod;
	dg=dg/2;

}
nm=(nm*tmp)%mod;

return nm;
}







unsigned int md(unsigned int num,unsigned int dg,unsigned int mod)
{

unsigned short lg[5]={0};
unsigned int mn[5]={0};

unsigned int rs=1;

unsigned int tmp=dg;


lg[0]=log2(dg); //take logarithm


unsigned int l=pow(2,lg[0]);

//unsigned int mm=(dg/lg);

unsigned int ot=(dg%l); //exponent rest from dg

short j=1;

while(ot)
{

if(ot<=3)
	break;


lg[j]=log2(ot);
rs=pow(2,lg[j]);
ot=ot%rs;
j++;

}

unsigned int nn=1;

if(ot>0)
{
nn=pow(num,ot);
nn=nn%mod;
}

unsigned int f=3;

unsigned int tl=0;


bool br=0;

while(j)
{

num=(num*num)%mod;

	for(f=0;f<j;f++)
	{
		lg[f]--;


		if(lg[f]==0)
		{
			mn[tl]=num;
			tl++;


			if(f==0)
			{
				br=1;
				break;
			}



		}


	}

	if(br)
		break;

}


j=0;
rs=1;



while(1)
{
if(mn[j]==0)
	break;
if(j>=5)
	break;

rs=(rs*mn[j])%mod;
j++;

}

rs=(rs*nn)%mod;


return rs;
}





int main()
{

srand(time(0));

unsigned int on=rand()%50;
unsigned int st=rand()%50;

if(st&1==1)
	st++;

unsigned int m=rand()%50;

if(m==0)
	m=m+50;

unsigned int r=md(on,st,m);

//on=bin(on,st);

std::cout<<on<<"^ "<<st<<" mod "<<m<<" = ";
std::cout<<r<<"\n";


return 0;
}
 

//compare two methodes: 
//Binary method 
//and repetition of  quadrats
