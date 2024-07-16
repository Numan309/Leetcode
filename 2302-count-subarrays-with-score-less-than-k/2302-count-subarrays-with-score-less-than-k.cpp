class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
         int n = nums.size();

        long long sum = 0, score = 0;
        long long count = 0;

        int start = 0, end = 0;

        while(end < n){
            sum += nums[end];
            score = sum * (end-start+1);

            while(score>=k && start<=end){
                sum -= nums[start];
                start++;
                score = sum * (end-start+1);
            }

            count += (end-start+1);
            end++;
        }

        return count;

    }
};