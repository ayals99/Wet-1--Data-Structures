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


void mergeArrays(ID** mergedIdArray, ID** sortedId1, ID** sortedId2, int length1, int length2){
    if (length1 == ZERO && length2 == ZERO) {
        return;
    }
    // if arrived here, that means that at least one of the arrays is not empty
    int i = 0;
    int j = 0;
    int k = 0;
    if ( (length1 != ZERO)
        && (length2 != ZERO)
        && (sortedId1 != nullptr)
        && (sortedId2 != nullptr)
        && (mergedIdArray != nullptr)){
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
    if ((length1 != ZERO) && (sortedId1 != nullptr) && (mergedIdArray != nullptr)){
        while (i < length1) {
            mergedIdArray[k] = sortedId1[i];
            i++;
            k++;
        }
    }
    if ((length2 != ZERO) && (sortedId2 != nullptr) && (mergedIdArray != nullptr)){
        while (j < length2) {
            mergedIdArray[k] = sortedId2[j];
            j++;
            k++;
        }
    }
}

void mergeArrays(Strength** mergedStrengthArray, Strength** sortedStrength1, Strength** sortedStrength2, int length1, int length2){
    if (length1 == ZERO && length2 == ZERO) {
        return;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while ( (i < length1) && (j < length2)
            && (sortedStrength1 != nullptr)
            && (sortedStrength2 != nullptr)
            && (mergedStrengthArray != nullptr)){
        if ( *(sortedStrength2[j]) >= *(sortedStrength1[i]) ){
            mergedStrengthArray[k] = sortedStrength1[i];
            i++;
        }
        else{
            mergedStrengthArray[k] = sortedStrength2[j];
            j++;
        }
        k++;
    }
    while ((i < length1) && (sortedStrength1 != nullptr) && (mergedStrengthArray != nullptr)){
        mergedStrengthArray[k] = sortedStrength1[i];
        i++;
        k++;
    }
    while ((j < length2) && (sortedStrength2 != nullptr) && (mergedStrengthArray != nullptr)){
        mergedStrengthArray[k] = sortedStrength2[j];
        j++;
        k++;
    }

    // delete only the pointer to the elements of array, not the instances of Strength
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



int countNonDuplicates(ID** arrayToCount,int size)
{
    int counter = 0;
    if(arrayToCount == nullptr){
        return counter;
    }
    for (int i = 0; i < size; ++i) {
        if (i < size - 1) {
            if (arrayToCount[i]->getContestant()->getID() == arrayToCount[i + 1]->getContestant()->getID()) {
                i++;
            }
        }
        counter++;
    }
    return counter;
}


void deleteDuplicates(ID** mergedWithoutDuplicates, ID** mergedIDArray, int fullSize, int numberOfNonDuplicates, int mainTeamID)
{
    int newArrayIndex = 0;
    if ((mergedIDArray == nullptr) || (mergedWithoutDuplicates == nullptr)){
        return;
    }
    for (int i = 0; i < fullSize; i++, newArrayIndex++)
    {
        if (i < fullSize - 1)
        {
            if ( mergedIDArray[i]->getContestant()->getID() == mergedIDArray[i+1]->getContestant()->getID())
            {
                if ( mergedIDArray[i]->getContestant()->isRegisteredInTeam(mainTeamID))
                {
                    mergedWithoutDuplicates[newArrayIndex] = mergedIDArray[i];
                    delete mergedIDArray[i+1];
                    mergedIDArray[i+1] = nullptr;
                }
                else{
                    mergedWithoutDuplicates[newArrayIndex] = mergedIDArray[i+1];
                    delete mergedIDArray[i];
                    mergedIDArray[i] = nullptr;
                }
                i++;
            }
            else
            {
                mergedWithoutDuplicates[newArrayIndex] = mergedIDArray[i];
            }
        }
        else{
            mergedWithoutDuplicates[newArrayIndex] = mergedIDArray[i];
        }
    }
}

void deleteDuplicates(Strength** mergedWithoutDuplicates, Strength** mergedStrengthArray, int fullSize, int numberOfNonDuplicates, int mainTeamID)
{
    if ((mergedWithoutDuplicates == nullptr) || (mergedStrengthArray == nullptr)){
        return;
    }
    int newArrayIndex = ZERO;
    for (int i = 0; i < fullSize; i++, newArrayIndex++)
    {
        if (i < fullSize - 1)
        {
            Strength* a = mergedStrengthArray[i];
            Strength* b = mergedStrengthArray[i+1];
            if (mergedStrengthArray[i]->getContestant()->getID() == mergedStrengthArray[i+1]->getContestant()->getID())
            {
                if (mergedStrengthArray[i]->getContestant()->isRegisteredInTeam(mainTeamID))
                {
                    mergedWithoutDuplicates[newArrayIndex] = mergedStrengthArray[i];
                    delete mergedStrengthArray[i+1];
                    mergedStrengthArray[i+1] = nullptr;
                }
                else{
                    mergedWithoutDuplicates[newArrayIndex] = mergedStrengthArray[i+1];
                    delete mergedStrengthArray[i];
                    mergedStrengthArray[i] = nullptr;
                }
                i++;
            }
            else
            {
                mergedWithoutDuplicates[newArrayIndex] = mergedStrengthArray[i];
            }
        }
        else{
            mergedWithoutDuplicates[newArrayIndex] = mergedStrengthArray[i];
        }
    }
}

AVL_Tree<ID>* createEmptyTree(int numberOfElements){
    AVL_Tree<ID>* newTree = new AVL_Tree<ID>(); // O(1)
    if (numberOfElements == ZERO){
        newTree->setRoot(nullptr);
        newTree->setSize(ZERO);
        return newTree;
    }
    int height  = (int)floor(log2(numberOfElements + 1));

    newTree->setRoot(AUX_EmptyTree<ID>(height)); // O(n)

    int fullBinaryTreeSize = 0;
    for (int i = height; i >= ZERO; i--){
        fullBinaryTreeSize += (int)pow(2, i);
    }

    newTree->setSize(fullBinaryTreeSize);

    deleteSpareNodes<ID>(newTree , nullptr, newTree->getRoot(), height, numberOfElements);// O(n)
    assert(newTree->getSize() == numberOfElements);
    return newTree;
}

AVL_Tree<Strength>* createEmptyStrengthTree(int numberOfElements){
    AVL_Tree<Strength>* newTree = new AVL_Tree<Strength>(); // O(1)
    if (numberOfElements == ZERO){
        newTree->setRoot(nullptr);
        newTree->setSize(ZERO);
        return newTree;
    }
    int height  = (int)floor(log2(numberOfElements + 1));
    newTree->setRoot(AUX_EmptyTree<Strength>(height)); // O(n)

    int fullBinaryTreeSize = 0;
    for (int i = height; i >= ZERO; i--){
        fullBinaryTreeSize += (int)pow(2, i);
    }

    newTree->setSize(fullBinaryTreeSize);

    deleteSpareNodes<Strength>(newTree , nullptr, newTree->getRoot(), height, numberOfElements);// O(n)
    assert(newTree->getSize() == numberOfElements);
    return newTree;
}

// As we learned in the recitation:
AVL_Tree<ID>* ArrayToTree(ID** array, int numberOfElements){
    AVL_Tree<ID>* newTree = createEmptyTree(numberOfElements); // O(n)
    if (array != nullptr) {
        insertArrayToTree(array, newTree); // O(n)
    }
    return newTree;
}

AVL_Tree<Strength>* ArrayToTree(Strength** strengthArray, int arrayLength, int treeSize, subtreePosition position) { // O(n)
    AVL_Tree<Strength>* newTree = createEmptyStrengthTree(treeSize); // O(n)

    if (strengthArray == nullptr){
        return newTree;
    }

    Strength** POSITION_Array = new Strength*[treeSize]; // O(n)

    int POSITION_Array_index = 0;
    for (int i = 0; i < arrayLength; i++){ // O(n)
        if (strengthArray[i]->getPosition() == position){ // O(1)
            POSITION_Array[POSITION_Array_index] = strengthArray[i]; // O(1)
            POSITION_Array_index++;
        }
    }

    insertArrayToTree(POSITION_Array, newTree); // O(n)
    delete[] POSITION_Array;// O(n)
    POSITION_Array = nullptr;

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
void Team::decrementSize(){
    m_size--;
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
        int team1ID = this->getID();
        int team2ID = team2->getID();

        int team1Size = this->getSize();
        int team2Size = team2->getSize();

        /**ID Arrays*/

        // Create an ID array for team 1:
        ID** sortedId1 = nullptr;
        if (team1Size != ZERO){
            sortedId1 = new ID* [team1Size];
        }
        this->getSortedIdArray(sortedId1); // O(n_team_ID1)

        // create an ID array for team 2
        ID** sortedId2WithDuplicates = nullptr;
        if (team2Size != ZERO) {
            sortedId2WithDuplicates = new ID* [team2Size];
        }
        team2->getSortedIdArray(sortedId2WithDuplicates); // O(n_team_ID2)


        // merge both ID arrays
        int fullSize = team1Size + team2Size;
        ID** mergedIDArray = nullptr;
        if (fullSize != ZERO) {
            mergedIDArray = new ID*[fullSize];
        }
        mergeArrays(mergedIDArray, sortedId1, sortedId2WithDuplicates,this->getSize() ,team2->getSize());

        delete[] sortedId1;
        delete[] sortedId2WithDuplicates;
        sortedId1 = nullptr;
        sortedId2WithDuplicates = nullptr;

        int numOfNonDuplicates = countNonDuplicates(mergedIDArray, fullSize);
        ID** mergedIDArrayWithOutDuplicates = nullptr;
        if (numOfNonDuplicates != ZERO) {
            mergedIDArrayWithOutDuplicates = new ID*[numOfNonDuplicates];
        }


        deleteDuplicates(mergedIDArrayWithOutDuplicates ,mergedIDArray,fullSize, numOfNonDuplicates, this->getID());

        // assign all contestants to team1 and unregister them from team2
        if (mergedIDArrayWithOutDuplicates != nullptr) {
            for (int i = 0; i < numOfNonDuplicates; i++) {
                mergedIDArrayWithOutDuplicates[i]->getContestant()->unregisterWithTeam(team2ID);
                mergedIDArrayWithOutDuplicates[i]->getContestant()->registerWithTeam(this);
            }
        }

        delete[] mergedIDArray;
        mergedIDArray = nullptr;


        /**Strength*/

        //create a Strength array for team 1
        Strength** sortedStrength1 = nullptr;
        if (this->getSize() != ZERO) {
            sortedStrength1 = new Strength*[team1Size];
        }
        this->getSortedStrengthArray(sortedStrength1); // O(n_team_ID1)

        //create a Strength array for team 2
        Strength** sortedStrength2WithDuplicates =nullptr;
        if (team2Size != ZERO) {
            sortedStrength2WithDuplicates = new Strength*[team2Size];
        }
        team2->getSortedStrengthArray(sortedStrength2WithDuplicates);

        Strength** mergedStrengthArray = nullptr;
        if (fullSize != ZERO) {
            mergedStrengthArray = new Strength *[fullSize];
        }
        mergeArrays(mergedStrengthArray, sortedStrength1, sortedStrength2WithDuplicates,
                    team1Size, team2Size); // O(n)

        delete[] sortedStrength1;
        sortedId1 = nullptr;

        delete[] sortedStrength2WithDuplicates;
        sortedStrength2WithDuplicates = nullptr;


        Strength** mergedStrengthArrayWithoutDuplicates = nullptr;
        if (numOfNonDuplicates != ZERO) {
            mergedStrengthArrayWithoutDuplicates = new Strength*[numOfNonDuplicates];
        }
        deleteDuplicates(mergedStrengthArrayWithoutDuplicates,
                         mergedStrengthArray,
                         fullSize, numOfNonDuplicates,
                         team1ID);
        delete[] mergedStrengthArray;
        mergedStrengthArray = nullptr;

        int leftTreeSize = ceilDivisionByThree(numOfNonDuplicates);
        int middleTreeSize = ceilDivisionByThree(numOfNonDuplicates);
        int rightTreeSize = numOfNonDuplicates - leftTreeSize - middleTreeSize;

        //loop through mergedIdArray and for each ID, assign position to each parallelStrength:
        for (int i = 0; i < numOfNonDuplicates; i++){ // O(n)
            subtreePosition currentPosition = UNASSIGNED;
            if (i < leftTreeSize){
                currentPosition = LEFT;
            }
            else if (i < leftTreeSize + middleTreeSize){
                currentPosition = MIDDLE;
            }
            else{
                currentPosition = RIGHT;
            }
            if (mergedIDArrayWithOutDuplicates != nullptr) {
                mergedIDArrayWithOutDuplicates[i]->getParallelStrength()->setPosition(currentPosition); // O(1)
            }
        }

//      create three almost full ID subtrees with empty nodes //O(n_team_ID1 + n_team_ID2)
//      move all of mergedIdArray into the subtrees according to their m_position //O(n_team_ID1 + n_team_ID2)
        int startIndex = 0;
        AVL_Tree<ID>* new_LEFT_ID_Tree = ArrayToTree(mergedIDArrayWithOutDuplicates, leftTreeSize); // O(n)

        startIndex += leftTreeSize;
        AVL_Tree<ID>* new_MIDDLE_ID_Tree = ArrayToTree(mergedIDArrayWithOutDuplicates + startIndex, middleTreeSize); // O(n)

        startIndex += middleTreeSize;
        AVL_Tree<ID>* new_RIGHT_ID_Tree = ArrayToTree(mergedIDArrayWithOutDuplicates + startIndex, rightTreeSize); // O(n)

//        create three almost full Strength subtrees  //O(n_team_ID1 + n_team_ID2)
//              move all of mergedStrengthArray into the subtrees according to their m_position //O(n_team_ID1 + n_team_ID2)
        AVL_Tree<Strength>* new_LEFT_Strength_Tree = ArrayToTree(mergedStrengthArrayWithoutDuplicates, numOfNonDuplicates , leftTreeSize  , LEFT);
        AVL_Tree<Strength>* new_MIDDLE_Strength_Tree = ArrayToTree(mergedStrengthArrayWithoutDuplicates, numOfNonDuplicates, middleTreeSize , MIDDLE);
        AVL_Tree<Strength>* new_RIGHT_Strength_Tree = ArrayToTree(mergedStrengthArrayWithoutDuplicates, numOfNonDuplicates, rightTreeSize, RIGHT);

        delete[] mergedIDArrayWithOutDuplicates; // O(n)
        delete[] mergedStrengthArrayWithoutDuplicates; // O(n)
        mergedIDArrayWithOutDuplicates = nullptr;
        mergedStrengthArrayWithoutDuplicates = nullptr;

        team2->removeDataFromSubtrees(); // O(n_team_ID2)

        this->removeDataFromSubtrees(); // O(n_team_ID1)
        this->deleteSubtrees(); // O(n_team_ID1)

        m_LEFT_ID_Tree = new_LEFT_ID_Tree;
        m_MIDDLE_ID_Tree = new_MIDDLE_ID_Tree;
        m_RIGHT_ID_Tree = new_RIGHT_ID_Tree;
        m_LEFT_Strength_Tree = new_LEFT_Strength_Tree;
        m_MIDDLE_Strength_Tree = new_MIDDLE_Strength_Tree;
        m_RIGHT_Strength_Tree = new_RIGHT_Strength_Tree;

        assert(m_LEFT_ID_Tree->getSize() == m_LEFT_Strength_Tree->getSize());
        assert(m_MIDDLE_ID_Tree->getSize() == m_MIDDLE_Strength_Tree->getSize());
        assert(m_RIGHT_ID_Tree->getSize() == m_RIGHT_Strength_Tree->getSize());

        setSize(m_LEFT_ID_Tree->getSize() + m_MIDDLE_ID_Tree->getSize() + m_RIGHT_ID_Tree->getSize()); // O(1)
        this->updateTeamStrength(); // O(log n)
        this->updateAusterity(); // O(log n)
    }
    catch(std::bad_alloc & e)
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

void nullifyArray(Contestant** array, int size){
    for (int i = 0; i < size; i++){
        array[i] = nullptr;
    }
}

int Team::calculateAusterity(){
    int maxPossibleStrength = ZERO;

    if (this->getSize() == ZERO){
        return ZERO;
    }

    if ( ( (this->getSize() - AUSTERITY_REMOVALS) % NUMBER_OF_SUBTREES ) != ZERO ){
        return ZERO;
    }

    Contestant** LEFT_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    Contestant** MIDDLE_removedContestants = new Contestant*[AUSTERITY_REMOVALS];
    Contestant** RIGHT_removedContestants = new Contestant*[AUSTERITY_REMOVALS];

    for (int left_removals = 0; left_removals <= AUSTERITY_REMOVALS; left_removals++){

        if ( (left_removals == ZERO && this->getSize() == THREE) || left_removals > m_LEFT_ID_Tree->getSize()){
            continue;
        }


        if (left_removals != 0) {
            delete_i_from_LeftTree(LEFT_removedContestants, left_removals);
        }

        int right_removals = ZERO;
        int middle_removals = ZERO;

        while ( (left_removals != AUSTERITY_REMOVALS) && (right_removals <= AUSTERITY_REMOVALS - left_removals)) {

            if (right_removals > m_RIGHT_ID_Tree->getSize()){
                right_removals++;
                continue;
            }

            delete_k_from_RightTree(RIGHT_removedContestants, right_removals);

            middle_removals = AUSTERITY_REMOVALS - left_removals - right_removals;


            if ((middle_removals == ONE && right_removals == TWO) || (middle_removals == ONE && left_removals == TWO)) {
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

                // TODO: when debugging, check if the tree returned to original state

//              second case: the smallest Strength in the group that's left without the border ID.

                // Since tree has returned to original state, we need to remove the weakest strength in right/left tree again
                if (right_removals > ZERO) {
                    delete_k_from_RightTree(RIGHT_removedContestants, right_removals);
                }
                else{
                    delete_i_from_LeftTree(LEFT_removedContestants, left_removals);
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
                    delete_j_from_MiddleTree(MIDDLE_removedContestants,middle_removals);
                    this->balanceTrees();
                    maxPossibleStrength = max(maxPossibleStrength, this->calculateTeamStrength());
                    reInsert(MIDDLE_removedContestants, middle_removals, MIDDLE);
                    nullifyArray(MIDDLE_removedContestants, AUSTERITY_REMOVALS);
                }
            }

            if ( middle_removals == ZERO && (left_removals  + right_removals == AUSTERITY_REMOVALS) ) {
                this->balanceTrees();
                maxPossibleStrength = max(maxPossibleStrength, this->calculateTeamStrength());
            }
            reInsert(RIGHT_removedContestants, right_removals, RIGHT);
            nullifyArray(RIGHT_removedContestants, AUSTERITY_REMOVALS);
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
        nullifyArray(LEFT_removedContestants, AUSTERITY_REMOVALS);
    }

    delete[] LEFT_removedContestants;
    delete[] MIDDLE_removedContestants;
    delete[] RIGHT_removedContestants;
    LEFT_removedContestants = nullptr;
    MIDDLE_removedContestants = nullptr;
    RIGHT_removedContestants = nullptr;

    return maxPossibleStrength;
}

void Team::updateAusterity(){
    m_austerity = calculateAusterity();
}


void Team::delete_i_from_LeftTree(Contestant** LEFT_removedContestants, int i){
    if (i == ZERO){
        return;
    }
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
}

void Team::delete_j_from_MiddleTree(Contestant** MIDDLE_removedContestants, int j){
    if (j == ZERO) {
        return;
    }

    for (int m = 0; m < j; m++){
        Strength* removedStrength = m_MIDDLE_Strength_Tree->find_Minimum_In_Subtree();
        ID* removedID_MIDDLE = m_MIDDLE_ID_Tree->find(removedStrength->getID());
        MIDDLE_removedContestants[m] = removedID_MIDDLE->getContestant();

        m_MIDDLE_ID_Tree->remove(removedID_MIDDLE);
        m_MIDDLE_Strength_Tree->remove(removedStrength);
        m_size--;
    }
}

void Team::delete_k_from_RightTree(Contestant** RIGHT_removedContestants, int k){
    if (k == ZERO) {
        return;
    }
    for (int n = 0; n < k; n++){
        Strength* removedStrength = m_RIGHT_Strength_Tree->find_Minimum_In_Subtree();// O(log(n))
        ID* removedID = m_RIGHT_ID_Tree->find(removedStrength->getID());// O(log(n))
        RIGHT_removedContestants[n] = removedID->getContestant();

        m_RIGHT_ID_Tree->remove(removedID);
        m_RIGHT_Strength_Tree->remove(removedStrength);
        m_size--;
    }
}

void Team::reInsert(Contestant** removedContestants, int amount, subtreePosition position){
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
    m_LEFT_ID_Tree = nullptr;
    delete m_MIDDLE_ID_Tree;
    m_MIDDLE_ID_Tree = nullptr;
    delete m_RIGHT_ID_Tree;
    m_RIGHT_ID_Tree = nullptr;
    delete m_LEFT_Strength_Tree;
    m_LEFT_Strength_Tree = nullptr;
    delete m_MIDDLE_Strength_Tree;
    m_MIDDLE_ID_Tree = nullptr;
    delete m_RIGHT_Strength_Tree;
    m_RIGHT_Strength_Tree = nullptr;
}


void Team::getSortedIdArray(ID** sortedIDArray) const{
    if (sortedIDArray == nullptr){
        return;
    }
    ID** LEFT_sortedIDArray = new ID*[m_LEFT_ID_Tree->getSize()];
    m_LEFT_ID_Tree->inOrderToArray(LEFT_sortedIDArray);

    ID** MIDDLE_sortedIDArray = new ID*[m_MIDDLE_ID_Tree->getSize()];
    m_MIDDLE_ID_Tree->inOrderToArray(MIDDLE_sortedIDArray);

    ID** RIGHT_sortedIDArray = new ID*[m_RIGHT_ID_Tree->getSize()];
    m_RIGHT_ID_Tree->inOrderToArray(RIGHT_sortedIDArray);

    ID** tempArray = new ID*[m_LEFT_ID_Tree->getSize() + m_MIDDLE_ID_Tree->getSize()];
    mergeArrays(tempArray, LEFT_sortedIDArray, MIDDLE_sortedIDArray, m_LEFT_ID_Tree->getSize(), m_MIDDLE_ID_Tree->getSize());
    mergeArrays(sortedIDArray, tempArray, RIGHT_sortedIDArray, m_LEFT_ID_Tree->getSize() + m_MIDDLE_ID_Tree->getSize(), m_RIGHT_ID_Tree->getSize());

    delete[] tempArray;
    tempArray = nullptr;

    delete[] LEFT_sortedIDArray;
    LEFT_sortedIDArray = nullptr;

    delete[] MIDDLE_sortedIDArray;
    MIDDLE_sortedIDArray = nullptr;

    delete[] RIGHT_sortedIDArray;
    RIGHT_sortedIDArray = nullptr;
}

void Team::getSortedStrengthArray(Strength** sortedStrengthArray) const{
    if (sortedStrengthArray == nullptr){
        return;
    }
    Strength** LEFT_sortedStrengthArray = new Strength *[m_LEFT_Strength_Tree->getSize()];
    m_LEFT_Strength_Tree->inOrderToArray(LEFT_sortedStrengthArray);

    Strength** MIDDLE_sortedStrengthArray = new Strength *[m_MIDDLE_Strength_Tree->getSize()];
    m_MIDDLE_Strength_Tree->inOrderToArray(MIDDLE_sortedStrengthArray);

    Strength** RIGHT_sortedStrengthArray = new Strength *[m_RIGHT_Strength_Tree->getSize()];
    m_RIGHT_Strength_Tree->inOrderToArray(RIGHT_sortedStrengthArray);

    Strength** tempArray = new Strength * [ m_LEFT_Strength_Tree->getSize() + m_MIDDLE_Strength_Tree->getSize()];
    mergeArrays(tempArray, LEFT_sortedStrengthArray, MIDDLE_sortedStrengthArray, m_LEFT_Strength_Tree->getSize(), m_MIDDLE_Strength_Tree->getSize());

    mergeArrays(sortedStrengthArray, tempArray, RIGHT_sortedStrengthArray, m_LEFT_Strength_Tree->getSize() + m_MIDDLE_Strength_Tree->getSize(), m_RIGHT_Strength_Tree->getSize());

    delete[] tempArray;
    delete[] LEFT_sortedStrengthArray;
    delete[] MIDDLE_sortedStrengthArray;
    delete[] RIGHT_sortedStrengthArray;

    tempArray = nullptr;
    LEFT_sortedStrengthArray = nullptr;
    MIDDLE_sortedStrengthArray = nullptr;
    RIGHT_sortedStrengthArray = nullptr;
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

Contestant::Contestant(int id, int countryID, Sport sport, int strength)
                                : m_id(id),
                                m_countryID(countryID),
                                m_sport(sport),
                                m_strength(strength),
                                m_country(nullptr),
                                m_teams{nullptr, nullptr, nullptr}{}

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

void Contestant::registerWithTeam(Team* team){
    if (this->isRegisteredInTeam(team->getID())){
        return;
    }
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){
         if (m_teams[i] == nullptr){
             m_teams[i] = team;
             return;
         }
    }
}

void Contestant::unregisterWithTeam(int teamID){
    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){
        if (m_teams[i] != nullptr){
            if (m_teams[i]->getID() == teamID){
                m_teams[i] = nullptr;
                return;
            }
        }
    }
}

void Contestant::updateStrength(int change) {
    m_strength += change;
}

std::ostream& operator<<(std::ostream& os, const Contestant& contestant){
    os << "Contestant ID: " << contestant.m_id << ", Strength: " << contestant.m_strength << std::endl;
    return os;
}