class Solution {
public:

    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        int curr=1;
        for(int i=1;i<=n;i++){
            ans.push_back(curr);
            if(curr*10<=n){
                curr*=10;
            }
            else{
                while(curr%10==9 || curr>=n){
                    curr/=10;
                }
                curr+=1;
            }
        }
        

        return ans;
    }
};
//https://leetcode.com/problems/lexicographical-numbers/solutions/5813956/interviewers-expect-iterative-approach-lets-understand