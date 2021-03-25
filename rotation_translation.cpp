		auto oper1 = [&] ( ){
			
			vector< vector< ll > >  temp  ( 3 , vector< ll > (3, 0LL )) ;
			temp[ 2][2]=1 ;
			temp [ 0][1]  =1 ;
			temp [ 1][0] = -1 ;
			
			iden = matrix_multiplication( temp  , iden ) ;
			 
			
		};
			auto oper2 = [&] ( ){
			
			vector< vector< ll > >  temp  ( 3 , vector< ll > (3, 0LL)) ;
			temp[ 2][2]=1 ;
			temp [ 0][1]  =-1 ;
			temp [ 1][0] = 1 ;
			
			iden = matrix_multiplication(  temp  ,iden) ;
			 
			
		};
		
		auto oper3 = [&] ( ll p ){
			
			vector< vector< ll > >  temp ( 3 , vector< ll > (3, 0LL )) ;
			temp[ 2][2]=1 ;
			temp[ 0] [ 0] = -1 ;
			temp [ 1][1] =1 ;
			temp[ 0][2] = 2*p;
			iden = matrix_multiplication( temp , iden) ;
		};
			auto oper4 = [&] (ll p ){
			
			vector< vector< ll > >  temp ( 3 , vector< ll > (3, 0LL )) ;
			temp[ 2][2]=1 ;
			temp[ 1 ][1] = -1 ;
			temp [ 0][0] =1 ;
			temp [ 1][2 ] = 2*p ;
			iden = matrix_multiplication( temp ,iden ) ;
			 
			
		};
