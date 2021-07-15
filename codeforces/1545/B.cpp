#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 100010;
const int MOD = 998244353;
char str[MAXN];
long long F[MAXN], rF[MAXN];
long long inv(long long a, long long m) {
	if (a == 1) return 1;
	return inv(m%a, m) * (m - m/a) % m;
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
	ll ans = F[a + c] * rF[a] % MOD * rF[c] % MOD;
	printf("%d\n", (int) ans);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int n;
	F[0] = rF[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		F[i] = F[i-1] * i % MOD;
		rF[i] = rF[i-1] * inv(i, MOD) % MOD;
	}
	int tt;
	cin>> tt;
	while(tt--) {
		comp();
	}
}