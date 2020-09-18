#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <memory>

#include <fstream>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "../BigInt.h"

#define FIL "/tmp/tst"

#define PLUS  1
#define MINUS 2
#define DIV  3
#define MULT 4
#define POW 5
#define MOD 99

#define TIME 55000

/*
Automatic test of BigInt library
(C)
*/

using namespace std;

const char *beg="#!/bin/bash";

const char *kmd="echo `bc <<<  ";
const char *kmd_tw="` > /tmp/tst";

const char *sq="sqrt("; //sqrt to add


void ver_cmd()
{
system("ls /usr/bin |grep bc>/tmp/ko");

fstream fs;
fs.open("/tmp/ko",fstream::in);
fs.seekg(0,ios::end);
int sz=fs.tellg();
fs.close();
system("rm /tmp/ko");

if(sz==0)
{
cout<<"programm bc is not install in your system\n";
cout<<"please install it to be able to use auto_test progamm\n";
cout<<"or use manual test\n";
exit(-7);
}

}





void wrt(string in) //write bash script and execute command
{
//const char *cm=in.c_str();
fstream fs;
fs.open("/tmp/sc",fstream::out);

if(!fs.is_open())
{
std::cout<<"err:file is not open";
fs.close();
exit(1);

}


fs.write(beg,strlen(beg)); //write beginning
fs.write("\n",2); //enter
fs.write(in.c_str(),in.size()); //write command

fs.close();

system("chmod +x /tmp/sc");

system("/tmp/sc");
system("rm /tmp/sc");

//system(in.c_str());
}


string sp(string on,int zch,string tw)
{
string rt;
rt.append(kmd); //append first part of command
rt.append(on); //append first number

switch(zch) //append digit
{
case 1:
	rt.append("+");
	break;
case 2:
	rt.append("-");
	break;
case 3:
	rt.append("/");
	break;
case 4:
	rt.append("*");
	break;
case 5:
	rt.append("^");

default:
	rt.append("%");
}

rt.append(tw); //append second number
rt.append(kmd_tw); //append second part of command


return rt;

}




string rd() //read the result of operation of programm to compare from file
{
fstream fs;

string rt;	

fs.open(FIL,fstream::in);

fs.seekg(0,ios::end); //take number of digit to read

size_t sz=fs.tellg();
fs.seekg(0,ios::beg); //return to the beginning of file


//unique_ptr <char>lp(new char(sz));
//char *buf=lp.get();

char *buf=new char[sz+1];
if(fs.read(buf,sz)) 
	rt.append(buf,0,sz-1);

else
	rt.append("err:error reading");


fs.close();



delete[]buf;
return rt;

}

inline void prn_hlp()
{
cout<<"usage: auto_test -t pause_time -d digits number";
cout<<"\n";
}


//
//command usage
//auto_test -t pause time -d digit number
//-h help
//

int main(int argc,char**argv) 
{

ver_cmd();

 
unsigned int lim=0; //first
unsigned int lm=0; //second

unsigned int on[10]={0};
unsigned int to[10]={0};

int dg=10;
int tim=TIME; //time
string srt;

/////////////////////////////////////////
if(argc==2)
{
prn_hlp();
return -3;
}
if(argc>2) //some arguments
{

for(int i=1;argc==3?i<argc:i<5;i=i+2)
{
if(strcmp(&argv[i][0],"-t")==0) //time in milliseconds
{
int l=0;
l=atoi(&argv[i][3]);
l<=0?tim=TIME:tim=l;

}

else if(strcmp(&argv[i][0],"-d")==0) //amount of digits
{
int l=atoi(&argv[i][3]);
l<=0?dg=10:dg=l;

}

else 
{
prn_hlp();
return -9;
}
}

}

////////////////////




int up=9; //1srt number
int lw=1; 

int sc=9;//second number
int tw=1; 

srand(time(0));

for(int i=1;i<=dg;)
{


if(up>=1000000) //if the number reached the limit
{

lim++; //limit
up=9;
lw=1;

sc=9;
tw=1;
lm=0;
}

if(sc>up&&lm==lim) //the second number reached the limit
{
sc=9;
tw=1;
up=up*10;
lw=lw*10;
lm=0;
i++;
continue;
}

if(sc>=1000000 && lm < lim) //limit of first number didnt reach the limit of second  
{
lm++;
sc=9;
tw=1;
}


int  a=lm;
while(a<=lm) //fill array with random numbers until limit
{
int tm=rand()%(sc-tw)+tw;

to[a]=tm;
a++;
}


int y=lim;
while(y<=lim) //first number generation
{

int tm=rand()%(up-lw)+lw;
on[y]=tm;

y++;
}

printf("\nlm%d\t",lm);
printf("\nlim%d\t",lim);

BigInt od(on,lim+1); //first number
BigInt dv(to,lm+1); //second number
BigInt tr="0"; //result



if(od<dv)
{
BigInt tl=od;
od=dv;
dv=tl;

}




cout<<"\n\nfirst number\n\n"<<od.gt_str()<<"\n";
cout<<"\n\nsecond number\n\n"<<dv.gt_str()<<"\n";

usleep(tim);
system("clear");
std::cout<<"\n\n";

cout<<"\n\n<======= plus =======>\n\n";
tr=od+dv;

std::cout<<od.gt_str()<<"+"<<dv.gt_str()<<"="<<tr.gt_str()<<"\n";

srt=sp(od.gt_str(),PLUS,dv.gt_str()); //concate command to be executed


wrt(srt); //execute a command

srt.clear();

srt=rd(); //read a result of executing


if(srt.find("err")!=string::npos) //error occured
{
std::cout<<"\nerror occured\n";
std::cout<<srt.c_str();
break;
}

if(tr!=srt) //result of calc and result of program are not equal
{
cout<<"some error occured in program"<<tr.gt_str()<<"not equal"<<srt;
break;
}


srt.clear();

usleep(tim);
system("clear");



cout<<"\n\n<======= minus =======>\n\n";
tr=od-dv;
cout<<od.gt_str()<<"-"<<dv.gt_str()<<"="<<tr.gt_str()<<"\n";

srt=sp(od.gt_str(),MINUS,dv.gt_str());


wrt(srt);
srt.clear();

srt=rd();

if(srt.find("err")!=std::string::npos) //error in while proceeding
{
cout<<"error occured:\n";
cout<<srt;
break;

}

if(tr!=srt)
{
cout<<"some error in programm"<<"result of programm"<<tr.gt_str()<<"not equal"<<srt;
break;
}



srt.clear();

usleep(tim);
system("clear");


cout<<"<=======division=======>\n\n";
tr=od/dv;

cout<<od.gt_str()<<"/"<<dv.gt_str()<<"="<<tr.gt_str()<<"\n";

srt=sp(od.gt_str(),DIV,dv.gt_str());

wrt(srt);
srt.clear();

srt=rd();

if(srt.find("err")!=std::string::npos)
{
cout<<"error occured:\n";
cout<<srt;
break;

}

if(tr!=srt)
{
cout<<"some error in programm"<<tr.gt_str()<<"not equal"<<srt;
break;
}


srt.clear();

usleep(tim);
system("clear");


cout<<"<=======multiply=======>\n\n";
tr=od*dv;

cout<<od.gt_str()<<"*"<<dv.gt_str()<<"="<<tr.gt_str()<<"\n";
srt=sp(od.gt_str(),MULT,dv.gt_str());

wrt(srt);
srt.clear();

srt=rd();

if(srt.find("err")!=std::string::npos)
{
cout<<"error occured:\n";
cout<<srt;
break;

}


if(tr!=srt)
{
cout<<"some error in programm "<<"result of programm"<<tr.gt_str()<<"is not equal"<<srt;

break;
}



srt.clear();

usleep(tim);
system("clear");

cout<<"<=======modulus=======>\n\n";


tr=od%dv;

cout<<od.gt_str()<<"mod"<<dv.gt_str()<<"="<<tr.gt_str()<<"\n";

srt=sp(od.gt_str(),MOD,dv.gt_str());

wrt(srt);
srt.clear();

srt=rd();

if(srt.find("err")!=std::string::npos)
{
cout<<"error occured:\n";
cout<<srt;
break;

}

if(tr!=srt)
{
cout<<"some error in programm\n"<<"result of program"<<tr.gt_str()<<"is not equal to "<<srt<<"\n";
break;
}



srt.clear();

usleep(tim);
system("clear");


cout<<"<======pow==========>\n\n";
tr= /* */



unsigned int rnd=rand()%999; /////////////

BigInt fr(rnd);

cout<<od.gt_str()<<"^"<<fr.gt_str()<<" mod"<<dv.gt_str()<<"="<<tr.gt_str()<<"\n";

srt=sp(od.gt_str(),POW.fr.gt_str());
srt=sp(srt,MOD,dv.gt_str());

wrt(str);
srt.clear();

srt=rd();

if(srt.find("err"!==std::string::npos)
{
std::cout<<"error occured\n";
std::cout<<srt;
break;
}

usleep(tim);
system("clear");



cout<<"<=======square=======>\n\n";
tr=od.sqrt();

cout<<"sqrt "<<od.gt_str()<<"="<<tr.gt_str()<<"\n";

srt.append(kmd);
srt.append("'");
srt.append(sq);
srt.append(od.gt_str());
srt.append(")");
srt.append("'");
srt.append(kmd_tw);


wrt(srt);
srt.clear();
srt=rd();

if(srt.find("err")!=std::string::npos)
{
cout<<"\nerror occured\n";
cout<<srt;
break;

}

if(tr!=srt)
{
cout<<"some error occured in programm "<<od.gt_str()<<dv.gt_str()<<"first "<<tr.gt_str()<<" is not equal "<<srt;
break;

}

tr=dv.sqrt();

srt.clear();

cout<<"sqrt "<<dv.gt_str()<<"="<<tr.gt_str()<<"\n";

srt.append(kmd);
srt.append("'");
srt.append(sq);
srt.append(dv.gt_str());
srt.append(")");
srt.append("'");
srt.append(kmd_tw);


wrt(srt);
srt.clear();
srt=rd();

if(srt.find("err")!=std::string::npos)
{
cout<<"error occured\n";
cout<<srt;
break;

}

if(tr!=srt)
{
cout<<"{2} some error occured in programm\n";
cout<<"first"<<tr.gt_str()<<"is not equal"<<srt<<"\n";
break;

}


memset(to+lm,0,lm);

srt.clear();
usleep(tim);

sc=sc*10;
tw=tw*10;

}

system("clear");


cout<<"\n\n<====== END ======>\n\n";



return 0;
}
