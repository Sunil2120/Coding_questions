    
    int kth_smallest(vector<int>& nums1,vector<int>& nums2,int n,int m,int k)
    {
        if(k > (n+m))
        {
            return -1;
        }
        if(n==0)
        {
            return nums2[k-1];
        }
        else if(m==0)
        {
            return nums1[k-1];
        }
        if(m < n)
        {
            return kth_smallest(nums2,nums1,m,n,k);
        }
        int low = max(0,k-m);
        int high = min(k,n);
        while(low<=high)
        {
            int cut1 = (low+high)>>1;
            int cut2 = (k-cut1);
            int l1 = cut1==0?INT_MIN:nums1[cut1-1];
            int l2 = cut2==0?INT_MIN:nums2[cut2-1];
            int r1 = cut1==n?INT_MAX:nums1[cut1];
            int r2 = cut2==m?INT_MAX:nums2[cut2];
            if(l1 <= r2 && l2 <= r1)
            {
                return max(l1,l2);
            }
            if(l1 > r2)
            {
                high = cut1-1;
            }
            else
            {
                low = cut1+1;
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int first = kth_smallest(nums1,nums2,n,m,(n+m)/2 + 1);
        if((n+m)%2!=0)
        {
            return (double)first;
        }
        int second = kth_smallest(nums1,nums2,n,m,(n+m)/2);
        return (double)(first+second)/2.0;
        
    }