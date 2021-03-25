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

ll a,b,x,y;
cin>>a>>b>>x>>y;
ll n;
cin>>n;




if( a== b){
	
	if( x>y){
		swap(x,y);
	}
	
}
else{
	
	
	int tmp1 = max(a - n , x);
	int tmp2 =   max( b-n  , y) ;
	
	if( tmp1 >= tmp2){
		
		swap(a,b);
		swap(x,y);		
		
	}
	
	
}



int tmp =min( n , abs(x-a ));

a-= tmp;
n -= tmp;

if( n> 0){
	b -= min(n , b-y);
}

cout<<a*b<<endl;






return 0;

}






int main(){
 quick;
int t =1; 
cin>>t;
while(t-- )
 Main();

 return 0;


}
