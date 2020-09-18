#include "BigInt.h"
#include <iostream>
#include <stdio.h>


BigInt pow(BigInt nm,BigInt dg,BigInt mod)
{
if(dg=="0")
	return "1";

if(dg=="1")
	return nm;

BigInt tmp("1");
bool is=0;

if(mod=="0")
	is=1;

	while(dg!="1")
	{
        	if((dg%"2")=="1")
		{
			dg=dg-"1"; 
			tmp=(tmp*nm);

				if(!is)
					tmp=tmp%mod;

		}

                nm=nm*nm;
		dg=dg/"2";

	}

nm=nm*tmp;

if(!is)
	nm=nm%mod;

return nm;
}



int main()
{
BigInt nm("123");


BigInt y("7");
BigInt m("199");

BigInt r=pow(nm,y,m);



std::cout<<nm.gt_str()<<"^"<<y.gt_str()<<" mod "<<m.gt_str()<<" = ";
std::cout<<r.gt_str();

return 0;

}
