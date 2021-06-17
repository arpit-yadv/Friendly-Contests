#include<bits/stdc++.h>

using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr) {
    int n= arr.size();
    sort(arr.begin(),arr.end());
    if(arr.size()<=1)
        return true;
    int d= arr[1]-arr[0];
    for(int i =1;i<arr.size();i++){
        if(arr[i]-arr[i-1]!=d)
            return false;
    }
    return true;
}