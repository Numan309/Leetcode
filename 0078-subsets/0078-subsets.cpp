#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
    #define pb push_back

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
		int subsets_cb = (1<<n);//1<<n means 2^n
		vvi subsets;
		for(int masks = 0;masks<subsets_cb;masks++){
			vi subset;
			for(int i=0;i<n;i++)
			{
				if((masks & (1<<i))!=0){
					subset.pb(nums[i]);
				}
			}
			subsets.pb(subset);
		}
		return subsets;
    }
};