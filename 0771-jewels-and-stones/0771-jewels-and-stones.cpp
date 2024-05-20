class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = stones.length();
        int m = jewels.length();
          int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(stones[i]==jewels[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};