#include "rsa.h"

#define FRM 250
#define TO 512

int main()
{

srand(time(0));

mpz_class a=bg_num(FRM,TO);
mpz_class b=bg_num(FRM,TO);
mpz_class c=a*b;

unsigned int llg=_lg(a);
unsigned int ll=_lg(b);
unsigned int la=_lg(c);

std::cout<<a.get_str()<<"\n";
std::cout<<"bits\t"<<llg<<"\n";

std::cout<<b.get_str()<<"\n";
std::cout<<"bits\t"<<ll<<"\n";

std::cout<<c.get_str()<<"\n";
std::cout<<"bits\t"<<la<<"\n";

//system("pause");

return 0;
}
