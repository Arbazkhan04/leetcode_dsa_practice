#include<iostream>
using namespace std;
#include<cmath>

int calPowSum(int num)
{
    if(num==0)
    {
        return 1;
    }

    return pow(2,num)+calPowSum(num-1);
}

int main()
{
  cout<<calPowSum(3);
}