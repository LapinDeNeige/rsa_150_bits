#include "BigInt.h"

using namespace std;




bool BigInt ::les (BigInt two) //less than
{
//0(N)=N
//best O(N)=1
BigInt *one=this;


if(one->get_num_siz()==two.get_num_siz()) //if amount of digits of two numbers is equal
{
char gg[2]={0};
char bb[2]={0};
bool st=0;

for(int i=0;i<one->get_num_siz();i++)
{


//begin from te beginning
gg[0]=one->get_str_pos(i); //get the current position of digit
bb[0]=two.get_str_pos(i);

short ll=atoi(gg); //one
short qq=atoi(bb); //tow

if(ll<qq) //one < two
{ //if the first number on the i position  is less that second one
st=true; //first number is less
break;
}
else if(qq<ll) //first number is  more on the i position is more than second number
{
st=false; //first number is not less
break;
}

else //if the numbers on the i position are equal
    continue; //go to the net digit

}




return st;




}


if(one->get_num_siz() < two.get_num_siz()) //if amount of digits of first number is less than of second
    return true; //less
else
    return false; //not less
//best O(N)=1

}


bool BigInt:: equ(BigInt two) //equal
{
//O(N)=N
//best O(N)=1
BigInt *one=this;

bool is_eq=true;

if(one->get_num_siz()!=two.get_num_siz()) //the sizes number are not equal
    return false; //numbers are not equal //best O(N)=1

//else count of numbers digits is equal

for(int i=0;i<one->get_num_siz();i++)
{
if(one->get_str_pos(i)!=two.get_str_pos(i)) //if the first number in the position
{ //is not equal to the second number in the i position
    is_eq=false; //numbers are not equal
    break; //
}

//else numbers are equal
}
return is_eq;

}


string BigInt :: conv_int_to_str(unsigned int i) //convert int number to string
{
string rt;
stringstream ss;
ss<<i;
rt.append(ss.str());
return rt;

}


string BigInt::conv_int_to_str (unsigned int *in,const int siz) //convert array of int to str and save it to str
{
string rt;

for(int i=0;i<siz;i++)
{

stringstream ss;
ss<<in[i];

//std::cout<<"current"<<ss.str()<<"\n";
rt.append (ss.str());

}

return rt;

}

void BigInt::conv_str_to_int(unsigned int *out,const int siz) //string to integer
{
string str=this->in_str;

//std::cout<<"str size"<<str.size()<<"\n";

if(str.size()<9) //amount of digits of current number is less than 9
	out[0]=(unsigned int)atoi(str.c_str());


else
{


for(int i=0, a=0;i<str.size();i=i+9,a++)
{
string cur;
if((str.size()-i)>=9) //razniza mezhdu the last digit and current digit
	cur=str.substr(i,i+9); //take 9 digits



else //the differenceis less than 9
	cur=str.substr(i,str.size()); //take last 9 digits


out[a]=(unsigned int)atoi(cur.c_str()); //convert current digit to int
//and add it to the current array
}

}

}


//just get string and convert each one to the int
//sum them and get back to str result
BigInt BigInt::sum (BigInt two) // sum each int vector
{
//O(N)=N

//result of sum invert back to string
BigInt *one;
BigInt ret; //to return
one=this;

//find the vector with min size
string on_str= one->gt_str(); //get a string order of the numbers from the first class

string tw_str=two.gt_str(); //get from the second class
string result;

if(tw_str.size() > on_str.size())
{
string tmp=tw_str;
tw_str=on_str;
on_str=tmp;

}



int siz;

//int mn=fin_min(one->get_num_siz(),two.get_num_siz());


short rest=0;
char tr[1];
char tt[1];
//size_t j=tw_str.size()-1;



for(int i=on_str.size()-1, j=tw_str.size()-1;i>=0;i--,j=j-1)   //sum from end
{

short res;

memset(tr,0,sizeof(tr)/sizeof(char));
memset(tt,0,sizeof(tt)/sizeof(char));


tr[0]=on_str[i];//take each digit
short oon=atoi(tr); //convert it to number
short dif=on_str.size()-tw_str.size();

int tow;

if(i<=(dif-1))
    tow=0;


else
{
tt[0]=tw_str[j];
tow=atoi(tt);
}
res=oon+tow;
res=res+rest; //add rest stayed from the previeous sum

rest=rest^rest;

if(res > 9) //more than 4 digits
{
rest=res/10; //first
res=res%10; //last

}

std::stringstream ss;

ss<<res;



result.insert(0,ss.str());
}




if(rest > 0)
{
stringstream ss;
ss <<rest;
result.insert(0,ss.str());
}




ret.ins_str(result); //all right

return ret;

}






BigInt BigInt:: mult (BigInt two) //here each result of mult save in string
{


//and convert `it to the bigInt
//////////////
BigInt *on;
on=this;
int cnt=0; //count of zeroes to multiply
short pnt=0; //count of eroe
BigInt rss;
string onn=on->gt_str(); //get first vector
string tow=two.gt_str(); //get anotger vector
//this->get_siz() > two.get_siz() ? on=this :on=twothis=two;
string rr;
bool trig=false;

if(two=="0")
{
rss.ins_str("0");
return rss;

}

//and now beginning from the end of the string
//multiply them
//convert to the string and add zeros
//and to the class



char tr[2];
char tt[2];
for(short i=onn.size()-1;i >=0;i--)
{
cnt=0; //count of zeroes to add
for(short j=tow.size()-1; 0 <= j;j--)
{
short cry=0;
tr[0]=onn[i]; //get each four numbers
tt[0]=tow[j];
short onn=atoi(tr);
short tww=atoi(tt);
 //mult
int res=onn*tww;
//convert to string
std::stringstream ss;
ss<<res;
rr=ss.str();



if((cnt+pnt) > 0)
{
for(int i=0;i < (cnt+pnt);i++)
{
rr.append("0");

}

if(trig)
{
trig=false;
cnt--;
}
}
BigInt de(rr);
rss=rss+de;

cnt++;
}


pnt++;

}

return rss;
}





BigInt BigInt::sub (BigInt two)
{
//O(N)=N

BigInt *one;
one=this;
string on_str=one->gt_str();
string tw_str=two.gt_str();
string result;
BigInt rrs;
char on[1];
char tt[1];
short carry=0;

if(this->equ(two)) //O(1)
{
result.append("0");
rrs.ins_str(result);
return rrs;
}
if(tw_str.size() > on_str.size())
{                                 //if second number is bigger than firest one
string tmp=on_str;                 //change them
on_str=tw_str;
tw_str=tmp;

}

for(int i=on_str.size()-1,j=tw_str.size()-1;i>=0;i--,j--) //from the end
{
memset(on,0,sizeof(on)/sizeof(char));
memset(tt,0,sizeof(tt)/sizeof(char));

on[0]=on_str[i];
short onn=0;
onn=atoi(on);  //take first number

if(i < on_str.size()-tw_str.size() &&!carry)
{                                            //reached end of the second number
                                            //fill result with zeros
stringstream ss;
ss << onn;
result.insert(0,ss.str());
//carry=0;
continue;


}


tt[0]=tw_str[j]; //take second number
short ttw=atoi(tt);

onn=onn-carry;
carry=0;

if(onn < ttw) //if first is less than second
{
carry++;  //retake 10 to the first
onn=onn+10;

}

short res=(onn-ttw);

stringstream ss;
ss <<res;

result.insert(0,ss.str());

}

if(result[0]=='0') //if result begins wih zeroes
{
short i=0;
while(result[i]=='0')  //erase them
    result.erase(0,1);

}



rrs.ins_str(result);
return rrs;

}



string BigInt::sub(string two)
{ //o(N)=N
BigInt *one;
one=this;
string on_str=one->gt_str();

string result;
BigInt rrs;
char on[1];
char tt[1];
short carry=0;


if(two.size() > on_str.size())
{
string tmp=on_str;
on_str=two;
two=tmp;

}


for(int i=on_str.size()-1,j=two.size()-1;i>=0;i--,j--)
{
memset(on,0,sizeof(on)/sizeof(char));
memset(tt,0,sizeof(tt)/sizeof(char));
on[0]=on_str[i];
short onn=0;
onn=atoi(on);

if(i < on_str.size()-two.size() &&!carry) //reached the end of one of numbers
{

stringstream ss;
ss << onn; //convert the bigger number
result.insert(0,ss.str());
//carry=0;
continue;


}


tt[0]=two[j];



short ttw=atoi(tt);

onn=onn-carry;
carry=0;

if(onn < ttw)
{
carry++;
onn=onn+10;

}

short res=(onn-ttw);

stringstream ss;
ss <<res;

result.insert(0,ss.str());

}

if(result[0]=='0')
{
short i=0;
while(result[i]=='0')
    result.erase(0,1);

}




return result;


}


BigInt BigInt::sqrt() //get square from big by binary search
{ //O(N)=logN*(n^2+3N)

BigInt *on=this; //first(dividing) number
BigInt m;
if(*on=="1"||*on=="0") //O(1)
	return *on;


BigInt r=*on; //right
BigInt l ("0"); //left


while(l<=r)
{
m=(r+l);
m=m/2; //proposed number
BigInt rs=m*m;//square of proposed number

if(*on<rs) //the first (dividing) number is less than kva of proposed one
    r=m-"1"; //search in the left subhalfte
else  //rs>on //first (dividing) number is more or euqal tthan kva of proposed number
{
BigInt tl=m*"2"; //find out if the kva of the next after proposed number is more than
tl=tl+"1"; //first number
tl=tl+rs; //kva of the next after sec(proposed) number

if(tl<=*on)//it's less than the first(deviding) number
    l=m+"1"; //search the next number as the proposed number is not enough big

else //>=rs //it's more or equal to the first(dividing) number
    break; //the proposed number is enough big found it
}



}

return m;

}



BigInt BigInt::div(int tw) //divide
{

//O(N)=2(siz(two))+(siz(one)-siz(two))
//O(N)=N
//the best O(N) is 1
short cnt=0;
char ch[34]={0};

string on=this->gt_str();
string res; //result str

char ff[2]={0};
int tm=tw; //


int th;

string bb;
bb.append("0");
string ii;
ii=on.at(0);



if(tw==1)                //if second number (divided)is 1
{                          //return dividing number
res.append(on);
return res;

//O(N)=1
}



if(ii.compare(bb)==0) //if first umber is zero
{
res.append("0"); //return zero
return res;
}


if(cnt==0 &&tw==0) //if a divided number is zero
{                   //returned answer is error
res.append("error");
return res;

}

while(tm) //get the count of digits of the second number
{
//0(N)=N
tm=tm/10;
cnt++;

}




for(int i=0;i<cnt;i++)
{ //O(N)=N
ch[i]=on.at(i);  //move to the temporary array a divider

}

//equal
int oo=0;



for(int i=0;i<cnt;i++)  //and convert divivder from string to int
{

ff[0]=ch[i];
short y=atoi(ff);
oo=(oo*10)+y;

}


if(oo<tw )  //divider is less than divided number
{
if(on.length()<cnt)  //if divider is less than deivided number
{
res.append("0");
return res;

}

if(cnt>on.size()) //if first (dividing) number is less than second (divided) number
{
res.append("0"); //return 0
return res;
}



while(true) //if the current sub of the fisrt(dividing) number is less than soconf one
{
if(oo>=tw) //if it is not true
    break; //get out

if(cnt == on.size())  //the size of the first number is equal to the sone of second
{
//res.append("0");
break;
}

ch[cnt]=on.at(cnt);
char rr=ch[cnt];


oo=(oo*10)+atoi(&rr); //add the next digits to the first number

cnt++;
}


}



int jj=oo;

short rst=tw;
bool bg=1;
th=-1;

bool twc=0;


for(int i=cnt-1;i<=on.size()-1;i++)
{

//O(N)=(siz(one)-siz(two))
//O(N)=N

if(rst<tw && jj!=0) //result of devisnion is less than devided number and it is not zero
{


if(twc)
{
res.append("0");

char yu=on.at(i);
jj=(rst*10)+atoi(&yu);
rst=jj;

/*
if(i==(on.size()-1)&& jj<tw)
    break;

else if(i==(on.size()-1)&& jj >=tw)
{
i--;
bg=true;
continue;
}
*/

}


else if(rst>0) //there is some rest of div
{
char yu=on.at(i);
jj=(th*10)+atoi(&yu); //take the next digit
rst=jj;//
twc=1;

}


//24145
//134
else if(rst==0) //no rest
{
char yu=on.at(i);
jj=atoi(&yu);
rst=jj;
//jj==0?th=-1:th=jj;

twc=1;

}

if(i==on.size()-1) //reached the end of the first number
{
if(jj>=tw) //the current taken number is more than second one
{

i--;
bg=true;
continue; //continue dividing
}

else //the current taken number is less than second  number
{
res.append("0"); //add null to the result
break;//jj<tw //out

}
}

continue;
}

bg==false?i=i-1:i=i;

rst=jj%tw;
jj=jj/tw;

stringstream ss;
ss<<jj;
res.append(ss.str());

if(jj==0)
    jj=1;
th=rst;

bg=0;

twc==1?twc=0:twc=twc;

}


BigInt rtt;
rtt.ins_str(res);

return rtt;

}





BigInt BigInt::div(BigInt two)
{
//O(N)=log2N*(N+N)
//worse O(N)=log2N*(N^2+N);
//best O(N)=1
//search an answer with the binary search

BigInt *one=this; //first (dividing) number

BigInt y;
if(*one<two) //if the first number is less than second one
{
y.ins_str("0"); //0
return y;
//best O(N)=1
}


BigInt l("0");
BigInt r=*one;


while(l <=r)
{
string rr=r.gt_str();//get str from bigint
string ll=l.gt_str();
y=(r+l);//get a middle
y=y/2;
string yy=y.gt_str();


BigInt rs=two*y;//multiply a second divided  number with current middle num for check if it is equal or not to the dividing number
//get proposal
//best O(N)=N
//worse O(N)=N*N

string bc=rs.gt_str();
if( rs <= *one) //if a result of multiplication of left and middle nm is less than dividing num
{
BigInt jj=rs+two;//O(N)=N

if(*one < jj) //check if the proposed number is smaller by one
{
break; //found
}
else
    l=y+"1"; //continue search

//continue
}

else
{
r=y-"1";

}


}

return y;


}




void BigInt::ins_str  (string in) //insert string
{
this->in_str=in;

}

void BigInt ::app_str(string in)  //append string
{
string on=this->in_str;
on.append(in);
this->in_str=on;



}




string BigInt ::gt_str () //get string
{
return this->in_str;

}


char BigInt::get_str_pos (short pos) //got string in some position
{
if(pos>=this->get_num_siz())
    return false;

return this->in_str[pos];


}



long long BigInt:: get_num_siz() //get number of digits
{
short ho=in_str.size();
return ho;
}


BigInt BigInt::operator + (BigInt two)
{
return this->sum(two);



}

BigInt BigInt ::operator-(BigInt two)
{
return this->sub(two);

}

BigInt BigInt ::operator*(BigInt two)
{
return this->mult(two);


}



BigInt BigInt::operator/(BigInt two)
{
return div(two);
}


BigInt BigInt ::operator/(int two)
{

return this->div(two);

}



bool BigInt::operator < (BigInt two)
{
return this->les(two);

}

bool BigInt::operator==(BigInt two)
{
return this->equ(two);

}


bool BigInt ::operator!= (BigInt one)
{
if(this->equ(one))
	return false;

return true;
}



BigInt BigInt ::operator %(BigInt tw)
{ //O(log(n)+n^2+n)
BigInt tm=this->div(tw);
tm=tm.mult(tw);
BigInt rt=this->sub(tm);

return rt;
}

bool BigInt ::operator<=(BigInt two)
{
if(this->les(two))
    return true;
if(this->equ(two))
        return true;

return false;

}


BigInt::BigInt (char *in)
{

this->in_str=in;


}

BigInt :: BigInt (string in)
{
this->in_str=in;

}


BigInt::BigInt(unsigned int *i,const int siz) //convert int key to string
{
//convert it to string
//and save in in_str

this->in_str=conv_int_to_str(i,siz);

}


BigInt::BigInt (unsigned int i) //take one digit nmber
{
this->in_str=conv_int_to_str(i);

}

BigInt ::BigInt ()
{
this->in_str="0";

//spl_str(in_str);

};



/*
int main()
{
    return 0;
}
*/


