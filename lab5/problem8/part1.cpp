#include<iostream>
#include <unordered_map> 
using namespace std;

unordered_map<int,int> memo;

int truSum(int num)
{
   if(num<=3)
   {
    return num; 
   }

   if(memo.find(num)!=memo.end())
   {
    return memo[num];
   }

   memo[num]=truSum(num-1)+truSum(num-2)+truSum(num-3);
   return memo[num];
}

int main()
{
  int num;
  cout<<"Enter val";
  cin>>num;
  cout<<truSum(num);
}