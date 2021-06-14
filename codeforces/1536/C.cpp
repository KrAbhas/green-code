#include<bits/stdc++.h>
using namespace std;
 
void solve(){	
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<pair<int,int>,int> ratio;
	int d=0;int k=0;
	for(char ch: s){
		if(ch=='D')
			d++;
		else
			k++;
		int p=__gcd(d,k);
		cout<<++ratio[{d/p,k/p}]<<" ";
	}
	cout<<endl;
}
 
void solve_t(){
	int t;
	cin>>t;
	//cout<<t;
	int i=0;
	while(t--){
		i++;
		//printf("Case #%i: ", i);
		solve();
	}
}
 

int main(){
	solve_t();
	
}