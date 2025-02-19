/*
 Author: Aditya Raghav [ zerojude ]
 INDIA 
*/
#include <bits/stdc++.h>
using namespace std;




/*

	SPACE: LINEAR , O( operations_count ) 
	TIME:  LINEAR , O( operations_count  )

*/



/*

PROBLEM: 

DESIGN DS: 

	1: redo
	2: undo 
	3: print_current_state 

*/

class operation
{
public:
	int id ;
	string name ;

	operation( int id_1 , string x ){
		this->id = id_1 ;
		this->name = x ;
	}
};

class DS
{
	// deque -> push,pop on both ends
    // past          future
	// [   ]         [ ]
	//  1 2 3 4 5 6  7 8 9
	//            | 

    //  1 2 3 4 5 6   [ 10 , 7 , 8 , 9 ]




	deque< operation > past , future ;

	int chunk_size = 3 ;

	operation invalid_state = operation( rand()%INT_MAX , "invalid_state" );

	operation curr = invalid_state ;

public:

	DS(){};

	void undo(){

		if(past.size())
		{
			auto op = past.back();
			past.pop_back();

			if(past.size())
			curr = past.back();
			else
			{
				curr = invalid_state ;
			}
			future.push_front(op);
		}	
		else
		{
			cout<<"cant do undo"<<endl;
		}		
	}

	void long_undo()
	{
		int cnt = min( (int)past.size() , chunk_size );

		while(cnt--)
			undo();
	}

	void redo()
	{
		if( future.size() == 0 )
		{
			cout<<"cant do redo"<<endl;
			return ;
		}
		else
		{
			auto op = future.front();
			future.pop_front();

			past.push_back(op);
			curr = op;
		}
	}

	void long_redo()
	{
		int cnt = min( (int)future.size() , chunk_size );
		
		while( cnt-- )
			redo();
	}

	void do_operation( operation op )
	{
		past.push_back(op);
		curr = op ;
	}


	void print_state()
	{
		cout<<curr.name<<endl;
	}
};



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto solve = [&]()->void{
        
    	operation op1( rand()%INT_MAX , "1" );
    	operation op2( rand()%INT_MAX , "2" );
    	operation op3( rand()%INT_MAX , "3" );
    	operation op4( rand()%INT_MAX , "4" );
    	operation op5( rand()%INT_MAX , "5" );
    	operation op6( rand()%INT_MAX , "6" );


    	DS *tool = new DS();


    	// tool->do_operation(op1);
    	// tool->do_operation(op2);

    	tool->print_state();
    	tool->undo();
    	tool->redo();
    	tool->print_state();

    };
    

int test = 1 ;
cin>>test;
while(test--)
solve();
return 0;
}   