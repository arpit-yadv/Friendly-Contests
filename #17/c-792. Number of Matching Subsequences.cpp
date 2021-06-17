class Solution {
public:

//https://leetcode.com/problems/number-of-matching-subsequences/

    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> a(26,vector<int>(0));
        int n = s.length();
        for(int i =0;i<n;++i){
            a[s[i]-'a'].push_back(i);
        }
        int ans = 0;
        
        for(auto word : words){
            int x = -1;
            bool found = true;
            for(auto c: word){
                auto it = upper_bound(a[c-'a'].begin(),a[c-'a'].end(),x);
                if(it==a[c-'a'].end())found = false;
                else x = *it;
            }
            if(found)ans++;
        }
        return ans;
    }
};