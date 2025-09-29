class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int left = m - 1;
        int right = 0;
        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        nums1.resize(m + n);

        int j = 0;
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[j++];
           
        }
        int arr=nums1.size();
        double ans;

    if (arr % 2 == 0) {
        ans = (nums1[arr/2] + nums1[arr/2 - 1]) / 2.0; 
    } else {
        ans = double(nums1[arr/2]); 
    }

    return ans;
        
    }
};