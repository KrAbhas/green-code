#include<bits/stdc++.h>
using namespace std;

int msb(int n){
	int k=1;
	while(k<<1<=n){
		k=k<<1;
	}
	return k-1;
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
		int c=0;
		for(char ch:s){
			if(ch=='0')
				c++;
		}
		//cout<<c;
		if(c%2==1){
		    if(c==1)
		        cout<<"BOB";
		    else
			    cout<<"ALICE";
		}
		else{
			cout<<"BOB";
		}
		cout<<"\n";
	}
}