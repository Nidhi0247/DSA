class Solution {
public:
    int reverseNum(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // reversed value -> index
        int ans = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            // check: reverse(nums[i]) == nums[j]
            if (mp.count(nums[j])) {
                ans = min(ans, j - mp[nums[j]]);
            }

            // store reverse(nums[j]) for future
            int rev = reverseNum(nums[j]);
            mp[rev] = j;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
