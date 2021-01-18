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
int const num=1e5+1;
int s=0;

int vis[num];
int cat[num];

void dfs(vi adj[], int node,int dest, int count, int par){
	if(vis[node]==1){
		return;
	}
	if(cat[node]==1 && cat[par]==0){
		count=1;
	}
	else if(cat[node]==1){
		count++;
	}
	//deb(node);
	//deb(count);
	vis[node]=1;
	
	if(count>dest){
		return;
	}
	//deb(adj[node].size());
	if(adj[node].size()==1 && vis[adj[node][0]]==1){
		//deb(node);
		s++;
		return;
	}
	for(int child: adj[node]){
		dfs(adj,child,dest,count, node);
	}
}

void solve(){
	int n,m;
	cin>>n>>m;

	vi adj[n+1];
	int a,b;
	for(int i=1;i<=n;i++){
		cin>>cat[i];
	}
	for(int i=1;i<n;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	//cout<<"hello";
	//deb(n);
	s=0;

	dfs(adj,1,m,0,0);
	cout<<s;
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