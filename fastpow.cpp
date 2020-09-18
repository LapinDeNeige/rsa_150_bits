#include <iostream>
#include "../BigInt/BigInt.h"
#include <stdio.h>




BigInt fastpow(BigInt num,BigInt dg,BigInt mod)
{

if(dg=="0")
	return (BigInt)"1";
if(dg=="1")
	return *this;

BigInt lg[20]={"0"}; //logs
BigInt nm[20]={"0"}; //result numbers to multiply


BigInt tw("2");
int j=0;

lg[0]=dg.lg();

BigInt l;
l=tw.binpow(lg[0],(BigInt)"0"); //2^log

BigInt ot;
ot=dg%l; //rest from 2^log
j++;

while((BigInt)"3"<=ot)
{
l=ot.lg();
lg[j]=l;

l=tw.binpow(l,(BigInt)"0");

ot=ot%l;
j++;
}

BigInt nn("1");

if(ot!=(BigInt)"0")
	nn=num.binpow(ot,mod);

int tl=0;

bool br=1;

BigInt rs("1");

while(br)
{
num=(num*num)%mod;

	for(size_t f=0;f<j;f++)
	{
		lg[f]=lg[f]-"1";
		
		if(lg[f]=="0")
		{
			nm[tl]=num;
			tl++;
			j--;
			if(f==0)
			{
			br=0;
			break;
			}

		}



	}

}


j=0;

while(nm[j]!="0") //multiply results between one another
{
rs=(rs*nm[j])%mod;
j++;

}

if(j==0) //nothing to count
	rs=(BigInt)"0";

rs=(rs*nn)%mod; //mupltiply result on the rest 


return rs;


}

