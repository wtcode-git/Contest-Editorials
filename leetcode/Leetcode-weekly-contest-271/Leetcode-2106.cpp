class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int start, int k) {
        const int maxn = (int)2e5 + 5;
        vector<int> v(maxn, 0);
        for(auto pos:fruits){
            // pos[0] contains the position and pos[1] contains the number of fruits at pos[0]
            v[pos[0]] = pos[1];
        }
        // left vector to store the prefix sum(fruits) from i to start
        vector<int> left(maxn, 0);
        // right vector to store the prefix sum(fruits) from start to i
        vector<int> right(maxn, 0);
        // initially both at the start position consists v[start] apples
        left[start] = v[start];
        right[start] = v[start];
        // Calculate prefix sum for left and right vector respectively
        for(int i = start - 1; i >= 0; i--){
            left[i] = v[i] + left[i + 1];
        }
        for(int i = start + 1; i < maxn; i++){
            right[i] = right[i - 1] + v[i];
        }
        // Initialise ans as the number of apples at the start position, as we know that in the worst case, i may not be able to move at all, but i would be able to collect v[start] apples always
        int ans = v[start];
        for(int i = 0; i <= min(k, start); i++){
            // I have moved distance i to the left from start, so remaining distance to move to the right is k - 2 * i (because i have to return back to the starting position as well)
            int r = k - 2 * i;
            if(r < 0) continue;
            r = min(r, maxn - 1 - start);
            if(r + start < maxn)
            ans = max(ans, left[start - i] + right[start + r] - v[start]);
        }
        
        for(int i = 0; i <= min(k, maxn - 1 - start); i++){
            // I have moved distance i to the right from start, so remaining distance to move to the left is k - 2 * i (because i have to return back to the starting position as well)
            int l = k - 2 * i;
            if(l < 0) continue;
            l = min(l, start);
            if(start - l >= 0)
            ans = max(ans, left[start - l] + right[start + i] - v[start]);
        }
        return ans;
    }
};
