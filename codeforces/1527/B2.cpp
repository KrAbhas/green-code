#include<bits/stdc++.h>
using namespace std;

pair<int,int> isPal(string s,int n){
	int c=0;
	int t=0;
	for(int i=0;i<=n/2;i++){
		if(s[i]==s[n-i-1]){
			if(s[i]=='0')
				if(i!=n-i-1)
					t+=2;
				else
					t++;
		}
		else{
			c++;
		}
		if(c==2){
			return {0,0};
		}
	}
	if(c==0){
		return {1,t};
	}
	else return {2,t};
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		pair<int,int> k=isPal(s,n);
		if(k.first==0){
			cout<<"ALICE";
		}
		else if(k.first==1){
			if(k.second%2==0 || k.second==1){
				cout<<"BOB";
			}
			else{
				cout<<"ALICE";
			}
		}
		else{
			if(k.second==1)
				cout<<"DRAW";
			else
				cout<<"ALICE";
		}
		cout<<"\n";
	}
}