class Solution {
public:
    int minMaxDifference(int num) {
        string n = to_string(num);
        char minnum = 'a', maxnum = 'a';

        for (char it : n) {
            if (it != '9' && maxnum == 'a') {
                maxnum = it;
            }
            if (it != '0' && minnum == 'a') {
                minnum = it;
            }
        }

        string minans = n, maxans = n;
        for (char &it : minans) {
            if (it == minnum) it = '0';
        }
        for (char &it : maxans) {
            if (it == maxnum) it = '9';
        }

        return stoi(maxans) - stoi(minans);
    }
};
