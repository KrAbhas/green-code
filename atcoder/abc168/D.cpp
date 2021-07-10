#include<bits/stdc++.h>
using namespace std;
#define ll long long

int vis[100001];

int bfs(vector<vector<int>> gr){
	memset(vis,-1,sizeof(vis));
	queue<int> q;
	q.push(1);
	vis[1]=0;
	int c=1;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int i=0;i<gr[k].size();i++){
			if(vis[gr[k][i]]==-1){
				q.push(gr[k][i]);
				vis[gr[k][i]]=k;
				c++;
			}
		}
	}
	return c;
}

int main(){
	int n, m;
	cin>>n>>m;
	int a,b;
	vector<vector<int>>gr(n+1,vector<int>());
	for(int i=0;i<m;i++){
		cin>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	if(bfs(gr)!=n)
		cout<<"No\n";
	else{
		cout<<"Yes\n";
		for(int i=2;i<n+1;i++){
			cout<<vis[i]<<"\n";
		}
	}

}