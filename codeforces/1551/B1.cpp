#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin>>tt;
	while(tt--){
		string s;
		cin >> s;
		int arr[26];
		memset(arr, 0, sizeof(arr));
		int n = (int) s.size();
		for(int i = 0; i < n; i++){
			arr[s[i] - 'a'] += 1;
		}
		int c = 0;
		for(int i = 0; i < 26; i++){
			if (arr[i] <= 1)
				c += arr[i];
			else c += 2;
		}
		cout << (c/2) << "\n";
	}
}

