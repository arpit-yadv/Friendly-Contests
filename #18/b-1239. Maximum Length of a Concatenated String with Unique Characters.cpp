class Solution {
public:
  //https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
    int ans = 0;
    
    bool isUnique(string s){
        vector<int>a(26,0);
        for(auto c: s){
            a[c-'a']++;
            if(a[c-'a']>1)return false;
        }
        return true;
    }
    
    void maxlen(vector<string>&a,int i,string s){
        if(i==a.size()){
            int p = s.length();
            ans = max(p,ans);
            return;            
        }
        if(isUnique(s+a[i]))
        maxlen(a,i+1,s+a[i]);
        maxlen(a,i+1,s);
    }
    
    int maxLength(vector<string>& a) {
        string temp = "";
        maxlen(a,0,temp);
        return ans;
    }
};