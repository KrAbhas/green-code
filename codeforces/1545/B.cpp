#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 100001;
const ll mod = 998244353;

ll fact[maxn];
ll inv[maxn];

ll power(ll a, ll m){
	ll res=1;
	while(m>0){
		if(m & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		m = m >> 1;
	}
	return res;
}


void comp(){
	int n;
	cin>>n;
	int a=0,b=0,c=0;
	int x;
	int t=0;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		x=s[i]-'0';
		//cout<<x<<" ";
		if(x==1){
			if(t==1){
				c++;
				t=0;
			}
			else t=1;
		}
		else if(t==1){
			b++;
		}
		if(x==0){
			a++;
			t=0;
		}
		//cout<<(a+b+c)<<" ";
	}
	b=0;
	ll ans = ((fact[a + c] * inv[a])% mod * inv[c]) %mod;
	printf("%d\n", (int) ans);
}


int main(){

	fact[0] = 1;
	inv[0] = 1;

	for(int i=1;i<maxn;i++){
		fact[i]=i;
		fact[i] = (fact[i] * fact[i-1])%mod;
		inv[i] = power(fact[i], mod-2);
		//cout<<inv[i]<<endl;
	}
	int tt;
	cin>> tt;
	while(tt--) {
		comp();
	}
}