class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0, currentSum = 0, start = 0, k = 10001; 
        vector<bool> isPresent(k, false);

        for (int end = 0; end < nums.size(); end++) {

            while (isPresent[nums[end]]) {
                isPresent[nums[start]] = false;
                currentSum -= nums[start];
                start++;
            }

            isPresent[nums[end]] = true; 
            currentSum += nums[end];

            result = max(result, currentSum); 
        }

        return result; 
    }
};