class Solution {
public:
    int hammingWeight(int n) {
        int setBit = 0;
        while(n>0)
        {
            n = (n & (n-1));
                setBit++;
            
        }
        return setBit;
    }
};