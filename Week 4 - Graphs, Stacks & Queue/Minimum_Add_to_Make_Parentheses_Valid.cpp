class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> ch;
        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                ch.push(s[i]);
                ans++;
            } else {
                if(!ch.empty() && ch.top() == '(') {
                    ch.pop();
                    ans--;
                } else {
                    ch.push(s[i]);
                    ans++;
                }
            }
        }

        return ans;
    }
};