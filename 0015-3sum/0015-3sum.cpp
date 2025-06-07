class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplets; // to avoid duplicates
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            unordered_set<int> seen;
            for (int j = i + 1; j < n; ++j) {
                int third = -nums[i] - nums[j];
                if (seen.count(third)) {
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(triplet.begin(), triplet.end()); // sort before inserting to set
                    triplets.insert(triplet);
                }
                seen.insert(nums[j]);
            }
        }

        // Convert set to vector
        vector<vector<int>> result(triplets.begin(), triplets.end());
        return result;
    }
};
