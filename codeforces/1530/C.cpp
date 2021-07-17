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
		int me[n];
		int badme[n];
		int lly[n];
		for(int i=0;i<n;i++)cin>>me[i];
		for(int i=0;i<n;i++)cin>>lly[i];
		sort(me,me+n,greater<int>());
		sort(lly, lly+n,greater<int>());
		int k=n-(n/4);
		int a=0;
		int b=0;
		int c=0;
		int p=0;
		int r=k;
		for(int i=0;i<k;i++){
			a+=me[i];
			b+=lly[i];
		}
		p=n;
		int i=k;
		while(a<b){
			p++;
			int t=p-p/4;
			if(t>k)
				for(int j=k;j<t;j++){
					a+=100;
					//cout<<a<<" ";
					if(i<n){
						b+=lly[i];
						i++;
					}
					if(a>=b)
						break;
				}
			else{
				if(r>0)
					a-=me[--r];
				else a-=100;
				//cout<<r;
				a+=100;
			}
			if(a>=b)
				break;
			k=t;
		}



		//cout<<(a)<<" "<<b<<endl;
		cout<<(p-n)<<"\n";
	}
}