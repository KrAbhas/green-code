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

const int maX = 1e4 + 7;

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

	bool arr[maX];
	arr[0] = false;
	for (int i = 1; i < maX; i++) {
		int k = i;
		arr[i] = true;
		while (k >= 3) {
			if (k % 3 == 2) {
				arr[i] = false;
				break;
			}
			k = k / 3;
		}
		if (k % 3 == 2) {
			arr[i] = false;
		}
	}
	cout << endl;
	cin >> tt;
	while (tt--) {
		int n; cin >> n; 
		while (true) {
			int k = n;
			while (k >= maX) {
				if (k % 3 == 2) {
					break;
				}
				k = k / 3;
			}
			if (k < maX) {
				if (arr[k]){
					cout << n << endl;
					break;
				}
			}
			n++;
		}
	}
}       	

