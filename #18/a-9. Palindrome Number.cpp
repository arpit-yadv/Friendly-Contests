class Solution {
public:
  //https://leetcode.com/problems/palindrome-number/
    bool isPalindrome(int x) {
        string s = "";
        if(x<0)return false;
        while(x){
            int temp1 = x%10;
            char temp = (char)temp1+'0';
            x = x/10;
            s+=temp;
        }
        string p = s;
        reverse(s.begin(),s.end());
        if(s==p)return true;
        return false;
    }
};