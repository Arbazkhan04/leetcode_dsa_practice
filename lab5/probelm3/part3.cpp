#include<iostream>
using namespace std;

bool searchBinary(int *arr,int left ,int right , int target)
{
    int mid= (left+right)/2;
    if(arr[mid]==target)
     {
        return true;
     }
     if(left>right)
     {
        return false;
     }
     mid<target? left=mid+1:right=mid-1;
   return searchBinary(arr,left,right,target);

}

int main()
{
  int arr[10]={1,2,3,4,5,6,7,8,9};
  int target = 7;
  int left = 0;
  int right = 9;
  cout<<searchBinary(arr,left,right,target);

}