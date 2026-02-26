class Solution {
public:
string func(string s){
    int n=s.size();
    char carry='1';
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            if(carry=='1'){
                s[i]='0';
                carry='1';
            }
            else{
                s[i]='1';
                carry='0';
            }
        }
        else{
            if(carry=='1'){
                s[i]='1';
                carry='0';
            }
            else{
                s[i]='0';
                carry='0';
            }
        }
    }
    if(carry=='1'){
        s="1"+s;
    }
    return s;
}
    int numSteps(string s) {
        int count=0;
        while(s!="1"){
            if(s[s.size()-1]=='0'){
                s.pop_back();
            }else{
                s=func(s);
            }
        count++;
        }
        return count;
    }
};