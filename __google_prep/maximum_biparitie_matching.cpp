/*
    each boys tries to match with all the girls,

    two things can happen:

        1-> girls is free
        2-> girls is matched 


    #1-> when girl is free i will match with her

    #2-> 
        if girl is matched then i will still try to match with her, if the other boy that is already matched with here can match
        with some other girl if yes i will with here otherwise this matching will not happen

*/



#include<bits/stdc++.h>
using namespace std;

vector<int>vis , match ;

int find_match( vector<vector<int>>&A , int i )
{
    if(vis[i])
        return 0 ;
    vis[i] = 1 ;

    for( int j = 0 ; j < (int)A[i].size(); j++ )
    {
        if( A[i][j] )
        {
            if( match[j] == -1 || find_match( A , match[j] ) )
            {
                match[j] = i ;
                return 1 ;
            }
        }
    }

    return 0 ;
}

int solve(vector<vector<int>>& A ) {

    int M = A.size(); // boys 
    int N = A.back().size();  // girls 

    match.assign(N,-1);
    int res = 0 ;

    for( int i = 0 ; i < M ; i++ )
    {
        vis.assign(M,0);
        res += find_match( A , i );
    }
    return res;
}

int main()
{

    // Define the invitation matrix
    vector<vector<int> > invitationMatrix
    =            {{0, 1, 1, 0, 0, 0},
                  {1, 0, 0, 1, 0, 0},
                  {0, 0, 1, 0, 0, 0},
                  {0, 0, 1, 1, 0, 0},
                  {0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 1}};

    // Call the maximumInvitations function and store the
    // result
    int totalInvitations
        = solve(invitationMatrix);

    // Print the result
    cout << "The maximum possible number of accepted "
            "invitations is: "
         << totalInvitations << endl;

    return 0;
}
