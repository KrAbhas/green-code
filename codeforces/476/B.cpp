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

double findprobab(int n, int r){
	//deb(r);
	int k=min(r,n-r);
	int t=max(r,n-r);
	int factr=1;
	int factn=1;
	for(int i=1;i<=k;i++){
		factr=factr*i;
		factn=factn*(t+i);
	}
	//deb(factr);
	//deb(factn);
	double prob=factn/(factr);

	//deb(prob);
	return prob/pow(2,n);
}
void solve(){
	string sa,sb;
	cin>>sa;
	cin>>sb;
	int aplus=0;
	int aminus=0;
	int bplus=0;
	int bminus=0;
	int bque=0;
	for(char ch: sa){
		if(ch=='+'){
			aplus++;
		}
		else aminus++;
	}
	for(char ch: sb){
		if(ch=='+'){
			bplus++;
		}
		else if(ch=='-')
			bminus++;
		else bque++;
	}
	int apos=aplus-aminus;
	int bpos=bplus-bminus;
	int c=apos-bpos;
	int t=0;
	double pro=0;
	cout.precision(20);
	//deb(c);
	//deb(bque);
	if(c>bque || c<-1*bque){
		//printf("HI");
		printf("%d",pro);
		return;
	}
	else{
		int k=bque-abs(c);
		t=t+abs(c);
		if(k%2!=0){
			cout<<pro;
			return;
		}
		else{
			//printf("hi");
			t=t+k/2;
			pro=findprobab(bque,t);
			//cout<<pro;
			cout.precision(20);
			cout<<pro;
			return;
		}
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