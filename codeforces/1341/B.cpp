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
	int tt;
	cin >> tt;
	while(tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int arr[n]; arr[0] = 0;
		for (int i = 1; i < n - 1; i++) {
			if (a[i] > a[i + 1] && a[i] > a[i - 1]) {
				arr[i] = 1;
			}
			else arr[i] = 0;
			arr[i] = arr[i] + arr[i - 1];
		}
		arr[n - 1] = arr[n - 2];
		int m = 0; int c = 0;
		for (int i = 0; i < n - k + 1; i++) {
			if (m < arr[i + k - 2] - arr[i]) {
				m = arr[i + k - 2] - arr[i];
				c = i;
			}
		}
		cout << m + 1 << " " << c + 1 << endl;
	}
	return 0;
}       	

