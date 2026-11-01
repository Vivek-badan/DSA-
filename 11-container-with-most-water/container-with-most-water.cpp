class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxarea=0;
        while(l<r){
            int width=r-l;
            int minheight=min(height[l],height[r]);
            int area=minheight*width;
            maxarea=max(area,maxarea);
            if(height[l]<height[r]) {
                l++;
            }
            else{
                r--;
            }


        }
        return maxarea;
        
    }
};