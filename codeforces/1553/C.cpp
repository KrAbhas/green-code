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
		int ze1=0,on1=0,un1=0,ze2=0,on2=0,un2=0,rem1=5,rem2=5;
		for(int i=0;i<10;i++){
			if(i%2==0){
				if(s[i]=='0')
					ze1++;
				else if(s[i]=='1')
					on1++;
				else un1++;
				rem1--;
			}
			else{
				if(s[i]=='0')
					ze2++;
				else if(s[i]=='1')
					on2++;
				else un2++;
				rem2--;
			}
			if(i==9 || on1+un1>on2+rem2 || on2+un2>on1+rem1){
				cout<<(i+1)<<"\n";
				break;

			}
		}
	}
}

