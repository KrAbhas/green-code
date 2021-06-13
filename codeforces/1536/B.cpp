#include<bits/stdc++.h>
using namespace std;
 
void solve(){	
	int n;
	cin>>n;
	string s;
	cin>>s;
	//cout<<s.length();
	int k=0;
	int l=0;
	string str="a";
	char ch='a';
	while(k==0){
		int p=l;
		int skip=1;
		while(true){
			if(skip==0){
				int r=l;
				while(r>=0 && str[r]=='z'){
					str[r]='a';
					r--;
				}
				if(r==-1)
					break;
				str[r]++;
			}
			else
				skip=0;
			int t=0;
			for(int i=0;i<s.length()-l;i++){
				if(str.compare(s.substr(i,l+1))==0){
					t=1;
					break;
				}
			}
			if(t!=1){
				k=1;
				break;
			}
		}
		if(k==1)
			break;
		for(int j=0;j<=l;j++){
			str[j]='a';
		}
		str='a'+str;
		l++;
	}
	cout<<str<<endl;
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