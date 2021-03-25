

// you can implement 
// 1. prop  2. range_sum  
struct Treap{
    
    int data , weight ,size;
    Treap *left , *right;
    Treap( int val ){
        
        left = right = NULL;
        weight = rand();
        data = val ;
        size= 1 ;
    }
    
};

int size(Treap * node ){
    
    return ( node == NULL ? 0 : node->size) ;    
}

void split( Treap *treap ,Treap *&left , Treap*&right , int key ){
     
     if( treap ==NULL) {
         left = right = NULL;
     }
     else{
         
         if( size( treap->left ) <key) {
             split( treap->right , treap->right , right, 
             key - size(treap->left)-1 
             ) ;
             left = treap;
             
         }
         else{
             
             split( treap->left , left , treap->left, key) ;
             right = treap;
         }
         treap->size = ( size( treap->left) +size( treap->right) +1 );
         
     }    
}

void merge( Treap *&treap , Treap *left , Treap *right ){
     
     if( left == NULL)
     treap = right;
     else if( right ==NULL)
     treap = left ;
     else{
         
         if( left ->weight <right->weight ) {
             merge( left->right , left ->right , right );
             treap = left ;
         }
         else{
             merge ( right->left , left , right ->left );
             treap= right ;
         }
        
        treap->size = size(treap->left ) + size( treap->right) +1 ;
         
     } 
      
}

// some info regarding to the function use .. 
/*
*      Treap *l1 ,*r1 , *l2 , *r2 ;
//     o   o   o   o   o   o   o   o   o   o 
//     | ---- l1 --|   |----   r1 -------- |
*   // |-l2-| |-r2-|
*      split(root , l1, r1, r+1);
*      split( l1 ,l2,r2 , l );
*      Treap * temp =NULL; 
*      merge (temp, r2 , l2 );
*      merge( root, temp, r1 ) ; 
*
*/



// just to print the output of the whole transformation .. Use inorder .... 


vector < int > ans ;
void inorder( Treap * root ){
   
   if( root == NULL) {
       return ;
   }    
   
   inorder( root ->left ) ;
   //cout<<root->data<<" ";
   ans.pb( root->data ) ;
   inorder( root->right ) ;
    
    
}
