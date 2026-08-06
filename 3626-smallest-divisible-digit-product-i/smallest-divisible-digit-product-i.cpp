class Solution {
public:
    int productfunction(int n){
        int product=1;
        while(n>0){
            int lastdigit=n%10;
            product *=lastdigit;
            n=n/10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        for(int i=n ; i<=108;i++){
            if(productfunction(i) % t ==0){
                return i;
            }
        }
        return -1;
        
    }
};