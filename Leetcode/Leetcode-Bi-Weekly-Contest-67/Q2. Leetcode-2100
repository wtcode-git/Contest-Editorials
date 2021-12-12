class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<pair<int,int>> inc_dec(n);
        int c1=0,c2=0;
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1])c1++;
            else c1=0;
            if(security[n-i-1]<=security[n-i])c2++;
            else c2=0;
            inc_dec[i].first=c1;
            inc_dec[n-i-1].second=c2;
        }
        vector<int> ans(0);
        for(int i=0;i<n;i++)
            if(inc_dec[i].first>=time && inc_dec[i].second>=time)
                ans.push_back(i);
        return ans;
    }
};
