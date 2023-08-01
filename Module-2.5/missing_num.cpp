class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s= nums.size();
        int r=s*(s+1)/2;
        int sum = 0;
        for(int i=0; i<s; i++)
        {
            sum+=nums[i];
        }
        return r-sum;
    }
};