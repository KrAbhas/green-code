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

int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		vector<int> arr(26);
		vector<int> brr(26);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			arr[a[i] - 'a']++;
			brr[b[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] < brr[i] || (arr[i] -= brr[i]) % k){
				ok = false;
				break;
			}
			if (i < 25)
				arr[i + 1] += arr[i];
		}
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
}       	
