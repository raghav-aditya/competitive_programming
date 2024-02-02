
#include <iostream>
using namespace std;

int main()
{
    int A[4][4];
    for( int i = 0 ; i < 4 ; i++ )
    for( int j = 0 ; j < 4 ; j++ )
    cin>>A[i][j];

    for( int i = 0 ; i < 4 ; i++ )
    {
        int s = 0;
        for( int j = 0 ; j < 4 ; j++ )
            s += A[i][j] ;
        cout<<s<<" ";
    }

    cout<<endl;
    cout<<endl;

    for( int j = 0 ; j < 4 ; j++ )
    {
        int s = 0 ;
        for( int i = 0 ; i < 4 ; i++ )
            s += A[i][j] ;
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<endl;
}