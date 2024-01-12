#include <iostream>
#include <stack>
using namespace std;

int calculateSum(char c, int a1, int a2);

int prefix(string exp)
{
    stack<int> pre; 
    for (int i = exp.size() - 1; i >= 0; i--) //
    {
        if (isdigit(exp[i]))
        {
            int val = exp[i] - '0'; 
            pre.push(val);
        }
        else
        {
            int p1 = pre.top(); 
            pre.pop();
            int p2 = pre.top();
            pre.pop();
            int result = calculateSum(exp[i], p1, p2);
            pre.push(result);
        }
    }
    return pre.top();
}

int postfix(string exp)
{
    stack<int> pre; 
    for (int i = 0;i<exp.size();i++) 
    {
        if (isdigit(exp[i]))
        {
            int val = exp[i] - '0'; 
            pre.push(val);
        }
        else
        {
            int p1 = pre.top(); 
            pre.pop();
            int p2 = pre.top();
            pre.pop();
            int result = calculateSum(exp[i], p1, p2);
            pre.push(result);
        }
    }
    return pre.top();
}
int calculateSum(char c, int a1, int a2) 
{
    int sum;
    switch (c)
    {
    case '+':
        sum = a1 + a2;
        break;
    case '-':
        sum = a1 - a2;
        break;
    case '*':
        sum = a1 * a2;
        break;
    case '/':
        sum = a1 / a2;
        break; 
    }
    return sum;
}

int main()
{
    string exp;
    cout << "Enter value: ";
    cin >> exp;
    int prefixEvaluation = prefix(exp);
    cout << "Prefix Evaluation: " << prefixEvaluation << endl;
   
    return 0;
}

