class Solution {
public:
    string orderlyQueue(string s, int k) {
      
        // if k>1 we simply sort and return 
        if(k>1){
            sort(s.begin(),s.end());
        return s;
        }
        string res = s;
          int n = s.length();
        for(int i=1;i<=n-1;i++)
        {
            string temp = s.substr(i)+s.substr(0,i);
            res = min(res,temp);
        }
        return res;
    }
};