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

int arr[100000];

void sieve(){
	arr[1]=1;
	arr[0]=1;
	for(int i=2;i<10000;i++){
		if(arr[i]==0)
			for(int j=i*i;j<100000;j=j+i){
				arr[j]=1;
			}
	}
}

void solve(){
	int d;
	cin>>d;
	int a=d+1;
	int i=a;
	while(arr[i]==1){
		i++;
	}
	//cout<<arr[i];
	a=i+d;
	swap(a,i);
	while(arr[i]==1){
		i++;
	}
	printi(i*a);
}

void solve_t(){
	int t;
	cin>>t;
	sieve();
	while(t--){
		solve();
		cout<<"\n";
	}
}

int main(){

	solve_t();
}