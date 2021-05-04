#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define deb(x) cout<<#x<<" "<<x<<endl
#define fo(i,n) for(int i=0;i<n;i++)
#define nl cout<<endl;
#define inputi(a) scanf("%d",&a)
#define inputl(a) scanf("%lld",&a)
#define printi(a) printf("%d ",a)
#define printl(a) printf("%lld ",a)
#define vi vector<int>
#define vl vector<ll>
const ll Max2=1e9+7;
const int Max1=1e6+1;
 
template<typename... T>
void read(T&&... arg){
	((cin>>arg),...);
}
 
template<typename... T> 
void write(T&&... arg){ //rvalue reference (new to cpp)
	((cout<<arg<<" "),...);
	//cout<<endl;
}
 
/*
int iscomposite[Max1];
void sieve(){
	iscomposite[0]=1;
	iscomposite[1]=1;
	for(int i=2;i*i<Max1;i++){
		if(!iscomposite[i]){
			for(int j=i+i;j<Max1;j=j+i){
				iscomposite[j]=1;
			}
		}
	}
}
 
*/
 
ll nc2(ll n){
	return n*(n-1)/2;
}
 
void self_max(ll &a, ll b){
	a=max(a,b);
}
 
void self_min(ll &a, ll b){
	a=min(a,b);
}
 
void solve(){	
	int n;
	inputi(n);
	vector<vector<int>>arr(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		inputi(arr[i][i]);
	}

	for(int i=0;i<n;i++){
		//cout<<i;
		int x=arr[i][i];
		int t=x-1;
		int k=i;
		int j=i;
		while(t>0){
			if(k-1>=0){
				if(arr[j][k-1]==0){
					arr[j][k-1]=x;
					k--;
				}
				else{
					arr[j+1][k]=x;
					j++;
				}
			}
			else{
				if(arr[j+1][k]==0){
					arr[j+1][k]=x;
					j++;
				}
			}
			t--;
			//break;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==0){
				printf(" ");
			}
			else printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
 
void solve_t(){
	int t;
	inputi(t);
	int i=0;
	while(t--){
		i++;
		//printf("Case #%i: ", i);
		solve();
	}
}
 
int main(){

	solve();
}