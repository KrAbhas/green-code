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
		ll n;
		cin >> n;
		int chance = 0;
		ll arr[2] = {0};
		while (n > 0) {
			if (n % 2 == 1) {
				n--;
				arr[chance]++;
			}
			else if (n == 4) {
				n = 1;
				arr[chance] += 3;
			}
			else if (n % 4 == 0) {
				n--;
				arr[chance]++;
			}
			else {
				n = n / 2;
				arr[chance] += n;
			}
			chance = chance ^ 1;
		}
		cout << arr[0] << endl;
	}
}       	
