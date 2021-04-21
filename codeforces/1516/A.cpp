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
	int k;
	inputi(n);
	inputi(k);
	int arr[n];
	for(int i=0;i<n;++i){
		inputi(arr[i]);
	}
	int t;
	t=0;
	arr[n-1]+=k;
	while(k){
		if(k>=arr[t]){
			k-=arr[t];
			arr[t]=0;
			t++;
		}
		else{
			arr[t]-=k;
			k=0;
		}
	}
	for(int i=0;i<n;++i){
		printi(arr[i]);
	}
	printf("\n");
}

void solve_t(){
	int t;
	inputi(t);
	while(t--){
		solve();
	}
}

int main(){
	solve_t();
}

