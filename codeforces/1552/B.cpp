#include<bits/stdc++.h>
using namespace std;

#define ll long long

//if runtime error
//check: div by 0
//check: out of bound

bool mycmp (pair<int,int>& a, pair<int,int>& b) {
	return a.first <= b.first;
}

int good(int d, int j, int arr[][5]) {
	int r = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[d][i] > arr[j][i]) {
			r++;
		}
	}
	return r > 2 ? j : d;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int arr[n][5];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 5; j++){
				cin >> arr[i][j];
			}
			//cout<<endl;
		}

		int d = 0;
		for (int i = 1; i < n; i++) {
			d = good(d, i, arr);
		}
		int ok = d;
		for (int i = 0; i < n; i++) {
			if (good(d, i, arr) != d) {
				ok = -2;
				break;
			}
		}
		
		cout << (ok + 1) << "\n";
	}
}

