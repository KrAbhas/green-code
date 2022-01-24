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
template<class T> bool asnminpos (T& a, const T& b, T& pos, const T& i){return b < a? a = b, pos = i, 1: 0;}
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a < b? a = b, pos = i, 1: 0;}

const ll maX = 1e4 + 7;

long long power(long long x, long long y, long long p) 
{ 
    long long res;
    return res; 
} 


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> um(n + 1, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			um[a[i]]++;
		}
		vector<int> res;
		int mex = 0;
		int curmex = 0;
		int maxm = 0;
		vector<int> b(n + 1, 0);
		while (um[mex]) mex++;
		res.pb(mex);
		for (int i = 0; i < n; i++) {
			asnmx(maxm, a[i]);
			b[a[i]]++;
			while (b[curmex]) curmex++;
			um[a[i]]--;
			if (curmex == mex) {
				curmex = 0;
				int k = 0;
				while (k != maxm + 1) {
					b[k] = 0;
					k++;
				}
				maxm = 0;
				mex = 0;
				while (um[mex]) mex++;
				if (i < n - 1)
					res.pb(mex);
			}
		}
		cout << res.size() << endl;
		for (auto i: res) cout << i << " ";
		cout << endl;
	}
}       	

