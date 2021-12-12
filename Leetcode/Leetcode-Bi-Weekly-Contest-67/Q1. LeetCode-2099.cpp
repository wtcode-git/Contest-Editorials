class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> val_ind(0);
        for(int i=0;i<n;i++)
            val_ind.push_back(make_pair(nums[i],i));
        sort(val_ind.begin(),val_ind.end());
        set<int> inds;
        while(k--){
            inds.insert(val_ind.back().second);
            val_ind.pop_back();
        }
        vector<int> ans(0);
        for(int ind:inds)
            ans.push_back(nums[ind]);
        return ans;
    }
};
