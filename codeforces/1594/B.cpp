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
template<class T> bool asnmaxpos (T& a, const T& b, T& pos, const T& i){return a <= b? a = b, pos = i, 1: 0;}

const int maX = 1e9 + 7;

int power(long long x, ll y, int p) 
{ 
    int res = 1;     // Initialize result 

    x = x % p; // Update x if it is more than or 
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 

        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		int p = 1;
		int i = 0;
		ll s = 0;
		while (p <= k) {
			if (p & k) 
				s = (s + power(n, i, maX)) % maX;
			p = p << 1;
			i++;
		}
		cout << s << endl;
	}
}       	

