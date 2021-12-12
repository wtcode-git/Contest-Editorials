class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        for(int i = 0; i < n; i++){
            long long int mx = INT_MIN, mn = INT_MAX;
            for(int j = i; j < n; j++){
                mx = max(mx, (long long)nums[j]);
                mn = min(mn, (long long)nums[j]);
                ans += mx - mn;
            }
        }
        return ans;
    }
};
