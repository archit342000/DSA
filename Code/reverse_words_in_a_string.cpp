// https://leetcode.com/problems/reverse-words-in-a-string/description/
// Difficulty: Medium
// Tags: Strings

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word; 
        vector<string> words;
        string ans;

        while(ss>>word){
            words.push_back(word);
        }

        for(int i=words.size()-1; i>=0; i--){
            ans += words[i];
            if(i!=0){
                ans += " ";
            }
        }

        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for(char ch: s){
            if(ch==' '){
                if(word != ""){
                    if(ans!=""){
                        ans = word + " " + ans;
                    }
                    else{
                        ans = word;
                    }
                    word = "";
                }
            }
            else{
                word += ch;
            }
        }

        if(word != ""){
            if(ans!=""){
                ans = word + " " + ans;
            }
            else{
                ans = word;
            }
        }

        return ans;
    }
};