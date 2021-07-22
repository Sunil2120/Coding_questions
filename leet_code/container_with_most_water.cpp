 int maxArea(vector<int>& height) {
        int max_area = INT_MIN;
        int i=0;
        int n = height.size();
        int j = n-1;
        while(i<=j)
        {
            int area = (j-i)*min(height[i],height[j]);
            max_area = max(max_area,area);
            if(height[i] <  height[j])
            {
                i+=1;
            }
            else
            {
                j-=1;
            }
        }
        return max_area;
        
    }