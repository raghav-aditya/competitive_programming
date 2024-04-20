/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;


class T
{
public:

    string data ; 
    unordered_map< string , T* > child ;
    bool visited = 0 ;  // visited node 

    int visitedFileCount = 0 ; // visit file count 

    T( string data_ ){
        this->data = data_ ;
    }

    bool is_visited()
    {
        return this->visited ;
    }

    int fileCount()
    {
        return child.size();
    }
};


class TRIE
{
    T* root = new T("#"); // root of trie 

    vector< string > split( string A )
    {
        vector< string >res ;
        for( auto &x : A )
            if( x == '/' )x = ' ';

        stringstream ss(A);
        string x ;

        while( ss>>x )
            res.push_back(x);
        return res ;
    }


    void print( vector< string > A )
    {
        for( auto x : A )
            cout<<"/"<<x;
        cout<<endl;
    }

    void pull( T* node )
    {
        int s = 0 ;
        for( auto v : node->child )
        {
            T* ch = v.second ;
            s += ch->is_visited();
        }

        node->visitedFileCount = s ;
    }

    void dfs( T* node , vector< string >&res )
    {
        if( node == nullptr )
            return ;

        if( node->fileCount() > 0 && node->visitedFileCount == node->fileCount() )
        {
            print(res);
        }
        else
        {
            for( auto beg : node->child )
            {
                string val = beg.first ;
                T* ch_pointer = beg.second ;

                if( ch_pointer->is_visited() )
                {
                    res.push_back(val);
                    dfs( ch_pointer , res );
                    res.pop_back();
                }
            }
        }
    }


public:

    TRIE(){
        root->visited = true ; // trie root is always visited 
    }

    void insert( string A )
    {
        auto B = split(A);
        T* node = root ;

        for( int i = 0 ; i < (int)B.size() ; i++ )
        {
            string x = B[i];
            
            if( node->child[x] == nullptr )
            {
                T* ch = new T( x );
                node->child[x] = ch ;
            }
            node = node->child[x];
        }
    }

    void visit( string A )
    {
        auto B = split(A);

        T* node = root ;

        for( int i = 0 ; i < (int)B.size() ; i++ )
        {
            string x = B[i];
            T* ch = node->child[x];
            ch->visited = 1 ;

            pull(node);
            node = ch ;
        }
    }

    void query()
    {   
        T* node = root ;
        vector< string > res ;
        dfs(node , res );
    }
};



int32_t main() {

    vector< string > A 
    {
            "/a/b/x.txt",
            "/a/b/p.txt",
            "/a/c",
            "/a/d/y.txt",
            "/a/d/z.txt"
    };

    vector< string > B 
    {
        "/a/d/y.txt",
        "/a/d/z.txt",
        "/a/b/p.txt"
    };

    TRIE trie ;

    for( auto x : A )
        trie.insert(x);

    for( auto x : B )
        trie.visit(x);

    trie.query();

return 0;
}   




/*



I was given (as strings) as directories e.g.
/a/b/x.txt
/a/b/p.txt
/a/c
/a/d/y.txt
/a/d/z.txt

Also, I was given the selected directories e.g.
/a/d/y.txt
/a/d/z.txt
/a/b/p.txt

My output should be
/a/d
/a/b/p.txt



*/