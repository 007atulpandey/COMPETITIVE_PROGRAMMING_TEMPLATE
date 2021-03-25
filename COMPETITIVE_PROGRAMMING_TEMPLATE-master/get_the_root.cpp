
int get_root ( int  size) {
	int nn = size; 
	queue< int > q;
	for( int i =  0  ; i <nn ;i++) {
		if(adj[ i]. size() == 1) {
			q.push( i ) ;
		}
	}
	vector< bool > vis ( nn , false  ) ;
	
	
	while( q.size()> 1 ) {
		
		int a = q.front ();
		q.pop();
		if( vis [ a]  == true  ) 
		continue ;
		vis [ a] = 1 ; 
		for( auto it : adj [ a]  ) {
			if( vis [ it ] == true ) {
				continue ;
			}			
			q.push( it) ;
		}		
		
	}
	 
	 
	 return q.front (); 
	

}

