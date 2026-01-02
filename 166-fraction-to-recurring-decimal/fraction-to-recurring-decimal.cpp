class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result;
        if ((numerator < 0) ^ (denominator < 0)) result.push_back('-');
        long num = labs(numerator), den = labs(denominator);
        string intPart;
        if (num / den == 0) intPart.push_back('0');
        else {
            long val = num / den;
            string temp;
            while (val) { temp.push_back('0' + val % 10); val /= 10; }
            reverse(temp.begin(), temp.end());
            intPart += temp;
        }
        result += intPart;

        long rem = num % den;
        if (rem == 0) return result;

        result.push_back('.');
        unordered_map<long, int> seen;

        while (rem) {
            if (seen.count(rem)) {
                result.insert(seen[rem], "(");
                result.push_back(')');
                break;
            }
            seen[rem] = result.size();
            rem *= 10;
            result.push_back('0' + (rem / den));
            rem %= den;
        }
        return result;
    }
};