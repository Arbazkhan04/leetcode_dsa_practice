/*recursive solution
*/
class Solution {
public:
    int tribonacci(int n) {
        if(n<=0){return 0;}
        if(n==1 || n==2){return 1;}
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};

// tabulation solution(buttom up approach)
class Solution {
public:
    int tribonacci(int n) {
        vector<int> t(n+3);
        t[0]=0;
        t[1]=1;
        t[2]=1;
        for(int i=3;i<=n;i++){
            t[i]=t[i-1]+t[i-2]+t[i-3];
        }
        return t[n];

    }
};