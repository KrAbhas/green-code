#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dist(pair<int,int> a, pair<int,int>b){
	return abs(a.first - b.first)+abs(a.second - b.second);
}

int main(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int c=0;
		while(n!=0){
			c=max(c,n%10);
			n/=10;
		}
		cout<<c<<"\n";
	}
}