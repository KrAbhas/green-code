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
		string str;
		cin >> str;
		if (n == 1 || str[0] == str[1]){
			cout << str[0] << str[0] << endl;
			continue;
		}
		int k = 0;
		for (int i = 1; i < n; i++) {
			if ((str[i] - 'a') <= (str[i - 1] - 'a')) {
				k = i;
			}
			else if (str[i] > str[k])
				break;
		}
		for (int i = 0; i <= k; i++) {
			cout << str[i];
		}
		for (int i = k; i >= 0; i--) {
			cout << str[i];
		}
		cout << "\n";
	}
}