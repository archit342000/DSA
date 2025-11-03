// https://leetcode.com/problems/string-to-integer-atoi/description/
// Difficulty: Medium
// Tags: Strings, Recursion

class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();

        int i=0;

        while(i<n && s[i]==' '){
            i++;
        }

        int sign = 1;

        if(s[i]=='+'){
            sign=1;
            i++;
        }
        else if(s[i]=='-'){
            sign=-1;
            i++;
        }

        int ans=0;

        while(i<n && s[i]>='0' && s[i]<='9'){
            int digit=s[i]-'0';

            if(sign==1 && ans>=(INT_MAX-digit)/10.0){
                return INT_MAX;
            }
            else if(sign==-1 && ans>(INT_MAX-digit)/10.0){
                return INT_MIN;
            }
            else{
                ans = ans*10+digit;
            }

            i++;
        }

        return sign*ans;
    }
};

class Solution {
public:
    void myAtoiUtil(string &s, int i, long &ans, int &sign, bool &flag){
        if(i==s.size()){
            return;
        }
        if(isdigit(s[i])){
            flag=true;
            ans=ans*10+(s[i]-'0');
            if(ans>INT_MAX && sign==1){
                return;
            }
            if(ans>INT_MAX && sign==-1){
                return;
            }
            return myAtoiUtil(s, i+1, ans, sign, flag);
        }
        else{
            if(!flag){
                if(s[i]==' '){
                    return myAtoiUtil(s, i+1, ans, sign, flag);
                }
                else if(s[i]=='+'){
                    flag=true;
                    sign=1;
                    return myAtoiUtil(s, i+1, ans, sign, flag);
                }
                else if(s[i]=='-'){
                    flag=true;
                    sign=-1;
                    return myAtoiUtil(s, i+1, ans, sign, flag);
                }
            }
            else{
                return;
            }
        }
    }
    int myAtoi(string s) {
        long ans=0;
        int sign=1;
        bool flag=false;

        myAtoiUtil(s, 0, ans, sign, flag);

        if(ans>INT_MAX && sign==-1){
            return INT_MIN;
        }
        if(ans>INT_MAX && sign==1){
            return INT_MAX;
        }
        return ans*sign;
    }
};