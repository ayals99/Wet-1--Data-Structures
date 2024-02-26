#include "Contestant_Country_ID_Strength_Team.h"


static const int NUMBER_OF_SUBTREES = 3;
static const int ONE = 1;
static const int TWO = 2;
static const int THREE = 3;


////** Team  **////

Team::~Team(){
    deleteSubtrees();
}

int ceilDivisionByThree(int n){
    return (n / 3) + ( (n % 3) != 0); // O(1)
}


ID** mergeArrays(ID** sortedId1, ID** sortedId2, int length1, int length2){
    if (length1 == ZERO && length2 == ZERO) {
        delete[] sortedId1;
        delete[] sortedId2;
        return nullptr;
    }

    // if arrived here, that means that at least one of the arrays is not empty
    ID** mergedIdArray = new ID*[length1 + length2]; // O(n_team_ID1 + n_team_ID2)

    int i = 0;
    int j = 0;
    int k = 0;
    if(length1 != ZERO && length2 != ZERO){
        while (i < length1 && j < length2) {
            if (sortedId2[j]->getID() >= sortedId1[i]->getID()) {
                mergedIdArray[k] = sortedId1[i];
                i++;
            } else {
                mergedIdArray[k] = sortedId2[j];
                j++;
            }
            k++;
        }
    }
    if (length1 != ZERO){
        while (i < length1) {
            mergedIdArray[k] = sortedId1[i];
            i++;
            k++;
        }
    }
    if (length2 != ZERO) {
        while (j < length2) {
            mergedIdArray[k] = sortedId2[j];
            j++;
            k++;
        }
    }

    // delete only the pointer to the elements of array, not the instances of ID
    delete[] sortedId1;
    delete[] sortedId2;
    return mergedIdArray;
}

Strength** mergeArrays(Strength** sortedStrength1, Strength** sortedStrength2, int length1, int length2){
    if (length1 == ZERO && length2 == ZERO) {
        delete[] sortedStrength1;
        delete[] sortedStrength2;
        return nullptr;
    }

    Strength** mergedStrengthArray = new Strength*[length1 + length2]; // O(n_team_ID1 + n_team_ID2)
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < length1 && j < length2){
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
    while (i < length1){
        mergedStrengthArray[k] = sortedStrength1[i];
        i++;
        k++;
    }
    while (j < length2){
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

int findAmountOfIdNonDuplicates(ID** ArrayWithDuplicates, int arrayLength, int teamId2){
    int counter = 0;
    for(int i = 0; i < arrayLength; i++){ // O(n_team_ID2
        if (findTeamIndex(ArrayWithDuplicates[i]->getContestant(), teamId2) == NOT_FOUND){
            counter++;
        }

    }
    return counter;
}

int findAmountOfStrengthNonDuplicates(Strength** ArrayWithDuplicates,int arrayLength, int teamId2){
    int counter = 0;

    for (int i = 0; i < arrayLength; i++){ // O(n_team_ID2
        // a Non-duplicate in sortedStrength2 will be registered in team2
        if (findTeamIndex(ArrayWithDuplicates[i]->getContestant(), teamId2) != NOT_FOUND){
            counter++;
        }
    }
    return counter;
}

// explain deleteDuplicates:
// deleteDuplicates loops through sortedId2 and if a contestant is in both teams
// it removes the registration from team2 and leaves only him registered only in team1
// it then creates a new array with the remaining contestants which are not duplicates
// deleting the duplicate ID's instances from sortedId2WithDuplicates while doing that.

ID** deleteDuplicates(ID** ArrayWithDuplicates, int arrayLength, int teamId2, int teamId1, int& newArraySize) { // O(n_team_ID2)

    // remove the registration from team2 and leaves only him registered only in team1
    for (int i = 0; i < arrayLength; ++i) {
        Contestant* contestant = ArrayWithDuplicates[i]->getContestant();
        // if he is registered in team1 as well, he is a duplicate:
        if (findTeamIndex(contestant, teamId1) != NOT_FOUND){
            int teamId2InArray = findTeamIndex(contestant, teamId2);
            contestant->removeTeam(teamId2InArray);
        }
    }

    // create a new array with the remaining contestants which are not duplicates
    newArraySize  = findAmountOfIdNonDuplicates(ArrayWithDuplicates,arrayLength, teamId2);
    ID** sortedId2 = new ID*[newArraySize]; // O(n_team_ID2)


    for (int j = 0; j < newArraySize; j++){ // O(n_team_ID2
        if (findTeamIndex(ArrayWithDuplicates[j]->getContestant(), teamId2) == NOT_FOUND){
            sortedId2[j] = ArrayWithDuplicates[j];
        }
        if (findTeamIndex(ArrayWithDuplicates[j]->getContestant(), teamId1) != NOT_FOUND){
            delete ArrayWithDuplicates[j]; // delete the instance of the ID.
        }
    }
    return sortedId2;
}

Strength** deleteDuplicates(Strength** sortedStrength2, int sortedStrength2Length, int teamId2, int teamId1, int& newArraySize) { // O(n_team_ID2)
// we run this function after we have already deleted the duplicates from the ID array
// we can recognize a duplicate in sortedStrength2 by checking if the contestant is registered in teamId1
    for(int i = 0; i < sortedStrength2Length; i++){ // O(n_team_ID2)
        if (findTeamIndex(sortedStrength2[i]->getContestant(), teamId1) != NOT_FOUND) {
            delete sortedStrength2[i]; // delete the instance of the Strength, because it is a duplicate
        }
    }

    newArraySize =  findAmountOfStrengthNonDuplicates(sortedStrength2,sortedStrength2Length, teamId2);

    Strength** sortedStrength2WithoutDuplicates = new Strength*[newArraySize]; // O(n_team_ID2)

    for(int j = 0; j< newArraySize; j++){
        if (findTeamIndex(sortedStrength2[j]->getContestant(), teamId2) != NOT_FOUND){
            sortedStrength2WithoutDuplicates[j] = sortedStrength2[j];
        }
    }

    return sortedStrength2WithoutDuplicates;
}

void moveIDsToTeam1(ID** sortedId2,int length_sortedId2, int teamId2, Team* team1) { // O(n_team_ID2)
    for (int i = 0; i < length_sortedId2; i++){
        Contestant* contestant = sortedId2[i]->getContestant();
        contestant->setTeam(findTeamIndex(contestant, teamId2), team1);
    }
}

// explain mergeIDsToArray:
ID** mergeIDsToArray(Team* team1, Team* team2, int& newTeamSize) { // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates

    // gets a sorted array of IDs from each team:
    ID** sortedId1 = team1->getSortedIdArray(); // O(n_team_ID1)
    ID** sortedId2WithDuplicates = team2->getSortedIdArray(); // O(n_team_ID2)
    // TODO: add cases of null pointers to arrays
    if (sortedId1 == nullptr && sortedId2WithDuplicates == nullptr){
        return nullptr;
    }
    if (sortedId1 == nullptr){
        return sortedId2WithDuplicates;
    }
    if (sortedId2WithDuplicates == nullptr){
        return sortedId1;
    }
    int lengthSorted1 = team1->getSize();
    int lengthSortedWithDuplicates2 = team2->getSize();

    // deleteDuplicates loops through sortedId2 and if a contestant is in both teams
    // it removes the registration from team2 and leaves only him registered only in team1
    // it then creates a new array with the remaining contestants which are not duplicates
    // deleting the duplicate IDs from sortedId2WithDuplicates while doing that.

    int lengthSorted2 = 0;
    ID** sortedId2 = deleteDuplicates(sortedId2WithDuplicates, lengthSortedWithDuplicates2, team2->getID(), team1->getID(), lengthSorted2); // O(n_team_ID2)
    delete[] sortedId2WithDuplicates; // O(n_team_ID2)

    newTeamSize = lengthSorted1 + lengthSorted2;

    // set all the contestants in sortedId2 to be registered in team1:
    moveIDsToTeam1(sortedId2,lengthSorted2, team2->getID(), team1); // O(n_team_ID2)

    // notice now that sorted Id2 is an array of non-duplicates only
    return mergeArrays(sortedId1, sortedId2, lengthSorted1, lengthSorted2); // O(n_team_ID1 + n_team_ID2) // need to take care of duplicates
}

// explain mergeStrengthsToArray:
Strength** mergeStrengthsToArray(Team* team1, Team* team2){ // O(n_team_ID1 + n_team_ID2){
    Strength** sortedStrength1 = team1->getSortedStrengthArray(); // O(n_team_ID1)
    Strength** sortedStrength2WithDuplicates = team2->getSortedStrengthArray(); // O(n_team_ID2)

    if (sortedStrength1 == nullptr && sortedStrength2WithDuplicates == nullptr){
        return nullptr;
    }
    if (sortedStrength1 == nullptr){
        return sortedStrength2WithDuplicates;
    }
    if (sortedStrength2WithDuplicates == nullptr){
        return sortedStrength1;
    }
    int lengthSortedStrength2 = ZERO;
    Strength** sortedStrength2 = deleteDuplicates(sortedStrength2WithDuplicates, team2->getSize(), team2->getID(), team1->getID(), lengthSortedStrength2); // O(n_team_ID2)

    delete[] sortedStrength2WithDuplicates; // O(n_team_ID2)

    return mergeArrays(sortedStrength1, sortedStrength2, team1->getSize(), lengthSortedStrength2); // O(n_team_ID1 + n_team_ID2)
}



// As we learned in the recitation:
AVL_Tree<ID>* ArrayToTree(ID** array, int numberOfElements){
    AVL_Tree<ID>* newTree = createEmptyTree<ID>(numberOfElements); // O(n)
    insertArrayToTree(array, newTree); // O(n)
    return newTree;
}

int countStrengthsWithPOSITIONInArray(Strength** array, int arrayLength,subtreePosition position){
    assert(array != nullptr);
    int counter = 0;
    for(int i = 0; i < arrayLength; i++){
        if (array[i]->getPosition() == position){
            counter++;
        }
    }
    return counter;
}

AVL_Tree<Strength>* ArrayToTree(Strength** strengthArray, int arrayLength, subtreePosition position) { // O(n)

    int numberOfElements = countStrengthsWithPOSITIONInArray(strengthArray, arrayLength, position); // O(n)

    AVL_Tree<Strength>* newTree = createEmptyTree<Strength>(numberOfElements); // O(n)

    Strength** POSITION_Array = new Strength*[numberOfElements]; // O(n)

    //
    int POSITION_Array_index = 0;
    for (int i = 0; i < arrayLength; i++){ // O(n)
        if (strengthArray[i]->getPosition() == position){ // O(1)
            POSITION_Array[POSITION_Array_index] = strengthArray[i]; // O(1)
            POSITION_Array_index++;
        }
    }

    insertArrayToTree(POSITION_Array, newTree); // O(n)
    delete[] POSITION_Array;// O(n)
    return newTree; // O(1)
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
    assert (contestantToRegister != nullptr);

    Strength* strength = new Strength(contestantToRegister, UNASSIGNED);
    ID* id = new ID(contestantToRegister, strength);
    assignInSubtrees(id, strength); // a lot of if statements
    balanceTrees(); //
    updateTeamStrength(); // O(log n)
    updateAusterity(); // O(log n)
    return StatusType::SUCCESS;
}

void Team::assignInSubtrees(ID* id, Strength* strength) {
//       Pseudo-code:
    assert (id != nullptr);
    assert (strength != nullptr);

    int max_left_ID = NOT_FOUND;
    if(m_LEFT_ID_Tree->find_Maximum_In_Subtree() == nullptr || m_MIDDLE_ID_Tree->find_Maximum_In_Subtree() == nullptr){ // O(log n)
        m_LEFT_ID_Tree->insert(id);
        strength->setPosition(LEFT);
        m_LEFT_Strength_Tree->insert(strength);
        m_size++;
        return;
    }
    else{
        max_left_ID = m_LEFT_ID_Tree->find_Maximum_In_Subtree()->getID();
    }

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

void moveLargestIDFromTree1ToTree2(AVL_Tree<ID>* IdTree1, AVL_Tree<ID>* IdTree2,
                                   AVL_Tree<Strength>* StrengthTree1,
                                   AVL_Tree<Strength>* StrengthTree2){
    ID* largestID = IdTree1->find_Maximum_In_Subtree();
    Contestant* largestContestant = largestID->getContestant();
    Strength* largestIdStrength = largestID->getParallelStrength();
    IdTree1->remove(largestID);

    subtreePosition position = largestIdStrength->getPosition();
    if (position == LEFT){
        position = MIDDLE;
    }
    else if (position == MIDDLE){
        position = RIGHT;
    }

    Strength* strengthToInsert = new Strength(largestContestant, position);
    StrengthTree1->remove(largestIdStrength);

    ID* idToInsert = new ID(largestContestant, strengthToInsert);
    IdTree2->insert(idToInsert);
    StrengthTree2->insert(strengthToInsert);
}

void moveSmallestIDFromTree1ToTree2(AVL_Tree<ID>* IdTree1, AVL_Tree<ID>* IdTree2,
                                   AVL_Tree<Strength>* StrengthTree1,
                                   AVL_Tree<Strength>* StrengthTree2){
    ID* smallestId = IdTree1->find_Minimum_In_Subtree();
    Contestant* smallestContestant = smallestId->getContestant();
    Strength* weakestStrength = IdTree1->find(smallestId)->getParallelStrength();
    IdTree1->remove(smallestId);

    subtreePosition position = weakestStrength->getPosition();
    if (position == RIGHT){
        position = MIDDLE;
    }
    else if (position == MIDDLE){
        position = LEFT;
    }
    Strength* strengthToInsert = new Strength(smallestContestant, position);
    ID* idToInsert = new ID(smallestContestant, strengthToInsert);
    StrengthTree1->remove(weakestStrength);

    IdTree2->insert(idToInsert);
    StrengthTree2->insert(strengthToInsert);
}

void Team::balanceTrees(){ // (1)
    if (this->m_size % 3 != 0){
        return;
    }
    int left_size = m_LEFT_ID_Tree->getSize();
    int middle_size = m_MIDDLE_ID_Tree->getSize();
    int right_size = m_RIGHT_ID_Tree->getSize();

    // TODO: add cases of empty subTrees
    if (left_size - middle_size == 1 && left_size - right_size == 2){
//          transfer largest in left tree to middle:
        moveLargestIDFromTree1ToTree2(m_LEFT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_LEFT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);

//          then transfer largest in middle to right
        moveLargestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_RIGHT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_RIGHT_Strength_Tree);
    }
    if (left_size - middle_size == 3 && left_size - right_size == 3){
//        transfer two from left to middle
        moveLargestIDFromTree1ToTree2(m_LEFT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_LEFT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
        moveLargestIDFromTree1ToTree2(m_LEFT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_LEFT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
//        then transfer one from middle to right
        moveLargestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_RIGHT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_RIGHT_Strength_Tree);
    }
    if (left_size - middle_size == 2 && left_size - right_size == 1){
//          transfer largest in left to middle
        moveLargestIDFromTree1ToTree2(m_LEFT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_LEFT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
    }

    if (middle_size - left_size == 1 && middle_size - right_size == 2){
//        transfer largest in middle to right
        moveLargestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_RIGHT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_RIGHT_Strength_Tree);
    }
    if (middle_size - left_size == 3 && middle_size - right_size == 3){
//       transfer largest in middle to right
        moveLargestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_RIGHT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_RIGHT_Strength_Tree);
//       transfer smallest in middle to left:
        moveSmallestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_LEFT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_LEFT_Strength_Tree);
    }
    if (middle_size - left_size == 2 && middle_size - right_size == 1){
//       transfer smallest in middle to left;
        moveSmallestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_LEFT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_LEFT_Strength_Tree);
    }

    if (right_size - left_size == 1 && right_size - middle_size == 2){
//       transfer smallest in right to middle:
        moveSmallestIDFromTree1ToTree2(m_RIGHT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_RIGHT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
    }

    if (right_size - left_size == 3 && right_size - middle_size == 3){
//      transfer two smallest from right to middle:
        moveSmallestIDFromTree1ToTree2(m_RIGHT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_RIGHT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
        moveSmallestIDFromTree1ToTree2(m_RIGHT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_RIGHT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
//      transfer smallest from middle to left:
        moveSmallestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_LEFT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_LEFT_Strength_Tree);
 }

     if (right_size - left_size == 2 && right_size - middle_size == 1){
//      transfer smallest in right to middle:
        moveSmallestIDFromTree1ToTree2(m_RIGHT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_RIGHT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
//      transfer smallest in middle to left:
        moveSmallestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_LEFT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_LEFT_Strength_Tree);
     }
     if (left_size - middle_size == 3 && right_size - middle_size == 3){
//      transfer
         moveLargestIDFromTree1ToTree2(m_LEFT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_LEFT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
         moveSmallestIDFromTree1ToTree2(m_RIGHT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_RIGHT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
     }
    if (left_size - right_size == 3 && middle_size - right_size == 3){
        moveLargestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_RIGHT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_RIGHT_Strength_Tree);
        moveLargestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_RIGHT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_RIGHT_Strength_Tree);
        moveLargestIDFromTree1ToTree2(m_LEFT_ID_Tree,
                                      m_MIDDLE_ID_Tree,
                                      m_LEFT_Strength_Tree,
                                      m_MIDDLE_Strength_Tree);
    }
    if (middle_size - left_size == 3 && right_size - left_size == 3){
        moveSmallestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                      m_LEFT_ID_Tree,
                                      m_MIDDLE_Strength_Tree,
                                      m_LEFT_Strength_Tree);
        moveSmallestIDFromTree1ToTree2(m_MIDDLE_ID_Tree,
                                       m_LEFT_ID_Tree,
                                       m_MIDDLE_Strength_Tree,
                                       m_LEFT_Strength_Tree);
        moveSmallestIDFromTree1ToTree2(m_RIGHT_ID_Tree,
                                       m_MIDDLE_ID_Tree,
                                       m_RIGHT_Strength_Tree,
                                       m_MIDDLE_Strength_Tree);
    }
}

StatusType Team::mergeTeams(Team* team2) {
    try {
        int newTeamSize = 0;
        ID** mergedIdArray = mergeIDsToArray(this, team2, newTeamSize); // O(n)

        Strength** mergedStrengthArray = mergeStrengthsToArray(this, team2); // O(n)

        int leftTreeSize = ceilDivisionByThree(newTeamSize);
        int middleTreeSize = ceilDivisionByThree(newTeamSize);
        int rightTreeSize = newTeamSize - leftTreeSize - middleTreeSize;

        //loop through mergedIdArray and for each ID, assign position to each parallelStrength:
        for (int i = 0; i < newTeamSize; i++){ // O(n)
            subtreePosition currentPosition = UNASSIGNED;
            if (i < leftTreeSize){
                currentPosition = LEFT;
            }
            else if (i < leftTreeSize + middleTreeSize + 1){
                currentPosition = MIDDLE;
            }
            else{
                currentPosition = RIGHT;
            }
            mergedIdArray[i]->getParallelStrength()->setPosition(currentPosition); // O(1)
        }



//      create three almost full ID subtrees with empty nodes //O(n_team_ID1 + n_team_ID2)
//      move all of mergedIdArray into the subtrees according to their m_position //O(n_team_ID1 + n_team_ID2)
        int startIndex = 0;
        AVL_Tree<ID>* new_LEFT_ID_Tree = ArrayToTree(mergedIdArray, leftTreeSize); // O(n)

        startIndex += leftTreeSize;
        AVL_Tree<ID>* new_MIDDLE_ID_Tree = ArrayToTree(mergedIdArray + startIndex -1, middleTreeSize); // O(n)

        startIndex += middleTreeSize;
        AVL_Tree<ID>* new_RIGHT_ID_Tree = ArrayToTree(mergedIdArray + startIndex - 1, rightTreeSize); // O(n)

//        create three almost full Strength subtrees  //O(n_team_ID1 + n_team_ID2)
//              move all of mergedStrengthArray into the subtrees according to their m_position //O(n_team_ID1 + n_team_ID2)
        AVL_Tree<Strength>* new_LEFT_Strength_Tree = ArrayToTree(mergedStrengthArray, leftTreeSize  , LEFT);
        AVL_Tree<Strength>* new_MIDDLE_Strength_Tree = ArrayToTree(mergedStrengthArray, middleTreeSize , MIDDLE);
        AVL_Tree<Strength>* new_RIGHT_Strength_Tree = ArrayToTree(mergedStrengthArray, rightTreeSize, RIGHT);

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
    if (this->getSize() == ZERO || this->getSize() % 3 != 0){
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
int max(int a , int b){
    if (a > b){
        return a;
    }
    return b;
}




//int Team::calculateAusterity(){
//    int maxPossibleStrength = ZERO;
//
//    if (this->getSize() == ZERO){
//        return ZERO;
//    }
//
//    if ( ( (this->getSize() - AUSTERITY_REMOVALS) % NUMBER_OF_SUBTREES ) != ZERO ){
//        return ZERO;
//    }
//
//    for (int left_removals = 0; left_removals <= AUSTERITY_REMOVALS; left_removals++){
//        if (left_removals > m_LEFT_ID_Tree->getSize()){
//            continue;
//        }
//
//        Contestant** LEFT_removedContestants = delete_i_from_LeftTree(left_removals);
//
//        int right_removals = ZERO;
//        int middle_removals = ZERO;
//
//        while (right_removals <= AUSTERITY_REMOVALS - left_removals) {
//            if (right_removals > m_RIGHT_ID_Tree->getSize()){
//                continue;
//            }
//            Contestant** RIGHT_removedContestants = delete_k_from_RightTree(right_removals);
//
//            middle_removals = AUSTERITY_REMOVALS - left_removals - right_removals;
//
//
//            if (middle_removals == ONE && right_removals == TWO || middle_removals == ONE && left_removals == TWO) {
////               first case: remove the border ID.
//
//                ID* borderID = nullptr;
//                if (right_removals == TWO) {
//                    borderID = m_MIDDLE_ID_Tree->find_Maximum_In_Subtree();
//                }
//                else {
//                    borderID = m_MIDDLE_ID_Tree->find_Minimum_In_Subtree();
//                }
//                Contestant *removedContestant = borderID->getContestant();
//                Strength *removedStrength = borderID->getParallelStrength();
//
//                m_MIDDLE_ID_Tree->remove(borderID);
//                m_MIDDLE_Strength_Tree->remove(removedStrength);
//
//                // TODO: balance tree somehow so we can check the maximum strength in the new subtree
//                maxPossibleStrength = max(maxPossibleStrength, calculateTeamStrength());
//
//
//                // Saving the weakest strength without the border ID.
//                Strength* weakestStrengthWithoutBorder = m_MIDDLE_Strength_Tree->find_Minimum_In_Subtree();
//                Contestant* weakestContestantWithoutBorder = weakestStrengthWithoutBorder->getContestant();
//                ID* weakestIDWithoutBorder = m_MIDDLE_ID_Tree->find(weakestStrengthWithoutBorder->getID());
//
//                m_MIDDLE_ID_Tree->insert(borderID);
//                m_MIDDLE_Strength_Tree->insert(removedStrength);
//                m_size++;
//
////              second case: the smallest Strength in the group that's left without the border ID.
//                m_MIDDLE_ID_Tree->remove(weakestIDWithoutBorder);
//                m_MIDDLE_Strength_Tree->remove(weakestStrengthWithoutBorder);
//                m_size--;
//                maxPossibleStrength = max(maxPossibleStrength, calculateTeamStrength());
//                m_MIDDLE_ID_Tree->insert(weakestIDWithoutBorder);
//                m_MIDDLE_Strength_Tree->insert(weakestStrengthWithoutBorder);
//                m_size++;
//            }
//            else {
//                if (middle_removals > m_MIDDLE_ID_Tree->getSize()){
//                    break;
//                }
//                Contestant** MIDDLE_removedContestants = delete_j_from_MiddleTree(middle_removals);
//                maxPossibleStrength = max(maxPossibleStrength, calculateTeamStrength());
//                reinsert_j_to_MiddleTree(MIDDLE_removedContestants, middle_removals);
//                delete[] MIDDLE_removedContestants;
//            }
//
//            if (left_removals + middle_removals + right_removals == AUSTERITY_REMOVALS) {
//                maxPossibleStrength = max(maxPossibleStrength, calculateTeamStrength());
//            }
//            reinsert_k_to_RightTree(RIGHT_removedContestants, right_removals);
//            right_removals++;
//            delete[] RIGHT_removedContestants;
//        }
//
//        if (left_removals + middle_removals + right_removals == AUSTERITY_REMOVALS) {
//            maxPossibleStrength = max(maxPossibleStrength, calculateTeamStrength());
//        }
//        reinsert_i_to_LeftTree(LEFT_removedContestants, left_removals);
//        delete[] LEFT_removedContestants;
//    }
//
//    return maxPossibleStrength;
//}

int Team::calculateAusterity(){ // doesn't work well when adding 6 contestants
    int maxPossibleStrength = ZERO;

    if (this->getSize() == ZERO){
        return ZERO;
    }

    if ( ( (this->getSize() - AUSTERITY_REMOVALS) % NUMBER_OF_SUBTREES ) != ZERO ){
        return ZERO;
    }

    for (int left_removals = 0; left_removals <= AUSTERITY_REMOVALS; left_removals++){

        if ( (left_removals == ZERO && this->getSize() == THREE) || left_removals > m_LEFT_ID_Tree->getSize()){
            continue;
        }

        Contestant** LEFT_removedContestants = nullptr;
        if (left_removals != 0) {
            LEFT_removedContestants = delete_i_from_LeftTree(left_removals);
        }

        int right_removals = ZERO;
        int middle_removals = ZERO;

        while ( (left_removals != AUSTERITY_REMOVALS) && (right_removals <= AUSTERITY_REMOVALS - left_removals)) {

            if (right_removals > m_RIGHT_ID_Tree->getSize()){
                right_removals++;
                continue;
            }

            Contestant** RIGHT_removedContestants = delete_k_from_RightTree(right_removals);

            middle_removals = AUSTERITY_REMOVALS - left_removals - right_removals;


            if (middle_removals == ONE && right_removals == TWO || middle_removals == ONE && left_removals == TWO) {
//               first case: remove the border ID.

                ID* borderID = nullptr;
                if (right_removals == TWO) {
                    borderID = m_MIDDLE_ID_Tree->find_Maximum_In_Subtree();
                }
                else {
                    borderID = m_MIDDLE_ID_Tree->find_Minimum_In_Subtree();
                }
                Contestant* removedContestant = borderID->getContestant();
                Strength* removedStrength = borderID->getParallelStrength();

                m_MIDDLE_ID_Tree->remove(borderID);
                m_MIDDLE_Strength_Tree->remove(removedStrength);
                m_size--;

                // Saving the weakest strength without the border ID.

                Contestant* weakestContestantWithoutBorder = m_MIDDLE_Strength_Tree->find_Minimum_In_Subtree()->getContestant();


                this->balanceTrees();
                maxPossibleStrength = max(maxPossibleStrength, calculateTeamStrength());

                if (right_removals > ZERO) {
                    this->reInsert(RIGHT_removedContestants, right_removals, RIGHT);
                }
                else{
                    this->reInsert(LEFT_removedContestants, left_removals, LEFT);
                }

                Strength* toReInsert = new Strength(removedContestant, MIDDLE);
                ID* toReInsertID = new ID(removedContestant, toReInsert);
                m_MIDDLE_ID_Tree->insert(toReInsertID);
                m_MIDDLE_Strength_Tree->insert(toReInsert);
                m_size++;
                this->balanceTrees();

                // TODO: when dubugging, check if the tree returned to original state

//              second case: the smallest Strength in the group that's left without the border ID.

                // Since tree has returned to original state, we need to remove the weakest strength in right/left tree again
                if (right_removals > ZERO) {
                    RIGHT_removedContestants = delete_k_from_RightTree(right_removals);
                }
                else{
                    LEFT_removedContestants = delete_i_from_LeftTree(left_removals);
                }

                Strength* weakestStrengthWithoutBorder = new Strength(weakestContestantWithoutBorder, MIDDLE);
                ID* weakestIDWithoutBorder = m_MIDDLE_ID_Tree->find(weakestContestantWithoutBorder->getID());
                m_MIDDLE_ID_Tree->remove(weakestIDWithoutBorder);
                m_MIDDLE_Strength_Tree->remove(weakestStrengthWithoutBorder);
                delete weakestStrengthWithoutBorder;



                m_size--;
                this->balanceTrees();

                maxPossibleStrength = max(maxPossibleStrength, this->calculateTeamStrength());

                Strength* toReInsert2 = new Strength(weakestContestantWithoutBorder, MIDDLE);
                ID* toReInsertID2 = new ID(weakestContestantWithoutBorder, toReInsert2);

                m_MIDDLE_ID_Tree->insert(toReInsertID2);
                m_MIDDLE_Strength_Tree->insert(toReInsert2);
                m_size++;
            }
            else {
                if (middle_removals > m_MIDDLE_ID_Tree->getSize()){
                    right_removals++;
                    continue;
                }
                if (middle_removals > ZERO){
                    Contestant** MIDDLE_removedContestants = delete_j_from_MiddleTree(middle_removals);
                    this->balanceTrees();
                    maxPossibleStrength = max(maxPossibleStrength, this->calculateTeamStrength());
                    reInsert(MIDDLE_removedContestants, middle_removals, MIDDLE);
                    delete[] MIDDLE_removedContestants;
                }
            }

            if ( middle_removals == ZERO && (left_removals  + right_removals == AUSTERITY_REMOVALS) ) {
                this->balanceTrees();
                maxPossibleStrength = max(maxPossibleStrength, this->calculateTeamStrength());
            }
            reInsert(RIGHT_removedContestants, right_removals, RIGHT);
            delete[] RIGHT_removedContestants;
            //Restores tree to original state
            this->balanceTrees();
            right_removals++;
        }

        if (left_removals == AUSTERITY_REMOVALS) {
            this->balanceTrees();
            maxPossibleStrength = max(maxPossibleStrength, calculateTeamStrength());
        }
        reInsert(LEFT_removedContestants, left_removals, LEFT);
        balanceTrees();

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
    if (i == ZERO) {
        return nullptr;
    }
    Contestant** LEFT_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    for (int t = 0; t < i; t++){
        Strength* removedStrength = m_LEFT_Strength_Tree->find_Minimum_In_Subtree(); // O(log(n))

        // TODO: what to do if we want to remove more contestants than we have?
        if (removedStrength == nullptr){
            break;
        }
        ID* removedID = m_LEFT_ID_Tree->find(removedStrength->getID()); // O(log(n))
        LEFT_removedContestants[t] = removedID->getContestant();

        m_LEFT_ID_Tree->remove(removedID);
        m_LEFT_Strength_Tree->remove(removedStrength);
        m_size--;
    }
    return LEFT_removedContestants;
}

Contestant** Team::delete_j_from_MiddleTree(int j){
    if (j == ZERO) {
        return nullptr;
    }
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
    if (k == ZERO) {
        return nullptr;
    }
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

void Team::reInsert(Contestant** removedContestants, int amount, subtreePosition position){
//    NOT a good assert:
//    assert(findArrayLength(removedContestants) == amount);
    for(int t = 0; t < amount ; t++){

        Strength* strength = new Strength(removedContestants[t], UNASSIGNED);
        ID* id = new ID(removedContestants[t], strength);

        if (position == LEFT){
            m_LEFT_ID_Tree->insert(id);
            m_LEFT_Strength_Tree->insert(strength);
        }
        else if (position == MIDDLE){
            m_MIDDLE_ID_Tree->insert(id);
            m_MIDDLE_Strength_Tree->insert(strength);
        }
        else{
            m_RIGHT_ID_Tree->insert(id);
            m_RIGHT_Strength_Tree->insert(strength);
        }
        m_size++;
    }
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
    ID** LEFT_sortedIDArray = m_LEFT_ID_Tree->inOrderToArray();
    ID** MIDDLE_sortedIDArray = m_MIDDLE_ID_Tree->inOrderToArray();
    ID** RIGHT_sortedIDArray = m_RIGHT_ID_Tree->inOrderToArray();

    ID** tempArray = mergeArrays(LEFT_sortedIDArray, MIDDLE_sortedIDArray, m_LEFT_ID_Tree->getSize(), m_MIDDLE_ID_Tree->getSize());
    ID** sortedIDArray = mergeArrays(tempArray, RIGHT_sortedIDArray, m_LEFT_ID_Tree->getSize() + m_MIDDLE_ID_Tree->getSize(), m_RIGHT_ID_Tree->getSize());

    return sortedIDArray;
}

Strength** Team::getSortedStrengthArray() const{
    Strength** LEFT_sortedIDArray = m_LEFT_Strength_Tree->inOrderToArray();
    Strength** MIDDLE_sortedIDArray = m_MIDDLE_Strength_Tree->inOrderToArray();
    Strength** RIGHT_sortedIDArray = m_RIGHT_Strength_Tree->inOrderToArray();

    Strength** tempArray = mergeArrays(LEFT_sortedIDArray, MIDDLE_sortedIDArray, m_LEFT_Strength_Tree->getSize(), m_MIDDLE_Strength_Tree->getSize());
    Strength** sortedStrengthArray = mergeArrays(tempArray, RIGHT_sortedIDArray, m_LEFT_Strength_Tree->getSize() + m_MIDDLE_Strength_Tree->getSize(), m_RIGHT_Strength_Tree->getSize());

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


////** Strength  **////
int Strength::getID() const{
    return m_contestant->getID();
}

int Strength::getStrength() const{
    return m_contestant->getStrength();
}

subtreePosition Strength::getPosition() const{
    return m_position;
}

Contestant* Strength::getContestant() const{
    return m_contestant;
}

void Strength::setPosition(subtreePosition position){
    m_position = position;
}

bool Strength::operator >= (const Strength& other) const{
    if (this->m_contestant->getStrength() == other.m_contestant->getStrength()){
        if (this->m_contestant->getID() >= other.m_contestant->getID()){
            return true;
        }
        else{
            return false;
        }
    }
    else if (this->m_contestant->getStrength() > other.m_contestant->getStrength()){
        return true;
    }
    else{
        return false;
    }
}

bool Strength::operator == (const Strength& other) const{
    if (*this >= other && other >= *this){
        return true;
    }
    else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Strength& strength){
    os << "Contestant ID: " << strength.m_contestant->getID() << ", Strength: " << strength.m_contestant->getStrength() << std::endl;
    return os;
}


////** ID  **////
int ID::getID() const{
    return m_contestant->getID();
}

Contestant* ID::getContestant() const{
    return m_contestant;
}

Strength* ID::getParallelStrength() const{
    return parallel_strength;
}

bool ID::operator==(const ID& other) const{
    if (this->m_contestant->getID() == other.m_contestant->getID()){
        return true;
    }
    else{
        return false;
    }
}
bool ID::operator>=(const ID& other) const{
    if (this->m_contestant->getID() >= other.m_contestant->getID()){
        return true;
    }
    else{
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const ID &id) {
    os << "Contestant ID: " << id.m_contestant->getID() << std::endl;
    return os;
}



////** Contestant  **////

bool Contestant::registeredInATeam() {
    for (int i = ZERO; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){
        if (m_teams[i] != nullptr){
            return true;
        }
    }
    return false;
}

Contestant::Contestant(int id, int countryID, Sport sport, int strength) : m_id(id), m_countryID(countryID), m_sport(sport), m_strength(strength), m_country(nullptr){
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){
        m_teams[i] = nullptr;
    }
}

bool Contestant::isAvailable() {
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; ++i) {
        if (m_teams[i] == nullptr){
            return true;
        }
    }
    return false;
}

bool Contestant::isRegisteredInTeam(int teamID) {
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; ++i) {
        if (m_teams[i] != nullptr){
            if (m_teams[i]->getID() == teamID){
                return true;
            }
        }
    }
    return false;
}

void Contestant::updateStrength(int change) {
    m_strength += change;
}

std::ostream& operator<<(std::ostream& os, const Contestant& contestant){
    os << "Contestant ID: " << contestant.m_id << ", Strength: " << contestant.m_strength << std::endl;
    return os;
}