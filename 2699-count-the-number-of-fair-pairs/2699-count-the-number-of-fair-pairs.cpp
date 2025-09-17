class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }

private:
    long long countPairs(const vector<int>& nums, long long limit) {
        long long res = 0;
        int n = nums.size(), j = n - 1;
        for (int i = 0; i < n; ++i) {
            while (j > i && (long long)nums[i] + nums[j] > limit) --j;
            res += max(0, j - i);
        }
        return res;
    }
};