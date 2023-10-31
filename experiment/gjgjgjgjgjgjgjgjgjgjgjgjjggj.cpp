#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x) , end(x) 
#define mask(i) (1LL << (i))
const int mod = pow(10,9)+7 ;
const int MAX = pow(10,5)+1 ;
const int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 } ;
const int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 } ;
int mod_pow( int a , int b )
{
    if( a == 0 || a == 1 ) return a ;
    if( b == 0 )return 1 ;
    int ha = mod_pow( a , b/2 ); ha *= ha; ha %= mod ; if( b&1 ) ha *= a ;
    return ha%mod ;
}
int inverse( int a )
{
    return mod_pow(a,mod-2);
}
vector<int> factorial( int N = MAX )
{
    vector<int>f(N,1);
    for( int i = 2 ; i < N ; i++ )f[i] = (i*f[i-1])%mod;
    return f ;
}


class T {
public:
    int st, en;
    int value;
    T *left  = nullptr ; 
    T *right = nullptr ;
    int lazy = 0 ;

    T(int st_, int en_){
        this->st = st_ ; 
        this->en = en_ ;
    }
};

class SegmentTree {


public:
    SegmentTree(const vector<int>& arr) {
        root = build(0, arr.size() - 1, arr);
    }
    void update(int l, int r, int del) {
        update(root, l, r, del);
    }

    int get(int l, int r) {
        return query(root, l, r);
    }


private:
    T *root;

    T* build(int st, int en, const vector<int>& arr) 
    { 
        if (st > en) return nullptr;
        
        T* node = new T(st, en);

        if (st == en) 
            node->value = arr[st];
        else {
            int mid = (st + en) / 2;
            node->left = build(st, mid, arr);
            node->right = build(mid + 1, en, arr);
            pull(node);
        }
        return node;
    }

    void update(T* node, int l , int r , int del) 
    {
        if (node == nullptr || l > node->en || r < node->st) {
            return;
        }

        if (l <= node->st && node->en <= r ) 
        {
            node->lazy += del;
            push(node);
        }
        else 
        {
            push(node);
            update(node->left, l, r, del);
            update(node->right, l, r, del);
            pull(node);
        }
    }    

    int query(T* node, int l, int r) 
    {
        push(node);
        if (node == nullptr || l > node->en || r < node->st) {
            return 0;
        }
        if (l <= node->st && node->en <= r) {
            return node->value;
        }
        int leftValue = query(node->left, l, r);
        int rightValue = query(node->right, l, r);

        return leftValue + rightValue;
    }


    void push(T* node) {
        if ( node && node->lazy != 0) {

            node->value += node->lazy * (node->en - node->st + 1);

            if (node->left )  node->left->lazy += node->lazy;
            if (node->right) node->right->lazy += node->lazy;

            node->lazy = 0;
        }
    }

    void pull( T * node ){
        node->value = node->left->value + node->right->value ;
    }

};


void go()
{
    int N ; cin>>N ;
    vector<int>A(N); 

    SegmentTree T2(A),T3(A),T5(A);

    for( auto &x : A )cin>>x ;
    int Q ; cin>>Q ;

    while(Q--)
    {
        int t , l , r , p ;

        cin>>t;

        if( t == 1 )
        {
            cin>>l>>r>>p;

            l--;
            r--; 

            if( p == 2 )
            {
                T2.update( l , r , 1 );
            }
            else if( p == 3 )
            {
                T3.update( l , r , 1 );
            }
            else 
            {
                T5.update( l , r , 1 );
            }
        }
        else
        {
            int k ; int d ;

            cin>>k>>d ;
            k--;
            
            int a = T2.get(k,k);
            int b = T3.get(k,k);
            int c = T5.get(k,k);

            T2.update(k,k,-a);
            T3.update(k,k,-b);
            T5.update(k,k,-c);
            A[k] = d ;
        }
    }
   

    for( int i = 0 ; i < N ; i++ )
    {
        int a = T2.get(i,i);
        int b = T3.get(i,i);
        int c = T5.get(i,i);

        while( a-- > 0  && A[i]%2 == 0 && A[i] != 0 )
            A[i] /= 2 ;

        while( b--  > 0 && A[i]%3 == 0 && A[i] != 0 )
            A[i] /= 3 ;

        while( c-- > 0  && A[i]%5 == 0 && A[i] != 0  )
            A[i] /= 5 ;
    }

    for( auto x : A )
        cout<<x<<" ";

    cout<<endl;
}


int32_t main()
   {
      std::ios::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);
      
      // freopen("input.txt", "r", stdin); 
      // freopen("output.txt", "w", stdout);
      

       int test = 1 ;
       // cin>>test;
       while(test--)
       {
         go();
       }

       
     
       return 0 ;
   } 
             
           
