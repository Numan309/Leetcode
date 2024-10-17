class Solution {
public:
    bool areNumbersAscending(string s) {
       stringstream str(s); 
        vector<int>v;
        string word;
        while(str >> word)
        {
            if(word[0]>='0' and word[0]<='9')
            {
                int t=stoi(word);
                v.push_back(t);
            }
        }
        for(int i=0; i<v.size()-1; i++)
        {
            if(v[i]>=v[i+1])
                return false;
        }
        
        return true;
    }
};