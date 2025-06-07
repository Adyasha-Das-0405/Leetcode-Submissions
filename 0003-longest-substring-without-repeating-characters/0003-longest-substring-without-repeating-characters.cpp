class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        unordered_map<char, int> seen;

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            if (seen.count(currentChar) && seen[currentChar] >= start) {
                start = seen[currentChar] + 1;
            }

            maxLen = max(maxLen, end - start + 1);
            seen[currentChar] = end; 
        }
        return maxLen;
    }
};
