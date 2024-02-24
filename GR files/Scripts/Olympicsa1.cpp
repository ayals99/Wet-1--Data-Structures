#include "Olympicsa1.h"


static const int MINIMUM_AUSTERITY_TEAM_SIZE = 3;

Olympics::Olympics(){ //O(1)
}

Olympics::~Olympics(){ // O(n+k+m)

}
	
StatusType Olympics::add_country(int countryId, int medals){ // O(log k)

    if (medals <= ZERO || countryId <= ZERO){
        return StatusType::INVALID_INPUT;
    }

    if (m_countryTree->find(countryId) != nullptr){
        return StatusType::FAILURE;
    }

    try {
        Country* newCountry = new Country(countryId, medals);
        m_countryTree->insert(newCountry);
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

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


StatusType Olympics::remove_country(int countryId){ // O(log k)
    if (countryId <= 0){
        return StatusType::INVALID_INPUT;
    }
    try {
        Country* countryToDelete = m_countryTree->find(countryId);
        if (countryToDelete == nullptr){
            return StatusType::FAILURE;

    }
        if (countryToDelete->getTeamCounter() != ZERO || countryToDelete->getContestantCounter() != ZERO){
            return StatusType::FAILURE;
        }
        delete countryToDelete;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}

//     Pseudo code:
//      check if countryId <= 0
//           If it does, return INVALID_INPUT.
//        in a try block:
//        Country* countryToDelete = find countryId in country tree.
//            If countryToDelete == nullptr, then countryId doesn't exist
//                return FAILURE.
//            if countryToDelete->getTeamCounter() is not ZERO or countryToDelete->getContestantCounter is not ZERO
//            return FAILURE.
//          delete countryToDelete.
//        if allocation failed, return StatusType::ALLOCATION_ERROR.
//            return StatusType::SUCCESS.



StatusType Olympics::add_team(int teamId,int countryId,Sport sport){ // O(log m + log k)
    if (teamId <= 0 || countryId <= 0){
        return StatusType::INVALID_INPUT;
    }
    if (m_teamTree->find(teamId) != nullptr){
        return StatusType::FAILURE;
    }
    try {
        Country* country = m_countryTree->find(countryId);
        if (country == nullptr){
            return StatusType::FAILURE;
        }
        Team* newTeam = new Team(teamId, countryId, sport, country);
        m_teamTree->insert(newTeam);
        return StatusType::SUCCESS;

    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}
// Pseudo code:
//      Check if teamId <= 0 or countryId <= 0
//          If it does, return StatusType::INVALID_INPUT.
//       in a try block:
//      Check if teamId exists already.
//          If it does, return StatusType::FAILURE.
//          Find the countryId and save a pointer to the country’s instance.
//          If country does not exist, return StatusType::FAILURE.
//          All of the id done in the constructor of Team:
//          Create a new team with no members.
//          intialize m_teamSize to 0.
//          intialize m_teamStrength to 0.
//          intialize m_austerityMeasures to 0.
//          Create all six Contestant Subtrees - three for ID ad three for Strength.
//          assign the team to the country by saving the country's pointer in m_countryPointer.
//      if allocation failed, return StatusType::ALLOCATION_ERROR.


StatusType Olympics::remove_team(int teamId) { // O(log m)
    if (teamId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        Team *teamToDelete = m_teamTree->find(teamId);
        if (teamToDelete == nullptr) {
            return StatusType::FAILURE;
        }
        if (teamToDelete->getSize() != ZERO) {
            return StatusType::FAILURE;
        }
        teamToDelete->getCountry()->decreaseTeamCounter();
        //TODO: We need to make sure logic is right here
        m_teamTree->remove(teamToDelete);
        //TODO: Make sure we do need to delete the team
        delete teamToDelete;
        return StatusType::SUCCESS;
    }catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

//     Pseudo-code:
//      Check if teamId <= 0
//        If it does, return StatusType::INVALID_INPUT.
//      in a try block:
//          Team* teamToDelete = find(teamId) in team tree.
//          If teamToDelete == nullptr then teamId doesn't exist
//              return FAILURE.
//      go to m_country pointer and decrease country's team count by 1.
//    if allocation failed, return StatusType::ALLOCATION_ERROR.
//    return StatusType::SUCCESS.
//we need to remove the team from the team tree and delete the team




	
StatusType Olympics::add_contestant(int contestantId ,int countryId,Sport sport,int strength){  // O(log n + log k)
    if (contestantId <= ZERO || countryId <= ZERO || strength < ZERO){
        return StatusType::INVALID_INPUT;
    }
    try {

        Country* country = m_countryTree->find(countryId);
        if (country == nullptr){
            return StatusType::FAILURE;
        }
        if (m_contestantTree->find(contestantId) != nullptr){
            return StatusType::FAILURE;
        }
        Contestant* newContestant = new Contestant(contestantId, countryId, sport, strength);
        newContestant->setCountryPointer(country);
        m_contestantTree->insert(newContestant);
        country->increaseContestantCounter();
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;

    }
}

//     Pseudo-code:
//      Check if contestantId <= 0 or countryId <= 0 or strength < 0
//          If it does, return StatusType::INVALID_INPUT.
//      in a try block:
//          Country* country = find(countryId) // save a pointer to the country’s instance in order to insert to m_countryPointer field
//              If country == nullptr, country does not exist
//                  return StatusType::FAILURE.
//
//          Check if contestantId exists in contestant tree
//              If it does:
//                  return StatusType::FAILURE.
//
//          Create a new contestant with the given parameters.
//          insert a pointer to newContestant into Olympic -> contestant tree.
//          increase country's contestant count by 1.
//          return StatusType::SUCCESS.
//      if allocation failed, return StatusType::ALLOCATION_ERROR.

StatusType Olympics::remove_contestant(int contestantId){ // O(log n)
    if (contestantId <= ZERO){
        return StatusType::INVALID_INPUT;
    }
    try {
        Contestant *contestantToDelete = m_contestantTree->find(contestantId);
        if (contestantToDelete == nullptr) {
            return StatusType::FAILURE;
        }
        if (contestantToDelete->registeredInATeam()) {
            return StatusType::FAILURE;
        }
        contestantToDelete->getCountryPointer()->decreaseContestantCounter();
        m_contestantTree->remove(contestantToDelete);
        //TODO: Make sure we do need to delete the contestant
        delete contestantToDelete;
        return StatusType::SUCCESS;
        }catch (std::bad_alloc& e){
            return StatusType::ALLOCATION_ERROR;
        }
        return StatusType::FAILURE;
}

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
//          olympics->m_contestantTree->remove(contestantToDelete); // will also delete the Contestant's instance
//      if allocation failed, return StatusType::ALLOCATION_ERROR.
//      return StatusType::SUCCESS;


StatusType Olympics::add_contestant_to_team(int teamId,int contestantId){ // O(log n + log m)

    if (teamId <= ZERO || contestantId <= ZERO){
        return StatusType::INVALID_INPUT;
    }
    try {
        Contestant *contestantToRegister = m_contestantTree->find(contestantId);
        if (contestantToRegister == nullptr) {
            return StatusType::FAILURE;
        }
        Team *draftingTeam = m_teamTree->find(teamId);
        if (draftingTeam == nullptr) {
            return StatusType::FAILURE;
        }
        if (draftingTeam->getCountryID() != contestantToRegister->getCountryID()) {
            return StatusType::FAILURE;
        }
        if (draftingTeam->getSport() != contestantToRegister->getSport()) {
            return StatusType::FAILURE;
        }
        for (int i = ZERO; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++) {
            if (contestantToRegister->getTeam(i) != nullptr) {
                if (contestantToRegister->getTeam(i)->getID() == teamId) {
                    return StatusType::FAILURE;
                }
            }
        }
        if (!contestantToRegister->isAvailable()) {
            return StatusType::FAILURE;
        }
        draftingTeam->insertContestant(contestantToRegister);
        return StatusType::SUCCESS;
    }catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

//     Pseudo-code:
//          Check if teamId <= 0 or contestantId <= 0
//              If it does, return StatusType::INVALID_INPUT.
//          in a try block:
//               Contestant* contestantToRegister =  find(contestantId) in contestant tree. //O(log n)
//                    if contestantToRegister == nullptr so contestant doesn't exist
//                         return StatusType::FAILURE
//               Team* draftingTeam = find (teamId) in team tree. // O(log m)
//                     if draftingTeam == nullptr, then team doesn't exist
//                          return StatusType::FAILURE
//              if (draftingTeam->getCountryID() != contestantToRegister->getCountryID() // O(1)
//                    return StatusType::FAILURE
//              if (draftingTeam->getSport() != contestantToRegister->getSport() // O(1)
//                    return StatusType::FAILURE
//              for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++)
//                    if contestantToRegister->teamArray[i] != nullptr
//                        if contestantToRegister->teamArray[i]->getID() == teamId
//                            return StatusType::FAILURE
//               if (contestantToRegister->isAvailable() == FALSE) // O(1)
//       	        return StatusType::FAILURE;


StatusType Olympics::remove_contestant_from_team(int teamId,int contestantId) { // O(log n + log m)

    if (teamId <= ZERO || contestantId <= ZERO) {
        return StatusType::INVALID_INPUT;
    }
    try {
        Contestant *contestantToUnregister = m_contestantTree->find(contestantId);
        if (contestantToUnregister == nullptr) {
            return StatusType::FAILURE;
        }
        Team *draftingTeam = m_teamTree->find(teamId);
        if (draftingTeam == nullptr) {
            return StatusType::FAILURE;
        }
        if (!contestantToUnregister->isRegisteredInTeam(teamId)) {
            return StatusType::FAILURE;
        }
        //TODO: we need to impolment removeContestantFromTeam in Team.cpp
        draftingTeam->removeContestantFromTeam(contestantToUnregister);
        return StatusType::SUCCESS;
    }catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}
//      Pseudo-code:
//      Check if teamId <= 0 or contestantId <= 0
//          If it does, return StatusType::INVALID_INPUT.
//      in a try block:
//          Contestant* contestantToUnregister =  find(contestantId) in contestant tree. //O(log n)
//              if contestantToUnregister == nullptr so contestant doesn't exist
//                  return StatusType::FAILURE
//          Team* draftingTeam = find (teamId) in team tree. // O(log m)
//              if draftingTeam == nullptr, then team doesn't exist
//                  return StatusType::FAILURE
//              bool isInTeam = false;
//              for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++)
//                    if contestantToRegister->teamArray[i] != nullptr
//                        if contestantToRegister->teamArray[i]->getID() == teamId
//                            isInTeam = true;
//              if (!isInTeam)
//                    return StatusType::FAILURE
//              draftingTeam->removeContestant(contestantToUnregister) // O(log n)
//              draftingTeam->updateTeamStrength; // O(log n)
//              draftingTeam->updateAusterity();  // O(log n)
//      if allocation failed, return StatusType::ALLOCATION_ERROR.
//      return StatusType::SUCCESS;


void removeContestantFromAllTeamSubtrees(Contestant* contestant){
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){
        if (contestant->getTeam(i) != nullptr){
            //TODO: we need to impolment removeContestant in Team.cpp
            //RemoveContestant should remove the data and then remove the node and balance the tree
            contestant->getTeam(i)->removeContestantFromSubtrees(contestant);
        }
    }
}

StatusType Olympics::update_contestant_strength(int contestantId ,int change){ // O(log n + log m)
    if(contestantId <= 0){
        return StatusType::INVALID_INPUT;
    }
    try {
        Contestant *contestantToUpdate = m_contestantTree->find(contestantId);
        if (contestantToUpdate == nullptr) {
            return StatusType::FAILURE;
        }
        if (change == ZERO) {
            return StatusType::SUCCESS;
        }
        if (contestantToUpdate->getStrength() - change < ZERO) {
            return StatusType::FAILURE;
        }
        //TODO:Need yo implement removeContestantFromAllTeamSubtrees
        //The function should just remove contestant from all team subtrees
        removeContestantFromAllTeamSubtrees(contestantToUpdate);
        contestantToUpdate->updateStrength(change);
        for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++) {
            if (contestantToUpdate->getTeam(i) != nullptr) {
                contestantToUpdate->getTeam(i)->insertContestant(contestantToUpdate);
            }
        }
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

//     Pseudo-code:
//      if contestantId <= 0
//          return StatusType::INVALID_INPUT.
//     in a try block:
//          Contestant* contestantToUpdate = find(contestantId) in contestant tree. //O(log n)
//              If contestantToUpdate == nullptr then contestantId doesn't exist
//                  return FAILURE.
//         if change == 0
//             return StatusType::SUCCESS
//        if (contestantToUpdate->getStength() - change < 0) { // O(1)
//            return StatusType::FAILURE;
//        }
//         removeContestantFromAllTeamSubtrees(contestantId); // O(log n + log m)
//         contestantToUpdate->updateStrength(change); // O(1)
//         for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++)
//                    if contestantToUpdate->teamArray[i] != nullptr
//                        contestantToUpdate->teamArray[i]->insertContestant(contestantToUpdate); // O(log n)
//    catch allocation errors
//          return StatusType::ALLOCATION_ERROR.
//    return StatusType::SUCCESS;



output_t<int> Olympics::get_strength(int contestantId){ // O(log n)
    if(contestantId <= ZERO){
        return StatusType::INVALID_INPUT;
    }
    try {
        Contestant *contestant = m_contestantTree->find(contestantId); // O(log n)
        if (contestant == nullptr) {
            return StatusType::FAILURE;
        }
        return output_t<int>(contestant->getStrength());
    }
    catch (std::bad_alloc& e){
        return output_t<int>(StatusType::ALLOCATION_ERROR);
    }
}
//     Pseudo-code:
//     if contestantId  <= 0
//          return INVALID_INPUT.
//     in try{} catch{} block:
//         Contestant* contestant = find(contestantId) in contestant tree. // O(log n)
//              If contestant == nullptr //then contestantId doesn't exist
//                  return FAILURE.
//         return output_t<int>(Contestant->getStrength());
//     If allocation failed, return output_t<int>(StatusType::FAILURE).



output_t<int> Olympics::get_medals(int countryId){ // O(log k)
    if (countryId <= ZERO){
        return StatusType::INVALID_INPUT;
    }
    try {
        Country *country = m_countryTree->find(countryId); // O(log k)
        if (country == nullptr) {
            return StatusType::FAILURE;
        }
        return output_t<int>(country->getMedals());
    }
    catch (std::bad_alloc& e){
        return output_t<int>(StatusType::ALLOCATION_ERROR);
    }
}
//     Pseudo-code:
//      if countryId  <= 0
//          return INVALID_INPUT.
//      try{} catch{} block:
//          Country* country = find(countryId) in country tree. // O(log k)
//              If country == nullptr then countryId doesn't exist
//                  return FAILURE.
//          return output_t<int>(country->getMedals()); // O(1)
//    If allocation failed, return output_t<int>(StatusType::FAILURE).



output_t<int> Olympics::get_team_strength(int teamId){ // O(log m)
    if (teamId <= ZERO){
        return StatusType::INVALID_INPUT;
    }
    try {
        Team *team = m_teamTree->find(teamId); // O(log m)
        if (team == nullptr) {
            return StatusType::FAILURE;
        }
        return output_t<int>(team->getStrength());
    }
    catch (std::bad_alloc& e){
        return output_t<int>(StatusType::ALLOCATION_ERROR);
    }
}
//	 Pseudo-code:
//     if teamId  <= 0
//         return INVALID_INPUT.
//     in try{} catch{} block:
//          Team* team = find(teamId) in team tree. // O(log m)
//          If team == nullptr then teamId doesn't exist
//              return FAILURE.
//          return output_t<int>(team->getTeamStrength()); // O(1)
//    If allocation failed, return output_t<int>(StatusType::FAILURE).




////** explanation for mergeTeams: **////

int ceilDivisionByThree(int n){
    return (n / 3) + ( (n % 3) != 0); // O(1)
}

// TODO: check if better to make mergeTeams a member function of Team class
//         return mergeTeams(team1, team2); // O(n_team_ID1 + n_team_ID2)

StatusType mergeTeams(Team* team1,Team*  team2){}
//       in a try block:

//            ID** mergedIdArray = mergeIDsToArray(team1, team2); // O(n_team_ID1 + n_team_ID2) // mergeIDsToArray needs to take care of duplicates
//            Strength** mergedStrengthArray = mergeStrengthsToArray(team1, team2); // O(n_team_ID1 + n_team_ID2) // mergeStrengthsToArray needs to take care of duplicates

//            int newTeamSize = findArrayLength(mergedIdArray) // O(n)

//            int newStrengthArraySize = findArrayLength(mergedStrengthArray) // O(n)

//            assert(newTeamSize == newStrengthArraySize)

//            //loop through mergedIdArray and for each ID, assign position to each parallelStrength:
//                for (int i = 0; i < newTeamSize; i++){ // O(n)
//                    Position currentPosition = UNASSIGNED;
//                    if (i < ceilDivisionByThree(newTeamSize)){
//                      currentPosition = LEFT;
//                    }
//                    else if (i < 2 * ceilDivisionByThree(newTeamSize)){
//                      currentPosition = MIDDLE;
//                    }
//                    else{
//                      currentPosition = RIGHT;
//                    }
//                    mergedIdArray[i]->getParallelStrength()->setPosition(currentPosition); // O(1)
//                 }

//        create three almost full ID subtrees //O(n_team_ID1 + n_team_ID2)
//              move all of mergedIdArray into the subtrees according to their m_position //O(n_team_ID1 + n_team_ID2)
//        create three almost full Strength subtrees  //O(n_team_ID1 + n_team_ID2)
//              move all of mergedStrengthArray into the subtrees according to their m_position //O(n_team_ID1 + n_team_ID2)

//        update the new team's strength // O( log (n_team_ID1 + n_team_ID2) )
//        update the new team's austerity // O( log (n_team_ID1 + n_team_ID2) )

//         team2->removeDataFromSubtrees(); // O(n_team_ID2)
//         delete team2;
//         team1->removeDataFromSubtrees(); // O(n_team_ID1)
//         team1->deleteSubtrees // O(n_team_ID1)

//         team1->assignNewSubtrees(ALL TREES) // O(1)

//      if allocation failed
//              return StatusType::ALLOCATION_ERROR
//      return StatusType::SUCCESS;






// explain mergeIDsToArray:
    // ID** mergeIDsToArray(Team* team1, Team* team2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates
    //        ID** sortedId1 = team1->getSortedArray(); // O(n_team_ID1)
    //        ID** sortedId2 = team2->getSortedArray(); // O(n_team_ID2)

    //        deleteDuplicates(sortedId2, team1->getID()); // O(n_team_ID2)
    //        moveIDsToTeam1(sortedId2, team1); // O(n_team_ID2) // switches the country pointer of the contestants to team1 instead of team 2

    //        return mergeArrays(sortedId1, sortedId2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates

// explain mergeStrengthsToArray:
//                Strength** mergeStrengthsToArray(Team* team1, Team* team2){ // O(n_team_ID1 + n_team_ID2){
//                      Strength** sortedStrength1 = team1->getSortedArray(); // O(n_team_ID1) // need to take care of duplicates
//                      Strength** sortedStrength2 = team2->getSortedArray(); // O(n_team_ID2) // need to take care of duplicates

//                      deleteDuplicates(sortedStrength2, team1->getID()); // O(n_team_ID2)
//                      return mergeArrays(sortedStrength1, sortedStrength2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates
//                }
//       }
//   }



StatusType Olympics::unite_teams(int teamId1,int teamId2) { // O(log m + n_team_ID1 + n_team_ID2)
    if (teamId1 <= ZERO || teamId2 <= ZERO || teamId1 == teamId2) {
        return StatusType::INVALID_INPUT;
    }
    try {
        Team *team1 = m_teamTree->find(teamId1);
        if (team1 == nullptr) {
            return StatusType::FAILURE;
        }
        Team *team2 = m_teamTree->find(teamId2);
        if (team2 == nullptr) {
            return StatusType::FAILURE;
        }
        if (team1->getCountryID() != team2->getCountryID()) {
            return StatusType::FAILURE;
        }
        if (team1->getSport() != team2->getSport()) {
            return StatusType::FAILURE;
        }
        return mergeTeams(team1, team2);

    } catch (std::bad_alloc &e) {
        return StatusType::ALLOCATION_ERROR;
    }
}


//     Pseudo-code:
//      if teamId1 <= 0 or teamId2 <= 0 or teamId1 == teamId2
//          return StatusType::INVALID_INPUT
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





StatusType Olympics::play_match(int teamId1, int teamId2) { // O(log k + log m)
    if (teamId1 <= ZERO || teamId2 <= ZERO || teamId1 == teamId2) {
        return StatusType::INVALID_INPUT;
    }
    try {
        Team *team1 = m_teamTree->find(teamId1); // O(log m)
        if (team1 == nullptr) {
            return StatusType::FAILURE;
        }
        Team *team2 = m_teamTree->find(teamId2); // O(log m)
        if (team2 == nullptr) {
            return StatusType::FAILURE;
        }
        if (team1->getSport() != team2->getSport()) {
            return StatusType::FAILURE;
        }
        int team1TotalScore = team1->getCountry()->getMedals() + team1->getStrength();
        int team2TotalScore = team2->getCountry()->getMedals() + team2->getStrength();
        if (team1TotalScore > team2TotalScore) {
            team1->getCountry()->addMedal();
        }
        if (team1TotalScore < team2TotalScore) {
            team2->getCountry()->addMedal();
        }
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc &e) {
        return StatusType::ALLOCATION_ERROR;
    }
}

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
//          int team1TotalScore = team1->getCountryPointer()->getMedals() + team1->getTeamStrength(); // O(1)
//          int team2TotalScore = team2->getCountryPointer()->getMedals() + team2->getTeamStrength(); // O(1)
//         if team1TotalScore > team2TotalScore
//              team1->getCountryPointer()->addMedal(); // O(1)
//         if team1TotalScore < team2TotalScore
//              team2->getCountryPointer()->addMedal(); // O(1)
// if allocation failed, return StatusType::ALLOCATION_ERROR.
// return StatusType::SUCCESS



    output_t<int> Olympics::austerity_measures(int teamId) { // O(log m)
        if (teamId <= ZERO) {
            return output_t<int>(StatusType::INVALID_INPUT);
        }
        try {
            Team *team = m_teamTree->find(teamId); // O(log m)
            if (team == nullptr) {
                return output_t<int>(StatusType::FAILURE);
            }
            if (team->getSize() < MINIMUM_AUSTERITY_TEAM_SIZE) {
                return output_t<int>(StatusType::FAILURE);
            }
            return output_t<int>(team->getAusterity()); // O(1)
        } catch (std::bad_alloc &e) {
            return output_t<int>(StatusType::ALLOCATION_ERROR);
        }
    }

//     Pseudo-code:
//      if teamId <= 0
//          return output_t<int>(StatusType::INVALID_INPUT).
//      in a try block:
//          Team* team = find teamId in team tree. // O(log m)
//              If team == nullptr then teamId doesn't exist
//                  return output_t<int>(StatusType::FAILURE).
//          if (team->getSize() < MINIMUM_AUSTERITY_TEAM_SIZE)
//              return output_t<int>(StatusType::FAILURE).
//          return output_t<int>(team->getAusterityMeasures()); // O(1)
//    If allocation failed, return output_t<int>(StatusType::FAILURE).



