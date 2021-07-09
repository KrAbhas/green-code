#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll lcm(ll a, ll b){
	return a*b/__gcd(a,b);
}
int main(){


	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int mod=1e9+7;
	long long tt;
	ll arr[50];
	arr[1]=1;
	for(ll i=2;i<50;i++){
		arr[i]=lcm(arr[i-1],i);
	}
	cin>>tt;
	while(tt--){
		ll n;
		cin>>n;
		ll s=0;
		for(int i=2;i<50;i++){
			s+=(i*(n/arr[i-1]-n/arr[i]));
			s=s%mod;
		}
		cout<<s<<"\n";
	}
}