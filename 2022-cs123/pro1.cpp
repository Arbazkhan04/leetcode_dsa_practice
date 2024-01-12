#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
string prefix(string exp);
string postfix(string exp);


string prefix(string exp)
{
  string revStr;
  string pConvert;
  //rever the string 
  for(char c: exp)
  {
      if(c==')')
      {
          c='(';
          revStr+=c;
      }
      else if(c=='(')
      {
          c=')';
          revStr+=c;
      }
      else
      {
          revStr+=c;
      }
      
  }
      reverse(revStr.begin(),revStr.end());
      pConvert = postfix(revStr);
     reverse(pConvert.begin(),pConvert.end());
     return pConvert;
  
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '/' || ch == '*') {
        return 2;
    }
    return 0;
}

string postfix(string exp) {
    stack<char> stack;
    string output;
    
    for (char c : exp) {
        if (isdigit(c) || isalpha(c)) {
            output += c;
        } 
        else if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                char top = stack.top();
                stack.pop();
                output += top;
            }
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
        } 
        else {
            while (!stack.empty() && precedence(c) <= precedence(stack.top())) {
                char top = stack.top();
                stack.pop();
                output += top;
            }
            stack.push(c);
        }
    }
    
    while (!stack.empty()) {
        char top = stack.top();
        stack.pop();
        output += top;
    }
    
    return output;
}

int main() {
    string exp;
    
    cout << "Enter expression: ";
    cin >> exp;
    
    string val = postfix(exp);
    cout << "Postfix: " << val << endl;
    
     string preVal = prefix(exp);
    cout << "pre: " << preVal << endl;
    
    return 0;
}

