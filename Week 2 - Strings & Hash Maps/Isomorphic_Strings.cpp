class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m)
            return false;

        unordered_map<char, char> hashMap;
        unordered_set<char> taken;

        for(int i=0; i<n; i++) {
            if(hashMap.find(s[i]) != hashMap.end()) {
                s[i] = hashMap[s[i]];
                if(s[i] != t[i])
                    return false;
                continue;
            }

            if(taken.find(t[i]) != taken.end())
                return false;

            hashMap[s[i]] = t[i];
            s[i] = t[i];
            taken.insert(t[i]);
        }

        return true;
    }
};
