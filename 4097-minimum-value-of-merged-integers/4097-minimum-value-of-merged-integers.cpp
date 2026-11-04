class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans= INT_MAX;
        
        for(int i=0;i<nums.size();i=i+2){
            string a= to_string(nums[i])+to_string(nums[i+1]);
            ans= min(ans,stoi(a));
        }
   return ans; }
};