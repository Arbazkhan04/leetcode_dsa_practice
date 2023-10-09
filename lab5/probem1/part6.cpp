#include<iostream>
using namespace std;

int calSum(int num)
{
    if(num==1)
    {
        return 1;
    }

    return num+calSum(num/2);
}

int main()
{
 cout<<calSum(16);
}