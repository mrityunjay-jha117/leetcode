// brute force
// class Solution {
// public:
//     bool valid(string & current) {
//     stack<char> st;
//     for (int i = 0; i < current.size(); i++) {
//         if (current[i] == '(') {
//             st.push('(');
//         } else if (current[i] == ')') {
//             if (st.empty()) return false; 
//             st.pop();
//         }
//     }
    
//     return (st.empty())?true:false; 
// }
//     void parenthesis(int n, string& current,
//                      vector<string>& ans) {
//         if (current.size() == 2 * n) {
//             if (valid(current)) {
//                 ans.push_back(current);
//             }
//                 return;
//         }
//         current+="(";
//         parenthesis(n, current, ans);
//         current.pop_back();
//         current+=')';
//         parenthesis(n, current, ans);
//         current.pop_back();
//     }
//     vector<string> generateParenthesis(int n) {
//         string current="";
//         vector<string> ans;
//         parenthesis(n, current, ans);
//         return ans;
//     }
// };
// optimal with pruning
class Solution {
public:
    vector<string> ans;
// unoptimised valid function
    // bool valid(string & current) {
    // stack<char> st;
    // for (int i = 0; i < current.size(); i++) {
    //     if (current[i] == '(') {
    //         st.push('(');
    //     } else if (current[i] == ')') {
    //         if (st.empty()) return false; 
    //         st.pop();
    //     }
    // }
    // return (st.empty())?true:false; 
// }
//optimied valid function
    bool valid(string & current){
        int count=0;
        for(auto &it:current){
            if(it=='('){
                count++;
            }else{
                count--;
            }
        }
        return !count;
    }
    
    void parenthesis(int n, string& current,
                     int i,int j) {
        if(j>i){
            return;
        }
        if (current.size() == 2 * n) {
            if (valid(current)) {
                ans.push_back(current);
            }
                return;
        }
        
        current+="(";
        parenthesis(n, current, i+1,j);
        current.pop_back();
        current+=')';
        parenthesis(n, current,i,j+1);
        current.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string current="";
        parenthesis(n, current,0,0);
        return ans;
    }
};