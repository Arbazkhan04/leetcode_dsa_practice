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