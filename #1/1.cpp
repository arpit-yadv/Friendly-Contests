#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-continuous-increasing-subsequence


int findLengthOfLCIS(vector<int> &nums)
{
    int n = nums.size();
    if(nums.size()==0) return 0;
    int c = 1;
    for (int i = 1; i < n; i++)
    {
        int c1 = 1;
        while (nums[i] > nums[i - 1] && i < n)
        {
            c1++;
            i++;
            if(i>=n)break;
            
        }
        c = max(c1, c);
    }
    return c;
}