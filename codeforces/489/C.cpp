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

void self_max(ll &a, ll b){
	a=max(a,b);
}

void self_min(ll &a, ll b){
	a=min(a,b);
}

void solve(){
	int s,m;
	cin>>m>>s;
	int small[m];
	int great[m];
	//for unaccepted conditions
	if((s<=0 && m!=1) || s>m*9){
		cout<<-1<<" "<<-1;
		return;
	}
	else if(s==0 && m==1){
		cout<<0<<" "<<0;
		return;
	}

	//for finding smallest
	int temps=s;
	int tempm=m;
	for(int i=0;i<tempm;i++){
		for(int j=9;j>=0;--j){
			if(temps-j>=0){
				small[i]=j;
				temps-=j;
				break;
			}
		}
	}
	//printing the smallest
	int k=0;
	if(small[m-1]==0){
		cout<<1;
		k=1;
	}
	else cout<<small[m-1];
	for(int i=m-2;i>=0;i--){
		if(small[i]!=0 && k==1){
			small[i]--;
			k=0;
		}
		cout<<small[i];
	}

	cout<<" ";
	//finding greatest
	temps=s;
	tempm=m;
	for(int i=0;i<tempm;i++){
		for(int j=9;j>=0;--j){
			if(temps-j>=0){
				great[i]=j;
				temps-=j;
				break;
			}
		}
	}

	//printing the largest
	for(int i=0;i<m;++i){
		cout<<great[i];
	}
}

void solve_t(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

int main(){

	solve();
}