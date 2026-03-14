class Solution {
public:
    void generateHappyStrings(string &current, vector<string> &result, int n) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                current.push_back(ch);
                generateHappyStrings(current, result, n);
                current.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> result;
        string current = "";
        generateHappyStrings(current, result, n);
        return k <= result.size() ? result[k - 1] : "";
    }
};