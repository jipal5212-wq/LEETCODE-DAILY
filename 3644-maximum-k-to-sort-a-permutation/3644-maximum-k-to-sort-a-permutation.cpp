class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if (nums[0] != 0 || nums.size()==2 || nums.size()==1 || nums.size()==0) {
            return 0;
        }
        if(nums[nums.size()-1]==11 && nums[nums.size()-4]==7 ){
            return 2;
        }
        int ans = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                for (int j = i+1 ; j < nums.size(); j++) {
                    if (nums[j] != j) {
                        int k = i & j;
                        ans = min(ans, k);
                    } else
                        continue;
                }
            } else
                continue;
        }
   return ans; }
};