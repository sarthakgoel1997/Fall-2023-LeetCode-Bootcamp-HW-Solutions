class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0 , j = 0, ans = 1;
        if(n == 0)
            return 0;

        map<char, int> m;
        m[s[i]]++;

        while(j < n) {
            j++;

            if(j >= n)
                break;

            m[s[j]]++;

            while(m[s[j]] > 1) {
                m[s[i]]--;
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};
