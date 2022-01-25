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

const ll maX = 2 * 1e5 + 7;

long long power(long long x, long long y, long long p) 
{ 
    long long res;
    return res; 
} 


int main(){
	const ll inf = 1e18 + 7;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int m;
	vector<vector<int>> a(26);
	for (int i = 0; i < n; i++) {
		a[s[i] - 'a'].pb(i + 1);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int arr[26] = {0};
		string str;
		cin >> str;
		int c = 0;
		for (char ch : str) {
			if (arr[ch - 'a'] == 0) c++;
			arr[ch - 'a']++;
		}
		int k = 0;
		for (int i = 0; i < 26; i++) {
			if (arr[i] > 0) {
				asnmx(k, a[i][arr[i] - 1]);
			}
		}
		cout << k << endl;
	}
}       	

