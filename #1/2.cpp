#include<bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/perfect-number/

bool checkPerfectNumber(int num) {
    int divisors=0;
    for(int i =1;i<=num/2;i++){
        if(num%i==0){
            divisors+=i;            
        }
    }
    cout<<divisors<<endl;
    if(divisors==num) return true;
    return false;
}