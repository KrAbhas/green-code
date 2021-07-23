#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool check(string s, string t, int i, int m, int n, int k, bool dir){
	if(i<0 || i>=m)
		return false;
	if(k==n-1){
		if(t[i]==s[k]){
			return true;
		}
		else return false;
	}
	else{
		//cout<<s[k]<<i<<k;
		if(t[i]!=s[k]){
			return false;
		}
	}
	//cout<<s[k]<<i<<k;
	if(dir==true){
		return check(s,t,i+1,m,n,k+1,true) || check(s,t,i-1,m,n,k+1,false);
	}
	else return check(s,t,i-1,m,n,k+1,false);
	
}


bool check(){
	string s;
	string t;
	cin>>t;
	cin>>s;

	int n=s.size();
	int m=t.size();
	for(int i=0;i<m;i++){
		//cout<<s[0]<<t[i]<<endl;
		if(t[i]==s[0]){
			//cout<<t[i]<<endl;
			if(check(s, t, i, m, n, 0, true)){
				return true;
			}
		}
	}
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin>>tt;
	while(tt--){
		if(check()){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
}

