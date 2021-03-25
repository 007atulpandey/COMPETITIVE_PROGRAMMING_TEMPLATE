class Point {
	
    public:  
    ll x ,y ;
    
    Point( ) {
		x =0 , y =0 ;
	}
    Point( ll  x, ll y ) {
		x = x ;
		y = y ;
	}
	
	
	
	Point operator + ( Point const &P) {
		Point temp ; 
		temp.x = x + P.x ;
		temp.y = y + P.y ;
		return temp; 
	}
    	
    ll operator * ( Point const & P) {
		
		return ( x*P.y - y*P.x) ;
		
	}
	
	Point operator - ( Point const &P ){
		
		Point temp ;
		temp.x = x - P.x;
		temp.y = y - P.y ;
		return temp ;
		
	}
	
	
	
	
};
