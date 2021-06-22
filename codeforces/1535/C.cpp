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
		cin>>s;
		long long total=0;
		int n=int(s.size());
		for(int i=1;i<n;i+=2){
			if(s[i]=='1')
				s[i]='0';
			else if(s[i]=='0')
				s[i]='1';
		}
		int lptr=0;
		int rptr=-1;
		int ocount=0;
		int zcount=0;
		while(rptr+1<n){
			rptr++;
			if(s[rptr]=='0')
					zcount++;
			else if(s[rptr]=='1')
				ocount++;
			while(zcount>0 && ocount>0){
				if(s[lptr]=='0')
					zcount--;
				else if(s[lptr]=='1')
					ocount--;
				lptr++;
			}
			total+=rptr-lptr+1;
		}
		cout<<total<<endl;
	}
}