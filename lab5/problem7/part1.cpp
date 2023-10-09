#include<iostream>
#include<vector>
using namespace std;

// int fib(int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     return fib(n-1)+fib(n-2);
    
// }

// int main()
// {
//    cout<<fib(6);
// }


//menoziation 

int fib(vector<int>& arr,int n)
{
   if(n<=1)
   {
    return n;
   }
   if(arr[n]!=-1)
   {
    return arr[n];
   }

   arr[n]=fib(arr,n-1)+fib(arr,n-2);
   return arr[n];
}
int main()
{
  int val;
  cout<<"Enter value";
  cin>>val;
  vector<int> arr(val+1,-1);
  cout<<fib(arr,val);

}