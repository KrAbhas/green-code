#include<bits/stdc++.h>
using namespace std;

#define ll long long

//if runtime error
//check: div by crt
//check: out of bound


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

		ll crt = 0;
		ll n; 
		cin >> n;
		vector<ll> arr(n);
		ll s = crt;
		for (ll i = crt; i < n; i++) {
			cin >> arr[i];
			s += arr[i];
		}
		sort(arr.begin(), arr.end());
		ll m; 
		cin >> m;
		for (ll i = crt; i < m; i++) {
			ll p = crt;
			ll a, b;
			cin >> a >> b;
			ll k;
			ll k2;
			auto low = lower_bound(arr.begin(), arr.end(), a);
			if (low == arr.end()) {
				k = *(--low);
			}
			else {
				k = *low;
			}
			if (k == a) {
				p += max (crt, (b - s + k));
			}
			else {
				if(k < a) {
					p += max (crt, (b - s + k));
					p += max (crt, (a - k));
				}
				else {
					if (low == arr.begin()) {
						p += max (crt, (b - s + k));
						p += max (crt, (a - k));
					}
					else {
						ll r = crt;
						ll t = crt;
						r += max (crt, (b - s + k));
						r += max (crt, (a - k));
						k = *(--low);
						t += max (crt, (b - s + k));
						t += max (crt, (a - k));
						p += min(r, t);
					}
				}
			}
			cout << p << "\n";
		}
 	}


