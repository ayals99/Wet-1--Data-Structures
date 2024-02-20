#include "Olympicsa1.h"



Olympics::Olympics(){ //O(1)
}

Olympics::~Olympics(){ // O(n+k+m)

}
	
StatusType Olympics::add_country(int countryId, int medals){ // O(log k)
	return StatusType::FAILURE;
}
	
StatusType Olympics::remove_country(int countryId){ // O(log k)
	return StatusType::FAILURE;
}

StatusType Olympics::add_team(int teamId,int countryId,Sport sport){ // O(log m + log k)
// Pseudo code:
//      Check if teamId exists already.
//          If it does, return FAILURE.
//      Find the countryId and save a pointer to the country’s instance.
//          If country does not exist, return FAILURE.
//      Create a new team with no members.
//      Create all six Contestant Subtrees.
    return StatusType::FAILURE;
}

StatusType Olympics::remove_team(int teamId){ // O(log m)
    // Pseudo-code:
    //  Team* teamToDelete = find teamId in team tree.
    //      If teamToDelete == nullptr then teamId doesn't exist
    //          return FAILURE.
    // go to m_country pointer and decrease country's team count by 1.
    // Delete team but make sure not to delete the contestants, because they are still in the system.

    return StatusType::FAILURE;
}
	
StatusType Olympics::add_contestant(int contestantId ,int countryId,Sport sport,int strength){  // O(log n + log k)

    return StatusType::FAILURE;
}
	
StatusType Olympics::remove_contestant(int contestantId){ // O(log n)
	return StatusType::FAILURE;
}
	
StatusType Olympics::add_contestant_to_team(int teamId,int contestantId){ // O(log n + log m)
	return StatusType::FAILURE;
}

StatusType Olympics::remove_contestant_from_team(int teamId,int contestantId){ // O(log n + log m)
	return StatusType::FAILURE;
}

StatusType Olympics::update_contestant_strength(int contestantId ,int change){ // O(log n + log m)
	return StatusType::FAILURE;
}

output_t<int> Olympics::get_strength(int contestantId){ // O(log n)
//     Pseudo-code:
//     if contestantId  <= 0
//          return INVALID_INPUT.
//     in try{} catch{} block:
//         Contestant* contestant = find contestantId in contestant tree. // O(log n)
//              If contestant == nullptr then contestantId doesn't exist
//                  return FAILURE.
//         return output_t<int>(StatusType::SUCCESS, Contestant->getStrength());
//         return answer; // O(1)
//     If allocation failed, return StatusType::ALLOCATION_ERROR.

}

output_t<int> Olympics::get_medals(int countryId){ // O(log k)
//     Pseudo-code:
//      try{} catch{} block:
//          Country* country = find countryId in country tree. // O(log k)
//              If country == nullptr then countryId doesn't exist
//                  return FAILURE.
//          return output_t<int>(StatusType::SUCCESS, country->getMedals()); // O(1)
//     If allocation failed, return StatusType::ALLOCATION_ERROR.
	return 0;
}

output_t<int> Olympics::get_team_strength(int teamId){ // O(log m)
//	 Pseudo-code:
//      Team* team = find teamId in team tree. // O(log m)
//          If team == nullptr then teamId doesn't exist
//              return FAILURE.
//     return team->getTeamStrength(); // O(1)
    return 0;
}

StatusType Olympics::unite_teams(int teamId1,int teamId2){ // O(log m + n_team_ID1 + n_team_ID2)

    return StatusType::FAILURE;
}

StatusType Olympics::play_match(int teamId1,int teamId2){ // O(log k + log m)
	return StatusType::FAILURE;
}

output_t<int> Olympics::austerity_measures(int teamId){ // O(log m)
//     Pseudo-code:
//      Team* team = find teamId in team tree. // O(log m)
//          If team == nullptr then teamId doesn't exist
//              return FAILURE.
//     return team->getAusterityMeasures(); // O(1)
	return 0;
}



