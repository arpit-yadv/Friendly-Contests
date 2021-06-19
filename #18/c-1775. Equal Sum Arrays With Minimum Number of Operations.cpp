class Solution {
public:

   //https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        int l1 = nums1.size();
        int l2 = nums2.size();
        int a = min(l1,l2);
        int b = max(l1,l2);
        if(a*6<b*1)return -1;  
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int sum1=0,sum2=0;
        for(int i =0;i<l1;++i){
            sum1+=nums1[i];
        }
        for(int i =0;i<l2;++i){
            sum2+=nums2[i];
        }
        int ans = 0;
        int x = abs(sum1-sum2);
        int i =0,j = 0;
        if(x==0)return 0;
        if(sum1>sum2){
            i = l1-1,j=0;
            while(i>=0 && j<l2){
                if(nums1[i]-1>6-nums2[j]){
                    x-=nums1[i]-1;
                    i--;
                    ans++;
                }else{
                    x-=(6-nums2[j]);
                    j++;
                    ans++;
                }
                if(x<=0){
                    return ans;
                }
            }
            while(i>=0){
                x-=nums1[i]-1;
                i--;
                ans++;
                if(x<=0)return ans;
            }
            while(j<l2){
                x-=(6-nums2[j]);
                j++;
                ans++;
            }
        }else{
            i = 0,j = l2-1;
            while(i<l1 && j>=0){
                if((nums2[j]-1)>(6-nums1[i])){
                    x-=(nums2[j]-1);
                    ans++;
                    j--;
                }else{
                    x-=(6-nums1[i]);
                    i++;
                    ans++;
                }

                if(x<=0)return ans;
            }
            while(i<l1){
                x-=(6-nums1[i]);
                i++;
                ans++;
                if(x<=0)return ans;
            }
            while(j>=0){
                x-=(nums2[j]-1);
                    ans++;
                    j--;
                if(x<=0)return ans;
            }
        }
        
        return ans;
        
    }
};