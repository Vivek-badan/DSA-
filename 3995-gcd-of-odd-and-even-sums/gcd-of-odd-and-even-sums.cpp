class Solution {
public:

    int ans(int &sumEven, int &sumOdd){

        while(sumEven > 0 && sumOdd > 0){

            if(sumEven > sumOdd){
                sumEven = sumEven % sumOdd;
            }
            else if(sumOdd > sumEven){
                sumOdd = sumOdd % sumEven;
            }
            else{
                return sumEven;   
            }
        }

        return max(sumEven, sumOdd);
    }

    int gcdOfOddEvenSums(int n) {

        int cntEven = 1;
        int cntOdd = 1;

        int sumEven = 0;
        int sumOdd = 0;

        int i = 1;

        while(cntEven <= n || cntOdd <= n){

            if(i % 2 == 0 && cntEven <= n){
                sumEven += i;
                cntEven++;
            }
            else if(i % 2 != 0 && cntOdd <= n){
                sumOdd += i;
                cntOdd++;
            }

            i++;
        }

        return ans(sumEven, sumOdd);
    }
};