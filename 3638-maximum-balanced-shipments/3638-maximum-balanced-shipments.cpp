class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int ans=0;
        vector<int>st;
        st.push_back(INT_MIN);
        for(auto &it:weight){
            if(st.back()<=it){
                st.push_back(it);
            }
            else{
                ans++;
                st.resize(1);
                st[0]=INT_MIN;
            }
        }
        return ans;
    }
};