#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dist(pair<int,int> a, pair<int,int>b){
	return abs(a.first - b.first)+abs(a.second - b.second);
}

int main(){


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int s=n+(n-1);
		for(int i=0;i<n-2;i++){
			s++;
			if(arr[i]<=arr[i+1] && arr[i+1]<=arr[i+2] || arr[i]>=arr[i+1] && arr[i+1]>=arr[i+2]){
				s--;
				//cout<<"hi\n";
			}
		}
		for(int i=0;i<n-3;i++){
			s++;
			if(arr[i]<=arr[i+1] && arr[i+1]<=arr[i+2] || arr[i]>=arr[i+1] && arr[i+1]>=arr[i+2])
				s--;
			else if(arr[i]<=arr[i+1] && arr[i+1]<=arr[i+3] || arr[i]>=arr[i+1] && arr[i+1]>=arr[i+3])
				s--;
			else if(arr[i]<=arr[i+2] && arr[i+2]<=arr[i+3] || arr[i]>=arr[i+2] && arr[i+2]>=arr[i+3])
				s--;
			else if(arr[i+1]<=arr[i+2] && arr[i+2]<=arr[i+3] || arr[i+1]>=arr[i+2] && arr[i+2]>=arr[i+3])
				s--;
		}
		cout<<s<<"\n";
	}
}