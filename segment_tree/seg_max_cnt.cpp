
struct segment {
	
	ll mx = -oo  , cnt =0;	
  	
};
vector< segment> seg( 1<<20) ;

void update( int l, int r ,  int i  ,int val , int x =1 ) {
	 if ( l > r ) {
		 return ;
	 }
	 if( l == r  ) {
		 seg[ x ].mx = val ;
		 seg[ x].cnt = 1 ;
		 return ;
	 }
	 int mid = (l+r ) /2 ;
	 if (i<=mid )
	 update(l , mid , i , val ,2*x );
	 else 
	 update(mid + 1 , r ,i ,val ,2*x+1 ) ;
  	 
  	 if ( seg[ 2*x].mx ==seg[ 2*x+1 ].mx){
		 seg[ x ].mx = seg[ 2*x].mx ;
		 seg[ x].cnt= seg[ 2*x].cnt + seg[ 2*x+1].cnt; 
	 }
	 else {
		 if ( seg[ 2*x].mx > seg[ 2*x +1 ].mx) {
			 seg [x ]= seg[ 2*x] ; 
		 }
		 else {
			 seg[x] = seg[ 2*x +1 ] ;
			 
		 }
	 }
  	
} 

array < ll ,2 > qry ( int l , int r, int lf ,int  tr,  int x= 1 ){
	
	if (l > r)
	return { - oo, -1LL };
	
	if ( r<lf || tr < l ){
		return { -oo, -1LL };
	} 
	if ( lf<=l &&tr >=r ) 
	return  { seg[ x].mx , seg[ x].cnt };
	int mid = ( l +r )/2 ;
	array< ll ,2 > left = qry ( l , mid , lf ,tr ,2*x) ;
	array< ll ,2 > right = qry ( mid +1 , r , lf ,tr, 2*x +1 );
	
	if (left[ 0] !=-oo && left[0] == right[ 0] ){
		return { left[ 0 ] , left [1 ]+ right [1 ] };
	}
	if ( left [ 0] == -oo && right[0] == -oo)
	{
		return { -oo, -1 };
	}
	if (left[ 0 ] > right [ 0 ] ){
		return left;
	}
	
	return right ;
	
}

