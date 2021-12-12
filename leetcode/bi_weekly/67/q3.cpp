#define sqr(x) (x)*1LL*(x)

class Solution {
private:
    bool trigger(vector<int>&b1,vector<int>&b2){
        return sqr(b1[0]-b2[0])+sqr(b1[1]-b2[1])<=sqr(b1[2]);
    }
    int solve(vector<vector<int>>&edges,int s){
        int n=edges.size();
        int ans=1;
        vector<bool> vis(n,false);
        vis[s]=true;
        list<int> qqq;
        qqq.push_back(s);
        while(!qqq.empty()){
            s=qqq.front();
            qqq.pop_front();
            for(int b:edges[s])
                if(!vis[b]){
                    vis[b]=true;
                    qqq.push_back(b);
                    ans++;
                }
        }
        return ans;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> triggers(n,vector<int>(0));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j&&trigger(bombs[i],bombs[j]))
                    triggers[i].push_back(j);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,solve(triggers,i));
        return ans;
    }
};
