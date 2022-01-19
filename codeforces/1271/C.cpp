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

const int maX = 1e9 + 7;

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
	int n;
	int sx, sy;
	cin>> n >> sx >> sy;
	pair<int,int> pnt[] = {{sx - 1, sy}, {sx + 1, sy},{sx, sy - 1}, {sx, sy + 1}};
	int a, b;
	int arr[4] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		int m = INT_MAX;
		for (int j = 0; j < 4; j++) {
			asnmn(m, abs(pnt[j].first - a) + abs(pnt[j].second - b));
		}
		for (int j = 0; j < 4; j++) {
			if(m == abs(pnt[j].first - a) + abs(pnt[j].second - b)) {
				arr[j]++;
			}
		}
	}
	int m = 0;
	int k = -1;
	for (int i = 0; i < 4; i++) {
		asnmaxpos(m, arr[i], k, i);	
	}
	cout << m << endl << pnt[k].first << " " << pnt[k].second << endl;
}       	

