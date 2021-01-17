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

//int k;
vi vis(1e5);

int bfs(int n,int m, vi adj[]){
	//int k=0;
	queue<int> q;
	q.push(n);
	vis[n]=1;
	while(!q.empty()){
		int a=q.front();
		q.pop();
		if((m>n && a>2*m) || (n>m && a>n)){
			continue;
		}
		//deb(a);
		//q.pop();
		for(int i: adj[a]){
			if(vis[i]==0){
				if(i==m){
					return vis[a];
				}
				//deb(i);
				vis[i]=vis[a]+1;
				q.push(i);

			}
		}
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	if(n==m){
		cout<<0;
		return;
	}
	int k=(n>2*m)?n:2*m;
	//deb(k);
	vi adj[k+1];
	for(int i=1;i<=k;++i){
		adj[i].push_back(i-1);
		adj[i].push_back(i*2);
	}
	cout<<bfs(n,m,adj);
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