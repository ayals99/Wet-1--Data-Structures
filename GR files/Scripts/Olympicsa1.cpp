#include "Olympicsa1.h"

static const int MINIMUM_AUSTERITY_TEAM_SIZE = 3;

Olympics::Olympics(){ //O(1)
    m_countryTree = new AVL_Tree<Country>(); // O(1)
    m_teamTree = new AVL_Tree<Team>(); // O(1)
    m_contestantTree = new AVL_Tree<Contestant>(); // O(1)
}

Olympics::~Olympics(){ // O(n+k+m)
    delete m_countryTree; // O(k)
    delete m_teamTree; // O(m)
    delete m_contestantTree; // O(n)
}
	
StatusType Olympics::add_country(int countryId, int medals){ // O(log k)

    if (medals < ZERO || countryId <= ZERO){
        return StatusType::INVALID_INPUT;
    }

    if (m_countryTree->find(countryId) != nullptr){ //  O(log k)
        return StatusType::FAILURE;
    }

    try {
        Country* newCountry = new Country(countryId, medals);
        m_countryTree->insert(newCountry); // O(log k)
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

//     Pseudocode:
//        check if medals <= 0 and if countryId <= 0
//             If it does, return INVALID_INPUT.
//        Check if countryId exists already.
//             If it does, return FAILURE.
//        in a try block:
//            Create a new country with no teams.
//            assign medals to the country.
//            initialize the country's team count to 0.
//            initialize the country's contestant count to 0.
//            return StatusType::SUCCESS.
//        if allocation failed, return StatusType::ALLOCATION_ERROR.

StatusType Olympics::remove_country(int countryId){ // O(log k)
    if (countryId <= 0){
        return StatusType::INVALID_INPUT;
    }
    try {
        Country* countryToDelete = m_countryTree->find(countryId); // O(log k)
        if (countryToDelete == nullptr){
            return StatusType::FAILURE;

        }
        if (countryToDelete->getTeamCounter() != ZERO || countryToDelete->getContestantCounter() != ZERO){ // O(1)
            return StatusType::FAILURE;
        }
//        delete countryToDelete;
        m_countryTree->remove(countryToDelete); // O(log k)
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}

//     Pseudocode:
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
    if (m_teamTree->find(teamId) != nullptr){ // O(log m)
        return StatusType::FAILURE;
    }
    try {
        Country* country = m_countryTree->find(countryId); // O(log k)
        if (country == nullptr){
            return StatusType::FAILURE;
        }
        Team* newTeam = new Team(teamId, countryId, sport, country);
        m_teamTree->insert(newTeam); // O(log m)
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

// Pseudocode:
//      Check if teamId <= 0 or countryId <= 0
//          If it does, return StatusType::INVALID_INPUT.
//       in a try block:
//      Check if teamId exists already.
//          If it does, return StatusType::FAILURE.
//          Find the countryId and save a pointer to the country’s instance.
//          If country does not exist, return StatusType::FAILURE.
//          All the id done in the constructor of Team:
//          Create a new team with no members.
//          initialize m_teamSize to 0.
//          initialize m_teamStrength to 0.
//          initialize m_austerityMeasures to 0.
//          Create all six Contestant Subtrees - three for ID ad three for Strength.
//          assign the team to the country by saving the country's pointer in m_countryPointer.
//      if allocation failed, return StatusType::ALLOCATION_ERROR.

StatusType Olympics::remove_team(int teamId) { // O(log m)
    if (teamId <= 0) {
        return StatusType::INVALID_INPUT;
    }
    try {
        Team *teamToDelete = m_teamTree->find(teamId); // O(log m)
        if (teamToDelete == nullptr) {
            return StatusType::FAILURE;
        }
        if (teamToDelete->getSize() != ZERO) { // O(1)
            return StatusType::FAILURE;
        }
        teamToDelete->getCountry()->decreaseTeamCounter(); // O(1)
        //TODO: We need to make sure logic is right here
        m_teamTree->remove(teamToDelete); // O(log m)

//        TODO: Make sure we do need to delete the team
//        delete teamToDelete;

        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

//     Pseudocode:
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

StatusType Olympics::add_contestant(int contestantId, int countryId, Sport sport, int strength){  // O(log n + log k)
    if (contestantId <= ZERO || countryId <= ZERO || strength < ZERO){
        return StatusType::INVALID_INPUT;
    }
    try {

        Country* country = m_countryTree->find(countryId); // O(log k)
        if (country == nullptr){
            return StatusType::FAILURE;
        }
        if (m_contestantTree->find(contestantId) != nullptr){ // O(log n)
            return StatusType::FAILURE;
        }
        Contestant* newContestant = new Contestant(contestantId, countryId, sport, strength);
        newContestant->setCountryPointer(country); // O(1)
        m_contestantTree->insert(newContestant); // O(log n)
        country->increaseContestantCounter(); // O(1)
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;

    }
}

//     Pseudocode:
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
        Contestant* contestantToDelete = m_contestantTree->find(contestantId); // O(log n)
        if (contestantToDelete == nullptr) {
            return StatusType::FAILURE;
        }
        if (contestantToDelete->registeredInATeam()) { // O(1)
            return StatusType::FAILURE;
        }
        contestantToDelete->getCountryPointer()->decreaseContestantCounter(); // O(1)
        m_contestantTree->remove(contestantToDelete); // O(log n)
        return StatusType::SUCCESS;
        }
        catch (std::bad_alloc& e){
            return StatusType::ALLOCATION_ERROR;
        }

        //        AYAL: I don't think we need this option of return FAILURE:
        //        return StatusType::FAILURE;

}

//     Pseudocode:
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
        Contestant* contestantToRegister = m_contestantTree->find(contestantId);
        if (contestantToRegister == nullptr) {
            return StatusType::FAILURE;
        }
        Team* draftingTeam = m_teamTree->find(teamId); // O(log m)
        if (draftingTeam == nullptr) {
            return StatusType::FAILURE;
        }
        if (draftingTeam->getCountryID() != contestantToRegister->getCountryID()) { // O(1)
            return StatusType::FAILURE;
        }
        if (draftingTeam->getSport() != contestantToRegister->getSport()) { // O(1)
            return StatusType::FAILURE;
        }
        for (int i = ZERO; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++) { // constant amount of iterations
            if (contestantToRegister->getTeam(i) != nullptr) {
                if (contestantToRegister->getTeam(i)->getID() == teamId) { // O(1)
                    return StatusType::FAILURE;
                }
            }
        }
        if (!contestantToRegister->isAvailable()) { // O(1)
            return StatusType::FAILURE;
        }
        draftingTeam->insertContestant(contestantToRegister); // O(log n)
        contestantToRegister->registerWithTeam(draftingTeam);
        return StatusType::SUCCESS;
    }
    catch(std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

//     Pseudocode:
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
        Contestant* contestantToUnregister = m_contestantTree->find(contestantId); // O(log n)
        if (contestantToUnregister == nullptr) {
            return StatusType::FAILURE;
        }
        Team *draftingTeam = m_teamTree->find(teamId); // O(log m)
        if (draftingTeam == nullptr) {
            return StatusType::FAILURE;
        }
        if (!contestantToUnregister->isRegisteredInTeam(teamId)){ // O(1)
            return StatusType::FAILURE;
        }
        contestantToUnregister->unregisterWithTeam(teamId); // O(1)
        draftingTeam->removeContestantFromTeam(contestantToUnregister); // O(log n)
        return StatusType::SUCCESS;
    }catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

//      Pseudocode:
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

void removeContestantFromAllTeamSubtrees(Contestant* contestant){ // O(log n)
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){ // constant amount of iterations
        if (contestant->getTeam(i) != nullptr){
            //TODO: we need to implement removeContestant in Team.cpp
            //removeContestantFromSubtrees should remove the data and then remove the node and balance the tree
            contestant->getTeam(i)->removeContestantFromSubtrees(contestant); // O(log n)
            contestant->getTeam(i)->decrementSize();
        }
    }
}

StatusType Olympics::update_contestant_strength(int contestantId ,int change){ // O(log n + log m)
    if(contestantId <= 0){
        return StatusType::INVALID_INPUT;
    }
    try {
        Contestant* contestantToUpdate = m_contestantTree->find(contestantId); // O(log n)
        if (contestantToUpdate == nullptr) {
            return StatusType::FAILURE;
        }
        if (change == ZERO) {
            return StatusType::SUCCESS;
        }
        if (contestantToUpdate->getStrength() + change < ZERO) {
            return StatusType::FAILURE;
        }

        //The function should just remove contestant from all team subtrees
        removeContestantFromAllTeamSubtrees(contestantToUpdate); // O(log n)
        contestantToUpdate->updateStrength(change);
        for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++) { // constant amount of iterations
            if (contestantToUpdate->getTeam(i) != nullptr) {
                contestantToUpdate->getTeam(i)->insertContestant(contestantToUpdate); // O(log n)
            }
        }
        return StatusType::SUCCESS;
    }
    catch (std::bad_alloc& e){
        return StatusType::ALLOCATION_ERROR;
    }
}

//     Pseudocode:
//      if contestantId <= 0
//          return StatusType::INVALID_INPUT.
//     in a try block:
//          Contestant* contestantToUpdate = find(contestantId) in contestant tree. //O(log n)
//              If contestantToUpdate == nullptr then contestantId doesn't exist
//                  return FAILURE.
//         if change == 0
//             return StatusType::SUCCESS
//        if (contestantToUpdate->getStrength() - change < 0) { // O(1)
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

//     Pseudocode:
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

//     Pseudocode:
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
        Team* team = m_teamTree->find(teamId); // O(log m)
        if (team == nullptr) {
            return StatusType::FAILURE;
        }
        return output_t<int>(team->getStrength()); // O(1)
    }
    catch (std::bad_alloc& e){
        return output_t<int>(StatusType::ALLOCATION_ERROR); // O(1)
    }
}


StatusType Olympics::unite_teams(int teamId1,int teamId2) { // O(log m + n_team_ID1 + n_team_ID2)
    if (teamId1 <= ZERO || teamId2 <= ZERO || teamId1 == teamId2) {
        return StatusType::INVALID_INPUT;
    }
    try {
        Team* team1 = m_teamTree->find(teamId1);
        if (team1 == nullptr) {
            return StatusType::FAILURE;
        }
        Team* team2 = m_teamTree->find(teamId2);
        if (team2 == nullptr) {
            return StatusType::FAILURE;
        }
        if (team1->getCountryID() != team2->getCountryID()) {
            return StatusType::FAILURE;
        }
        if (team1->getSport() != team2->getSport()) {
            return StatusType::FAILURE;
        }
        StatusType result  = team1->mergeTeams(team2); // O(n_team_ID1 + n_team_ID2)

        if (m_teamTree->remove(team2) != StatusType::SUCCESS){ // O(log m)
            return StatusType::FAILURE;
        }

        return result;
    }
    catch (std::bad_alloc &e) {
        return StatusType::ALLOCATION_ERROR;
    }
}

//     Pseudocode:
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
        Team* team1 = m_teamTree->find(teamId1); // O(log m)
        if (team1 == nullptr) {
            return StatusType::FAILURE;
        }

        Team* team2 = m_teamTree->find(teamId2); // O(log m)

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

//     Pseudocode:
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
        Team* team = m_teamTree->find(teamId); // O(log m)
        if (team == nullptr) {
            return output_t<int>(StatusType::FAILURE);
        }
        if (team->getSize() < MINIMUM_AUSTERITY_TEAM_SIZE) { // O(1)
            return output_t<int>(StatusType::FAILURE);
        }
        return output_t<int>(team->getAusterity()); // O(1)
    } catch (std::bad_alloc &e) {
        return output_t<int>(StatusType::ALLOCATION_ERROR);
    }
}

//     Pseudocode:
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