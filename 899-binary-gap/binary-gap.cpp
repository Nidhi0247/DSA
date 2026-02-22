class Solution {
public:
    int binaryGap(int n) {
        vector<int>ans;
        int key;
        for (int i =n ;i>0;i/=2){
            key = i%2;
            ans.push_back(key);
        }
        int output=0;

        for(int i =0;i<ans.size();i++){
            if(ans[i]==1){
                for(int j=i+1;j<ans.size(); j++){
                    if(ans[j]==1){
                        output = max(output,j-i);
                        break;
                    }
                }
            }
        }
        return output;
    }
};