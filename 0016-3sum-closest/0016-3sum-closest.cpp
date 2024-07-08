class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int ans=0; 
        int diff= INT_MAX;
        for (int i=0; i<n-2; i++){
            int start= i+1; int end= n-1;
            while (start<end){
                int sum = nums[i]+ nums[start]+ nums[end];
                if (sum> target){
                    end--;
                }
                else if (sum< target){
                    start++;
                }
                else return target;
                if (abs(target-sum) < diff){
                    diff= abs(target-sum);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};