class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;  
        unordered_set<string> seen;
        for (int i = 0; i <= s.size() - k; i++) {
            seen.insert(s.substr(i, k));
            if (seen.size() == (1 << k)) return true;
        }
        return false;
    }
};