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

int lowland(int ht[], int n, int a){
	int c=-1;
	for(int i=a;i<n-1;i++){
		if(ht[i]<ht[i+1]){
			c=i;
			break;
		}
	}
	if(c==-1){
		return n-1;
	}
	return c;
}

void solve(){
	int n, k;
	cin>>n>>k;
	int ht[n];
	for(int i=0;i<n;i++){
		cin>>ht[i];
	}
	int pos=0;
	for(int i=0;i<k;i++){
		if(pos!=0 && ht[pos]>ht[pos-1]){
			pos--;
		}
		else if(ht[pos+1]<=ht[pos]){
				//deb(pos);
				pos=lowland(ht,n,pos);
				//deb(pos);
		}
		//deb(pos);
		if(pos==n-1){
			printi(-1);
			printf("\n");
			return;
		}
		else{
			ht[pos]++;
		}
	}
	printi(pos+1);
	printf("\n");
}

void solve_t(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

int main(){
	solve_t();
}
