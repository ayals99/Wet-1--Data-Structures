// 
// 234218 Data Structures 1.
// Semester: 2024A (winter).
// Wet Exercise #1.
// 
// Recommended TAB size to view this file: 8.
// 
// The following main file is necessary to link and run your code.
// This file is READ ONLY: even if you submit something else, the compiler ..
// .. WILL use our file.
// 

#include "Olympicsa1.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void print(string cmd, StatusType res, ofstream &fout);
void print(string cmd, output_t<int> res, ofstream &fout);

int main_check()
{
    cout << "Welcome to the Olympics" << endl;

    // Input variables - for debug means
    ifstream fin("22ktest_in.txt");
    ofstream fout("22ktest_in_ours.txt");
	
    int d1, d2, d3, g1;
    string b1;
    bool b;

    // Init
    Olympics *obj = new Olympics();
	
    // Execute all commands in file
	string op;
	while (fin >> op)
    {
        if (!op.compare("add_country")) {
            fin >> d1 >> d2;
            print(op, obj->add_country(d1, d2), fout);
        } else if (!op.compare("remove_country")) {
            fin >> d1;
            print(op, obj->remove_country(d1), fout);
        } else if (!op.compare("add_team")) {
            fin >> d1 >> d2 >> d3;
            print(op, obj->add_team(d1, d2, (Sport)d3), fout);
        } else if (!op.compare("remove_team")) {
            fin >> d1;
            print(op, obj->remove_team(d1), fout);
        } else if (!op.compare("add_contestant")) {
            fin >> d1 >> d2 >> d3 >> g1;
            print(op, obj->add_contestant(d1, d2, (Sport)d3, g1), fout);
        } else if (!op.compare("remove_contestant")) {
            fin >> d1;
            print(op, obj->remove_contestant(d1), fout);
        } else if (!op.compare("add_contestant_to_team")) {
            fin >> d1 >> d2;
            print(op, obj->add_contestant_to_team(d1, d2), fout);
        } else if (!op.compare("remove_contestant_from_team")) {
            fin >> d1 >> d2;
            print(op, obj->remove_contestant_from_team(d1, d2), fout);
        } else if (!op.compare("update_contestant_strength")) {
            fin >> d1 >> d2;
            print(op, obj->update_contestant_strength(d1, d2), fout);
        } else if (!op.compare("get_strength")) {
            fin >> d1;
            print(op, obj->get_strength(d1), fout);
        } else if (!op.compare("get_medals")) {
            fin >> d1;
            print(op, obj->get_medals(d1), fout);
        } else if (!op.compare("get_team_strength")) {
            fin >> d1;
            print(op, obj->get_team_strength(d1), fout);
        } else if (!op.compare("unite_teams")) {
            fin >> d1 >> d2;
            print(op, obj->unite_teams(d1, d2), fout);
        } else if (!op.compare("play_match")) {
            fin >> d1 >> d2;
            print(op, obj->play_match(d1, d2), fout);
        } else if (!op.compare("austerity_measures")) {
            fin >> d1;
            print(op, obj->austerity_measures(d1), fout);
        } else {
            fout << "Unknown command: " << op << endl;
            return -1;
        }
        // Verify no faults
        if (fin.fail()){
            fout << "Invalid input format" << endl;
            return -1;
        }
    }

    // Quit 
	delete obj;
	return 0;
}

// Helpers
static const char *StatusTypeStr[] =
{
   	"SUCCESS",
	"ALLOCATION_ERROR",
	"INVALID_INPUT",
	"FAILURE"
};

void print(string cmd, StatusType res, ofstream &fout) 
{
	fout << cmd << ": " << StatusTypeStr[(int) res] << endl;
}

void print(string cmd, output_t<int> res, ofstream &fout) 
{
    if (res.status() == StatusType::SUCCESS) {
	    fout << cmd << ": " << StatusTypeStr[(int) res.status()] << ", " << res.ans() << endl;
    } else {
	    fout << cmd << ": " << StatusTypeStr[(int) res.status()] << endl;
    }
}

// my unit tests
int main()
{
    main_check();
    return 0;
}