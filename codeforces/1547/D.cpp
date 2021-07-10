#include<bits/stdc++.h>
using namespace std;
#define ll long long

int vis[100001];


int main(){
	
	
	int tt;
	cin>>tt;
	while(tt--){
		int t;
		cin>>t;
		ll n;
		ll k;
		ll r=0;
		for(int i=0;i<t;i++){
			n=k^r;
			cin>>k;
			if(i==0){
				cout<<"0 ";
				continue;
			}
			ll p=n;
			n |= n >> 1;
		    n |= n >> 2;
		    n |= n >> 4;
		    n |= n >> 8;
		    n |= n >> 16;
		    n=~n;
		    ll s=n|k;
		    s=~s;
		    ll y=s&p;
		    cout<<y<<" ";
		    r=y;
		}
		cout<<"\n";
	}

}