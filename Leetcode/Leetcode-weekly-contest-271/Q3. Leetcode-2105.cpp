class Solution {
public:
    int minimumRefill(vector<int>& v, int capacityA, int capacityB) {
            
        int n = v.size();
        // i signifies the position of alice, j signifies the position of bob
        int i = 0, j = n - 1;
        int ans = 0; // Number of times refill is required
        int alice = capacityA, bob = capacityB;
        
        while(i < j){
            if(v[i] > alice){
                alice = capacityA;
                ans++;
                alice -= v[i];
            }
            else {
                alice -= v[i];
            }
            
            if(v[j] > bob){
                bob = capacityB;
                ans++;
                bob -= v[j];
            }
            else {
                bob -= v[j];
            }
            
            i++;
            j--;
        }
        if(i == j){
            if(alice == bob){
                if(alice < v[i]) ans++;
            }
            else if(max(alice, bob) < v[i]) ans++;
        }
        return ans;
    }
};
