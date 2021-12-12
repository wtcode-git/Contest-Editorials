class Solution {
public:
    int countPoints(string s) {
        // The number of rods are 10
        vector<set<char>> v(10);
        // ith rod, ith vector will contain the distinct color of rings
        int n = s.length();
        for(int i = 0; i < n; i += 2){
            v[s[i + 1] - '0'].insert(s[i]);
        }
        int ans = 0;
        for(int i = 0; i < 10; i++){
            if(v[i].size() == 3) ans++;
        }
        return ans;
    }
};
