#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod=998244353;

void add(ll& a, ll b){
	a=(a+b)%mod;
}

int main(){


	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int n;
	cin>>n;
	int arr[n];
	char c;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c=='+')
			cin>>arr[i];
		else arr[i]=-1;
	}
	ll s=0;
	ll dp[n+1][n+1];
	for(int t=0;t<n;t++){
		if(arr[t]==-1)
			continue;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<n;i++){
			if(i==t){
				for(int j=0;j<n;j++){
					add(dp[i+1][j],dp[i][j]);
				}
				continue;
			}
			for(int j=0;j<n;j++){
				add(dp[i+1][j],dp[i][j]);
				if(arr[i]!=-1){
					if(arr[i]<arr[t] || (arr[i]==arr[t] && i<t)){
						add(dp[i+1][min(j+1,n)],dp[i][j]);
					}

					else{
						add(dp[i+1][j],dp[i][j]);
					}
				}
				else{
					if(i<t){
						add(dp[i+1][max(j-1,0)],dp[i][j]);
					}
					else if(j>0){
						add(dp[i+1][j-1],dp[i+1][j]);
					}
				}
			}
		}
		for(int i=0;i<n+1;i++){
			//cout<<s<<endl;
			add(s,(arr[t]*dp[n][i]));
		}
	}
	cout<<s<<endl;
}