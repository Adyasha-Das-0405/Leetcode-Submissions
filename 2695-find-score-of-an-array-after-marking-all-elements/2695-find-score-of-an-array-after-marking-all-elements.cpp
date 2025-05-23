class Solution {
public:
    static long long findScore(const vector<int> &nums) {
        const uint n = nums.size();
        uint64_t s = 0;
        for (uint j = 0; j < n; j += 2) {
            uint64_t odd = 0, even = 0;
            for (uint v = nums[j], w; j + 1u < n && nums[j] > (w = nums[j + 1u]); j++, v = w)
                (j & 1u ? odd : even) += v;
            s += (j & 1u ? odd : even) + nums[j];
        }
        return s;
    }
};