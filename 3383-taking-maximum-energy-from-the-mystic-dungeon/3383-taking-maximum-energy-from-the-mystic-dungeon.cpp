class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
    int maxEnergy = INT_MIN;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // If jump is valid, add the energy of the magician k steps ahead
        if (i + k < n) {
            energy[i] += energy[i + k];
        }

        // Keep track of the maximum energy possible
        maxEnergy = max(maxEnergy, energy[i]);
    }

    return maxEnergy;
    }
};