struct segment {
	
	ll sum =0, pre =0 , suf = 0, mx= -oo;	
  	
};
vector< segment> seg( 1<<20) ;

void update( int l, int r ,  int i  ,int val , int x =1 ) {
	 if ( l > r ) {
		 return ;
	 }
	 if( l == r  ) {
		 seg[ x].sum = val;
		 seg[ x].pre= val ;
		 seg[ x] .suf = val ;
		 seg[ x].mx = val;
		 return ;
	 }
	 int mid = (l+r ) /2 ;
	 if (i<=mid )
	 update(l , mid , i , val ,2*x );
	 else 
	 update(mid + 1 , r ,i ,val ,2*x+1 ) ;
  	 
  	 
  	 seg[ x]= {seg[ 2*x].sum + seg[ 2*x+1].sum ,
		  max(seg[ 2*x].pre , seg[ 2*x].sum +seg[ 2*x+1].pre ),
		   max(seg[ 2*x].suf + seg[ 2*x+1].sum ,seg[ 2*x+1].suf ),
		    seg[x].mx
		 		   };
	 seg[ x ].mx = max({seg[x].mx ,seg[x].sum , seg[ x].pre , seg[ x].suf });
  	
} 
array< ll , 4>  qry_mx_seg( int l , int r, int lf ,int  tr,  int x= 1 ){
	
	if (l > r)
	return  { 0 ,0, 0,-oo} ;
	
	if ( r<lf || tr < l ){
		return  { 0 ,0 ,0 , -oo } ;
	} 
	if ( lf<=l &&tr >=r ) 
	return  { seg[ x].sum , seg[ x].pre , seg[ x].suf , seg[ x].mx } ;
	int mid = ( l +r )/2 ;
	array< ll ,4 > left = qry_mx_seg ( l , mid , lf ,tr ,2*x) ;
	array< ll ,4 > right = qry_mx_seg ( mid +1 , r , lf ,tr, 2*x +1 );
	
	
	return  { left[ 0] + right[ 0] , max(left[0]+right[ 1] , left[ 1] ), max(left[ 2]+right[ 0] ,right [ 2 ] ), 
		
		max({ left[3] ,right[3] , left[ 0] + right[ 0] , max(left[0]+right[ 1] , left[ 1] ), max(left[ 2]+right[ 0] ,right [ 2 ] )  })
		
		}; 
	
}
