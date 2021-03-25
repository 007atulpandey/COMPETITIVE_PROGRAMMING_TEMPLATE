// diameter ( adj );
// dia_a = diameter_first_end ;
// diameter_tot = diameter_of_tree......

int dia_a  , diameter_tot; 
void dia_dfs( int u , int par ,  int dis  , vector< vector< int  > > adj  ) {
	 
	 
	 if( dis > diameter_tot) {
		 diameter_tot = dis;
		 dia_a = u ;
	 }
	 for( auto it : adj[ u ] ){
		 
		 if( it == par  )
		 continue ;
		 
		 dia_dfs( it  , u , dis+1  , adj  );
		 
	 }
     
}

int diameter ( vector< vector< int > > adj , int n ){
	diameter_tot = 0 ;
	
	dia_dfs( 0 , 0 , 0 ,adj) ;
	int a= dia_a;
	diameter_tot = 0 ;
    dia_dfs( a, a , 0 ,adj) ;
	
	return diameter_tot ;
	  
  	
}
