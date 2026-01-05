class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int count =0;
        long long sum =0;
        long long mina = LLONG_MAX;
        for(int i=0;i<n;i++){
            for(int j= 0; j<n;j++){
                mina= min(mina,(long long)abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    count++;
                }
            }
        }
        if(count%2==0){
            return sum;
        }
        else{
            return sum - 2*mina;
        }
    }
};