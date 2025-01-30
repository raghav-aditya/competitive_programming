class prefix_sum_2d
{
    int N ;
    vector<vector<int>>T ;
    vector<vector<int>>A ;

public:

    prefix_sum_2d( vector< vector<int>> &A_ )
    {
        this->A = A_; 
        this->N = A.size();

        vector< vector<int> > T_ ( N+1 , vector<int>(N+1 , 0 ));

        this-> T = T_ ;


        for( int i = 0 ; i < N ; i++ )
        for( int j = 0 ; j < N ; j++ )
            T[i+1][j+1] = T[i][j+1] + T[i+1][j] - T[i][j] + A[i][j] ;

    }

    int query( int a , int b , int c , int d )
    {
        return T[c+1][d+1] + T[a][b] - T[a][d+1] - T[c+1][b] ;
    }
};