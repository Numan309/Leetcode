class Solution {
public:
    bool isVowel(char &ch)
    {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int vowel = 0,consonent = 0;
            for(int j=i;j<n;j++)
            {
                if(isVowel(s[j]))
                {
                    vowel++;
                }else{
                    consonent++;
                }
                if(consonent==vowel && (consonent*vowel)%k==0)
                {
                    res+=1;
                }
            }
        }
        return res;
    }
};