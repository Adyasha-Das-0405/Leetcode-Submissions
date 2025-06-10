class Solution {
public:
    bool checkInclusion(string target, string source) {
        if (target.length() > source.length()) {
            return false;
        }
        
        unordered_map<char, int> targetFreq;
        unordered_map<char, int> windowFreq;
        
        for (int i = 0; i < target.length(); i++) {
            targetFreq[target[i]]++;
            windowFreq[source[i]]++;
        }

        if (targetFreq == windowFreq) {
            return true;
        }
        int left = 0;
        for (int right = target.length(); right < source.length(); right++) {
            windowFreq[source[right]]++;      
            windowFreq[source[left]]--;

            if (windowFreq[source[left]] == 0) {
                windowFreq.erase(source[left]); 
            }

            left++;

            if (windowFreq == targetFreq) {
                return true;
            }
        }
        
        return false;        
    }
};
