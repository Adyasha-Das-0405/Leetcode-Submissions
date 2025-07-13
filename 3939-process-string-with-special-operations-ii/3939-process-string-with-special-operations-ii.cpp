class Solution {
public:
    struct Step {
        char op;
        char ch;
        long long length;
    };

    char processStr(string s, long long k) {
        vector<Step> history;
        long long len = 0;

        for (char c : s) {
            if (islower(c)) {
                ++len;
                history.push_back({'a', c, len});
            } else if (c == '*') {
                if (len > 0) {
                    --len;
                    history.push_back({'*', 0, len});
                }
            } else if (c == '%') {
                history.push_back({'%', 0, len});
            } else if (c == '#') {
                len *= 2;
                if (len > 1e15) len = 1e15 + 1;  // Cap to prevent overflow
                history.push_back({'#', 0, len});
            }
        }

        if (k >= len) return '.';

        for (int i = history.size() - 1; i >= 0; --i) {
            auto [op, ch, currLen] = history[i];

            if (op == 'a') {
                if (k == currLen - 1) return ch;
                // else: do nothing
            } else if (op == '#') {
                long long half = currLen / 2;
                if (k >= half) k -= half;
            } else if (op == '%') {
                k = currLen - 1 - k;
            } else if (op == '*') {
                // deletion, we can't trace this part, just continue
                // doesn't affect k directly
            }
        }

        return '.';
    }
};
