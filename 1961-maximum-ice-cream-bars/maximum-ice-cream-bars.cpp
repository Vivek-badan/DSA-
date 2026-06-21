class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int l=0;
        int cnt=0;
        while(coins>0 && l<costs.size()){
            if(costs[l]<=coins){
                coins-=costs[l];
                l++;
                cnt++;
            }
            else{
               break;
            }

        }
        return cnt;
    }
};