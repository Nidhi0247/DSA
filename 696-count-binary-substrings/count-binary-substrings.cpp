class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>subs;
        int count =1;
        for(int i=1;i<s.size();i++ ){
            if(s[i]==s[i-1]) count+=1;
            else {
                subs.push_back(count);
                count=1;
               }
        }
        subs.push_back(count);
        int sum =0;
        for(int i =1;i<subs.size();i++){
            sum+=min(subs[i],subs[i-1]);
        }
        return sum;
    }
};