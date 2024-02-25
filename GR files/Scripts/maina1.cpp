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
//
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


#include "AVL_Tree.h"
#include "../Classes/Team.h"
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

    return 0;
}