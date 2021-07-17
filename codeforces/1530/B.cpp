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
		int h,w;
		cin>>h>>w;
		int arr[h+2][w+2];
		memset(arr,0,sizeof(arr));
		arr[1][1]=1;
		
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				//cout<<arr[i][j];
				if(!(i==1 && j==1))
					if(i==1 || i==h || j==1 || j==w)
						if(!((arr[i-1][j]) || arr[i][j-1] || arr[i+1][j] || arr[i][j+1] || arr[i-1][j-1] || arr[i-1][j+1] || arr[i+1][j-1] || arr[i+1][j+1]))
							arr[i][j]=1;
				cout<<arr[i][j];
			}
			cout<<"\n";
		}
		cout<<endl;
	}
}