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


ll power( ll a,ll n){
	
	ll ans = 1;
	while(n){
		
		if( n&1){
			
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		n/=2;
	}
	
	return ans;
	
	
}


ll get_hash(string  s){
	
	
	const int p = 31 ;
	const int m = 1e9+7;
	
	ll hash = 0 ;
	ll pow = 1;
	for(auto c: s){
		
		hash = (hash+ pow*(c-'a'+1))%m;
		pow*=p;
		pow%=m;
		
		
		
	}
	//cout<<"hellloooo "<<hash<<endl;
	return hash;
	
}


vector <int > count_(string const& s , ll hash , int l) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 7;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
         //cout<<h[i+1]<<" ";
	}

  
       vector < int  >ans ;
   
   
     //cout<<"HAHSE\n";
        for (int i = 0; i <= n - l; i++) {
			
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * ( i==0 ?1:  power(p_pow[i] ,m-2)  ) ) % m;
            
            //cout<<cur_h<<" ";
            if(cur_h == hash){
				
				ans.pb(i);
			}
            
        }
        //cout<<endl;
        
   return ans ;
    
}



int Main(){


int n;
cin>>n;
string  s;
cin>>s;

ll hash = get_hash( s);

cout<<hash<<endl;
string t;
cin>>t;

vector <int > ans = count_(t , hash, n);

for(auto it : ans){
	cout<<it<<"\n";
}
if(ans.size()==0)
cout<<endl;




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
