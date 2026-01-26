class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        //1 2 3 4 
        int n=arr.size();
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]<mini){
                mini=arr[i]-arr[i-1];
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }
            else if(arr[i]-arr[i-1]==mini){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};