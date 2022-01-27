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
typedef pair<int, int> pi;

const ll maX = 998244353;

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
		int n, u, l, d, r;
		bool ok = true;
		cin >> n >> u >> r >> d >> l;
		for (int i = 0; i < 16; i++) {
			int arr[] = {u, l, d, r};
			ok = true;
			for (int j = 0; j < 4; j++) {
				if (i & (1 << j)) {
					arr[j]--;
					arr[(j + 1) % 4]--;
				}
			}
			for (int i = 0; i < 4; i++) {
				if (arr[i] < 0 || arr[i] > n - 2){
					ok = false;
				}
			}
			if (ok) break;
		}
		if (!ok) cout << "NO\n";
		else cout << "YES\n";
	}
}       	
