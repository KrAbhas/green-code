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
const int Max1=1e2+1;
 
template<typename... T>
void read(T&&... arg){
	((cin>>arg),...);
}
 
template<typename... T> 
void write(T&&... arg){ //rvalue reference (new to cpp)
	((cout<<arg<<" "),...);
	//cout<<endl;
}

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
int k=0;

void self_max(ll &a, ll b){
	a=max(a,b);
}

void self_min(ll &a, ll b){
	a=min(a,b);
}

ll nc2(ll n){
	return n*(n-1)/2;
}

int stotime(string s,string form){
	//int n=8;
	int k;
	int min;
	if(form[0]=='A'){
		//cout<<"here\n";
		k=stoi(s.substr(0,2));
		k=k%12;
		min=stoi(s.substr(3,5));
	}
	else{
		int l=stoi(s.substr(0,2));
		k=12+l%12;
		min=stoi(s.substr(3,5));
	}
	int t=(k+10)*100+min;
	return t;
}

int getdistinct(vector<char> f, vector<char> s){
	int c=0;
	sort(f.begin(),f.end());
	for(char ch:s){
		if(binary_search(f.begin(),f.end(),ch)){
			c++;
		}
	}
	return c;
}

unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) 
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
 
    // val is the key or the value that
    // has to be added to the data part
    Node(int val)
    {
        data = val;
 
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};
typedef struct Node node;
int dp[Max1];

node *maketree(int arr[], int lb, int ub, int depth){
	//deb(lb);
	//deb(ub);
	if(lb>ub){
		return NULL;
	}
	//int temp[ub-lb];
	int k=lb;
	int maxm=arr[k];

	for(int i=lb; i<=ub;i++){
		if(arr[i]>maxm){
			maxm=arr[i];
			k=i;
		}
	}
	node *root=new node(maxm);
	
	dp[maxm]=depth;
	if(lb==ub){
		return root;
	}
	else{
		root->left=maketree(arr,lb,k-1,depth+1);
		root->right=maketree(arr,k+1,ub,depth+1);
		return root;
	}
}

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<Max1;i++){
		dp[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	maketree(arr,0,n-1,0);
	for(int i=0;i<n;i++){
		//deb(arr[i]);
		cout<<(dp[arr[i]])<<" ";
	}
	cout<<"\n";
}

void solve_t(){
	int t;
	cin>>t;
	while(t--){
		//cout<<"hello";
		solve();
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve_t();

}
