#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin>> tt;
	while(tt--) {
		int p=0;
		int n;
		cin >> n;
		int arr[n];
		map<int,pair<int,int>> unsorted;
		pair<int,int> target;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			unsorted[arr[i]].first += i%2==0?1:0;
			unsorted[arr[i]].second += i%2!=0?1:0;
		}
		sort(arr,arr+n);
		for(int i=0;i<n;i++){
			int k=arr[i];
			pair<int,int> each={0,0};
			while(i<n-1 && arr[i] == arr[i+1]){
				if(i%2==0){
					each.first+=1;
				}
				else each.second+=1;
				i++;
			}
			if(i%2==0){
				each.first+=1;
			}
			else each.second+=1;
			pair<int,int> t=unsorted[k];
			if(t.first != each.first || t.second!=each.second){
				//cout<<t.first<<" "<<t.second<<" "<<each.first<<" "<<each.second<<" ";
				//cout<<k<<" ";
				cout<<"No\n";
				p=1;
				break;
			}
		}
		if(p==0)
			cout<<"Yes\n";
	}
}