class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        // Create a boolean vector to mark prime numbers.
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes
        
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                // Mark multiples of `i` as non-prime.
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Count the number of primes.
        int primeCount = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) ++primeCount;
        }
        
        return primeCount;
    }
};
