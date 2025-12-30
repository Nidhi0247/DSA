class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int maxarea = 0;
        int j = n-1;
        int minheight= height[0];
        int i = 0 ;
         while (i < j) {
            int minheight = min(height[i], height[j]);
            int area = (j - i) * minheight;
            maxarea = max(maxarea, area);

            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
};