class Solution {
public:
    int maxDistance(vector<int>& color) {
        int ans = 0 ;
        int n =color.size();
        for(int j=color.size() -1;j>0;j--){
            if(color[j]!= color[0]) ans= max(ans,j);
            
        }for(int i =0;i<color.size();i++){
            if(color[i]!=color[n-1]) ans = max(ans,n-1-i);
        }

        return ans;

    }
};