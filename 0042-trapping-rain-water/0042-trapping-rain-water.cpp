class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int trapped = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                trapped += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                trapped += rightMax - height[right];
            }
        }

        return trapped;        
    }
};