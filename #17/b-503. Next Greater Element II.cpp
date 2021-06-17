class Solution {
public:
//https://leetcode.com/problems/next-greater-element-ii/
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> q;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i =n-1;i>=0;--i){
            q.push(nums[i]);
        }
        for(int i = n-1;i>=0;--i){
            ans[i]=-1;
            while(!q.empty() && q.top()<=nums[i]){
                    if(!q.empty()){

                        q.pop();
                    }
                        
            }
            if(!q.empty())
                ans[i]=q.top();
            q.push(nums[i]);
        }
        return ans;
    }
};