class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>t1;
        for(int i= 0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                if(!s1.empty())
                    s1.pop();
            }else{
                s1.push(s[i]);
            }
           
        }
        for(int j=0;j<t.size();j++)
        {
            if(t[j]=='#'){
                if(!t1.empty())
                    t1.pop();
            }else{
                t1.push(t[j]);
            }
        }
        return s1 == t1;
    }
};