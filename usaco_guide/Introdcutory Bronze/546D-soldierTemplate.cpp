// Source: https://usaco.guide/general/io
/* A simple idea would be to calculate n = a!/b! and dividing it by its smallest prime factor and storing the same in n in a loop and use a counter to calculate steps but since a and b is of range 5e6 its not possible to find a! and b! */
/*
Instead while iterating through each numbers within the range of a to b we can calculate the count and print outside the loop but for multiple queries it won't work where there are test cases 1e6
*/
/*
So we can instead store our solution or count of every numbers and then get the prefix sum array of it and after that we can get our result in constant time by doing fre[a] - fre[b] where a is having count from 1...b...a and b is having sum from 1...b so subtracting actually gives correct result
*/
// time complexity will be O(NloglogN) + 2 * O(500000){which is O(1) asymptotically} + O(T)
// space complexity will be 2*O(N) for creating two static arrays
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5000001;
ll spf[N],fre[N];
void create()
{
	for(int i=2; i<=N; i++)
	{
		spf[i]=i;
	}
	for(int i=2; i*i<=N; i++)
	{
		if(spf[i]==i) {
			for(int j=i*i; j<=N; j+=i)
			{
				if(spf[j]==j) {
					spf[j]=i;
				}
			}
		}
	}
	for(ll i=1; i<=5000001; i++)
	{
		int temp=i,cnt=0;
		while(i!=1) {
			i/=spf[i];
			cnt++;
		}
		fre[temp] = cnt;
		i=temp;
	}
	for(int i=2 ; i<=5000001; i++)
	{
		fre[i] = fre[i]+fre[i-1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	create();

	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,cnt=0;
		cin>>a>>b;
		cout << fre[a] - fre[b];
		if(t>=1) cout << "\n";
	}
}