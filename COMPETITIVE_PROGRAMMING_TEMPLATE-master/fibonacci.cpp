
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>


/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/
using namespace std;
using namespace __gnu_pbds;

// #define  part ..
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end() 
#define mod 1000000007
//#define maxx 200006
#define ll long long 
#define quick    ios_base::sync_with_stdio(NULL),cin.tie(0);
#define listll vector< long long > 
#define listi vector< int> 
#define pii   pair<int , int> 
#define pll pair<long long , long long > 
#define minheap priority_queue<long long , vector< long long >, greater<long long > >
#define rep(i,a,b) for(int i=a;i<b;i++)
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


template < class T > using oset = tree< T , null_type, less  < T  > , rb_tree_tag , tree_order_statistics_node_update > ;


// end of #define 

// define globals ...
const int maxx = 2e5+26;

//write function from here ...







int Main(){
 

ll n;
cin>>n;

if(n==0){
	cout<<0;
	return 0;
}
if(n==1)
{
	cout<<1<<endl;
	return 0;
}

ll mat[2][2];

mat[0][0]=1,mat[1][0]=1,mat[1][1]=0,mat[0][1]=1;

ll ans[2][2];
ans[0][0]=1,ans[1][1]=1;
ans[1][0]=0,ans[0][1]=0;


while(n){
	
	ll temp[2][2];
		
	if(n&1){
		
		temp[0][0] = ((mat[0][0]*ans[0][0])%mod +(mat[1][0]*ans[0][1])%mod)%mod;
		temp[1][0] = (( ans[1][0]*mat[0][0])%mod + (ans[1][1]*mat[1][0])%mod)%mod;
		temp[0][1] = (( ans[0][0]*mat[0][1])%mod + (ans[0][1]*mat[1][1])%mod)%mod;
		temp[1][1] = ( ( ans[1][0]*mat[0][1])%mod + ( ans[1][1]*mat[1][1])%mod)%mod;
		
		
		ans[1][1]=temp[1][1];
		ans[0][0]=temp[0][0];
		ans[0][1] =temp[0][1];
		ans[1][0] = temp[1][0];
		
		
		
	}
	
		temp[0][0] = ((mat[0][0]*mat[0][0])%mod +(mat[1][0]*mat[0][1])%mod)%mod;
		temp[1][0] = (( mat[1][0]*mat[0][0])%mod + (mat[1][1]*mat[1][0])%mod)%mod;
		temp[0][1] = (( mat[0][0]*mat[0][1])%mod + (mat[0][1]*mat[1][1])%mod)%mod;
		temp[1][1] = ( ( mat[1][0]*mat[0][1])%mod + ( mat[1][1]*mat[1][1])%mod)%mod;
		
		
		mat[1][1]=temp[1][1];
		mat[0][0]=temp[0][0];
		mat[0][1] =temp[0][1];
		mat[1][0] = temp[1][0];
	    
	    n/=2;
	    
	
	
	
	
	
	
}

cout<<ans[0][1]<<endl;


 


return 0;

}

















int main(){
 quick;
int t =1; 
//cin>>t;
while(t-- )
 Main();

 return 0;


}
