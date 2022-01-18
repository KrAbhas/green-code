#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) (x).begin(), (x).end()
#define intl int64_t
#define pb(x) push_back(x)
#define unmap unordered_map
#define unset unordered_set
template<class T> bool asnmx (T& a, const T& b){return a < b? a = b, 1: 0;} 
template<class T> bool asnmn (T& a, const T& b){return b < a? a = b, 1: 0;}
template<class T> bool asnminpos (T& a, const T& b, const T& i, T& pos){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, const T& i, T& pos){return a < b? a = b, pos = i, 1: 0;}

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n + 1);
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			a[i + 1] = a[i] + 1;
		else a[i + 1] = a[i] - 1;
	}
	int c = 0;
	for (int i = 1; i < n + 1; i++) {
		if (a[i] < 0 || (a[i - 1] < 0 && a[i] == 0))
			c++;
	}
	if (a[n] != 0) cout << -1 << endl;
	else cout << c << endl;
}       	

