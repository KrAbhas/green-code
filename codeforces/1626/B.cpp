#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, const T& i, T& pos){return a < b? a = b, pos = i, 1: 0;}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while(tt--) {
		string s;
		cin >> s;
		int n = s.length();
		int m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = s[i] - '0';
 		}
		int k = 0;
		m = a[0] + a[1];
		for (int i = 0; i < n - 1; i++) {
			if (a[i] + a[i + 1] > 9) {
				m = a[i] + a[i + 1];
				k = i;
			}
		}
		string stri = s.substr(0, k) + to_string(m) + s.substr(k + 2, n);  
		cout << stri << endl;
	}
	return 0;
}       	

