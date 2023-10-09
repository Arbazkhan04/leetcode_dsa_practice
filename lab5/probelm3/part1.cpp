#include<iostream>
using namespace std;


int searchFirstEntry(int *arr, int currentIndex, int target,int size)
{
   if(arr[currentIndex]==target)
   {
    return  currentIndex;
   }
   if(currentIndex>=size)
   {
    return -1;
   }
   return searchFirstEntry(arr,currentIndex+1,target,size);
}

int main()
{
    int size =5;
    int arr[5] = {1,2,3,5,6};
    cout<<searchFirstEntry(arr,0,5,size);

} 