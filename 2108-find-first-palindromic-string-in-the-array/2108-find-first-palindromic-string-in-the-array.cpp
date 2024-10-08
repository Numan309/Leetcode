class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
       for(auto &word:words)
       {
         string temp = word;
           reverse(temp.begin(),temp.end());
           if(temp==word)
               return word;
       }       
        return "";
    }
};