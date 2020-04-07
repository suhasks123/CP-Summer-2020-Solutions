class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        /*for(i=0;i<=k;i++)
        {
            if(ans[i]>max)
            {
                max = ans[i];
            }
        }*/

        int m = *max_element(nums.begin(), nums.begin()+k);
        ans.push_back(m);
        int i;
        for(i=1;i<=n-k;i++)
        {
            if(nums[i-1]==m)
            {
                m = *max_element(nums.begin()+i, nums.begin()+i+k);
                ans.push_back(m);
                continue;
            }

            else if(nums[i+k-1]>m)
            {
                m=nums[i+k-1];
                ans.push_back(m);
                continue;
            }
            ans.push_back(m);
        }
        return ans;
    }
};
