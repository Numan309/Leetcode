class Solution {
public:
    long long countSubstrings(string s, char c) {
       long long count = 0;
        for(char &ch : s) {
            if(ch == c) {
                count++;
            }
        }
           
        return count *(count-1)/2 + count;
    }
};
// Ex:  abada:-  3C2 = 3+3a = 3+3 = 6