#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--){
		int n;
		cin >> n;
		int k;
		cin >> k;
		if ((n + 1) / 2 < k) {
			cout << -1<<endl;
			continue;
		}
		int r = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				if (i == r && j == r) {
					cout << 'R';
					k--;
					if (k > 0)
						r += 2;
				}
				else {
					cout << ".";
				}
			}
			cout << endl;
		}
	}
}