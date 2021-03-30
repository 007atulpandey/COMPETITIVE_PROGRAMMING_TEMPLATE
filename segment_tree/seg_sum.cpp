
vector< ll > seg ( 1<<20) , lazy( 1<<20) ;


void prop( int x ) {
	
	lazy[ 2 *x ] = lazy[ x] ;
	lazy[ 2*x+1 ] = lazy[ x ] ;
	lazy[ x] = 0 ; 
	
}

void update(int l , int r ,int i ,  int val , int x =1  ) {
	
	if ( r < l   )
	return ;
	if ( l == r){
		seg[ x] = val ;
		return ; 
	} 
	
	int mid = ( l +r) /2 ;
	if (mid <i){
		update( mid+1 ,r, i , val , 2*x +1  ) ;
    }
    else{
		update( l , mid , i ,val , 2*x );
    }  
	seg[ x] = seg[ 2*x] + seg[ 2*x +1 ] ; 
	
}
void update_in_range(int l , int r , int lf, int tr ,  int val , int x = 1) {
   
   if ( lf<=l && tr >=r){
	   
	   lazy[ x] = val;
	   return ;
   }
   
   
	
}



ll qry_sum_range(int l ,int r , int lf , int tr, int x = 1  ) {
	
	if (r < l )
	return 0 ;
	if (r < lf || l >tr )
	return 0 ;
	if (lf<=l &&tr>=r){
		return seg[x];
	}
	prop(x ) ;
	ll ans =0 ;
	
	int mid = (l + r )/2 ;
	ans += qry_sum_range(l , mid , lf , tr, 2*x) ;
	ans += qry_sum_range(mid +1 , r , lf ,tr,2*x+1);
	
	return ans ;
	
}

