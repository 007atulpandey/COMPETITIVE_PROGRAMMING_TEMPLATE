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
#define ook order_of_key
#define fbo find_by_order 
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end() 
#define mod 1000000007
#define tot_time cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
//#define maxx 200006
#define fixed cout<<fixed<<setprecision(14);
#define ll long long 
#define quick    ios_base::sync_with_stdio(NULL),cin.tie(0), cout.tie( 0 );
#define listll vector< long long > 
#define listi vector< int> 
#define pii   pair<int , int> 
#define pll pair<long long , long long > 
#define minheap priority_queue<long long , vector< long long >, greater<long long > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define memo(a,x ) memset( a, x ,sizeof ( a) )
#define randoms mt19937 rng(26);

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





int bucket= 700 ;


struct Query {
    int left, right, idx;
 
    bool operator < (const Query other)  {
        return right < other.right;
    }
};



ll res  ; 

ll  mp [ 1000010] ;
void add (ll a ) {
	
	
	if( mp[a] == 0) {
		res +=1 ;
	}
	mp[a ] +=1 ;
	 
  	
}


void rem ( ll a ){
	
	 if( mp[a] ==1 ) 
	 res -=1 ;
	 
	 
	 mp[a] -=1 ;
	 
}








 int Main(){
        res =0 ;		
		int n ;
		for( int i =0 ;i < 1000010 ;i++)
		mp[i ] =0; 
		cin>>n;
		
		vector < int > arr ( n+1 ) ;
		for( int i=1;i<=n;i++)
		cin>>arr[ i] ;
		int m ;
		cin>>m;
		
		int t = n /bucket +2 ;
		vector< vector< Query> >  q (  t , vector< Query > ()) ;
		for( int i =0; i <m ;i++) {
			 
			 int l ,r ;
			 cin>>l>>r;
			  r++;
			 int bc = (l-1) /bucket;
			 q[ bc ].push_back( Query { l ,r, i} ); 
		}
		vector< ll>ans ( m ) ;
		for( auto &it : q )
		sort( it.begin (), it.end()) ;
		
		for( int  i= 0 ; i <  t ;i++) {
			
			if( q[ i].size() ==0 )
			continue ;
			int l  ,r ;
			l = i*bucket , r = i*bucket ;
		    
		    for( auto &it : q[ i] ){
				
				int left = it.left , right = it.right , idx= it.idx ;
				
			while (r < right) {
                add(arr[r]);
                r++;
            }
            while (l < left) {
                rem(arr[l]);
                l++;
            }
            while (l > left) {
                l--;
                add(arr[l]);
            }
				
				
				ans [ idx ] = res ;  
				
				
			}
			
			res =0 ;
			
			for( int j =l ;j < r ; j++) {
				mp[ arr[ j] ] =0 ;
			}
			
			
		}
		
		for(auto it : ans )
		cout<<it<<endl;
		
		
		
		tot_time ;



  
return 0;

}






int main(){
 quick;

  //#ifndef ONLINE_JUDGE
  //freopen ("outt.txt", "r", stdin);
  //freopen ("outt.txt", "w", stdout);
//#endif

int t =1; 
//cin>>t;
while(t-- )
 Main();

 return 0;
}


  


