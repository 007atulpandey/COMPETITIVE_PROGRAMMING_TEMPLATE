#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

// Picasso didn't learn to paint by watching lectures





// question url 
// https://www.codechef.com/problems/TRTOKENS


/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/

 
using namespace std;
using namespace __gnu_pbds;

// #define  part ..
#define ook order_of_key
#define fbo find_by_order 
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end() 
#define mod 1000000007
#define tot_time cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
//#define maxx 200006
#define fixed cout<<fixed<<setprecision(14);
#define ll long long 
#define quick    ios_base::sync_with_stdio(NULL),cin.tie(0);
#define listll vector< long long > 
#define listi vector< int> 
#define pii   pair<int , int> 
#define pll pair<long long , long long > 
#define minheap priority_queue<long long , vector< long long >, greater<long long > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define memo(a,x ) memset( a, x ,sizeof ( a) )
#define randoms mt19937 rng(26);

const long long oo = 1e18;
double PI = 3.14159265358979323846; 


template  < class  T >
vector< T > readvector  ( T  n ) {  vector < T > arr(n ) ;
	    for( int  i =0; i < n ; i ++ ) cin>>arr[i] ;
		return arr; }


ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

ll power( ll a, ll n, ll m= 1000000007){
  ll ans = 1;
  while(n){
  if(n&1)
  {
  ans *= a;
  ans%=m;
  }
  a*=a;
  a%=m;
  n/=2;
  }
  return ans ;
} 


vector< int > prm ;
vector < bool > vsp ;

void prime ( int nn = 100000 ) {
	vsp = vector < bool > ( nn+1, 0 );
	int size_prime = nn;
	for( ll i =2; i*i < size_prime ; i++){
		
		if( vsp[i] == 1)
		continue;
		for(ll j = i*i; j < size_prime ;j+=i){
			
			vsp[j] =1;
			
		}
		
		
	}
	
	for( int i= 2; i < size_prime ; i++)
	if (vsp[i] == 0)
	prm.pb(i);
	
	
}


//auto comparator = [] ( array < ll ,2 >  &a  , array < ll , 2  > &b ) {  return ( a[0] < b[0 ] || (a[ 0] == b[ 0] && a[1]  > b[1] ) ) ; } ; 

//priority_queue< array <  ll  , 2> , vector< array< ll ,2 > > , decltype( comparator )  > pq ( comparator);







template < class T > using oset = tree< T , null_type, less  < T  > , rb_tree_tag , tree_order_statistics_node_update > ;
// oset< int > tree ; 
// tree.ook ( val  )  return index of element ;
// tree.fbo ( idx )   return pointer at the element .




// end of #define 

// define globals ...
const int maxx = 2e5+26;

//write function from here ...
// never forget  to recheck your predefined function in template .. 
// already defined ::  prime , power , gcd : ( ll ).. 


vector< array < int ,2 >  > segtree;

void update ( ll l , ll r , ll x , ll idx , ll val  ){
   	
   	if( r < idx || l > idx ){
		return ; 
	}
	if ( l ==r ) {
		segtree[ x ] = {val, idx}  ;
		return ;
	}
	
	int mid = ( l +r )/2 ;
	if ( mid >=idx ) {
		update(l, mid ,2*x, idx ,val);
	}
	else {
		update(mid+1, r, 2*x+1 ,idx , val);
	}
	if ( segtree[ 2*x][ 0] > segtree[ 2*x+1] [ 0]) {
		segtree[ x] = segtree[ 2*x ] ;
	} 
	else 
	segtree[x] = segtree[ 2*x+1] ;
	
}

array< int , 2 >  qry (ll l , ll r , ll lf,ll rt , ll x ){
    
    if ( l > r )return { 0, -1} ;
    if ( r<lf || l >rt ){
	  return {0, -1 };
	}
	if ( lf<=l && r<=rt ) {
		
		return segtree[ x] ;
	}
		
	int mid = ( l + r ) /2 ;
    array < int ,2 >  ans1 = qry(l ,mid, lf,rt,2*x);
    array < int ,2 > ans2 = qry(mid+1, r , lf ,rt , 2*x+1 );
	return max( ans1, ans2) ;
}




int Main(){

   
    int n ;
    //cin>>n;
    scanf("%d",&n);
    char s [ n ] ;
    //cin>>s;
    scanf("%s",s);
    
    vector< listi> adj ( n) ;
    segtree  = vector< array < int ,2 > > (  4 *n); 
    for( int i = 1; i <n ;i ++){
		
		int a ;
		scanf("%d",&a);
		a -- ;
		adj [ a].pb ( i );
	}
    
	vector< int > h( n ) , intime( n ) , out( n ); 
	int tim =0 ;
	int cnt [ 2*n] ;
	
	ll ans =0 ;
	function < void ( int , int ) > dfs2 = [ &] ( int u , int v ) {
		intime [u] = tim ;
		 cnt[ tim ] =  u; 
		 tim ++; 
		for( int a :adj [ u ] ){
			
			if ( a == v) {
				continue ;
			}
			h[ a ] = h[ u] +1 ;
			dfs2( a , u ) ;
		}
		out[ u] = tim -1  ; 
		if ( s[ u ] %2){
			update(0,n-1,1,intime[ u],h[ u] ) ;
	    }
		if ( s[ u] %2 ==0 ){
				
				array < int ,2 > tmp = qry( 0, n-1,intime[ u],out[u],1);
				//cout<<tmp[0]<<" " <<tmp[1]<<" " <<u<<endl;
				if (  tmp [0] > 0 ){
					int ver  = cnt [ tmp [1] ] ;
					ans += max(0,tmp[0]- h[ u])  ;
					s[ ver] ='0';
					s[ u ] ='1';
					update(0,n-1,1,intime[u],h[u]);
					update(0,n-1,1,tmp[1],0);
				} 
								
			}
		
	};
	
	dfs2(0,0);
	printf("%lld\n",max(0LL,ans));
	
	
  
return 0;

}






int main(){
 quick;

  //#ifndef ONLINE_JUDGE
  //freopen ("input.txt", "r", stdin);
  //freopen ("outt.txt", "w", stdout);
//#endif

int t =1; 
//cin>>t;
scanf("%d",&t);
while(t-- )
 Main();

 return 0;
}


  


