#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

// Picasso didn't learn to paint by watching lectures




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







int Main(){
   
   ll f , aa , n , m ;
   cin>>aa>>f >> n >>m;
   
   int st , end ;
   vector< array< int , 2 >  > points ;
   string s[ n];
   for( int i =0; i < n; i ++){
	   
	   cin>>s[ i] ;
	   for( int j =0; j <m ;j++){
		   
		   if ( s[ i][  j ] =='S'){
			   
			   st = points.size();
			    points.push_back( { i , j }) ;
			  
		   }
		   if ( s[ i] [ j] =='G')
		   {
			   end = points.size();
			    points.push_back( { i , j }) ;
			  
		   } 
		   
		   if ( s[ i] [ j ] == 'W')
		   points.push_back( { i , j }) ;
		   
		   
	   }
	   
   }
    
    int cnt = points.size();
    queue < int > q ;
    ll dis [ cnt +1  ] ;
    for( int i =0; i <= cnt ; i++)
     dis [ i] = -1e12 ;
   dis [ st] = 0 ;
   q.push( st) ;
   while (q.size()){
	   
	   int a= q.front ( );
	   q.pop();
	   for(int i=0; i < cnt ; i++){
		   
		   if ( dis[i]  == -1e12 && ( ( (ll)(points[i][0]  - points[ a][0])*(ll)(points[i][0]  - points[ a][0])  )  + (ll)(points[i][1]  - points[ a][1])*(ll)(points[i][1]  - points[ a][1]  ) ) <=aa*aa ){
			   
			   dis[ i]  = dis [a] +1 ;
			   q.push( i ) ;
			   
		   }   
	   }
   }


    queue < int > qr ;
    ll disf  [ cnt +1  ] ;
    for( int i =0; i <= cnt ; i++)
     disf [ i] = -1e12 ;
   disf [ st] = 0 ;
   qr.push( st) ;
   while (qr.size()){
	   
	   int a= qr.front ( );
	   //cout<<a<<endl;
	   qr.pop();
	   for(int i=0; i < cnt ; i++){
		   
		   if ( disf[i]  == -1e12  && ( ( abs( points[i][0] - points[a ][ 0] )<= f  &&  points[ i][1] ==points[a] [1]    ) ||( abs( points[i][1] - points[a ][ 1] )<= f  &&  points[ i][0] ==points[a] [0]   ) )){
			   
			   disf[ i]  = disf [a] +1 ;
			   //cout<<i<<endl;
			   
			   qr.push( i ) ;
			   
		   }   
	   }
   }   
   
   if ( disf[ end ]==-1e12) disf[ end] = LLONG_MAX ; 
   if ( dis [ end ] == -1e12 ) dis[  end ] = LLONG_MAX ;
   
   //cout<<dis[ end ] <<" " <<disf [ end] <<endl;
   if (disf[end] == LLONG_MAX && dis[ end] ==LLONG_MAX ) {
	   
	   cout<<"NO WAY\n";
   }
   else if (disf [ end ] < dis [ end ] ) {
	   
	   cout<<"NO CHANCE\n";
	   
	   
   }
   else if ( dis[end ] < disf[ end]){
	   
	   cout<<"GO FOR IT\n";
   }
   else {
	   cout<<"SUCCESS\n";
   }
   
    
	
  
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
while(t-- )
 Main();

 return 0;
}


  


