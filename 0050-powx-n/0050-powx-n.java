class Solution {
    public double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        double result = 1.0;
        long power = n; 
        
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        
        while (power > 0) {
            if (power % 2 == 1) {
                result *= x;
            }
            x *= x;
            power /= 2;
        }
        
        return result;
    }
}
