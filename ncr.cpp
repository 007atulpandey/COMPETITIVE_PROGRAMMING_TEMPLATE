// working ....
vector < ll > fact , inv  ;

void factorial( ll  n ,ll  md   ){
	fact = vector < ll > ( n+1 , 1 );
	for(  ll i =2 ; i <= n ;i++){
		fact[i] =fact[i-1]*i;
		fact[i]%=md;
		
	}
		
}


void invi( ll n , ll md ){
	
	inv = vector < ll > ( n+1 , 1 );
	 inv[n] = power( fact[n] , md-2 ,md);
	 
	for( ll i =n-1 ; i >0 ;i-- ) {
		inv [i] = inv[i+1]*(i+1)%md;
		inv[i] %= md ;
		
	}
	
	
}

ll ncr ( ll n , ll r , ll md ){
	if( n < r)
	return 0 ;
	if( n <0 || r < 0)
	return  0; 
	
	return  (fact[n]%md*((inv[n-r]*inv[r])%md ) %md );
	
} 
