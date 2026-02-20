class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int>ans;
        int key =0;
        for(int i=n;i>0;i/=2){
            key= i%2;
            ans.push_back(key);
        }
       // ans.push_back(0);
        for(int i =0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]){ return false;}
        }
        return true;
    }
};