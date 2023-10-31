           #include<bits/stdc++.h>
           using namespace std ; 
           #define ar array 
           #define int long long  
           #define ld long double
           #define nl cout<<"\n" 
           


class SegmentTree {

private:
    struct T {
        int start, end, data;
        int lazy;
        T* left;
        T* right;
        T(int start_, int end_)
            : start(start_), end(end_), data(0), lazy(0), left(nullptr), right(nullptr) {}
        ~T() {
            delete left;
            delete right; 
        }
    };

    T* root;
    

public:
    SegmentTree(const std::vector<int>& arr) {
        root = build(0, arr.size() - 1, arr);
    }

    T* build(int start, int end, const std::vector<int>& arr) {
        if (start > end)
            return nullptr;

        T* node = new T(start, end);

        if (start == end) {
            node->data = arr[start];
        } else {
            int mid = (start + end) / 2;
            node->left = build(start, mid, arr);
            node->right = build(mid + 1, end, arr);
            pull(node);
        }

        return node;
    }

    void pull(T* node){
        node->data = node->left->data + node->right->data ;
    }

    void push(T* node) {
        if (node->lazy != 0) {
            node->data += (node->end - node->start + 1) * node->lazy;

            if (node->start != node->end) {
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }

            node->lazy = 0;
        }
    }

    void updateRange(T* node, int l, int r, int val) {
        if (node == nullptr || node->start > r || node->end < l)
            return;

        if (node->start >= l && node->end <= r) {
            node->data += (node->end - node->start + 1) * val;

            if (node->start != node->end) {
                node->left->lazy += val;
                node->right->lazy += val;
            }
        } else {
            push(node);
            updateRange(node->left, l, r, val);
            updateRange(node->right, l, r, val);
            pull(node);
        }
    }

    void updateRange(int l, int r, int val) {
        updateRange(root, l, r, val);
    }

    int query(T* node, int l, int r) {
        if (node == nullptr || node->start > r || node->end < l)
            return 0;

        if (node->start >= l && node->end <= r) {
            return node->data;
        } else {
            push(node);
            int leftSum = query(node->left, l, r);
            int rightSum = query(node->right, l, r);
            return leftSum + rightSum;
        }
    }

    int query(int l, int r) {
        return query(root, l, r);
    }

    ~SegmentTree() {
        delete root;
    }
};

     
        void go()
        {
            int N ; cin>>N ;
            vector<int>A(N);

            FT_RP T2(N),T3(N),T5(N);

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
                        T2.add( l , r , 1 );
                    }
                    else if( p == 3 )
                    {
                        T3.add( l , r , 1 );
                    }
                    else 
                    {
                        T5.add( l , r , 1 );
                    }
                }
                else
                {
                    int k ; int d ;

                    cin>>k>>d ;
                    k--;
                    
                    int a = T2.at(k);
                    int b = T3.at(k);
                    int c = T5.at(k);

                    T2.add(k,k,-a);
                    T3.add(k,k,-b);
                    T5.add(k,k,-c);
                    A[k] = d ;
                }
            }
           

            for( int i = 0 ; i < N ; i++ )
            {
                int a = T2.at(i);
                int b = T3.at(i);
                int c = T5.at(i);

                while( a-- > 0  && A[i]%2 == 0 && A[i] != 0 )
                    A[i] /= 2 ;

                while( b--  > 0 && A[i]%3 == 0 && A[i] != 0 )
                    A[i] /= 3 ;

                while( c-- > 0  && A[i]%5 == 0 && A[i] != 0  )
                    A[i] /= 5 ;
            }

            for( auto x : A )
                cout<<x<<" ";

            nl;
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
             
           
