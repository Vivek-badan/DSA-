class Solution {
public:
    long long countCommas(long long n) {

        long long result=0;
        long long lower=1000;
        long long commas=1;

        while(lower<=n){
            long long upper=lower*1000-1;
            if(upper>n) upper=n;

            long long countnumbers=upper-lower+1;
            result+=(countnumbers*commas);
            lower*=1000;
            commas++;
        }
        return result;
        
    }
};