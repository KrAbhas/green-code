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
	cin>>n;
	string b;
	cin>>b;
	string d="";
	for(int i=0;i<n;i++){
		if(b[i]=='1'){
			if(i>0 && d[i-1]=='2'){
				d=d+"1";
			}
			else{
				d=d+"2";
			}
		}
		else{
			if(i>0 && d[i-1]=='1'){
				d=d+"0";
			}
			else{
				d=d+"1";
			}
		}
	}
	for(int i=0;i<n;i++){
		if(d[i]=='2'){
			if(b[i]=='2'){
				b[i]='1';
			}
		}
		else if(d[i]=='1'){
			if(b[i]=='1'){
				b[i]='0';
			}
			else if(b[i]=='0'){
				b[i]='1';
			}
		}
	}
	cout<<b;
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
