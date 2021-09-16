import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;


public class B {

	/*
	 * Atul pandey 0826
	 * 
	 */

	static segtree seg [ ] = new segtree[800001];
	public static void main(String[] args) {
  		
	 FastScanner fs = new FastScanner();
	 int n = fs.nextInt();
	 int []arr= fs.readArray(n);
	 
	 int m = fs.nextInt();
	 ArrayList < query> qry = new ArrayList<query >();
	 
	 for( int i =0;i < m ;i ++) {
		 int l = fs.nextInt();
		 int r = fs.nextInt() ;
		 qry.add(new query(l,r,i));
	 }
	 Collections.sort(qry, new Comparator< query > (){
		 @Override 
		 public int compare ( query a  , query b) {
			 if ( a.r <=b.r )
				 return -1 ;
			 return 1 ;
		 }
	 }); 
	 
	 for ( int i = 0 ;i <800001; i ++) {
		 seg[i] = new segtree();
	 }
	 int vis []= new int [n+2 ];
	 for ( int i = 0;i < n+2 ;i ++)
		 vis [i] = 0 ;
	 int id = -1 ;
	 int st[] = new int [n +2 ];
	 int top = 0 ;
	 for (int i =0; i <n +2 ; i ++) {
		 st[i] =-1 ;
	 }
	 vis[0] =1 ;
	 long res [] = new long [m]; 
	 for( int i =0; i < m ; i++) {
		 
		 while ( id < qry.get(i).r-1){
			 id ++;
			 if ( top ==0  ) {
				 st[top +1 ] = id ;
				 top ++ ;
				 continue ;
			 }
			 if ( arr[st[top] ] > arr[id]){
				  st[top +1 ] = id ;
				  top +=1 ;
			 }
			 else {
				 while (top > 0&& ( arr[st[top]] <=arr[id] ) ){
					 top -=1 ;
				 }
				 st[top +1 ] = id ;
				 top +=1 ;
			 }
		 }
		 
		 int tmp = top ;
		 while ( vis [ st[tmp]+1 ] ==0 ){
			 int r = st[tmp];
			 int l = st[tmp-1];
			 update(1 , 0,  n -1 , l +1 , r , arr[r]);
			 vis [r+1 ] =1 ;
			 tmp -=1;
		 }
		 
		 long ans = rangeSum ( 1 , 0 , n -1 , qry.get(i).l -1 , qry.get(i).r -1 );
		 res [ qry.get(i).idx] = ans ;
		 
	 }
	 
	 for( int i =0; i < m;i ++)
		 System.out.println(res[i]);
	 
	}

	public static class query {
		public int l ,r ,idx;
		
		query( int l , int r , int idx ){
			this.l = l ;
			this.r = r ;
			this.idx = idx ;
		}
	} 

	public static class segtree { 
		public long sum  , lazy ; 
		segtree(){
			this.lazy= 0 ;
			this.sum =0 ;
			
		}
	};
	
	static void pull ( int x ,int l , int r ){
		if ( l > r )
			return ; 
		
		int mid = (l +r)/2 ;
		seg[2*x].sum = Math.max( ( long ) (mid - l +1 )* seg[x].lazy , seg[2*x].sum); 
		seg[2*x+1].sum = Math.max( ( long ) ( r- mid )* seg[x].lazy , seg[2*x+1].sum);

		seg[2*x].lazy =  Math.max(seg[2*x].lazy,seg[x].lazy) ; 
		seg[2*x+1 ].lazy =  Math.max(seg[2*x+1 ].lazy,seg[x].lazy) ; 
		seg[x].lazy =0 ;
		return ;
	}
	
	static void update ( int x , int l , int  r, int lf,  int rt , int val){
		if (l > r ||  lf >r || rt <l ){
			return;
		}
		
		if ( lf <= l && rt >= r ) {
			seg[x].lazy = val;
			seg[x].sum = (long )val *(r-l +1 ) ;
			return; 
		}
		
		int mid = ( l +r )/2 ;
		pull(x , l , r );
		update ( 2 *x , l , mid , lf , rt , val);
		update( 2 *x +1 , mid +1 , r , lf  , rt , val );
		seg[x].sum = seg[x*2 ].sum + seg[2*x+1 ] .sum;
	}
	
	static long rangeSum ( int x , int l ,int r , int lf , int rt  ) {
		
		if (l > r ||  lf >r || rt <l ){
			return 0L;
		}
		
		if ( lf <= l && rt >= r ) {
			return seg[x].sum; 
		}
		int mid = ( l +r )/2 ;
		pull (x , l , r );
		long left = rangeSum (2*x , l , mid , lf , rt );
		long right = rangeSum( 2 *x+1 , mid +1 ,r , lf ,rt );
		
		return left+ right;
		
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		}


}
//fun main(args: Array<String>) {
//    Main.main(args);
//}
