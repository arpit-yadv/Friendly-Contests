class Solution {
public:

//https://leetcode.com/problems/thousand-separator/
    string thousandSeparator(int n) {
        string ans = "";
        int c = 0;
        if(n==0)return "0";
        while(n){
            int temp = n%10;
            char temp1 = '0'+temp;
            ans+=temp1;
            n = n/10;
            c++;
            if(c%3==0 && n)ans+='.';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};