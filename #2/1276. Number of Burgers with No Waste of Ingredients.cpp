#include<bits/stdc++.h>
using namespace std;

vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    vector<int> ans;
    ans.clear();
    if(tomatoSlices%2==0 && tomatoSlices>=2*cheeseSlices && tomatoSlices<=4*cheeseSlices){

        int small = (4*cheeseSlices-tomatoSlices)/2;
        int jumbo = cheeseSlices-small;
        cout<<small;
        ans.push_back(jumbo);
        ans.push_back(small);
    }
    return ans;
}    
    