#include<iostream>
using namespace std;

int calSum(int num)
{
    if(num==1)
    {
        return 1;
    }

    return num+calSum(num/3);
}

int main()
{
 cout<<calSum(81);
}