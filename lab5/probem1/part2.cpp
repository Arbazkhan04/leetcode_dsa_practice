#include<iostream>
using namespace std;

int calSumOdd(int num)
{
    if(num==1)
    {
        return 1;
    }
    return num+calSumOdd(num-2);
}


int main()
{
  cout<<calSumOdd(9);
}