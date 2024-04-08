#include <bits/stdc++.h>
using namespace std ;

// We have an iPhone app, which on open, shows the most interesting people within a 30 mile radius. 
// Interesting people are those who share a lot of interests with you.

// This problem is about finding the optimal way to design the app.


/*
Constraints:

Overall we have 10M users in the app. In the Bay Area (30 miles), we had about 500K users.

Each person has 5K interest_ids. The total number of unique interests are very large, so usually people match on 3-5 interests. 
Most people have no interests in common.

This is more of a real-life problem, than a programming contest puzzle. So the test-case will reflect practically what happens in our software, 
and not hand-generated corner cases.

Tip: 0.1 delta in lat or lng, implies a 30 mile delta.

Scoring: Make it fast and keep the logic simple.

You can code in any language.
*/

#define id_and_intrest pair< int ,vector<int> > 

class TheApp {



  // update function when users moves from location one to location two 

	unordered_map< float , unordered_map< float , vector<id_and_intrest> > > data_structure ; 
	unordered_map< int , vector<int> > interest_by_user_id ;


	//  { lat , log -> id and { list of intrest }}



	float round_off( float point )
	{
		return point ;// it will do round off magic 
	}

	vector<int> process_data( vector< id_and_intrest > &users , unordered_set< int > &my_intrest_set )
	{
		 vector<int>users_id_with_common_intrests_at_position ; //

		 for( auto x : users )
		 {
		 	  int id = x.first ;
		 	  vector<int>his_intrest = x.second ;
		 	  int matches = 0 ;

		 	  for( auto interest : his_intrest )
		 	  {
		 	  	  matches += my_intrest_set.find( interest ) != my_intrest_set.end() ;

		 	  	  if( matches >= 5 ){
							 		 	 users_id_with_common_intrests_at_position.push_back(id);
							 		 	 break; 	  	
		 	  	  }
		 	  }
		 }

		 return users_id_with_common_intrests_at_position;
	}


public:

  vector<int> userOpensApp(float lat, float lng, int user_id) {  // get call 
	// Returns the top 10 user_ids, interesting around `user_id`.
	// containing the top 10 (or less) user_id’s who are within a 30 mile radius of the user and have the highest number of common interests.


  	vector<int> my_intrests = interest_by_user_id[user_id];
  	unordered_set< int > my_intrest_set ( my_intrests.begin() , my_intrests.end() );  

  	
  	vector< int > peoples ; // result 


  	for( int curr_lat = lat-0.1 ; curr_lat <= lat+0.1 ; curr_lat += 0.1 )
  	for( int curr_lng = lng-0.1 ; curr_lng <= lng+0.1 ; curr_lng += 0.1 )
  	{
  			vector< id_and_intrest > users = data_structure[curr_lat][curr_lng];

  			vector<int> users_id_with_common_intrests_at_position = process_data( users , my_intrest_set );

  			for( auto x : users_id_with_common_intrests_at_position )
  				peoples.push_back(x);
  	}

  	return peoples ;

 }

  void userDataCrawled(int user_id, vector < int > interest_ids, float lat, float lng) { // put call 
	// Update internal data structures. This happens when we crawl the user’s data from Facebook connect.


  	lat = round_off(lat);
  	lng = round_off(lng);

  	pair< int , vector<int> >  user = { user_id , interest_ids };

  	

  	interest_by_user_id[user_id] = interest_ids ;  // average O(1) 
  	data_structure[lat][lng].push_back(user) ;    // average O(1)
  }
};






/*
Constraints:

Overall we have 10M users in the app. In the Bay Area (30 miles), we had about 500K users.

Each person has 5K interest_ids. The total number of unique interests are very large, so usually people match on 3-5 interests. 
Most people have no interests in common.

This is more of a real-life problem, than a programming contest puzzle. So the test-case will reflect practically what happens in our software, 
and not hand-generated corner cases.

Tip: 0.1 delta in lat or lng, implies a 30 mile delta.

Scoring: Make it fast and keep the logic simple.

You can code in any language.
*/