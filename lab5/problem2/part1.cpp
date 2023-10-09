#include<iostream>
using namespace std;

string B2D(int num)
{
    if(num <=1)
    {
        return num==1? "1":"0"; 
    }

  return B2D(num/2) + (num%2==0? "0":"1");

}

int main()
{
 cout<<B2D(16);   
}