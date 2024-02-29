#include "Contestant.hpp"
#include "Contestant.cpp"
#include "Country.hpp"
#include "Country.cpp"
#include <iostream>
#include "AVLTree.hpp"
#include "Olympicsa1.h"
#include "Olympicsa1.cpp"
#include "Team.cpp"
int main(){
    Olympics olympus;
    
    std::cout << "Adding countries..." << '\n';
    std::cout << (int)olympus.add_country(48, 0) << '\n'; // poland
    std::cout << (int)olympus.add_country(84, 0) << '\n'; // vietnam

    std::cout << "Adding contestants..." << '\n';
    std::cout << (int)olympus.add_contestant(0xaba, 48, Sport::ACROBATICS, 4) << '\n'; // grzegorz
    std::cout << (int)olympus.add_contestant(0xabb, 48, Sport::SPINNING, 3) << '\n'; // wladyslaw
    std::cout << (int)olympus.add_contestant(0xab7, 48, Sport::BOULDERING, 7) << '\n'; // fryderyk
    std::cout << (int)olympus.add_contestant(0xabc, 84, Sport::ACROBATICS, 5) << '\n'; // chinh
    std::cout << (int)olympus.add_contestant(0xbbb, 84, Sport::SPINNING, 2) << '\n'; // nhung
    std::cout << (int)olympus.add_contestant(0xccc, 84, Sport::BOULDERING, 6) << '\n'; // truong
    std::cout << (int)olympus.add_contestant(0xabf, 48, Sport::SWIMMING, 1) << '\n'; // wladyslawa

    std::cout << "trying to get StatusType::INVALID_INPUT == 2" << '\n';
    std::cout << (int)olympus.add_contestant(0, 48, Sport::ACROBATICS, 4) << '\n'; // null id
    std::cout << (int)olympus.add_contestant(-1, 48, Sport::SPINNING, 3) << '\n'; // negative id
    std::cout << (int)olympus.add_contestant(0xab7, 0, Sport::BOULDERING, 7) << '\n'; // null country
    std::cout << (int)olympus.add_contestant(0xabc, -69, Sport::ACROBATICS, 5) << '\n'; // negative country
    std::cout << (int)olympus.add_contestant(0xbbb, 84, Sport::SPINNING, -2) << '\n'; // negative strength

    std::cout << "trying to get StatusType::FAILURE == 3" << '\n';
    std::cout << (int)olympus.add_contestant(0xcc, 972, Sport::ACROBATICS, 4) << '\n'; // no such country
    std::cout << (int)olympus.add_contestant(0xabf, 48, Sport::SWIMMING, 1) << '\n'; // wladyslawa again
    std::cout << (int)olympus.add_contestant(0xabf, 84, Sport::BOULDERING, 7) << '\n'; // wladyslawa's id again

    std::cout << "trying to get strength successfully\n";
    output_t<int> value = olympus.get_strength(0xabb);
    std::cout << '(' << (int)value.status() << ',' << value.ans() << ')' << "\n";
    output_t<int> value2 = olympus.get_strength(0xccc);
    std::cout << '(' << (int)value2.status() << ',' << value2.ans() << ')' << "\n";
    std::cout << "trying to get StatusType::INVALID_INPUT == 2" << '\n';
    output_t<int> value3 = olympus.get_strength(0); // null id
    std::cout << '(' << (int)value3.status() << ',' << value3.ans() << ')' << "\n";
    output_t<int> value5 = olympus.get_strength(-0b1111); // negative id
    std::cout << '(' << (int)value5.status() << ',' << value5.ans() << ')' << "\n";
    std::cout << "trying to get StatusType::FAILURE == 3" << '\n';
    output_t<int> value4 = olympus.get_medals(54); // no such contestant
    std::cout << '(' << (int)value4.status() << ',' << value4.ans() << ')' << "\n";

    std::cout << "Adding team..." << '\n';
    std::cout << (int)olympus.add_team(9, 48, Sport::ACROBATICS) << '\n'; // team poland
    std::cout << "trying to get StatusType::INVALID_INPUT == 2" << '\n';
    std::cout << (int)olympus.add_team(0, 48, Sport::ACROBATICS) << '\n'; // null id
    std::cout << (int)olympus.add_team(-1, 48, Sport::SPINNING) << '\n'; // negative id
    std::cout << (int)olympus.add_team(0xab7, 0, Sport::BOULDERING) << '\n'; // null country
    std::cout << (int)olympus.add_team(0xabc, -69, Sport::ACROBATICS) << '\n'; // negative country
    std::cout << "trying to get StatusType::FAILURE == 3" << '\n';
    std::cout << (int)olympus.add_team(9, 972, Sport::ACROBATICS) << '\n'; // no such country
    std::cout << (int)olympus.add_team(9, 48, Sport::SWIMMING) << '\n'; // team poland again

    std::cout << "Adding Grzegorz to team Poland..." << '\n';
    std::cout << (int)olympus.add_contestant_to_team(9, 0xaba) << '\n';
    std::cout << "trying to get StatusType::INVALID_INPUT == 2" << '\n';
    std::cout << (int)olympus.add_contestant_to_team(0, 0xabc) << '\n'; // null id
    std::cout << (int)olympus.add_contestant_to_team(-1, 0xabc) << '\n'; // negative id
    std::cout << (int)olympus.add_contestant_to_team(9, 0) << '\n'; // null contestant
    std::cout << (int)olympus.add_contestant_to_team(9, -69) << '\n'; // negative contestant
    std::cout << "trying to get StatusType::FAILURE == 3" << '\n';
    std::cout << (int)olympus.add_contestant_to_team(9, 0xaba) << '\n'; // grzegorz again
    std::cout << (int)olympus.add_contestant_to_team(9, 0xabb) << '\n'; // differnet sport
    std::cout << (int)olympus.add_contestant_to_team(9, 0xabc) << '\n'; // differnet country
    std::cout << "trying to get StatusType::FAILURE == 3 by removing grzegorz while he's active" << '\n';
    std::cout << (int)olympus.remove_contestant(0xaba) << '\n'; // grzegorz
    std::cout << "Adding contestants..." << '\n';
    std::cout << (int)olympus.add_contestant(0xaff, 48, Sport::ACROBATICS, 7) << '\n'; // jan
    std::cout << (int)olympus.add_contestant(0xafe, 48, Sport::ACROBATICS, 4) << '\n'; // max
    std::cout << (int)olympus.add_contestant(0xafd, 48, Sport::ACROBATICS, 6) << '\n'; // przemyslaw

    std::cout << "How strong is team Poland?" << '\n';
    output_t<int> team_strength = olympus.get_team_strength(9);
    std::cout << '(' << (int)team_strength.status() << ',' << team_strength.ans() << ')' << "\n";
    std::cout << "Adding Jan and Max to team Poland..." << '\n';
    std::cout << (int)olympus.add_contestant_to_team(9, 0xaff) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(9, 0xafe) << '\n';
    std::cout << "How strong is team Poland?" << '\n';
    output_t<int> team_strength2 = olympus.get_team_strength(9);
    std::cout << '(' << (int)team_strength2.status() << ',' << team_strength2.ans() << ')' << "\n";
    std::cout << "Adding Przemyslaw to team Poland..." << '\n';
    std::cout << (int)olympus.add_contestant_to_team(9, 0xafd) << '\n';
    std::cout << "How strong is team Poland?" << '\n';
    output_t<int> team_strength3 = olympus.get_team_strength(9);
    std::cout << '(' << (int)team_strength3.status() << ',' << team_strength3.ans() << ')' << "\n";

    std::cout << "trying to get StatusType::INVALID_INPUT == 2" << '\n';
    output_t<int> team_strength4 = olympus.get_team_strength(-2); // negative id
    std::cout << '(' << (int)team_strength4.status() << ',' << team_strength4.ans() << ')' << "\n";
    output_t<int> team_strength5 = olympus.get_team_strength(0); // null id
    std::cout << '(' << (int)team_strength5.status() << ',' << team_strength5.ans() << ')' << "\n";
    std::cout << "trying to get StatusType::INVALID_INPUT == 3" << '\n';
    output_t<int> team_strength6 = olympus.get_team_strength(17); // no such team
    std::cout << '(' << (int)team_strength6.status() << ',' << team_strength6.ans() << ')' << "\n";

    std::cout << "Adding teams..." << '\n';
    std::cout << (int)olympus.add_team(7, 48, Sport::ACROBATICS) << '\n'; // team poland2
    std::cout << (int)olympus.add_team(6, 48, Sport::ACROBATICS) << '\n'; // team poland3
    std::cout << (int)olympus.add_team(5, 48, Sport::ACROBATICS) << '\n'; // team poland4
    std::cout << "Adding Grzegorz to the new teams..." << '\n';
    std::cout << (int)olympus.add_contestant_to_team(7, 0xaba) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(6, 0xaba) << '\n';
    std::cout << "trying to get StatusType::FAILURE == 3 by adding grzegorz to a fourth team" << '\n';
    std::cout << (int)olympus.add_contestant_to_team(5, 0xaba) << '\n';
    std::cout << "Removing Grzegorz from team Poland 3..." << '\n';
    std::cout << (int)olympus.remove_contestant_from_team(6, 0xaba) << '\n';
    std::cout << "Adding Grzegorz to team Poland 4..." << '\n';
    std::cout << (int)olympus.add_contestant_to_team(5, 0xaba) << '\n';
    std::cout << "trying to get StatusType::INVALID_INPUT == 2 when removing" << '\n';
    std::cout << (int)olympus.remove_contestant_from_team(0, 0xabc) << '\n'; // null id
    std::cout << (int)olympus.remove_contestant_from_team(-1, 0xabc) << '\n'; // negative id
    std::cout << (int)olympus.remove_contestant_from_team(9, 0) << '\n'; // null contestant
    std::cout << (int)olympus.remove_contestant_from_team(9, -69) << '\n'; // negative contestant
    std::cout << "trying to get StatusType::FAILURE == 3 when removing" << '\n';
    std::cout << (int)olympus.remove_contestant_from_team(14, 0xabc) << '\n'; // no such team
    std::cout << (int)olympus.remove_contestant_from_team(7, 0x6666) << '\n'; // no such player
    std::cout << (int)olympus.remove_contestant_from_team(9, 0xccc) << '\n'; // truong is not in team poland
    std::cout << "trying to get strength pre-operation\n";
    output_t<int> value_pre = olympus.get_strength(0xaba);
    std::cout << '(' << (int)value_pre.status() << ',' << value_pre.ans() << ')' << "\n";
    std::cout << "trying to update grzegorz's strength\n";
    std::cout << (int)olympus.update_contestant_strength(0xaba, 6) << '\n';
    std::cout << "trying to get strength post-operation\n";
    output_t<int> value_post = olympus.get_strength(0xaba);
    std::cout << '(' << (int)value_post.status() << ',' << value_post.ans() << ')' << "\n";
    std::cout << "trying to update grzegorz's strength illegally\n";
    std::cout << (int)olympus.update_contestant_strength(0xaba, -11) << '\n';
    std::cout << "trying to get strength post-operation\n";
    output_t<int> value_post2 = olympus.get_strength(0xaba);
    std::cout << '(' << (int)value_post2.status() << ',' << value_post2.ans() << ')' << "\n";
    std::cout << "trying to get StatusType::INVALID_INPUT == 2" << '\n';
    std::cout << (int)olympus.update_contestant_strength(-12, -11) << '\n'; // negative id
    std::cout << (int)olympus.update_contestant_strength(0, 11) << '\n'; // null id
    std::cout << "trying to get StatusType::FAILURE == 3" << '\n';
    std::cout << (int)olympus.update_contestant_strength(0x6666, 11) << '\n'; // no such player
    std::cout << "Removing Max from team Poland..." << '\n';
    std::cout << (int)olympus.remove_contestant_from_team(9, 0xafe) << '\n';
    std::cout << "How strong is team Poland?" << '\n';
    output_t<int> team_strength7 = olympus.get_team_strength(9);
    std::cout << '(' << (int)team_strength7.status() << ',' << team_strength7.ans() << ')' << "\n";
    std::cout << "trying to get StatusType::FAILURE == 3 by removing team poland when it is active" << '\n';
    std::cout << (int)olympus.remove_team(9) << '\n';
    std::cout << "trying to get StatusType::FAILURE == 3 by removing a nonexistent team" << '\n';
    std::cout << (int)olympus.remove_team(13) << '\n';
    std::cout << "trying to get StatusType::INVALID_INPUT == 2" << '\n';
    std::cout << (int)olympus.remove_team(0) << '\n'; // null id
    std::cout << (int)olympus.remove_team(-1) << '\n'; // negative id
    std::cout << "trying to remove team Poland 3..." << '\n';
    std::cout << (int)olympus.remove_team(6) << '\n';

    std::cout << "Removing contestant Chinh..." << '\n';
    std::cout << (int)olympus.remove_contestant(0xabc) << '\n'; // chinh
    std::cout << "trying to get StatusType::FAILURE == 3 by removing vietnam when it still has active players" << '\n';
    std::cout << (int)olympus.remove_country(84) << '\n'; // vietnam
    std::cout << "Removing contestant Nhung..." << '\n';
    std::cout << (int)olympus.remove_contestant(0xbbb) << '\n'; // nhung
    std::cout << "trying to get StatusType::FAILURE == 3 by removing vietnam when it still has active players" << '\n';
    std::cout << (int)olympus.remove_country(84) << '\n'; // vietnam
    std::cout << "Removing contestant Truong..." << '\n';
    std::cout << (int)olympus.remove_contestant(0xccc) << '\n'; // truong
    std::cout << "Adding team Vietnam...\n";
    std::cout << (int)olympus.add_team(8, 84, Sport::SWIMMING) << '\n'; // team vietnam
    std::cout << "trying to get StatusType::FAILURE == 3 by removing vietnam when it still has active teams" << '\n';
    std::cout << (int)olympus.remove_country(84) << '\n'; // vietnam
    std::cout << "trying to remove team Vietnam..." << '\n';
    std::cout << (int)olympus.remove_team(8) << '\n';
    std::cout << "trying to remove vietnam when it has no active players" << '\n';
    std::cout << (int)olympus.remove_country(84) << '\n'; // vietnam
    return 0;
}