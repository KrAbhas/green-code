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
		int arr[102] = {0};
		int a;
		for (int i = 0; i < n; i++){
			cin >> a;
			arr[abs(a)]++;
		}
		int s = 0;
		if (arr[0] >= 1)
			s++;
		for (int i = 1; i < 101; i++) {
			s += min(2, arr[i]);
		}
		cout << s << endl;
	}
}