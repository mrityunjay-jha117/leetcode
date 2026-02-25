class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>>mp(32);
        for(auto &it:arr)
            mp[__builtin_popcount(it)].push_back(it);
        vector<int>ans;
        for(auto &it:mp){
            sort(it.begin(),it.end());
            ans.insert(ans.end(),it.begin(),it.end());
        }
        return ans;
        
    }
};