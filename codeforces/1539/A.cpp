#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--){
		ll n;
		cin>>n;
		ll x;
		ll t;
		cin>>x>>t;
		ll s=0;
		ll p=t/x;
		s=max(s,n-p)*p + min(p,n)*min(n-1,p-1)/2;
		cout<<s<<"\n";
	}
}