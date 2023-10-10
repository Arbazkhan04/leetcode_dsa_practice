#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> temp;
vector<int> preSubArr={};
void subArray(vector<int>& arr, int sIndex,int eIndex)
{
    vector<int> currSub;
    if(sIndex==arr.size() && eIndex == arr.size())
    {
       currSub.push_back(arr[eIndex]);
       temp.push_back(currSub);
       return;
    }

    if(eIndex!=arr.size())
    {
      currSub = preSubArr;
      currSub.push_back(arr[eIndex]);
    }
   temp.push_back(currSub);
   preSubArr=currSub;

    eIndex!=arr.size()? eIndex++:sIndex++;

    if(eIndex==arr.size())
    {
        eIndex=sIndex;
    }
    subArray(arr,sIndex,eIndex);
}


// vector<vector<int>> subArray(vector<int>& arr , int sIndex, int eIdnex)
// {
//   if(sIndex==arr.size()) //base case
//   {
//     return {{}};
//   }
 
//   eIdnex!=arr.size()? eIdnex++:sIndex++;

//   if(sIndex==arr.size())
//   {
//     eIdnex=sIndex;
//   }
   
//    vector<vector<int>> subArr = subArray(arr,sIndex,eIdnex);
//    return subArr;

// }

int main()
{
   
    vector<int> arr = {1, 3, 2};
    // vector<vector<int>> subArr = subArray(arr,0,0);
      subArray(arr,0,0);
    for(const vector<int>& arr:temp)
    {
        for(int val:arr)
        {
            cout<<val;
        }
        cout<<endl;
    }
}