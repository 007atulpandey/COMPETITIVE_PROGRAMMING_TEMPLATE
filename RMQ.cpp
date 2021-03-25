
const int s_rmq =21 ;
ll rmq[ maxx ][ s_rmq ] ;

template < typename T > 
void create_rmq( vector < T > &  arr ){
	int n = arr.size(); 
	for( int i =0;i < n;i++ ){
		rmq[ i][0] = arr[ i ] ;		
	}	
	for( int i = 1 ; i < s_rmq ; i++) {
		
		for( int  j =0;  j +( 1<<(i ) )<n ;j++){
			rmq [ j][i ] = min ( rmq [j][ i-1 ] , rmq[j+( 1<<( i-1 ))][i-1 ] ) ; 
		}
		
	}
	
}


ll rmq_qry( int a, int b ){
	
	ll ans = LLONG_MAX ;
	
	for( int i = s_rmq -1 ;i>=0 ;i--){
		if( a+ ( 1<<i) <= b+1){
			ans = min ( ans , rmq[ a][ i]) ;
			a = a+(1<<i) ;
		}		
	}
	 
	return ans ;
}






