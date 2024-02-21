#include "Olympicsa1.h"



Olympics::Olympics(){ //O(1)
}

Olympics::~Olympics(){ // O(n+k+m)

}
	
StatusType Olympics::add_country(int countryId, int medals){ // O(log k)
//     Pseudo code:
//        check if medals <= 0 and if countryId <= 0
//             If it does, return INVALID_INPUT.
//        Check if countryId exists already.
//             If it does, return FAILURE.
//        in a try block:
//            Create a new country with no teams.
//            assign medals to the country.
//            intialize the country's team count to 0.
//            intialize the country's contestant count to 0.
//            return StatusType::SUCCESS.
//        if allocation failed, return StatusType::ALLOCATION_ERROR.


	return StatusType::FAILURE;
}
	
StatusType Olympics::remove_country(int countryId){ // O(log k)
//     Pseudo code:
//      check if countryId <= 0
//           If it does, return INVALID_INPUT.
//        in a try block:
//        Country* countryToDelete = find countryId in country tree.
//
//            If countryToDelete == nullptr, then countryId doesn't exist
//                return FAILURE.
//            if countryToDelete->getTeamCounter() is not ZERO or countryToDelete->getContestantCounter is not ZERO
//            return FAILURE.
//          delete countryToDelete.
//        if allocation failed, return StatusType::ALLOCATION_ERROR.
//            return StatusType::SUCCESS.

    return StatusType::FAILURE;
}

StatusType Olympics::add_team(int teamId,int countryId,Sport sport){ // O(log m + log k)
// Pseudo code:
//      Check if teamId <= 0 or countryId <= 0
//          If it does, return StatusType::INVALID_INPUT.
//      Check if teamId exists already.
//          If it does, return StatusType::FAILURE.
//       in a try block:
//      Find the countryId and save a pointer to the country’s instance.
//          If country does not exist, return StatusType::FAILURE.
//          Create a new team with no members.
//          intialize m_teamSize to 0.
//          intialize m_teamStrength to 0.
//          intialize m_austerityMeasures to 0.
//          Create all six Contestant Subtrees - three for ID ad three for Strength.
//          assign the team to the country by saving the country's pointer in m_countryPointer.
//      if allocation failed, return StatusType::ALLOCATION_ERROR.
//            return StatusType::SUCCESS.

    return StatusType::FAILURE;
}

StatusType Olympics::remove_team(int teamId){ // O(log m)
//     Pseudo-code:
//      Check if teamId <= 0
//        If it does, return StatusType::INVALID_INPUT.
//      in a try block:
//          Team* teamToDelete = find teamId in team tree.
//          If teamToDelete == nullptr then teamId doesn't exist
//              return FAILURE.
//      go to m_country pointer and decrease country's team count by 1.
//      Delete team but make sure not to delete the contestants, because they are still in the system.
//    if allocation failed, return StatusType::ALLOCATION_ERROR.
//    return StatusType::SUCCESS.

    return StatusType::FAILURE;
}
	
StatusType Olympics::add_contestant(int contestantId ,int countryId,Sport sport,int strength){  // O(log n + log k)
//     Pseudo-code:
//      Check if contestantId <= 0 or countryId <= 0 or strength < 0
//          If it does, return StatusType::INVALID_INPUT.
//      in a try block:
//          Find the countryId and save a pointer to the country’s instance in m_countryPointer
//              If country does not exist, return StatusType::FAILURE.
//          Create a new contestant with the given parameters, intialize the Tames to 0.
//          Check if newContestant exists already by searching in contestant tree
//              If it does:
//                  delete newContestant
//                  return StatusType::FAILURE.
//          insert a pointer to newContestant to contestant tree.
//          increase country's contestant count by 1.
//      if allocation failed, return StatusType::ALLOCATION_ERROR.
//      return StatusType::SUCCESS.


    return StatusType::FAILURE;
}
	
StatusType Olympics::remove_contestant(int contestantId){ // O(log n)
//     Pseudo-code:
//      Check if contestantId <= 0
//          If it does, return StatusType::INVALID_INPUT.
//      in a try block:
//          Contestant* contestantToDelete = find contestantId in contestant tree.
//          If contestantToDelete == nullptr then contestantId doesn't exist
//              return FAILURE.
//          if contestant->registeredInATeam() == true
//              return FAILURE.
//          got to m_countryPointer and decrease country's contestant count by 1.
//          olympics->contestantTree->remove(contestantToDelete);
//      if allocation failed, return StatusType::ALLOCATION_ERROR.
	return StatusType::FAILURE;
}
	
StatusType Olympics::add_contestant_to_team(int teamId,int contestantId){ // O(log n + log m)
//     Pseudo-code:
//          Check if teamId <= 0 or contestantId <= 0
//              If it does, return StatusType::INVALID_INPUT.
//          in a try block:
//               std::shared_pointer<Contestant> contestantToSearch = make_shared(new contestant(teamId, dummyCountry)

//               Contestant* contestantToRegister =  find(contestantToSearch) in contestant tree. //O(log n)
//                    if contestantToRegister == nullptr so contestant doesn't exist
//                         return StatusType::FAILURE

//               std::shared_pointer<Team> teamToSearchFor = make_shared(new Team(teamId, dummyCountry, dummySport)) // O(1)
//               Team* draftingTeam = find (teamToSearchFor) in team tree. // O(log m)
//                     if draftingTeam == nullptr, then team doesn't exist
//                     return StatusType::FAILURE

//                  if draftingTeam->isAlreadyRegistered(contestantToRegister) == TRUE // O(1)
//                      return StatusType::FAILURE

//               if contestantToRegister->isAvailable() == FALSE // O(1)
//                      return StatusType::FAILURE


//               if draftingTeam->getSport() != contestantToRegister->getSport() // O(1)
//                      return StatusType::FAILURE

//               if draftingTeam->getCountryID() != contestantToRegister->getCountryID() // O(1)
//                      return StatusType::FAILURE

//               if (draftingTeam->insertContestant(contestantToRegister)!= SUCCESS) // O(log n)
//                      return StatusType::FAILURE

//    if allocation failed, return StatusType::ALLOCATION_ERROR.
//    return StatusType::SUCCESS;



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



