class Solution {
public:
    int climbStairs(int n) {
       vector<int> t(n+1);
    //    t[0]=1;
    //    t[1]=1;
    t[0]=0;
    t[1]=1;
    t[2]=2;
       for(int i=3;i<=n;i++){
           t[i]=t[i-1]+t[i-2];
       }
       return t[n];
    }
};


//fibnocii series 
class Solution {
public:
    int fib(int n) {
        vector<int> t(n+2);
        t[0]=0;
        t[1]=1;
        for(int i=2;i<=n;i++){
            t[i]=t[i-1]+t[i-2];
        }
        return t[n];
    }
};