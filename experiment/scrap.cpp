#include <bits/stdc++.h>
using namespace std;



/********** GO DOWN ***********/

/* 
   If the genius trains just as hard.... 
   what chance do I have to beat him? 
*/

string getCode( string A )
{
	if(A.size()==0)
		return "";
	string res ;
	while(A.back()!='/')
	{
		res = A.back() + res ;
		A.pop_back();
	}
	return res ;
}

int32_t main() {
	// your code goes here
	
	// <tr><td><a href="https://example.com">Example 1</a></td></tr>
	string A = "<tr><td><a href=\"";
	string B = "\"target=\"_blank\" id=\"link1\">";
	string C = "</a></td></tr>";
	int st = 1801 ;
	for( int i = 0 ; i < 559 ; i++ )
	{
		string x ;
		cin>>x ;

		string code = getCode(x);

		cout<<A<<x<<B<<" "<<st++<<" | "<<code<<C<<endl;
	}

	
	return 0;
}