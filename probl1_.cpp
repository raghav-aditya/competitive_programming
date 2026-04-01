/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 


/*

Q1.

Input: [“a.b.12”, “d.c.55”]  
Output: { “A”: { “B”: 12 }, “D”: { “C”: 55 } }

Input: [“a.b.12”, “a.b.c.4”, “d.c.55”]
Output: { A: { B: { C: 4 } }, D: { C: 55 } }



*/


class JsonNode
{
public:
	string val ;
	map< string , JsonNode* > childs ; // O(1);

	JsonNode(){}
	JsonNode(string key){
		val = key ;
	}

	void setKey( string key ){
		val = key ;
	}

	void addChild( string key , JsonNode * child )
	{
		childs[key] = child ;
	}

};



// "a.b.12" ---> a b 12 
// a.b.11 ---> 


void rec( JsonNode* root , vector<string>&tokens , int i )
{
	int N = tokens.size();

	if( i == N )
		return ;

	string key = tokens[i];



	if( (root->childs).find( key ) != (root->childs).end() )
	{
		root = root->childs[key];
		rec( root , tokens , i+1 );
	}
	else
	{
	     JsonNode * node = new JsonNode(key);

	     root->childs[key] = node ;

	     root = root->childs[key];

	     rec( root , tokens , i+1 );
	}
}


void dfs( JsonNode* root )
{

	if( (root->val).size() )
	{
		cout<<"{ "<<endl;
		cout<<"\""<<root->val<<"\""<<" : " ;

	}

	for( auto obj : root->childs )
	{
		JsonNode * child = obj.second ;

		dfs( child );
	}
	if( (root->val).size() )
	cout<<"}, "<<endl;
}


void tree( string A , JsonNode * root )
{

	// auto node = root ;


	for( auto &x : A )
	{
		if( x == '.' )
			x = ' ';
	}

	stringstream ss(A);
	vector< string > tokens ; 
	string key ;

	while( ss>> key )
	{
		tokens.push_back(key);
	}



	rec( root , tokens , 0 );


	// dfs( node );

	// tokens --> [  a , b , 12   ]
			//		 0
}


void solve( vector<string>&A ){


	 JsonNode * root = new JsonNode();

	 for( auto x : A )
	 {
	 	tree(x,root);
	 }

	 dfs(root);

    return ;
}

int32_t main() {


  vector<string>t1 = { "a.b.12", "d.c.55" };
  vector<string>t2 = { "a.b.12", "a.b.c.4", "d.c.55" };

  solve(t1);

  cout<<endl;
  cout<<endl;
  cout<<endl;

  // solve(t2);

return 0;
}   