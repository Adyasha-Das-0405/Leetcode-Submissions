class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
    vector<int> dp(n, 0);
    int maxEnergy = INT_MIN;

    // Fill dp from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Base energy from current magician
        dp[i] = energy[i];

        // If we can jump k steps ahead, add that energy
        if (i + k < n) dp[i] += dp[i + k];

        // Track the maximum so far
        maxEnergy = max(maxEnergy, dp[i]);
    }

    return maxEnergy;
    }
};