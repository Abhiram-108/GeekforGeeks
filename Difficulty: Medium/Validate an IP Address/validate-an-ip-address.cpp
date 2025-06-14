class Solution {
public:
    int isValid(string& s) {
        int n = s.size();
        int count = 0;
        string segment = "";

        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == '.') {
                if (segment.empty()) return 0;

                // check if all characters are digits
                for (char c : segment) {
                    if (!isdigit(c)) return 0;
                }

                // convert to int and check range
                int num = stoi(segment);
                if (num < 0 || num > 255) return 0;

                // check for leading zeros
                if (segment.size() > 1 && segment[0] == '0') return 0;

                count++;
                segment = "";
            } else {
                segment += s[i];
            }
        }

        return count == 4 ? 1 : 0;
    }
};
