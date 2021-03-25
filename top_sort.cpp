
vector< int > top_sort ( vector< vector< int > >  adj ) {
      int n = adj.size();
      vector< int > indegree (n+1, 0 ) ;
      for( auto it : adj ){
		  for( auto itr : it ) {
			  indegree[ itr ] +=1 ;
		  }
		  
	  }
	  
	  queue < int > q ;
	  
	  for( int i =0 ; i < n ; i ++) 
	  if( indegree[ i ] == 0 )
	  q.push( i ) ;  
	  vector< bool > vis ( n+1 , false ) ;
	  vector< int > ans ; 
	  while(q.size() ) {
		  int a;
		  a = q.front();
		  q.pop() ;
		  cout<<a<<endl;
		  if( vis[ a] )continue ;
		  vis[ a] =1 ;
		  ans .pb(a);
		  for( int i : adj[ a]) {
			  if( vis[ i] ) 
			  continue ;
			  q.push( i) ;
			  indegree[ i] -=1 ;
		  }		  
	  } 
	  
	  return ans ;
	
}
