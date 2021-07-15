#include<bits/stdc++.h>
using namespace std;

#define ll long long

void comp(){
	int n, m;
	cin >> n >> m;
	string s;
	map<char,pair<int,int>> str[m];
	for(int i = 0; i < n; i++){
		cin >> s;
		if(n==1){
			cout<<s<<endl;
			return;
		}
		for(int j=0;j<m;j++){
			str[j][s[j]].first++;
			str[j][s[j]].second++;
		}
	}

	string bads;
	for(int i = 0; i < n-1; i++){
		cin >> bads;
		for(int j = 0; j < m; j++){
			int k=--str[j][bads[j]].first;
			if(k == 0)
				str[j].erase(bads[j]);
		}
	}

	for(int i=0;i<m;i++){
		cout<<str[i].begin()->first;
	}
	cout<<"\n";
}

int main(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin>> tt;
	while(tt--) {
		comp();
		cout<<flush;
	}
}