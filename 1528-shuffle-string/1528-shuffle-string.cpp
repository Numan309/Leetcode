class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string s2=s;
       for(int i=0; i<indices.size(); i++) {
           s2[indices[i]]=s[i];

       } 
       return s2;
    }
};