
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class T
{
public:
    string val ; 
    unordered_map< string , T* > childs ;
    bool isFile = false ;
    int fileCount = 0 ;

    T( string str )
    {
        this->val = str ;

        for( auto &x : str ){
            if( x == '.' )
                isFile = true ;
        }
    }
};


class trie
{
    T* root = nullptr ;

    void print( vector<string>&A )
    {   
        for( auto x : A )
        {
            if( x != "" )
                cout<<"/"<<x;
        }
        cout<<endl;
    }

    void build( T* node , vector<string>&A , int i )
    {
        int N = A.size();
        if( i == N )
            return ;

        string val = A[i];

        if( node->childs[val] == nullptr )
        {
            T* x = new T( val );
            node->childs[val] = x ;
            node->fileCount += x->isFile ;
        }

        build( node->childs[val] , A , i+1 );
    }

    void query( T* node , vector<string>&res )
    {
        if( node == nullptr )
            return ;

        string val = node->val ;
        res.push_back(val);

        string fileName ; // storing filename of last fileType child

        for( auto x : node->childs )
        {
            T* child = x.second ;
            if(child->isFile)
                fileName = x.first ;
            else
                query( child , res );
        }

        if(node->fileCount == 1 )
        {
            res.push_back(fileName);
            print(res);
            res.pop_back();
        }
        else if( node->fileCount > 1 )
            print(res);

        res.pop_back();
    }

public:

    trie(){
        root = new T("");
    }

    void add( string A )    
    {
        for( auto &x : A ){
            if( x == '/' )x = ' ';
        }

        stringstream ss(A);
        vector< string > B ;
        string x ;

        while( ss>>x )
        {
            B.push_back(x);
        }
        build( root , B , 0 );
    }


    void task()
    {
        vector< string > res ;
        query( root , res );
    }
};

int32_t main() {
    // your code goes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N ;
    cin>>N ;
    vector< string > A(N);

    for( auto &x : A )cin>>x ;

    trie tool;
    
    for( auto x : A )
        tool.add(x);

    tool.task();
   
    return 0;
}


/*
input:

6
/home/foo/bar/file1.txt
/home/foo/bar/file2.txt
/home/foo/mobi/wiki/file3.txt
/home/foo/mobi/file4.txt
/home/foo/file5.txt
/home/foo/mobi/file6.txt

*/