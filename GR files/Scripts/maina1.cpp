////
//// 234218 Data Structures 1.
//// Semester: 2024A (winter).
//// Wet Exercise #1.
////
//// Recommended TAB size to view this file: 8.
////
//// The following main file is necessary to link and run your code.
//// This file is READ ONLY: even if you submit something else, the compiler ..
//// .. WILL use our file.
////

//#include "Olympicsa1.h"
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//void print(string cmd, StatusType res);
//void print(string cmd, output_t<int> res);
//
//int main()
//{
//
//    int d1, d2, d3, g1;
//    string b1;
//    bool b;
//
//    // Init
//    Olympics *obj = new Olympics();
//
//    // Execute all commands in file
//	string op;
//	while (cin >> op)
//    {
//        if (!op.compare("add_country")) {
//            cin >> d1 >> d2;
//            print(op, obj->add_country(d1, d2));
//        } else if (!op.compare("remove_country")) {
//            cin >> d1;
//            print(op, obj->remove_country(d1));
//        } else if (!op.compare("add_team")) {
//            cin >> d1 >> d2 >> d3;
//            print(op, obj->add_team(d1, d2, (Sport)d3));
//        } else if (!op.compare("remove_team")) {
//            cin >> d1;
//            print(op, obj->remove_team(d1));
//        } else if (!op.compare("add_contestant")) {
//            cin >> d1 >> d2 >> d3 >> g1;
//            print(op, obj->add_contestant(d1, d2, (Sport)d3, g1));
//        } else if (!op.compare("remove_contestant")) {
//            cin >> d1;
//            print(op, obj->remove_contestant(d1));
//        } else if (!op.compare("add_contestant_to_team")) {
//            cin >> d1 >> d2;
//            print(op, obj->add_contestant_to_team(d1, d2));
//        } else if (!op.compare("remove_contestant_from_team")) {
//            cin >> d1 >> d2;
//            print(op, obj->remove_contestant_from_team(d1, d2));
//        } else if (!op.compare("update_contestant_strength")) {
//            cin >> d1 >> d2;
//            print(op, obj->update_contestant_strength(d1, d2));
//        } else if (!op.compare("get_strength")) {
//            cin >> d1;
//            print(op, obj->get_strength(d1));
//        } else if (!op.compare("get_medals")) {
//            cin >> d1;
//            print(op, obj->get_medals(d1));
//        } else if (!op.compare("get_team_strength")) {
//            cin >> d1;
//            print(op, obj->get_team_strength(d1));
//        } else if (!op.compare("unite_teams")) {
//            cin >> d1 >> d2;
//            print(op, obj->unite_teams(d1, d2));
//        } else if (!op.compare("play_match")) {
//            cin >> d1 >> d2;
//            print(op, obj->play_match(d1, d2));
//        } else if (!op.compare("austerity_measures")) {
//            cin >> d1;
//            print(op, obj->austerity_measures(d1));
//        } else {
//            cout << "Unknown command: " << op << endl;
//            return -1;
//        }
//        // Verify no faults
//        if (cin.fail()){
//            cout << "Invalid input format" << endl;
//            return -1;
//        }
//    }
//
//    // Quit
//	delete obj;
//	return 0;
//}
//
//// Helpers
//static const char *StatusTypeStr[] =
//{
//   	"SUCCESS",
//	"ALLOCATION_ERROR",
//	"INVALID_INPUT",
//	"FAILURE"
//};
//
//void print(string cmd, StatusType res)
//{
//	cout << cmd << ": " << StatusTypeStr[(int) res] << endl;
//}
//
//void print(string cmd, output_t<int> res)
//{
//    if (res.status() == StatusType::SUCCESS) {
//	    cout << cmd << ": " << StatusTypeStr[(int) res.status()] << ", " << res.ans() << endl;
//    } else {
//	    cout << cmd << ": " << StatusTypeStr[(int) res.status()] << endl;
//    }
//}


#include "../../Classes/Contestant_Country_ID_Strength_Team.h"
#include <iostream>
#include <functional>

bool test_1(){
    AVL_Tree<int>* tree = new AVL_Tree<int>;

    int* a = new int(0);
    int* b = new int(1);
    int* c = new int(2);
    int* d = new int(3);
    int* e = new int(4);

    tree->insert(a);
    tree->insert(d);
    tree->insert(b);
    tree->insert(e);
    tree->insert(c);

    std::cout << "First Test, with int:"<<std::endl;
    if (!tree->printTreeInOrder()){
        return false;
    }

    tree->remove(b);
    std::cout << std::endl;
    if (!tree->printTreeInOrder()){
        return false;
    }
    return true;
}

bool test_2(){
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Second Test, with Contestants:" << std::endl;
        AVL_Tree<Contestant>* tree = new AVL_Tree<Contestant>;
        Contestant* a = new Contestant(2039374, 0, Sport::BOULDERING, 0);
        Contestant* b = new Contestant(208622412, 9, Sport::ACROBATICS, 1);
        Contestant* c = new Contestant(3, 30, Sport::ACROBATICS, 2);
        Contestant* d = new Contestant(999999, 12, Sport::ACROBATICS, 3);
        Contestant* e = new Contestant(1847, 4, Sport::ACROBATICS, 4);
        Contestant* f = new Contestant(22, 7, Sport::ACROBATICS, 5);

        tree->insert(a);
        tree->insert(b);
        tree->insert(c);
        tree->insert(d);
        tree->insert(e);
        tree->insert(f);

        if (!tree->printTreeInOrder()){
            return false;
        }

        tree->remove(d);

        std::cout << std::endl;
        if (!tree->printTreeInOrder()){
            return false;
        }

        tree->remove(b);

        std::cout << std::endl;

        if (!tree->printTreeInOrder()){
            return false;
        }
        return true;
}

bool Strength_and_ID_test(){
    // I want to create strength nodes and ID nodes and see if they work
    std::cout << std::endl;
    std::cout << "Third test, with Strength and their parallel IDs" << std::endl;

    AVL_Tree<Strength>* Strength_Tree = new AVL_Tree<Strength>;
    Contestant* a = new Contestant(2039374, 0, Sport::BOULDERING, 0);
    Contestant* b = new Contestant(208622412, 9, Sport::ACROBATICS, 1);
    Contestant* c = new Contestant(3, 9, Sport::ACROBATICS, 2);
    Contestant* d = new Contestant(999999, 12, Sport::ACROBATICS, 3);
    Contestant* e = new Contestant(1847, 4, Sport::ACROBATICS, 4);
    Contestant* f = new Contestant(22, 7, Sport::ACROBATICS, 5);

    Strength* strength_a = new Strength(a);
    Strength* strength_b = new Strength(b);
    Strength* strength_c = new Strength(c);
    Strength* strength_d = new Strength(d);
    Strength* strength_e = new Strength(e);
    Strength* strength_f = new Strength(f);

    ID* id_a = new ID(a, strength_a);
    ID* id_b = new ID(b, strength_b);
    ID* id_c = new ID(c, strength_c);
    ID* id_d = new ID(d, strength_d);
    ID* id_e = new ID(e, strength_e);
    ID* id_f = new ID(f, strength_f);

    Strength_Tree->insert(strength_a);
    Strength_Tree->insert(strength_d);
    Strength_Tree->insert(strength_c);
    Strength_Tree->insert(strength_f);
    Strength_Tree->insert(strength_e);
    Strength_Tree->insert(strength_b);

    std::cout << std::endl;
    if(!Strength_Tree->printTreeInOrder()){
        return false;
    }
    std::cout << std::endl;

    Strength_Tree->remove(strength_d);

    std::cout << std::endl << std::endl;
    if(!Strength_Tree->printTreeInOrder()){
        return false;
    }
    std::cout << std::endl;

    AVL_Tree<ID>* ID_Tree = new AVL_Tree<ID>;

    std::cout << "initial Tree size: " << ID_Tree->getSize() << std::endl;
    ID_Tree->insert(id_a);
    ID_Tree->insert(id_d);
    ID_Tree->insert(id_c);
    ID_Tree->insert(id_f);
    ID_Tree->insert(id_e);
    ID_Tree->insert(id_b);

    std::cout << "Tree size is now: " << ID_Tree->getSize() << std::endl;

    std::cout << std::endl;
    std::cout << "Tree size is now: " << ID_Tree->getSize() << std::endl;
    if(! (ID_Tree->printTreeInOrder())){
        return false;
    }

    std::cout << std::endl;
    ID_Tree->remove(id_d);
    std::cout << "Tree size is now: " << ID_Tree->getSize() << std::endl;
    if(! (ID_Tree->printTreeInOrder())){
        return false;
    }
    std::cout << std::endl;

    ID_Tree->remove(id_f);

    std::cout << std::endl;
    std::cout << "Tree size is now: " << ID_Tree->getSize() << std::endl;
    if(! (ID_Tree->printTreeInOrder())){
        return false;
    }
    std::cout << std::endl;


    return true;
}

bool testContestantMemberFunctions(){
    int contestantID = 182737394789;
    int countryID = 55;
    int strength = 0;

    Contestant* test_contestant = new Contestant(contestantID, countryID, Sport::BOULDERING, strength);

    if (test_contestant->getID() != contestantID){
        std::cout << "getID failed" << std::endl;
        return false;
    }
    if (test_contestant->getCountryID() != countryID){
        std::cout << "getCountryID failed" << std::endl;
        return false;
    }
    if (test_contestant->getSport() != Sport::BOULDERING){
        std::cout << "getSport failed" << std::endl;
        return false;
    }
    if (test_contestant->getStrength() != strength){
        std::cout << "getStrength failed" << std::endl;
        return false;
    }

    if (test_contestant->isAvailable() != true){
        std::cout << "isAvailable failed" << std::endl;
        return false;
    }

    for (int i = 0; i < NUMBER_OF_TEAMS_ALLOWED_PER_PLAYER; i++){
        if (test_contestant->isRegisteredInTeam(i) != false){
            std::cout << "isRegisteredInTeam failed" << std::endl;
            return false;
        }
    }

    if (test_contestant->registeredInATeam() != false){
        std::cout << "registeredInATeam failed" << std::endl;
        return false;
    }

    Contestant* test_contestant2 = new Contestant(contestantID + 5, countryID, Sport::BOULDERING, strength);

    if ( *(test_contestant) == *(test_contestant2) ) {
        std::cout << "operator== failed" << std::endl;
        return false;
    }
    if ( *(test_contestant) >= *(test_contestant2) ) {
        std::cout << "operator>= failed" << std::endl;
        return false;
    }

    Team* team = new Team(0, 0, Sport::BOULDERING, nullptr);

    test_contestant->setTeam(0, team);

    if (test_contestant->getTeam(0) != team){
        std::cout << "setTeam failed" << std::endl;
        return false;
    }

    test_contestant->removeTeam(0);

    if (test_contestant->getTeam(0) != nullptr){
        std::cout << "removeTeam failed" << std::endl;
        return false;
    }

    std::cout << "Contestant Test Passed" << std::endl;

    return true;
}

bool Team_test(){
    Country* country0 = new Country(0, 0);
    Country* country1 = new Country(1, 0);
    Country* country2 = new Country(2, 0);
    Country* country3 = new Country(3, 2);

    int team0ID = 0;
    int team1ID = 1;
    int team2ID = 2;
    int team3ID = 3;

    Team* team0 = new Team(team0ID, 0, Sport::BOULDERING, country0);
    Team* team1 = new Team(team1ID, 0, Sport::BOULDERING, country1);
    Team* team2 = new Team(team2ID, 0, Sport::ACROBATICS, country2);
    Team* team3 = new Team(team3ID, 0, Sport::SPINNING, country3);

    if (team0->getID() != 0){
        std::cout << "getID failed" << std::endl;
        return false;
    }
    if (team0->getCountryID() != 0){
        std::cout << "getCountryID failed" << std::endl;
        return false;
    }
    if (team0->getSport() != Sport::BOULDERING){
        std::cout << "getSport failed" << std::endl;
        return false;
    }
    if (team0->getStrength() != 0){
        std::cout << "getStrength failed" << std::endl;
        return false;
    }
    if (team0->getSize() != 0){
        std::cout << "getSize failed" << std::endl;
        return false;
    }
    if (team0->getAusterity() != 0){
        std::cout << "getAusterity failed" << std::endl;
        return false;
    }

    Contestant* contestant1 = new Contestant(1, 0, Sport::BOULDERING, 23);
    Contestant* contestant2 = new Contestant(2, 0, Sport::BOULDERING, 2);
    Contestant* contestant3 = new Contestant(3, 0, Sport::BOULDERING, 5);
    Contestant* contestant4 = new Contestant(4, 0, Sport::BOULDERING, 9);
    Contestant* contestant5 = new Contestant(5, 0, Sport::BOULDERING, 30);
    Contestant* contestant6 = new Contestant(6, 0, Sport::BOULDERING, 31);
    Contestant* contestant7 = new Contestant(7, 0, Sport::BOULDERING, 3);
    Contestant* contestant8 = new Contestant(8, 0, Sport::BOULDERING, 2);
    Contestant* contestant9 = new Contestant(9, 0, Sport::BOULDERING, 2);
    Contestant* contestant10 = new Contestant(10, 0, Sport::BOULDERING, 12);
    Contestant* contestant11 = new Contestant(11, 0, Sport::BOULDERING, 2);
    Contestant* contestant12 = new Contestant(12, 0, Sport::BOULDERING, 2);
    Contestant* contestant13 = new Contestant(13, 0, Sport::BOULDERING, 50);
    Contestant* contestant14 = new Contestant(14, 0, Sport::BOULDERING, 1);
    Contestant* contestant15 = new Contestant(15, 0, Sport::BOULDERING, 5);
    Contestant* contestant16 = new Contestant(16, 0, Sport::BOULDERING, 4);
    Contestant* contestant17 = new Contestant(17, 0, Sport::BOULDERING, 3);
    Contestant* contestant18 = new Contestant(18, 0, Sport::BOULDERING, 2);
    Contestant* contestant19 = new Contestant(19, 0, Sport::BOULDERING, 10);
    Contestant* contestant20 = new Contestant(20, 0, Sport::BOULDERING, 20);
    Contestant* contestant21 = new Contestant(21, 0, Sport::BOULDERING, 10);

    if (team0->insertContestant(contestant1) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant2) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant3) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->getStrength() != 30){
        std::cout << "first getStrength failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant4) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant5) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant6) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->getStrength() != 63){
        std::cout << "second getStrength failed" << std::endl;
        return false;
    }

    if (team0->getAusterity() != 84){
        std::cout << "second getAusterity failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant7) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant8) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant9) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant10) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant11) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant12) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant13) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant14) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant15) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant16) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant17) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant18) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant19) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant20) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }
    if (team0->insertContestant(contestant21) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->getSize() != 21){
        std::cout << "getSize failed" << std::endl;
        return false;
    }

    if (team0->getStrength() != 101){
        std::cout << "last getStrength failed" << std::endl;
        return false;
    }

    if (team0->getAusterity() != 101){
        std::cout << "getAusterity failed" << std::endl;
        return false;
    }

    std::cout << "Team Test Passed" << std::endl;
    return true;
}


int main(){

    if(!test_1()){
        std::cout << "Test 1 failed" << std::endl;
    }

    if(!test_2()){
        std::cout << "Test 2 failed" << std::endl;
    }
    if (!Strength_and_ID_test()){
        std::cout << "Strength_and_ID_test failed" << std::endl;
    }
    if (!testContestantMemberFunctions()){
        std::cout << "testContestantMemberFunctions failed" << std::endl;
    }

    if (!Team_test()){
        std::cout << "Team_test failed" << std::endl;
    }

    return 0;
}