#include<bits/stdc++.h>
using namespace std;

#define ll long long




int main(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int arr[n][2];
		int emp[n];
		int c=0;
		for(int i=0; i<n;i++){
			arr[i][0]=0;
			arr[i][1]=0;
			emp[i]=0;
		}
		int cnt=0;
		vector<int>match;
		map<int,int> m;
		for(int i=0; i<n;i++){
			cin>>arr[i][0];
			if(arr[arr[i][0]-1][1]!=1){
				arr[arr[i][0]-1][1]=1;
				cnt++;
				emp[i]=arr[i][0];
				m[arr[i][0]]=i;
			}
			//cout<<emp[i]<<" ";
		}
		//cout<<endl;
		for(int i=0; i<n;i++){
			if(arr[i][1]!=1)
				match.push_back(i+1);
		}
		int t=-1;
		if(!match.empty())
		for(int i=0;i<n;i++){
			if(emp[i]!=0)
				continue;
			if(match.empty())
				break;
			if(match.front()-1!=i){
				emp[i]=match.front();
				match.erase(match.begin());
				//cout<<emp[i]<<endl;
			}
			else{
				emp[i]=match.back();
				match.pop_back();
				//cout<<emp[i]<<endl;
			}
			if(t>=0 && emp[i]-1==i){
				swap(emp[t],emp[i]);
			}
			if(emp[i]-1==i){
				swap(emp[m[arr[i][0]]],emp[i]);
			}
			t=i;
		}
		cout<<cnt<<"\n";
		for(int i=0;i<n;i++){
			cout<<emp[i]<<" ";
		}
		cout<<"\n";
	}
}