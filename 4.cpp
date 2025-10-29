class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0;
        int high = m;
        
        int halfLen = (m + n + 1) / 2;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = halfLen - i;

            if (i > 0 && i <= m && j >= 0 && j <= n && nums1[i - 1] > nums2[j]) {
                high = i - 1; 
            }
            else if (j > 0 && j <= n && i >= 0 && i < m && nums2[j - 1] > nums1[i]) {
                low = i + 1;
            }
            else {
                int maxLeft;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
                }

                if ((m + n) % 2 != 0) {
                    return maxLeft;
                }

                int minRight;
                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = std::min(nums1[i], nums2[j]);
                }

                return (maxLeft + minRight) / 2.0;
            }
        }
        
        return 0.0; 
    }
};