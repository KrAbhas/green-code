#include<bits/stdc++.h>
using namespace std;
 
void solve(){	
	int n;
	cin>>n;
	//cout<<n;
	int p;
	int k=0;
	int c=0;
	int minm=99999;int maxm=0;
	for(int i=0;i<n;i++){
		cin>>p;
		if(k==0 && p<0){
			k=1;
		}
		if(p==0){
			c=1;
		}
		if(minm>p){
			minm=p;
		}
		if(maxm<p){
			maxm=p;
		}
		//cout<<p;
	}
	if(k==1){
		cout<<"No"<<'\n';
		return;
	}
	else{
		//cout<<minm<<maxm;
		cout<<"Yes\n";
		cout<<maxm+1<<"\n";
		
		for(int i=0;i<=maxm;i++){
			cout<<i<<" ";
		}
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