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
