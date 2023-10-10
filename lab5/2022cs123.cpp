// problem 1 part i 
#include<iostream>
using namespace std;

int calSum(int num)
{
    if(num==1)
    {
        return 1;
    }

    return num+calSum(num-1);
}


int main()
{
    cout<<calSum(5);
}

// pribelm 1 part 2

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

// problem 1 part 3
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

// porblem 1 part 4
#include<iostream>
using namespace std;
#include<cmath>

int calPowSum(int num)
{
    if(num==0)
    {
        return 1;
    }

    return pow(3,num)+calPowSum(num-1);
}

int main()
{
  cout<<calPowSum(3);
}

// problem 1 part 5
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

// problem 1 part 6
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

//probem 2 part 1
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

// problem 2 part 2 
#include<iostream>
using namespace std;

string nToSring(int n)
{
    switch (n)
    {
    case 1 :
        return "one";
    case 2:
        return "two";
   case 3:
        return "three";  
   case 4:
        return "Four";
   case 5 :
        return "Five";
   case 6:
        return "Six"; 
   case 7:
        return "Seven"; 
  case 8:
        return "Eight";
  case 9:
        return "Nine";
    
    default:
         return "zero";
    
    }
}

string IToS(int num)
{
  if(num < 10)
  {
    return nToSring(num);
  }

  return IToS(num/10)+nToSring(num%10);
}

int main()
{
   cout<<IToS(130);
}

// problem 2 part 3
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
  if(a%b==0)
  {
    return b;
  }

  return gcd(b,a%b);
}

int main()
{
  cout<<gcd(33,216);
}


// problem 3 part 1
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

// problem 3 part 3
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

// problem 7 part i 
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

// problem 8 part 1
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

// challange 1
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

// challenge 2 
#include <iostream>
#include <stack>
using namespace std;

void pushIntoCurrStack(stack<int> &oriStack, stack<int> &currstack)
{
    int oriStaVal = oriStack.top();
    oriStack.pop();
    currstack.push(oriStaVal);
}

void rearrangeStack(stack<int> &oriStack, stack<int> &currstack)
{
        int currStackVal = currstack.top();
        currstack.pop();
        oriStack.push(currStackVal);
}

void sortStack(stack<int> &oriStack, stack<int> &currstack)
{
    if (oriStack.empty())
    {
        return;
    }
    

    (!currstack.empty() && currstack.top() > oriStack.top())? rearrangeStack(oriStack, currstack) : pushIntoCurrStack(oriStack, currstack);

    if(currstack.empty())
    {
      pushIntoCurrStack(oriStack, currstack);
    }

     sortStack(oriStack, currstack);
    
}

int main()
{
    stack<int> oriStack;
    oriStack.push(1);
    oriStack.push(2);
    oriStack.push(4);
    oriStack.push(6);
    oriStack.push(2);

    stack<int> currStack;
    currStack.push(oriStack.top());
    oriStack.pop();

   sortStack(oriStack, currStack);

   cout<<currStack.top();
}