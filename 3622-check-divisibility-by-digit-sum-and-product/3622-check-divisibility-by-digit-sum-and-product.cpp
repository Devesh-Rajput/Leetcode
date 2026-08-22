class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum=0;
        int pro=1;
        int res=0;
        while(n>0){
            int digit=n%10;
            n/=10;
            pro*=digit;
            sum+=digit;
        }
        res=sum+pro;
    
        return original%res==0;
    }
};