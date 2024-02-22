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

//          Country* country = find(countryId) // save a pointer to the country’s instance in order to insert to m_countryPointer field
//              If country == nullptr, country does not exist
//                  return StatusType::FAILURE.

//          Check if contestantId exists in contestant tree
//              If it does:
//                  return StatusType::FAILURE.

//          Create a new contestant with the given parameters.
//          insert a pointer to newContestant into Olympic -> contestant tree.
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
//          Contestant* contestantToDelete = find(contestantId) in contestant tree.

//          If contestantToDelete == nullptr then contestantId doesn't exist
//              return FAILURE.

//          if contestantToDelete->registeredInATeam() == true
//              return FAILURE.

//          go to contestantToDelete->m_countryPointer and decrease country's contestant count by 1.
//          olympics->contestantTree->remove(contestantToDelete); // will also delete the Contestant's instance

//      if allocation failed, return StatusType::ALLOCATION_ERROR.

//      return StatusType::SUCCESS;
	return StatusType::FAILURE;
}
	
StatusType Olympics::add_contestant_to_team(int teamId,int contestantId){ // O(log n + log m)
//     Pseudo-code:
//          Check if teamId <= 0 or contestantId <= 0
//              If it does, return StatusType::INVALID_INPUT.
//          in a try block:

//               Contestant* contestantToRegister =  find(contestantId) in contestant tree. //O(log n)
//                    if contestantToRegister == nullptr so contestant doesn't exist
//                         return StatusType::FAILURE

//               Team* draftingTeam = find (teamId) in team tree. // O(log m)
//                     if draftingTeam == nullptr, then team doesn't exist
//                     return StatusType::FAILURE

// TODO: check if it's better to use the following code instead of checking inside the contestant class
//                  if draftingTeam->isAlreadyRegistered(contestantToRegister) == TRUE // O(log n)
//                      return StatusType::FAILURE



//               if contestantToRegister->isAvailable() == FALSE // O(1)
//                      return StatusType::FAILURE


//               if draftingTeam->getSport() != contestantToRegister->getSport() // O(1)
//                      return StatusType::FAILURE

//               if draftingTeam->getCountryID() != contestantToRegister->getCountryID() // O(1)
//                      return StatusType::FAILURE

//               if (draftingTeam->insertContestant(contestantToRegister)!= SUCCESS) // O(log n)
//
//                      return StatusType::FAILURE

//               draftingTeam->updateTeamStrength; // O(log n)
//               draftingTeam->updateAusterity();  // O(log n)

//    if allocation failed, return StatusType::ALLOCATION_ERROR.
//    return StatusType::SUCCESS;



	return StatusType::FAILURE;
}

StatusType Olympics::remove_contestant_from_team(int teamId,int contestantId){ // O(log n + log m)
//    Pseudo-code:
//      Check if teamId <= 0 or contestantId <= 0
//          If it does, return StatusType::INVALID_INPUT.

//      in a try block:

//          Contestant* contestantToUnregister =  find(contestantId) in contestant tree. //O(log n)
//              if contestantToUnregister == nullptr so contestant doesn't exist
//                  return StatusType::FAILURE

//          Team* draftingTeam = find (teamId) in team tree. // O(log m)
//              if draftingTeam == nullptr, then team doesn't exist
//                  return StatusType::FAILURE

//          TODO: check if it's better to use the following code instead of checking inside the contestant class
//              if draftingTeam->isAlreadyRegistered(contestantToUnregister) == FALSE // O(log n)
//                return StatusType::FAILURE

//              if draftingTeam->removeContestant(contestantToUnregister)!= SUCCESS // O(log n)
//                  return StatusType::FAILURE

//              draftingTeam->updateTeamStrength; // O(log n)
//              draftingTeam->updateAusterity();  // O(log n)

//      if allocation failed, return StatusType::ALLOCATION_ERROR.
//      return StatusType::SUCCESS;

	return StatusType::FAILURE;
}

StatusType Olympics::update_contestant_strength(int contestantId ,int change){ // O(log n + log m)
//     Pseudo-code:

//      Check if contestantId <= 0
//          If it does, return StatusType::INVALID_INPUT.

//     in a try block:
//          Contestant* contestantToUpdate = find(contestantId) in contestant tree. //O(log n)
//              If contestantToUpdate == nullptr then contestantId doesn't exist
//                  return FAILURE.

//         if change == 0
//             return StatusType::SUCCESS

//        contestantToUpdate->updateStrength(change); // O(1)

//        if contestantToUpdate->registeredInATeam() == TRUE
//              contestantToUpdate->updateTeamsStats(); //loop through and update the strength and Austerity of all three teams // O(log n)

//    if allocation failed, return StatusType::ALLOCATION_ERROR.
//    return StatusType::SUCCESS;
    return StatusType::FAILURE;
}

output_t<int> Olympics::get_strength(int contestantId){ // O(log n)
//     Pseudo-code:

//     if contestantId  <= 0
//          return INVALID_INPUT.

//     in try{} catch{} block:
//         Contestant* contestant = find(contestantId) in contestant tree. // O(log n)
//              If contestant == nullptr //then contestantId doesn't exist
//                  return FAILURE.
//         return output_t<int>(StatusType::SUCCESS, Contestant->getStrength());
// TODO: check if the following line is correct, because if allocation failed, we can't create a new output_t
//     If allocation failed, return output_t<int>(StatusType::FAILURE, ZERO).
}

output_t<int> Olympics::get_medals(int countryId){ // O(log k)
//     Pseudo-code:

//      if countryId  <= 0
//          return INVALID_INPUT.

//      try{} catch{} block:
//          Country* country = find(countryId) in country tree. // O(log k)
//              If country == nullptr then countryId doesn't exist
//                  return FAILURE.
//          return output_t<int>(StatusType::SUCCESS, country->getMedals()); // O(1)

// TODO: check if the following line is correct, because if allocation failed, we can't create a new output_t
//     If allocation failed, return output_t<int>(StatusType::FAILURE, ZERO).

	return 0;
}

output_t<int> Olympics::get_team_strength(int teamId){ // O(log m)
//	 Pseudo-code:
//     if teamId  <= 0
//          return INVALID_INPUT.

//     in try{} catch{} block:
//          Team* team = find(teamId) in team tree. // O(log m)
//          If team == nullptr then teamId doesn't exist
//              return FAILURE.
//          return output_t<int>(StatusType::SUCCESS, team->getTeamStrength()); // O(1)

// TODO: check if the following line is correct, because if allocation failed, we can't create a new output_t
//     If allocation failed, return output_t<int>(StatusType::FAILURE, ZERO).

    return 0;
}

StatusType Olympics::unite_teams(int teamId1,int teamId2) { // O(log m + n_team_ID1 + n_team_ID2)
//     Pseudo-code:

//      Check if teamId1 <= 0 or teamId2 <= 0 or teamId1 == teamId2
//          If it does, return StatusType::INVALID_INPUT.

//      in a try block:

//          Team* team1 = find(teamId1) in team tree. // O(log m)
//              if team1 == nullptr, then teamId1 doesn't exist
//                  return StatusType::FAILURE

//          Team* team2 = find(teamId2) in team tree. // O(log m)
//              if team2 == nullptr, then teamId2 doesn't exist
//                  return StatusType::FAILURE

//          if team1->getCountryID() != team2->getCountryID() // O(1)
//              return StatusType::FAILURE

//          if team1->getSport() != team2->getSport() // O(1)
//              return StatusType::FAILURE

//         return mergeTeams(team1, team2); // O(n_team_ID1 + n_team_ID2)


// explain mergeTeams:
//     StatusType mergeTeams(Team* team1,Team*  team2){
//       in a try block:
//            mergedIdArray = mergeIDsToArray(sortedId1, sortedId2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates
//            mergedStrengthArray = mergeStrengthsToArray(team1, team2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates
//
//            loop through mergedIdArray and for each ID, assign position to each parallelStrength

//        create a new team with no members. // O(1)

//        create three ID subtrees for the new team out of mergedIdArray //O(n_team_ID1 + n_team_ID2)
//              for each contestant that we transfer, update his teams to the new team // O(1)
//        create three Strength subtrees for the new team out of mergedStrengthArray //O(n_team_ID1 + n_team_ID2)

//        update the new team's strength // O( log (n_team_ID1 + n_team_ID2) )
//        update the new team's austerity // O( log (n_team_ID1 + n_team_ID2) )

//         delete team2 // O(n_team_ID2)
//         delete all subtrees in team1 // O(n_team_ID1)
//         assign all six new subtrees to team1 // O(1)

//      if allocation failed
//              restore all the changes we made to the teams
//              return StatusType::ALLOCATION_ERROR
//      return StatusType::SUCCESS;


// explain mergeIDsToArray:
    // ID** mergeIDsToArray(ID** sortedId1, ID** sortedId2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates
        //        ID** sortedId1 = team1->getSortedArray(); // O(n_team_ID1)
        //        ID** sortedId2 = team2->getSortedArray(); // O(n_team_ID2)
        //        return mergeArrays(sortedId1, sortedId2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates

// explain mergeStrengthsToArray:
//                Strength** mergeStrengthsToArray(Team* team1, Team* team2){ // O(n_team_ID1 + n_team_ID2){
//                      Strength** sortedStrength1 = team1->getSortedArray(); // O(n_team_ID1) // need to take care of duplicates
//                      Strength** sortedStrength2 = team2->getSortedArray(); // O(n_team_ID2) // need to take care of duplicates
//                      return mergeArrays(sortedStrength1, sortedStrength2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates
//                }
//       }


StatusType Olympics::play_match(int teamId1,int teamId2){ // O(log k + log m)\
//     Pseudo-code:
//      Check if teamId1 <= 0 or teamId2 <= 0 or teamId1 == teamId2
//          If it does, return StatusType::INVALID_INPUT.

//      in a try block:
//         Team* team1 = find(teamId1) in team tree. // O(log m)
//              if team1 == nullptr, then teamId1 doesn't exist
//                  return StatusType::FAILURE

//         Team* team2 = find(teamId2) in team tree. // O(log m)
//              if team2 == nullptr, then teamId2 doesn't exist
//                  return StatusType::FAILURE

//          if team1->getSport() != team2->getSport() // O(1)
//              return StatusType::FAILURE

//          int team1Points = team1->getCountryPointer()->getMedals() + team1->getTeamStrength(); // O(1)
//          int team2Points = team2->getCountryPointer()->getMedals() + team2->getTeamStrength(); // O(1)

//         if team1Points > team2Points
//              team1->getCountryPointer()->addMedal(); // O(1)
//         else if team1Points < team2Points
//              team2->getCountryPointer()->addMedal(); // O(1)
//         else // Tie


// if allocation failed, return StatusType::ALLOCATION_ERROR.
// return StatusType::SUCCESS

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



