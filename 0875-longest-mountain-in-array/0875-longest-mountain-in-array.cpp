#include <vector>
#include <algorithm> // for std::max

class Solution {
public:
    int longestMountain(std::vector<int>& arr) {
        if (arr.size() < 3) {
            return 0;
        }
        int longest = 0;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {  // peak of mountain
                int left = i;
                int right = i;

                // move left while strictly increasing
                while (left > 0 && arr[left - 1] < arr[left]) {
                    left--;
                }

                // move right while strictly decreasing
                while (right < arr.size() - 1 && arr[right + 1] < arr[right]) {
                    right++;
                }

                longest = std::max(longest, right - left + 1);
                // skip the elements we've already considered
                i = right;
            }
        }
        return longest;
    }
};
