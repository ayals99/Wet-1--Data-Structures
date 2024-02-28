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

#include "Olympicsa1.h"
#include <string>
#include <iostream>
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
    int contestantID = INT_MAX;
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


    if (team0->insertContestant(contestant16) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant2) != StatusType::SUCCESS){
        std::cout << "insertContestant 2 failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant3) != StatusType::SUCCESS){
        std::cout << "insertContestant 3 failed" << std::endl;
        return false;
    }


    if (team0->insertContestant(contestant13) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }



    if (team0->insertContestant(contestant5) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant12) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant4) != StatusType::SUCCESS){
        std::cout << "insertContestant 4 failed" << std::endl;
        return false;
    }


    if (team0->insertContestant(contestant6) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant19) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant7) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant17) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant8) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant15) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant9) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant1) != StatusType::SUCCESS){
        std::cout << "insertContestant 1 failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant21) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant10) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant14) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }


    if (team0->insertContestant(contestant11) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }


    if (team0->insertContestant(contestant18) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }

    if (team0->insertContestant(contestant20) != StatusType::SUCCESS){
        std::cout << "insertContestant failed" << std::endl;
        return false;
    }



    if (team0->getSize() != 21){
        std::cout << "getSize failed" << std::endl;
        return false;
    }

    std::cout<<std::endl;
    if (!team0->printTeamInOrder()){
        return false;
    }


    std::cout<<std::endl;

    if (team0->getStrength() != 101){
        std::cout << "last getStrength failed" << std::endl;
        return false;
    }

    if (team0->getAusterity() != 101){
        std::cout << "getAusterity failed" << std::endl;
        return false;
    }




    team0->removeContestantFromTeam(contestant1);

    if (team0->getStrength() != ZERO){
        std::cout << "getStrength failed" << std::endl;
        return false;
    }

    if (team0->getAusterity() != ZERO){
        std::cout << "getAusterity failed" << std::endl;
        return false;
    }
    if (contestant1->isRegisteredInTeam(0) != false){
        std::cout << "isRegisteredInTeam failed" << std::endl;
        return false;
    }

    team0->removeContestantFromTeam(contestant17);

    team0->removeContestantFromTeam(contestant11);

    if (team0->getStrength() != 101){
        std::cout << "getStrength failed" << std::endl;
        return false;
    }

    //// ** Merge Teams Test **

    team1->mergeTeams(team0);

    if (team1->printTeamInOrder() != true){
        std::cout << "printTeamInOrder failed after merge" << std::endl;
        return false;
    }

    if (team1->getStrength() != 101){
        std::cout << "getStrength failed" << std::endl;
        return false;
    }

    if (team1->getSize() != 18){
        std::cout << "getSize failed after merge" << std::endl;
        return false;
    }

    std::cout << "Team Test Passed" << std::endl;
    return true;
}


bool olympicTest(){
    Olympics* olympics = new Olympics();

    //// Countries:
    int country1Id = INT_MAX;
    int medalsCountry1 = 0;

    int country2Id = 55;
    int medalsCountry2 = 7;

    int invalidCountryId = 0;
    int medalsCountry3 = 90;

    int country4Id = 1;
    int medalsCountry4 = 21;


    /** Teams: **/
    int team1Id = 40;
    Sport sportTeam1 = Sport::BOULDERING;

    int team2Id = 12;
    Sport sportTeam2 = Sport::ACROBATICS;

    int team3Id = 3;
    Sport sportTeam3 = Sport::SPINNING;

    int team4Id = 4;
    Sport sportTeam4 = Sport::BOULDERING;

    int team5Id = 5;
    Sport sportTeam5 = Sport::FOOTBALL;

    //// Contestants:

    int contestant1Id = 1;
    int strength1 = 1000;
    Sport sport1 = Sport::BOULDERING;

    int contestant2Id = 2;
    int strength2 = 2059;
    Sport sport2 = Sport::ACROBATICS;

    int contestant3Id = 3;
    int strength3 = 294847;
    Sport sport3 = Sport::SPINNING;

    int contestant4Id = 4;
    int strength4 = 12;
    Sport sport4 = Sport::BOULDERING;

    int contestant5Id = 5;
    int strength5 = 340;
    Sport sport5 = Sport::FOOTBALL;

    int contestant6Id = 6;
    int strength6 = 45;
    Sport sport6 = Sport::BOULDERING;

    int contestant7Id = 7;
    int strength7 = 31;
    Sport sport7 = Sport::ACROBATICS;

    int contestant8Id = 8;
    int strength8 = 100;
    Sport sport8 = Sport::BOULDERING;

    int contestant9Id = 9;
    int strength9 = 200;
    Sport sport9 = Sport::BOULDERING;

    int contestant10Id = 10;
    int strength10 = 300;
    Sport sport10 = Sport::ACROBATICS;

    int contestant11Id = 11;
    int strength11 = 400;
    Sport sport11 = Sport::ACROBATICS;

    int contestant12Id = 12;
    int strength12 = 257;
    Sport sport12 = Sport::BOULDERING;

    int contestant13Id = 13;
    int strength13 = 19;
    Sport sport13 = Sport::BOULDERING;

    int contestant14Id = 14;
    int strength14 = 43;
    Sport sport14 = Sport::BOULDERING;


    /*** add_country tests: ***/
    if (olympics->add_country(country1Id, medalsCountry1) != StatusType::SUCCESS){
        std::cout << "add_country1 failed" << std::endl;
        return false;
    }

    if (olympics->add_country(country2Id, medalsCountry2) != StatusType::SUCCESS){
        std::cout << "add_country2 failed" << std::endl;
        return false;
    }

    if (olympics->add_country(country2Id, medalsCountry2) != StatusType::FAILURE){
        std::cout << "add_country2 twice failed" << std::endl;
        return false;
    }

    if (olympics->add_country(invalidCountryId, medalsCountry3) != StatusType::INVALID_INPUT){
        std::cout << "add_country3 failed" << std::endl;
        return false;
    }

    if (olympics->add_country(country4Id, medalsCountry4) != StatusType::SUCCESS){
        std::cout << "add_country4 failed" << std::endl;
        return false;
    }

    // We now have three countries, let's remove one:

    /** remove_country tests: **/
    if (olympics->remove_country(country2Id) != StatusType::SUCCESS){
        std::cout << "remove_country2 failed" << std::endl;
        return false;
    }

    if (olympics->remove_country(country2Id) != StatusType::FAILURE){
        std::cout << "remove_country2 twice failed" << std::endl;
        return false;
    }

    // we now have two countries - 1 and 4:

    // add team1 to country1

    /** add_team tests: **/

    if (olympics->add_team(team1Id, country1Id, sportTeam1) != StatusType::SUCCESS){
        std::cout << "add_team1 failed" << std::endl;
        return false;
    }

    if (olympics->add_team(team1Id, country1Id, sportTeam1) != StatusType::FAILURE){
        std::cout << "add_team1 twice failed" << std::endl;
        return false;
    }

    if (olympics->add_team(team2Id, country1Id, sportTeam2) != StatusType::SUCCESS){
        std::cout << "add_team2 failed" << std::endl;
        return false;
    }
    if (olympics->add_team(team3Id, country1Id, sportTeam3) != StatusType::SUCCESS){
        std::cout << "add_team3 failed" << std::endl;
        return false;
    }

    if (olympics->add_team(team4Id, country4Id, sportTeam4) != StatusType::SUCCESS){
        std::cout << "add_team4 failed" << std::endl;
        return false;
    }
    if (olympics->add_team(team5Id, country4Id, sportTeam5) != StatusType::SUCCESS){
        std::cout << "add_team5 failed" << std::endl;
        return false;
    }





    /** remove_team tests: **/
    if (olympics->remove_team(team3Id) != StatusType::SUCCESS){
        std::cout << "remove_team3 failed" << std::endl;
        return false;
    }
    if (olympics->remove_team(team3Id) != StatusType::FAILURE){
        std::cout << "remove_team3 twice failed" << std::endl;
        return false;
    }


    /** add_contestant tests: **/
    if (olympics->add_contestant(contestant2Id, country1Id, sport2, strength2) != StatusType::SUCCESS){
        std::cout << "add_contestant2 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant6Id, country4Id, sport6, strength6) != StatusType::SUCCESS){
        std::cout << "add_contestant6 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant4Id, country4Id, sport4, strength4) != StatusType::SUCCESS){
        std::cout << "add_contestant4 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant3Id, country1Id, sport3, strength3) != StatusType::SUCCESS){
        std::cout << "add_contestant3 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant7Id, country4Id, sport7, strength7) != StatusType::SUCCESS){
        std::cout << "add_contestant7 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant5Id, country4Id, sport5, strength5) != StatusType::SUCCESS){
        std::cout << "add_contestant5 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant5Id, country4Id, sport5, strength5) != StatusType::FAILURE){
        std::cout << "add_contestant5 twice failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant1Id, country1Id, sport1, strength1) != StatusType::SUCCESS){
        std::cout << "add_contestant1 failed" << std::endl;
        return false;
    }



    /** remove_contestant tests: **/

    if (olympics->remove_contestant(contestant7Id) != StatusType::SUCCESS){
        std::cout << "remove_contestant7 failed" << std::endl;
        return false;
    }

    if (olympics->remove_contestant(contestant7Id) != StatusType::FAILURE){
        std::cout << "remove_contestant7 twice failed" << std::endl;
        return false;
    }

    int invalid_contestantId = INT_MAX;

    if (olympics->remove_contestant(invalid_contestantId) != StatusType::FAILURE){
        std::cout << "remove_contestant7 twice failed" << std::endl;
        return false;
    }

    int invalid_contestantId2 = 0;

    if (olympics->remove_contestant(invalid_contestantId2) != StatusType::INVALID_INPUT){
        std::cout << "remove_contestant7 twice failed" << std::endl;
        return false;
    }



    /** add_contestant_to_team tests: **/
    if (olympics->add_contestant_to_team(team1Id, contestant1Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 1 to team1 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team1Id, contestant2Id) != StatusType::FAILURE){
        std::cout << "add_contestant 2 to team1 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team2Id, contestant2Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 2 to team2 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team2Id, contestant3Id) != StatusType::FAILURE){
        std::cout << "add_contestant 3 to team2 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team4Id, contestant4Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 4 to team1 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team5Id, contestant5Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 5 to team5 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team4Id, contestant6Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 6 to team4 failed" << std::endl;
        return false;
    }


    if (olympics->add_team(team3Id, country1Id, sportTeam3) != StatusType::SUCCESS){
        std::cout << "add_team3 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team3Id, contestant3Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 3 to team3 failed" << std::endl;
        return false;
    }

    /** remove_contestant_from_team tests: **/
    if (olympics->remove_contestant_from_team(team1Id, contestant1Id) != StatusType::SUCCESS){
        std::cout << "remove_contestant 1 from team1 failed" << std::endl;
        return false;
    }

    if (olympics->remove_contestant_from_team(team1Id,contestant1Id) != StatusType::FAILURE){
        std::cout << "remove_contestant 1 twice from team1 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team1Id, contestant1Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 1 to team1 failed" << std::endl;
        return false;
    }

    /** update_contestant_strength tests: **/
    if (olympics->update_contestant_strength(contestant2Id , 100) != StatusType::SUCCESS){
        std::cout << "first update_contestant 2 strength failed" << std::endl;
        return false;
    }

    if (olympics->get_strength(contestant2Id).ans() != 2159 && olympics->get_strength(contestant2Id).status() != StatusType::SUCCESS){
        std::cout << "first get_strength contestant2 failed" << std::endl;
        return false;
    }

    if (olympics->update_contestant_strength(contestant2Id , -3000) != StatusType::FAILURE){
        std::cout << "first update_contestant 2 strength failed" << std::endl;
        return false;
    }

    /** get_strength tests: **/
    if (olympics->get_strength(contestant2Id).ans() != 2159 && olympics->get_strength(contestant2Id).status() != StatusType::SUCCESS){
        std::cout << "second get_strength contestant2 failed" << std::endl;
        return false;
    }

    // checking invalid inputs:
    if (olympics->get_strength(invalid_contestantId).status() != StatusType::FAILURE){
        std::cout << "second get_strength contestant2 failed" << std::endl;
        return false;
    }

    if (olympics->get_strength(invalid_contestantId2).status() != StatusType::INVALID_INPUT){
        std::cout << "second get_strength contestant2 failed" << std::endl;
        return false;
    }

    /** get_medals tests: **/
    if (olympics->get_medals(country1Id).ans() != ZERO){
        std::cout << "get_medals country1 failed" << std::endl;
        return false;
    }

    if (olympics->get_medals(country4Id).ans() != 21){
        std::cout << "get_medals country4 failed" << std::endl;
        return false;
    }

    if (olympics->get_medals(invalidCountryId).status() != StatusType::INVALID_INPUT){
        std::cout << "get_medals invalidCountryId failed" << std::endl;
        return false;
    }

    if (olympics->get_medals(country2Id).status() != StatusType::FAILURE){
        std::cout << "get_medals country2Id failed" << std::endl;
        return false;
    }

    /** get_team_strength tests: **/

    // adding contestants 8 and 9 to team1:
    if (olympics->add_contestant(contestant8Id, country1Id, sport8, strength8) != StatusType::SUCCESS){
        std::cout << "add_contestant8 failed" << std::endl;
        return false;
    }
    if (olympics->add_contestant(contestant9Id, country1Id, sport9, strength9) != StatusType::SUCCESS){
        std::cout << "add_contestant9 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team1Id, contestant8Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 8 to team1 failed" << std::endl;
        return false;
    }
    if (olympics->add_contestant_to_team(team1Id, contestant9Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 9 to team1 failed" << std::endl;
        return false;
    }

    // adding contestants 10 and 11 to team2:
    if (olympics->add_contestant(contestant10Id, country1Id, sport10, strength10) != StatusType::SUCCESS){
        std::cout << "add_contestant10 failed" << std::endl;
        return false;
    }
    if (olympics->add_contestant(contestant11Id, country1Id, sport11, strength11) != StatusType::SUCCESS){
        std::cout << "add_contestant11 failed" << std::endl;
        return false;
    }
    if (olympics->add_contestant_to_team(team2Id, contestant10Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 10 to team2 failed" << std::endl;
        return false;
    }
    if (olympics->add_contestant_to_team(team2Id, contestant11Id) != StatusType::SUCCESS){
        std::cout << "add_contestant 11 to team2 failed" << std::endl;
        return false;
    }

    // testing get_team_strength for team 1:
    if (olympics->get_team_strength(team1Id).ans() != strength1 + strength8 + strength9){
        std::cout << "get_team_strength team1 failed" << std::endl;
        return false;
    }

    // testing get_team_strength for team 2:
    if (olympics->get_team_strength(team2Id).ans() != olympics->get_strength(contestant2Id).ans() + strength10 + strength11){
        std::cout << "get_team_strength team2 failed" << std::endl;
        return false;
    }

    if (olympics->remove_team(team3Id) != StatusType::FAILURE){
        std::cout << "remove_team3 with contestants failed" << std::endl;
        return false;
    }

    // testing get_team_strength for an invalid team:
    if (olympics->get_team_strength(77).status() != StatusType::FAILURE){
        std::cout << "get_team_strength team3 failed" << std::endl;
        return false;
    }

    // testing get_team_strength for an invalid input:
    if (olympics->get_team_strength(invalidCountryId).status() != StatusType::INVALID_INPUT){
        std::cout << "get_team_strength invalidCountryId failed" << std::endl;
        return false;
    }

    // testing unite_teams:

    if (olympics->unite_teams(team1Id ,team2Id) != StatusType::FAILURE){
        std::cout << "unite_teams team1 and team2 failed" << std::endl;
        return false;
    }


    int team6Id = 6;
    Sport sportTeam6 = Sport::BOULDERING;

    if (olympics->add_team(team6Id, country1Id, sportTeam6) != StatusType::SUCCESS){
        std::cout << "add_team6 failed" << std::endl;
        return false;
    }



    if (olympics->add_contestant(contestant12Id, country1Id, sport12, strength12) != StatusType::SUCCESS){
        std::cout << "add_contestant12 failed" << std::endl;
        return false;
    }
    if (olympics->add_contestant(contestant13Id, country1Id, sport13, strength13) != StatusType::SUCCESS){
        std::cout << "add_contestant13 failed" << std::endl;
        return false;
    }
    if (olympics->add_contestant(contestant14Id, country1Id, sport14, strength14) != StatusType::SUCCESS){
        std::cout << "add_contestant14 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team6Id, contestant12Id) != StatusType::SUCCESS)
    {
        std::cout << "add_contestant12 to team 6 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team6Id, contestant13Id) != StatusType::SUCCESS)
    {
        std::cout << "add_contestant13 to team 6 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team6Id, contestant14Id) != StatusType::SUCCESS)
    {
        std::cout << "add_contestant14 to team 6 failed" << std::endl;
        return false;
    }


    if (olympics->unite_teams(team1Id ,team6Id) != StatusType::SUCCESS){
        std::cout << "unite_teams team6 and team4 failed" << std::endl;
        return false;
    }

    if (olympics->get_team_strength(team1Id).ans() != strength1 + strength12 + strength14){
        std::cout << "get_team_strength team1 after unite failed" << std::endl;
        return false;
    }

    if (olympics->austerity_measures(team1Id).ans() != strength1 + strength12 + strength14){
        std::cout << "austerity_measures team1 failed" << std::endl;
        return false;
    }

//    StatusType play_match(int teamId1,int teamId2);
//
//    output_t<int> austerity_measures(int teamId);

    std::cout << "First Olympic Test Passed" << std::endl;
    return true;
}

bool unite_teams_test(){

    Olympics* olympics = new Olympics();

    // create a country and add it to the olympics:
    int countryId = 1;
    int medals = 0;

    if (olympics->add_country(countryId, medals) != StatusType::SUCCESS){
        std::cout << "add_country failed" << std::endl;
        return false;
    }

    //create two teams with the same sport:

    int team1Id = 1;
    Sport sportTeam1 = Sport::BOULDERING;


    int team2Id = 2;
    Sport sportTeam2 = Sport::BOULDERING;


    if (olympics->add_team(team1Id, countryId, sportTeam1) != StatusType::SUCCESS){
        std::cout << "add_team1 failed" << std::endl;
        return false;
    }

    if (olympics->add_team(team2Id, countryId, sportTeam2) != StatusType::SUCCESS){
        std::cout << "add_team2 failed" << std::endl;
        return false;
    }
    // create six contestants with the same sport and insert three into team1 and three into team2:

    int contestant1Id = 1;
    int strength1 = 1000;

    int contestant2Id = 2;
    int strength2 = 2000;

    int contestant3Id = 3;
    int strength3 = 3000;

    int contestant4Id = 4;
    int strength4 = 4000;

    int contestant5Id = 5;
    int strength5 = 5000;

    int contestant6Id = 6;
    int strength6 = 6000;


    // add all six contestants to olympics:

    if (olympics->add_contestant(contestant1Id, countryId, sportTeam1, strength1) != StatusType::SUCCESS){
        std::cout << "add_contestant1 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant2Id, countryId, sportTeam1, strength2) != StatusType::SUCCESS){
        std::cout << "add_contestant2 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant3Id, countryId, sportTeam1, strength3) != StatusType::SUCCESS){
        std::cout << "add_contestant3 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant4Id, countryId, sportTeam2, strength4) != StatusType::SUCCESS){
        std::cout << "add_contestant4 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant5Id, countryId, sportTeam2, strength5) != StatusType::SUCCESS){
        std::cout << "add_contestant5 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant(contestant6Id, countryId, sportTeam2, strength6) != StatusType::SUCCESS){
        std::cout << "add_contestant6 failed" << std::endl;
        return false;
    }

    // add three contestants to team1 and three to team2:

    if (olympics->add_contestant_to_team(team1Id, contestant1Id) != StatusType::SUCCESS){
        std::cout << "add_contestant1 to team1 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team1Id, contestant2Id) != StatusType::SUCCESS){
        std::cout << "add_contestant2 to team1 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team1Id, contestant3Id) != StatusType::SUCCESS){
        std::cout << "add_contestant3 to team1 failed" << std::endl;
        return false;
    }

    // add three contestants to team2:

    if (olympics->add_contestant_to_team(team2Id, contestant4Id) != StatusType::SUCCESS){
        std::cout << "add_contestant4 to team2 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team2Id, contestant5Id) != StatusType::SUCCESS){
        std::cout << "add_contestant5 to team2 failed" << std::endl;
        return false;
    }

    if (olympics->add_contestant_to_team(team2Id, contestant6Id) != StatusType::SUCCESS){
        std::cout << "add_contestant6 to team2 failed" << std::endl;
        return false;
    }

    // unite the teams:

    if (olympics->unite_teams(team1Id, team2Id) != StatusType::SUCCESS){
        std::cout << "unite_teams failed" << std::endl;
        return false;
    }







    std::cout << "Unite Teams Test Passed" << std::endl;
    return true;

}

int main(){
//
//    if(!test_1()){
//        std::cout << "Test 1 failed" << std::endl;
//    }
//
//    if(!test_2()){
//        std::cout << "Test 2 failed" << std::endl;
//    }
//    if (!Strength_and_ID_test()){
//        std::cout << "Strength_and_ID_test failed" << std::endl;
//    }
//    if (!testContestantMemberFunctions()){
//        std::cout << "testContestantMemberFunctions failed" << std::endl;
//    }

//    if (!Team_test()){
//        std::cout << "Team_test failed" << std::endl;
//    }

//    if (!olympicTest()){
//        std::cout << "olympicTest failed" << std::endl;
//    }


    if (!unite_teams_test()){
        std::cout << "unite_teams_test failed" << std::endl;
    }

    return 0;
}