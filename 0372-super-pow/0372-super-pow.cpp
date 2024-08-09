class Solution {
public:
        const int h = 1140;
    int binExpIter(int a,long long b,int M)
	{
		int ans = 1;
		while(b>0)
		{
			if(b&1)
			{
				//ans = ans*a;//if answer if modulo
				ans = (ans*1LL*a)%M;
			}
			//a = a*a;
			a = (a*1LL*a)%M;
			b = b>>1;
		}
		return ans;
	}
    int superPow(int a, vector<int>& b) {
         int ans = 0;
int n = b.size();
for(int i = n-1; i >=0; i--){

ans = (ans+(b[i]*binExpIter(10,n-i-1,h))%h);

}
return binExpIter(a, ans,1337);
    }
};