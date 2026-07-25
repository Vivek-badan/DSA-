class Solution {
public:
    int maxProduct(int n) {
       
       vector<int>getdigits;
       // EXTRACTION OF NUMBER 
        while(n>0){
            getdigits.push_back(n%10);
            n=n/10;
        }
        //SORT THE ARRAY 
        sort(getdigits.begin(),getdigits.end());
        int m=getdigits.size();
        return {getdigits[m-1]*getdigits[m-2]};

        
    }
};