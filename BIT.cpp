
// binary index tree .. 
void upd_bit( int idx , ll val ,  vector < ll >& bt  ) {
	 int n = bt.size(); 
	 for( ++idx ; idx < n ; idx += ( idx &( -idx)) ) {
		 bt[ idx ] += val ;
	 }
  
}

ll qry ( int idx  , vector < ll> &bt   ) {
	   
	   ll ans = 0 ;
	   for(  ++idx ; ~(idx -1); idx-=( idx &( -idx)) ) {
		   ans += bt[ idx] ;
	   }
	return ans ;
	}

