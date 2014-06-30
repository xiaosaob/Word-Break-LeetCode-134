// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// For example, given
// s = "leetcode",
// dict = ["leet", "code"].

// Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        if(!n) return false;
        vector<bool> table(n+1, false);
        table[n] = true;
        for(int i = n-1; i >= 0; --i) {
            bool found = false;
            for(int j = i; j < n; ++j) {
                if(dict.count(s.substr(i,j-i+1)) && table[j+1]) {
                    found = true;
                    break;
                }
            }
            table[i] = found ? true : false;
        }
        return table[0];
    }
};
