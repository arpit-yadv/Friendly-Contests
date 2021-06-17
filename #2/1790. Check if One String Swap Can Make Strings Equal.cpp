#include<bits/stdc++.h>

using namespace std;

bool areAlmostEqual(string s1, string s2) {
    int c=0;
    unordered_set<int> uset[2];
    for(int i=0;i<s1.length();i++){
        uset[0].insert(s1[i]);
        uset[1].insert(s2[i]);
    }
    if(uset[0]!=uset[1])
        return false;
    for(int i = 0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            c++;
        }
    }
    if(c<=2){
        return true;
    }
    return false;
}
   