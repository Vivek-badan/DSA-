class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int ans;
        int org_n=n;
        while(n>0){
            int last_digit=n%10;
            sum+= last_digit;
            product*=last_digit;
            
            n=n/10;
        }
        ans=sum+product;
        if(org_n%ans==0) {
            return true;
            }
        else{
            return false;
        }
    }
};