#include<bits/stdc++.h>
using namespace std;

#define ll long long

//if runtime error
//check: div by 0
//check: out of bound

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tt;
	cin >> tt;
	while (tt--) {
		ll n, k;
		cin >> n;
		ll maxm = 0;
		ll minm = 999999999;
		ll a,b;
		cin >> b;
		for (ll i = 1; i < n; i++) {
			a = b;
			cin >> b;
			maxm = max (maxm, a * b);
		}
		cout << maxm << "\n";
	}
}

