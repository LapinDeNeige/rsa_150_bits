#include "BigInt.h"
#include <string.h>
#include <iostream>
#include <stdio.h>


int main()
{
unsigned int arr[2]={648,123};
BigInt on(arr,sizeof(arr)/sizeof(int));

//BigInt on="120";

on=on.sqrt();

std::cout<<on.gt_str();

return 0;
}
