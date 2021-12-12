// ques_1 ----------------------------------------------------------------------------------------------------------

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


// ques_2 ----------------------------------------------------------------------------------------------------------

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

// ques_3 ----------------------------------------------------------------------------------------------------------

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

//ques_4 ----------------------------------------------------------------------------------------------------------

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class lcn{
public:
    int score;
    string name;
    lcn(int s=0,string n=""){
        this->score=s;
        this->name=n;
    }
    bool operator<(const lcn c)const{
        return this->score>c.score||(this->score==c.score && strcmp(this->name.c_str(),c.name.c_str())<0);
    }
};

class SORTracker {
private:
    tree<lcn,null_type,less<lcn>,rb_tree_tag,tree_order_statistics_node_update> locations;
    int gc;
public:
    SORTracker() {
        locations.clear();
        gc=0;
    }
    
    void add(string name, int score) {
        locations.insert(lcn(score,name));
    }
    
    string get() {
        return locations.find_by_order(gc++)->name;
    }
};
