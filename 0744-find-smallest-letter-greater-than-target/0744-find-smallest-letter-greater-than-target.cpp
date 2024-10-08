class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ind = upper_bound(begin(letters),end(letters),target)-begin(letters);
        
        if(ind==letters.size())
        {
            return letters[0];
        }
        return letters[ind];
    }
};