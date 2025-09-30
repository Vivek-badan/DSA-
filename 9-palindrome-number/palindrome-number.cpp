class Solution {
public:
    bool isPalindrome(int x) {
        int original_x=x;
        //bit extraction
        long long sum=0;
        while(x>0){
            
            int d=x%10;
            sum=sum*10+d;
            x=x/10;
        }
        if(sum==original_x){
            return true;
        }

        return false;
    }
};