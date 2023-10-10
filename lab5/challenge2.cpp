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