  int n ;
  cin>>n;
  int m ;
  cin >>m;
  
  
  vector<  vector< array < int ,2 >  >  >  adj( n  ) ;
  for( int i = 0 ;i < m ;   i ++) 
  {
	  int a,b;
	  cin>>a>>b;
	  a -- , b-- ;
	   int w ;
	   cin>>w;
	   
	  adj[ a] . push_back ( { b, w } );
	  adj[ b].push_back( { a, w} ) ;
	  
	  
  }
   
  vector<  ll > dis ( n+1 , LLONG_MAX) ;
  
  priority_queue <  array < ll ,2 >  , vector< array < ll ,2 > >  , greater  < array < ll ,2  >  > > pq ;
  pq.push( { 0,0}) ;
  vector< bool > vis (n +1 , 0 ) ;
  while( pq.size() >0 ) {
	  array  < ll , 2> temp = pq.top ();
	  pq.pop();
	  if( vis[ temp[1]] == 1)
	  continue ;
	   
	  int u = temp[ 1 ] ;
	  int w = temp[ 0 ];
	  dis[ u] = w ; 
	  vis[ u ] = 1 ; 
	  
	  for( auto it: adj[ u ]) {
		  
		  if( dis[ it[ 0]] > dis[ u ] + it[1 ]  && vis[ it [ 0 ]] == 0 ) {
			  pq.push( { dis[ u ] + it [1 ] , it[0 ]});
			  
		  }
		  
		  
	  }
	  
  }
  
  for( int i =0 ; i < n;i++){
	  cout<<dis[ i] <<" \n"[ i==n-1] ;
  }
  
