#include "Team.h"

static const int NUMBER_OF_SUBTREES = 3;
static const int ONE = 1;
static const int TWO = 2;

Team::~Team(){
    deleteSubtrees();
}

int ceilDivisionByThree(int n){
    return (n / 3) + ( (n % 3) != 0); // O(1)
}

int findArrayLength(ID** array){ // O(n)
    int i = 0;
    while (array[i] != nullptr){
        i++;
    }
    return i;
}

int findArrayLength(Strength** array){ // O(n)
    int i = 0;
    while (array[i] != nullptr){
        i++;
    }
    return i;
}

ID** mergeArrays(ID** sortedId1, ID** sortedId2){
    ID** mergedIdArray = new ID*[findArrayLength(sortedId1) + findArrayLength(sortedId2)]; // O(n_team_ID1 + n_team_ID2)
    int i = 0;
    int j = 0;
    int k = 0;
    while (sortedId1[i] != nullptr && sortedId2[j] != nullptr){
        if (sortedId2[j]->getID() >= sortedId1[i]->getID()){
            mergedIdArray[k] = sortedId1[i];
            i++;
        }
        else{
            mergedIdArray[k] = sortedId2[j];
            j++;
        }
        k++;
    }
    while (sortedId1[i] != nullptr){
        mergedIdArray[k] = sortedId1[i];
        i++;
        k++;
    }
    while (sortedId2[j] != nullptr){
        mergedIdArray[k] = sortedId2[j];
        j++;
        k++;
    }

    // delete only the pointer to the elements of array, not the instances of ID
    delete[] sortedId1;
    delete[] sortedId2;
    return mergedIdArray;
}

Strength** mergeArrays(Strength** sortedStrength1, Strength** sortedStrength2){
    Strength** mergedStrengthArray = new Strength*[findArrayLength(sortedStrength1) + findArrayLength(sortedStrength2)]; // O(n_team_ID1 + n_team_ID2)
    int i = 0;
    int j = 0;
    int k = 0;
    while (sortedStrength1[i] != nullptr && sortedStrength2[j] != nullptr){
        if (sortedStrength2[j]->getStrength() >= sortedStrength1[i]->getStrength()){
            mergedStrengthArray[k] = sortedStrength1[i];
            i++;
        }
        else{
            mergedStrengthArray[k] = sortedStrength2[j];
            j++;
        }
        k++;
    }
    while (sortedStrength1[i] != nullptr){
        mergedStrengthArray[k] = sortedStrength1[i];
        i++;
        k++;
    }
    while (sortedStrength2[j] != nullptr){
        mergedStrengthArray[k] = sortedStrength2[j];
        j++;
        k++;
    }

    // delete only the pointer to the elements of array, not the instances of Strength
    delete[] sortedStrength1;
    delete[] sortedStrength2;
    return mergedStrengthArray;
}

int findTeamIndex(Contestant* contestant, int teamId) { // O(1)
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++) {
        if (contestant->getTeam(i) != nullptr) {
            if (contestant->getTeam(i)->getID() == teamId) {
                return i;
            }
        }
    }
    return NOT_FOUND;
}

int findAmountOfIdNonDuplicates(ID** ArrayWithDuplicates, int teamId2){
    int i = 0;
    int counter = 0;
    while (ArrayWithDuplicates[i] != nullptr){
        if (findTeamIndex(ArrayWithDuplicates[i]->getContestant(), teamId2) == NOT_FOUND){
            counter++;
        }
        i++;
    }
    return counter;
}

int findAmountOfStrengthNonDuplicates(Strength** ArrayWithDuplicates, int teamId2){
    int counter = 0;
    int i = 0;
    while (ArrayWithDuplicates[i] != nullptr){
        // a Non-duplicate in sortedStrength2 will be registered in team2
        if (findTeamIndex(ArrayWithDuplicates[i]->getContestant(), teamId2) != NOT_FOUND){
            counter++;
        }
        i++;
    }
    return counter;
}

// explain deleteDuplicates:
// deleteDuplicates loops through sortedId2 and if a contestant is in both teams
// it removes the registration from team2 and leaves only him registered only in team1
// it then creates a new array with the remaining contestants which are not duplicates
// deleting the duplicate ID's instances from sortedId2WithDuplicates while doing that.

ID** deleteDuplicates(ID** ArrayWithDuplicates, int teamId2, int teamId1) { // O(n_team_ID2)
    int i = 0;

    // remove the registration from team2 and leaves only him registered only in team1
    while (ArrayWithDuplicates[i] != nullptr) {
        Contestant* contestant = ArrayWithDuplicates[i]->getContestant();
        // if he is registered in team1 as well, he is a duplicate:
        if (findTeamIndex(contestant, teamId1) != NOT_FOUND){
            int teamId2InArray = findTeamIndex(contestant, teamId2);
            contestant->removeTeam(teamId2InArray);
        }
        i++;
    }

    // create a new array with the remaining contestants which are not duplicates
    ID** sortedId2 = new ID*[findAmountOfIdNonDuplicates(ArrayWithDuplicates, teamId2)]; // O(n_team_ID2)

    int j = 0;
    while (ArrayWithDuplicates[j] != nullptr) {
        if (findTeamIndex(ArrayWithDuplicates[j]->getContestant(), teamId2) == NOT_FOUND){
            sortedId2[j] = ArrayWithDuplicates[j];
        }
        if (findTeamIndex(ArrayWithDuplicates[j]->getContestant(), teamId1) != NOT_FOUND){
            delete ArrayWithDuplicates[j]; // delete the instance of the ID.
        }
        j++;
    }
    return sortedId2;
}

Strength** deleteDuplicates(Strength** sortedStrength2, int teamId2, int teamId1) { // O(n_team_ID2)
// we run this function after we have already deleted the duplicates from the ID array
// we can recognize a duplicate in sortedStrength2 by checking if the contestant is registered in teamId1

    int i = 0;

    while (sortedStrength2[i] != nullptr) {
        if (findTeamIndex(sortedStrength2[i]->getContestant(), teamId1) != NOT_FOUND) {
            delete sortedStrength2[i]; // delete the instance of the Strength, because it is a duplicate
        }
        i++;
    }

    int newLength =  findAmountOfStrengthNonDuplicates(sortedStrength2, teamId2);
    Strength** sortedStrength2WithoutDuplicates = new Strength*[newLength]; // O(n_team_ID2)

    int j = 0;
    while (sortedStrength2[j] != nullptr) {
        if (findTeamIndex(sortedStrength2[j]->getContestant(), teamId2) != NOT_FOUND){
            sortedStrength2WithoutDuplicates[j] = sortedStrength2[j];
        }
        j++;
    }

    return sortedStrength2WithoutDuplicates;
}

void moveIDsToTeam1(ID** sortedId2, int teamId2, Team* team1) { // O(n_team_ID2)
    int i = 0;
    while (sortedId2[i] != nullptr) {
        Contestant* contestant = sortedId2[i]->getContestant();
        contestant->setTeam(findTeamIndex(contestant, teamId2), team1);
        i++;
    }
}

// explain mergeIDsToArray:
ID** mergeIDsToArray(Team* team1, Team* team2) { // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates

    // gets a sorted array of IDs from each team a
    ID** sortedId1 = team1->getSortedIdArray(); // O(n_team_ID1)
    ID** sortedId2WithDuplicates = team2->getSortedIdArray(); // O(n_team_ID2)

    // deleteDuplicates loops through sortedId2 and if a contestant is in both teams
    // it removes the registration from team2 and leaves only him registered only in team1
    // it then creates a new array with the remaining contestants which are not duplicates
    // deleting the duplicate IDs from sortedId2WithDuplicates while doing that.

    ID** sortedId2 = deleteDuplicates(sortedId2WithDuplicates, team2->getID(), team1->getID()); // O(n_team_ID2)
    delete[] sortedId2WithDuplicates; // O(n_team_ID2)

    // set all the contestants in sortedId2 to be registered in team1:
    moveIDsToTeam1(sortedId2, team2->getID(), team1); // O(n_team_ID2)

    // notice now that sorted Id2 is an array of non-duplicates only
    return mergeArrays(sortedId1, sortedId2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates
}

// explain mergeStrengthsToArray:
Strength** mergeStrengthsToArray(Team* team1, Team* team2){ // O(n_team_ID1 + n_team_ID2){
    Strength** sortedStrength1 = team1->getSortedStrengthArray(); // O(n_team_ID1)
    Strength** sortedStrength2WithDuplicates = team2->getSortedStrengthArray(); // O(n_team_ID2)
    Strength** sortedStrength2 = deleteDuplicates(sortedStrength2WithDuplicates, team2->getID(),team1->getID()); // O(n_team_ID2)
    delete[] sortedStrength2WithDuplicates; // O(n_team_ID2)
    return mergeArrays(sortedStrength1, sortedStrength2); // O(n_team_ID1 + n_team_ID2)
}

AVL_Tree<ID>* ArrayToTree(ID** array, int startIndex, int endIndex){
    AVL_Tree<ID>* newTree = new AVL_Tree<ID>(); // O(1)

    for (int i = startIndex; i < endIndex; i++){ // O(n)

    }
    return newTree;
}

AVL_Tree<Strength>* ArrayToTree(Strength** array, subtreePosition position){
    AVL_Tree<Strength>* newTree = new AVL_Tree<Strength>(); // O(1)
    int i = 0;
    while (array[i] != nullptr){
        if (array[i]->getPosition() == position){

        }
        i++;
    }
    return newTree;
}


int Team::getID() const{
    return m_id;
}

int Team::getCountryID() const{
    return m_countryID;
}
Sport Team::getSport() const{
    return m_sport;
}
int Team::getStrength() const{
    return m_strength;
}
int Team::getSize() const{
    return m_size;
}
int Team::getAusterity() const{
    return m_austerity;
}
Country* Team::getCountry() const{
    return m_country;
}

// TODO: use these functions in the implementation of Team::insertContestant() // O(log n)
//               draftingTeam->updateTeamStrength; // O(log n)
//               draftingTeam->updateAusterity();  // O(log n)

StatusType Team::insertContestant(Contestant* contestantToRegister){// O(log n)
    Strength* strength = new Strength(contestantToRegister, UNASSIGNED);
    ID* id = new ID(contestantToRegister, strength);
    assignInSubtrees(id, strength); // a lot of if statements
    balanceTrees();
    return StatusType::SUCCESS;
}

void Team::assignInSubtrees(ID* id, Strength* strength) {
//       Pseudo-code:
    int max_left_ID = m_LEFT_ID_Tree->find_Maximum_In_Subtree()->getID();
    int max_middle_ID = m_MIDDLE_ID_Tree->find_Maximum_In_Subtree()->getID();

    if (id->getID() < max_left_ID){
        m_LEFT_ID_Tree->insert(id);
        strength->setPosition(LEFT);
        m_LEFT_Strength_Tree->insert(strength);
    }
    else if (id->getID() < max_middle_ID){
        m_MIDDLE_ID_Tree->insert(id);
        strength->setPosition(MIDDLE);
        m_MIDDLE_Strength_Tree->insert(strength);
    }
    else{
        m_RIGHT_ID_Tree->insert(id);
        strength->setPosition(RIGHT);
        m_RIGHT_Strength_Tree->insert(strength);
    }
    m_size++;

}

void Team::balanceTrees(){ // (1)
//        if (this->m_size % 3 != 0){
//            return;
//        }
//        int left_size = m_LEFT_ID_Tree->getSize();
//        int middle_size = m_MIDDLE_ID_Tree->getSize();
//        int right_size = m_RIGHT_ID_Tree->getSize();
//
//      if (left size - middle size == 1 && left size - right size == 2){
//        {
//          transfer largest in left tree to middle
//          then transfer largest in middle to right
//        }
//      if (left size - middle size == 3 && left size - right size == 3){
//        transfer two from left to middle
//        then transfer one from middle to right
//      }
//      if (left size - middle size == 2 && left size - right size == 1){
//          transfer largest in left to middle
//      }

//      if (middle size - left size == 1 && middle size - right size == 2){
//        transfer largest in middle to right
//      }
//      if (middle size - left size == 3 && middle size - right size == 3){
//       transfer largest in middle to right
//       transfer smallest in middle to left
//      }
//     if (middle size - left size == 2 && middle size - right size == 1){
//       transfer smallest in middle to left
//     }

//     if (right size - left size == 1 && right size - middle size == 2){
//       transfer smallest in right to middle
//     }
//     if (right size - left size == 3 && right size - middle size == 3){
//      transfer two smallest from right to middle
//      transfer smallest from middle to left
//     }
//     if (right size - left size == 2 && right size - middle size == 1){
//      transfer smallest in right to middle
//      transfer smallest in middle to left
//     }
}

StatusType Team::mergeTeams(Team* team2) {
    try {
        ID** mergedIdArray = mergeIDsToArray(this, team2); // O(n)
        Strength** mergedStrengthArray = mergeStrengthsToArray(this, team2); // O(n)

        int newTeamSize = findArrayLength(mergedIdArray); // O(n)
        int newStrengthArraySize = findArrayLength(mergedStrengthArray); // O(n)
        assert(newTeamSize == newStrengthArraySize);

        //loop through mergedIdArray and for each ID, assign position to each parallelStrength:
        for (int i = 0; i < newTeamSize; i++){ // O(n)
            subtreePosition currentPosition = UNASSIGNED;
            if (i < ceilDivisionByThree(newTeamSize)){
                currentPosition = LEFT;
            }
            else if (i < 2 * ceilDivisionByThree(newTeamSize)){
                currentPosition = MIDDLE;
            }
            else{
                currentPosition = RIGHT;
            }
            mergedIdArray[i]->getParallelStrength()->setPosition(currentPosition); // O(1)
        }

        int startIndex = 0;

//      create three almost full ID subtrees with empty nodes //O(n_team_ID1 + n_team_ID2)
//      move all of mergedIdArray into the subtrees according to their m_position //O(n_team_ID1 + n_team_ID2)
        AVL_Tree<ID>* new_LEFT_ID_Tree = ArrayToTree(mergedIdArray, startIndex, ceilDivisionByThree(newTeamSize)); // O(n)
        AVL_Tree<ID>* new_MIDDLE_ID_Tree = ArrayToTree(mergedIdArray, ceilDivisionByThree(newTeamSize)  + 1, 2 * ceilDivisionByThree(newTeamSize)); // O(n)
        AVL_Tree<ID>* new_RIGHT_ID_Tree = ArrayToTree(mergedIdArray, 2 * ceilDivisionByThree(newTeamSize) + 1, newTeamSize); // O(n)

//        create three almost full Strength subtrees  //O(n_team_ID1 + n_team_ID2)
//              move all of mergedStrengthArray into the subtrees according to their m_position //O(n_team_ID1 + n_team_ID2)
        AVL_Tree<Strength>* new_LEFT_Strength_Tree = ArrayToTree(mergedStrengthArray, LEFT);
        AVL_Tree<Strength>* new_MIDDLE_Strength_Tree = ArrayToTree(mergedStrengthArray, MIDDLE);
        AVL_Tree<Strength>* new_RIGHT_Strength_Tree = ArrayToTree(mergedStrengthArray, RIGHT);

        delete[] mergedIdArray; // O(n)
        delete[] mergedStrengthArray; // O(n)

        team2->removeDataFromSubtrees(); // O(n_team_ID2)
        delete team2;
        this->removeDataFromSubtrees(); // O(n_team_ID1)
        this->deleteSubtrees(); // O(n_team_ID1)

        m_LEFT_ID_Tree = new_LEFT_ID_Tree;
        m_MIDDLE_ID_Tree = new_MIDDLE_ID_Tree;
        m_RIGHT_ID_Tree = new_RIGHT_ID_Tree;
        m_LEFT_Strength_Tree = new_LEFT_Strength_Tree;
        m_MIDDLE_Strength_Tree = new_MIDDLE_Strength_Tree;
        m_RIGHT_Strength_Tree = new_RIGHT_Strength_Tree;

        this->updateTeamStrength(); // O(log n)
        this->updateAusterity(); // O(log n)
    }catch(std::bad_alloc & e)
    {
        return StatusType::ALLOCATION_ERROR;
    }
    return StatusType::SUCCESS;
}

int Team::calculateTeamStrength(){
    int teamStrength = TEAM_STRENGTH_NOT_MOD_3;
    if (this->getSize() % 3 != 0){
        return teamStrength;
    }

    teamStrength += m_LEFT_Strength_Tree->find_Maximum_In_Subtree()->getStrength();
    teamStrength += m_MIDDLE_Strength_Tree->find_Maximum_In_Subtree()->getStrength();
    teamStrength += m_RIGHT_Strength_Tree->find_Maximum_In_Subtree()->getStrength();

    return teamStrength;
}

void Team::updateTeamStrength(){
    m_strength = calculateTeamStrength();
}

int Team::calculateAusterity(){
    int maxPossibleStrength = ZERO;

    if ( ( (this->getSize() - AUSTERITY_REMOVALS) % NUMBER_OF_SUBTREES ) != ZERO ){
        return maxPossibleStrength;
    }

    for (int left_removals = 0; left_removals <= AUSTERITY_REMOVALS; left_removals++){
        Contestant** LEFT_removedContestants = delete_i_from_LeftTree(left_removals);

        int right_removals = ZERO;
        int middle_removals = ZERO;

        while (right_removals <= AUSTERITY_REMOVALS - left_removals) {
            Contestant **RIGHT_removedContestants = delete_k_from_RightTree(right_removals);

            middle_removals = AUSTERITY_REMOVALS - left_removals - right_removals;


            if (middle_removals == ONE && right_removals == TWO || middle_removals == ONE && left_removals == TWO) {
//               first case: remove the border ID.

                ID *borderID = nullptr;
                if (right_removals == TWO) {
                    borderID = m_MIDDLE_ID_Tree->find_Maximum_In_Subtree();
                } else {
                    borderID = m_MIDDLE_ID_Tree->find_Minimum_In_Subtree();
                }
                Contestant *removedContestant = borderID->getContestant();
                Strength *removedStrength = borderID->getParallelStrength();

                m_MIDDLE_ID_Tree->remove(borderID);
                m_MIDDLE_Strength_Tree->remove(removedStrength);

                updateMAXPossibleStrength();

                // Saving the weakest strength without the border ID.
                Strength *weakestStrengthWithoutBorder = m_MIDDLE_Strength_Tree->find_Minimum_In_Subtree();
                Contestant *weakestContestantWithoutBorder = weakestStrengthWithoutBorder->getContestant();
                ID *weakestIDWithoutBorder = m_MIDDLE_ID_Tree->find(weakestStrengthWithoutBorder->getID());

                m_MIDDLE_ID_Tree->insert(borderID);
                m_MIDDLE_Strength_Tree->insert(removedStrength);
                m_size++;

//               second case: the smallest Strength in the group that's left without the border ID.
                m_MIDDLE_ID_Tree->remove(weakestIDWithoutBorder);
                m_MIDDLE_Strength_Tree->remove(weakestStrengthWithoutBorder);
                m_size--;
                updateMAXPossibleStrength();
                m_MIDDLE_ID_Tree->insert(weakestIDWithoutBorder);
                m_MIDDLE_Strength_Tree->insert(weakestStrengthWithoutBorder);
                m_size++;
            } else {
                Contestant **MIDDLE_removedContestants = delete_j_from_MiddleTree(middle_removals);
                updateMAXPossibleStrength();
                reinsert_j_to_MiddleTree(MIDDLE_removedContestants, middle_removals);
                delete[] MIDDLE_removedContestants;
            }


            if (left_removals + middle_removals + right_removals == AUSTERITY_REMOVALS) {
                updateMAXPossibleStrength();
            }
            reinsert_k_to_RightTree(RIGHT_removedContestants, right_removals);
            right_removals++;
            delete[] RIGHT_removedContestants;
        }

            if (left_removals + middle_removals + right_removals == AUSTERITY_REMOVALS) {
                updateMAXPossibleStrength();
            }
            reinsert_i_to_LeftTree(LEFT_removedContestants, left_removals);
            delete[] LEFT_removedContestants;
    }

    return maxPossibleStrength;
}


void Team::updateAusterity(){
    m_austerity = calculateAusterity();
}

void Team::updateMAXPossibleStrength(){
    int currentAusterityStrength = calculateTeamStrength();
    if (currentAusterityStrength > m_austerity){
        m_austerity = currentAusterityStrength;
    }
}

Contestant** Team::delete_i_from_LeftTree(int i){
    Contestant** LEFT_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    for (int t = 0; t < i; t++){
        Strength* removedStrength = m_LEFT_Strength_Tree->find_Minimum_In_Subtree(); // O(log(n))
        ID* removedID = m_LEFT_ID_Tree->find(removedStrength->getID()); // O(log(n))
        LEFT_removedContestants[t] = removedID->getContestant();

        m_LEFT_ID_Tree->remove(removedID);
        m_LEFT_Strength_Tree->remove(removedStrength);
        m_size--;
    }
    return LEFT_removedContestants;
}

Contestant** Team::delete_j_from_MiddleTree(int j){
    Contestant** MIDDLE_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    for (int m = 0; m < j; m++){
        Strength* removedStrength = m_MIDDLE_Strength_Tree->find_Minimum_In_Subtree();
        ID* removedID_MIDDLE = m_MIDDLE_ID_Tree->find(removedStrength->getID());
        MIDDLE_removedContestants[m] = removedID_MIDDLE->getContestant();

        m_MIDDLE_ID_Tree->remove(removedID_MIDDLE);
        m_MIDDLE_Strength_Tree->remove(removedStrength);
        m_size--;
    }
    return MIDDLE_removedContestants;
}

Contestant** Team::delete_k_from_RightTree(int k){
    Contestant** RIGHT_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    for (int n = 0; n < k; n++){
        Strength* removedStrength = m_RIGHT_Strength_Tree->find_Minimum_In_Subtree();// O(log(n))
        ID* removedID = m_RIGHT_ID_Tree->find(removedStrength->getID());// O(log(n))
        RIGHT_removedContestants[n] = removedID->getContestant();

        m_RIGHT_ID_Tree->remove(removedID);
        m_RIGHT_Strength_Tree->remove(removedStrength);
        m_size--;
    }
    return RIGHT_removedContestants;
}

void Team::reinsert_i_to_LeftTree(Contestant** LEFT_removedContestants, int i){
    for(int t = 0; t < i; t++){
        Strength* strengthToInsert = new Strength(LEFT_removedContestants[t], LEFT);
        ID* idToInsert = new ID(LEFT_removedContestants[t], strengthToInsert);
        m_LEFT_ID_Tree->insert(idToInsert);
        m_LEFT_Strength_Tree->insert(strengthToInsert);
        m_size++;
    }
}

void Team::reinsert_j_to_MiddleTree(Contestant** MIDDLE_removedContestants, int j){
    for(int m = 0; m < j; m++){
        Strength* strengthToInsert = new Strength(MIDDLE_removedContestants[m], MIDDLE);
        ID* idToInsert = new ID(MIDDLE_removedContestants[m], strengthToInsert);
        m_MIDDLE_ID_Tree->insert(idToInsert);
        m_MIDDLE_Strength_Tree->insert(strengthToInsert);
        m_size++;
    }
}

void Team::reinsert_k_to_RightTree(Contestant** RIGHT_removedContestants, int k){
    for (int n = 0; n < k; n++){
        Strength* strengthToInsert = new Strength(RIGHT_removedContestants[n], RIGHT);
        ID* idToInsert = new ID(RIGHT_removedContestants[n], strengthToInsert);
        m_RIGHT_ID_Tree->insert(idToInsert);
        m_RIGHT_Strength_Tree->insert(strengthToInsert);
        m_size++;
    }
}

void Team::removeDataFromSubtrees(){
    m_LEFT_ID_Tree->removeDataFromTree();
    m_MIDDLE_ID_Tree->removeDataFromTree();
    m_RIGHT_ID_Tree->removeDataFromTree();
    m_LEFT_Strength_Tree->removeDataFromTree();
    m_MIDDLE_Strength_Tree->removeDataFromTree();
    m_RIGHT_Strength_Tree->removeDataFromTree();
}

void Team::deleteSubtrees(){
    delete m_LEFT_ID_Tree;
    delete m_MIDDLE_ID_Tree;
    delete m_RIGHT_ID_Tree;
    delete m_LEFT_Strength_Tree;
    delete m_MIDDLE_Strength_Tree;
    delete m_RIGHT_Strength_Tree;
}

void Team::assignNewSubtrees(AVL_Tree<ID>* LEFT_ID_Tree,
                       AVL_Tree<ID>* MIDDLE_ID_Tree,
                       AVL_Tree<ID>* RIGHT_ID_Tree,
                       AVL_Tree<Strength>* LEFT_Strength_Tree,
                       AVL_Tree<Strength>* MIDDLE_Strength_Tree,
                       AVL_Tree<Strength>* RIGHT_Strength_Tree){
    m_LEFT_ID_Tree = LEFT_ID_Tree;
    m_MIDDLE_ID_Tree = MIDDLE_ID_Tree;
    m_RIGHT_ID_Tree = RIGHT_ID_Tree;
    m_LEFT_Strength_Tree = LEFT_Strength_Tree;
    m_MIDDLE_Strength_Tree = MIDDLE_Strength_Tree;
    m_RIGHT_Strength_Tree = RIGHT_Strength_Tree;
}

ID** Team::getSortedIdArray() const{
    ID** sortedIDArray = new ID*[m_size];
    int index = 0;
    return sortedIDArray;
}

Strength** Team::getSortedStrengthArray() const{
    Strength** sortedStrengthArray = new Strength*[m_size];
    return sortedStrengthArray;
}

void Team::removeContestantFromTeam(Contestant* contestant) {
    removeContestantFromSubtrees(contestant); // O(log(n)
    m_size--;
    //update the team strength
    this->updateTeamStrength(); // O(log(n)
    //update the team austerity
    this->updateAusterity(); // O(log(n)

    //update the contestant's team array:
    int indexInContestant = findTeamIndex(contestant,this->getID());
    contestant->removeTeam(indexInContestant);

}

void Team::removeContestantFromSubtrees(Contestant *contestant) {
    int contestantID = contestant->getID();

    // check left subtree:

    ID* matchingID = m_LEFT_ID_Tree->find(contestantID); // O(log(n)
    if (matchingID != nullptr){ // if the contestant is in the left subtree
        m_LEFT_Strength_Tree->remove(matchingID->getParallelStrength()); // O(log(n)
        m_LEFT_ID_Tree->remove(matchingID); // O(log(n)

    }

        // if the contestant is not in the left subtree, check the middle subtree
    else if(m_MIDDLE_ID_Tree->find(contestantID) != nullptr){
        matchingID = m_MIDDLE_ID_Tree->find(contestantID); // O(log(n)
        m_MIDDLE_Strength_Tree->remove(matchingID->getParallelStrength()); // O(log(n)
        m_MIDDLE_ID_Tree->remove(matchingID); // O(log(n)
    }
    else{ // if the contestant is not in the left or middle subtree, he must be in the right subtree
        matchingID = m_RIGHT_ID_Tree->find(contestantID); // O(log(n)
        m_RIGHT_Strength_Tree->remove(matchingID->getParallelStrength()); // O(log(n)
        m_RIGHT_ID_Tree->remove(matchingID); // O(log(n)
    }
}