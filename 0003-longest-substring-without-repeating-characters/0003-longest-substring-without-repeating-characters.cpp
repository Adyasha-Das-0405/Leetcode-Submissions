class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxLen = 0;
        unordered_set<char> seenChars;

        for (int end = 0; end < s.length(); ++end) {
            while (seenChars.count(s[end])) {
                seenChars.erase(s[start]);
                ++start;
            }

            seenChars.insert(s[end]);
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
