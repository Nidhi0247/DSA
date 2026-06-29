class Solution {
public:
    bool check(vector<int>& arr) {
    arr[0] = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1] + 1) {
            arr[i] = arr[i - 1] + 1;
        }
    }
    return true;
}
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        check(arr);
        int large = arr[n-1];
        return large;
        
    }
};