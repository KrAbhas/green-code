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

int k=0;
int no=0;

int bin_search(int a[], int lb, int ub, int n){
	//printi(n);
	if(lb<=ub){
		int mid=(lb+ub)/2;
		//printi(mid);
		//printi(a[mid]);
		if(a[mid]==n)
			return mid;
		if(a[mid]>n)
			return bin_search(a,lb,mid,n);
		if(a[mid]<n)
			return bin_search(a,mid,ub,n);
	}
	else return -1;
}

void check_seg(int a[], int b[], int ta, int tb){
	k++;
	//binary_search()
	for(int i=0;i<=tb-ta;i++){
		if(a[i+ta]!=b[tb-i]){
			return;
		}
	}
	no++;
}

void solve(){
	k=0;
	no=0;
	int n;
	cin>>n;
	int a[n];
	int b[n];
	//cout<<"HI";
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	int ta=0;
	int tb=0;
	for(int i=0;i<n;++i){
		if(a[i]!=b[i]){
			//cout<<"h1\n";
			if(k==1){
				//inputi(ta);
				cout<<"no\n";
				return;
			}
			ta=i;
			tb=bin_search(a,ta,n,b[ta]);
			//printi(tb);
			check_seg(a,b,ta, tb);
			i=tb;
			if(k==1 && no==0){
				//printf("h2\n");
				//printi(tb);
				printf("no\n");
				return;
			}
		}
	}
	printf("yes\n");
	printi(ta+1);
	printi(tb+1);
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