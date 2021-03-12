#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/group-anagrams

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> ans;
    unordered_map<int,int> uset[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<strs[i].length();j++){
            uset[i][strs[i][j]]++;
        }
    }
    for(int i=0;i<n;i++){
        if(uset[i].find(-1)!=uset[i].end()) continue;
        vector<string> s={strs[i]};
        for(int j=i;j<n;j++){
            if(i==j) continue;
            if(uset[i].find(-1)==uset[i].end()){
                
                if(uset[i]==uset[j]){
                    s.push_back(strs[j]);
                    uset[j][-1]++;
                }
            }
        }
        ans.push_back(s);
    }
    return ans;
        
} 

