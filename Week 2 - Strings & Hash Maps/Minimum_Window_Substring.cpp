class Solution {
public:
    bool patternExists(unordered_map<char, int> &root, unordered_map<char, int> &pattern) {
        for(auto it = pattern.begin(); it != pattern.end(); it++) {
            if(it->second > root[it->first])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(m > n)
            return "";

        unordered_map<char, int> root, pattern;
        for(int i=0; i<m; i++)
            pattern[t[i]]++;
        

        int ansLen=INT_MAX, ansLow=-1, i=0, j=0;

        while(j < n) {
            root[s[j]]++;

            while(patternExists(root, pattern)) {
                if(ansLen > j-i+1) {
                    ansLen = j-i+1;
                    ansLow = i;
                }

                root[s[i]]--;
                i++;
            }

            j++;
        }

        if(ansLow == -1)
            return "";
        
        string ans;
        for(int k = ansLow; k < ansLow+ansLen; k++)
            ans += s[k];

        return ans;
    }
};
