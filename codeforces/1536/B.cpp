#include<bits/stdc++.h>
using namespace std;
 
void solve(){	
	int n;
	cin>>n;
	string s;
	cin>>s;
	int k=0;
	string st;
	vector<string> strings={""};
	while(k==0){
		vector<string> nstrings;
		for(auto &str: strings){
			for(int i=0;i<26;i++){
				string nstr=str+char('a'+i);
				nstrings.push_back(nstr);
				//cout<<nstr<<" ";
				if(s.find(nstr)==string::npos){
					//cout<<nstr<<" ";
					k=1;
					st=nstr;
					break;
				}
			}
			if(k==1){
				break;
			}
		}
		strings.swap(nstrings);
	}
	cout<<st<<endl;
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