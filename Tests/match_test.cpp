#include "Contestant.hpp"
#include "Country.hpp"
#include <iostream>
#include "AVLTree.hpp"
#include "Olympicsa1.h"

int main(){
    Olympics olympus;

    std::cout << "Checking play_match..." << '\n';
    std::cout << "Adding countries..." << '\n';
    std::cout << (int)olympus.add_country(1658, 0) << '\n'; // jamaica
    std::cout << (int)olympus.add_country(54, 0) << '\n'; // argentina

    std::cout << "Adding teams..." << '\n';
    std::cout << (int)olympus.add_team(9, 1658, Sport::ACROBATICS) << '\n'; // team jamaica in acrobatics
    std::cout << (int)olympus.add_team(8, 1658, Sport::SPINNING) << '\n'; // team jamaica in spinning
    std::cout << (int)olympus.add_team(10, 54, Sport::ACROBATICS) << '\n'; // team argentina in acrobatics

    std::cout << "Adding contestants..." << '\n';
    std::cout << (int)olympus.add_contestant(0xaaa, 1658, Sport::ACROBATICS, 4) << '\n';
    std::cout << (int)olympus.add_contestant(0xaba, 1658, Sport::ACROBATICS, 5) << '\n';
    std::cout << (int)olympus.add_contestant(0xaca, 1658, Sport::ACROBATICS, 6) << '\n';
    std::cout << (int)olympus.add_contestant(0xddd, 54, Sport::ACROBATICS, 2) << '\n';
    std::cout << (int)olympus.add_contestant(0xded, 54, Sport::ACROBATICS, 5) << '\n';
    std::cout << (int)olympus.add_contestant(0xdfd, 54, Sport::ACROBATICS, 8) << '\n';

    std::cout << "Adding contestants to teams..." << '\n';
    std::cout << (int)olympus.add_contestant_to_team(9, 0xaaa) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(9, 0xaba) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(9, 0xaca) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(10, 0xddd) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(10, 0xded) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(10, 0xdfd) << '\n';

    std::cout << "How strong is Team Jamaica in Acrobatics?" << '\n';
    output_t<int> team_strength = olympus.get_team_strength(9);
    std::cout << '(' << (int)team_strength.status() << ',' << team_strength.ans() << ')' << "\n";
    std::cout << "How strong is Team Argentina in Acrobatics?" << '\n';
    output_t<int> team_strength2 = olympus.get_team_strength(10);
    std::cout << '(' << (int)team_strength2.status() << ',' << team_strength2.ans() << ')' << "\n";

    std::cout << "How many medals does Jamaica have?" << '\n';
    output_t<int> value = olympus.get_medals(1658);
    std::cout << '(' << (int)value.status() << ',' << value.ans() << ')' << "\n";
    std::cout << "How many medals does Argentina have?" << '\n';
    output_t<int> value2 = olympus.get_medals(54);
    std::cout << '(' << (int)value2.status() << ',' << value2.ans() << ')' << "\n";

    std::cout << "Current game: Argentina vs Jamaica, in Acrobatics." << '\n';
    std::cout << (int)olympus.play_match(10, 9) << '\n';
    std::cout << "How many medals does Jamaica have?" << '\n';
    output_t<int> value_game = olympus.get_medals(1658);
    std::cout << '(' << (int)value_game.status() << ',' << value_game.ans() << ')' << "\n";
    std::cout << "How many medals does Argentina have?" << '\n';
    output_t<int> value_game2 = olympus.get_medals(54);
    std::cout << '(' << (int)value_game2.status() << ',' << value_game2.ans() << ')' << "\n";

    std::cout << "Updating Jamaican player strength..." << '\n';
    std::cout << (int)olympus.update_contestant_strength(0xaba, 1) << '\n';
    std::cout << "How strong is Team Jamaica in Acrobatics?" << '\n';
    output_t<int> team_strength3 = olympus.get_team_strength(9);
    std::cout << '(' << (int)team_strength3.status() << ',' << team_strength3.ans() << ')' << "\n";
    std::cout << "How strong is Team Argentina in Acrobatics?" << '\n';
    output_t<int> team_strength4 = olympus.get_team_strength(10);
    std::cout << '(' << (int)team_strength4.status() << ',' << team_strength4.ans() << ')' << "\n";

    std::cout << "Current game: Argentina vs Jamaica, in Acrobatics." << '\n';
    std::cout << (int)olympus.play_match(10, 9) << '\n';
    std::cout << "How many medals does Jamaica have?" << '\n';
    output_t<int> value_game3 = olympus.get_medals(1658);
    std::cout << '(' << (int)value_game3.status() << ',' << value_game3.ans() << ')' << "\n";
    std::cout << "How many medals does Argentina have?" << '\n';
    output_t<int> value_game4 = olympus.get_medals(54);
    std::cout << '(' << (int)value_game4.status() << ',' << value_game4.ans() << ')' << "\n";

    std::cout << "Updating Argentinian player strength..." << '\n';
    std::cout << (int)olympus.update_contestant_strength(0xded, 1) << '\n';
    std::cout << "How strong is Team Jamaica in Acrobatics?" << '\n';
    output_t<int> team_strength5 = olympus.get_team_strength(9);
    std::cout << '(' << (int)team_strength5.status() << ',' << team_strength5.ans() << ')' << "\n";
    std::cout << "How strong is Team Argentina in Acrobatics?" << '\n';
    output_t<int> team_strength6 = olympus.get_team_strength(10);
    std::cout << '(' << (int)team_strength6.status() << ',' << team_strength6.ans() << ')' << "\n";

    std::cout << "Current game: Argentina vs Jamaica, in Acrobatics." << '\n';
    std::cout << (int)olympus.play_match(10, 9) << '\n';
    std::cout << "How many medals does Jamaica have?" << '\n';
    output_t<int> value_game5 = olympus.get_medals(1658);
    std::cout << '(' << (int)value_game5.status() << ',' << value_game5.ans() << ')' << "\n";
    std::cout << "How many medals does Argentina have?" << '\n';
    output_t<int> value_game6 = olympus.get_medals(54);
    std::cout << '(' << (int)value_game6.status() << ',' << value_game6.ans() << ')' << "\n";

    std::cout << "Current game: StatusType::INVALID_INPUT == 2." << '\n';
    std::cout << (int)olympus.play_match(9, 9) << '\n'; // vs itself
    std::cout << (int)olympus.play_match(10, 0) << '\n'; // null id
    std::cout << (int)olympus.play_match(10, -9) << '\n'; // negative id
    std::cout << (int)olympus.play_match(0, 9) << '\n'; // null id
    std::cout << (int)olympus.play_match(-10, 9) << '\n'; // negative id

    std::cout << "Current game: StatusType::FAILURE == 3." << '\n';
    std::cout << (int)olympus.play_match(7, 9) << '\n'; // no such team
    std::cout << (int)olympus.play_match(10, 11) << '\n'; // no such team
    std::cout << (int)olympus.play_match(9, 8) << '\n'; // wrong sports
    std::cout << (int)olympus.play_match(8, 10) << '\n'; // wrong sports

    std::cout << "Checking unite_teams..." << '\n';
    std::cout << "Adding teams..." << '\n';
    std::cout << (int)olympus.add_team(7, 1658, Sport::ACROBATICS) << '\n'; // team jamaica in acrobatics
    std::cout << (int)olympus.add_team(6, 1658, Sport::SPINNING) << '\n'; // team jamaica in spinning
    std::cout << (int)olympus.add_team(5, 54, Sport::ACROBATICS) << '\n'; // team argentina in acrobatics
    std::cout << (int)olympus.add_team(4, 1658, Sport::ACROBATICS) << '\n'; // team jamaica in acrobatics
    std::cout << (int)olympus.add_team(3, 1658, Sport::SPINNING) << '\n'; // team jamaica in spinning
    std::cout << (int)olympus.add_team(2, 54, Sport::ACROBATICS) << '\n'; // team argentina in acrobatics
    std::cout << (int)olympus.add_team(1, 54, Sport::ACROBATICS) << '\n'; // team argentina in acrobatics

    std::cout << "Adding contestants..." << '\n';
    std::cout << (int)olympus.add_contestant(0xada, 1658, Sport::ACROBATICS, 2) << '\n';
    std::cout << (int)olympus.add_contestant(0xaea, 1658, Sport::ACROBATICS, 3) << '\n';
    std::cout << (int)olympus.add_contestant(0xafa, 1658, Sport::ACROBATICS, 8) << '\n';
    std::cout << (int)olympus.add_contestant(0xdad, 54, Sport::ACROBATICS, 1) << '\n';
    std::cout << (int)olympus.add_contestant(0xdbd, 54, Sport::ACROBATICS, 2) << '\n';
    std::cout << (int)olympus.add_contestant(0xdcd, 54, Sport::ACROBATICS, 3) << '\n';
    std::cout << (int)olympus.add_contestant(0xa1a, 1658, Sport::SPINNING, 4) << '\n';
    std::cout << (int)olympus.add_contestant(0xa2a, 1658, Sport::SPINNING, 7) << '\n';
    std::cout << (int)olympus.add_contestant(0xa0a, 1658, Sport::SPINNING, 6) << '\n';

    std::cout << "Adding contestants to teams..." << '\n';
    std::cout << (int)olympus.add_contestant_to_team(7, 0xada) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(7, 0xaea) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(4, 0xafa) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(5, 0xdad) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(5, 0xdbd) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(2, 0xdcd) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(1, 0xdcd) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(5, 0xddd) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(3, 0xa1a) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(3, 0xa2a) << '\n';
    std::cout << (int)olympus.add_contestant_to_team(3, 0xa0a) << '\n';

    std::cout << "How strong are the ten teams?" << '\n';
    output_t<int> team1 = olympus.get_team_strength(1);
    std::cout << '(' << (int)team1.status() << ',' << team1.ans() << ')' << "\n";
    output_t<int> team2 = olympus.get_team_strength(2);
    std::cout << '(' << (int)team2.status() << ',' << team2.ans() << ')' << "\n";
    output_t<int> team3 = olympus.get_team_strength(3);
    std::cout << '(' << (int)team3.status() << ',' << team3.ans() << ')' << "\n";
    output_t<int> team4 = olympus.get_team_strength(4);
    std::cout << '(' << (int)team4.status() << ',' << team4.ans() << ')' << "\n";
    output_t<int> team5 = olympus.get_team_strength(5);
    std::cout << '(' << (int)team5.status() << ',' << team5.ans() << ')' << "\n";
    output_t<int> team6 = olympus.get_team_strength(6);
    std::cout << '(' << (int)team6.status() << ',' << team6.ans() << ')' << "\n";
    output_t<int> team7 = olympus.get_team_strength(7);
    std::cout << '(' << (int)team7.status() << ',' << team7.ans() << ')' << "\n";
    output_t<int> team8 = olympus.get_team_strength(8);
    std::cout << '(' << (int)team8.status() << ',' << team8.ans() << ')' << "\n";
    output_t<int> team9 = olympus.get_team_strength(9);
    std::cout << '(' << (int)team9.status() << ',' << team9.ans() << ')' << "\n";
    output_t<int> team10 = olympus.get_team_strength(10);
    std::cout << '(' << (int)team10.status() << ',' << team10.ans() << ')' << "\n";

    std::cout << "Merging teams..." << '\n';
    std::cout << (int)olympus.unite_teams(7, 4) << '\n';
    std::cout << (int)olympus.unite_teams(5, 10) << '\n';
    std::cout << (int)olympus.unite_teams(6, 8) << '\n';
    std::cout << (int)olympus.unite_teams(1, 2) << '\n';

    std::cout << "How strong are the teams?" << '\n';
    output_t<int> team1_ = olympus.get_team_strength(1);
    std::cout << '(' << (int)team1_.status() << ',' << team1_.ans() << ')' << "\n";
    output_t<int> team3_ = olympus.get_team_strength(3);
    std::cout << '(' << (int)team3_.status() << ',' << team3_.ans() << ')' << "\n";
    output_t<int> team5_ = olympus.get_team_strength(5);
    std::cout << '(' << (int)team5_.status() << ',' << team5_.ans() << ')' << "\n";
    output_t<int> team6_ = olympus.get_team_strength(6);
    std::cout << '(' << (int)team6_.status() << ',' << team6_.ans() << ')' << "\n";
    output_t<int> team7_ = olympus.get_team_strength(7);
    std::cout << '(' << (int)team7_.status() << ',' << team7_.ans() << ')' << "\n";
    output_t<int> team9_ = olympus.get_team_strength(9);
    std::cout << '(' << (int)team9_.status() << ',' << team9_.ans() << ')' << "\n";

    std::cout << "Let us try to get the strength of deleted teams - (3,0)" << '\n';
    output_t<int> team2_ = olympus.get_team_strength(2);
    std::cout << '(' << (int)team2_.status() << ',' << team2_.ans() << ')' << "\n";
    output_t<int> team4_ = olympus.get_team_strength(4);
    std::cout << '(' << (int)team4_.status() << ',' << team4_.ans() << ')' << "\n";
    output_t<int> team8_ = olympus.get_team_strength(8);
    std::cout << '(' << (int)team8_.status() << ',' << team8_.ans() << ')' << "\n";
    output_t<int> team10_ = olympus.get_team_strength(10);
    std::cout << '(' << (int)team10_.status() << ',' << team10_.ans() << ')' << "\n";

    std::cout << "Merging teams..." << '\n';
    std::cout << (int)olympus.unite_teams(7, 9) << '\n';
    std::cout << (int)olympus.unite_teams(1, 5) << '\n';
    std::cout << (int)olympus.unite_teams(3, 6) << '\n';

    std::cout << "How strong are the teams?" << '\n';
    output_t<int> team1__ = olympus.get_team_strength(1); // 54, Sport::ACROBATICS
    std::cout << '(' << (int)team1__.status() << ',' << team1__.ans() << ')' << "\n";
    output_t<int> team3__ = olympus.get_team_strength(3); // 1658, Sport::SPINNING
    std::cout << '(' << (int)team3__.status() << ',' << team3__.ans() << ')' << "\n";
    output_t<int> team7__ = olympus.get_team_strength(7); // 1658, Sport::ACROBATICS
    std::cout << '(' << (int)team7__.status() << ',' << team7__.ans() << ')' << "\n";

    std::cout << "Merging teams, expecting StatusType::INVALID_INPUT == 2..." << '\n';
    std::cout << (int)olympus.unite_teams(0, 4) << '\n'; // null id
    std::cout << (int)olympus.unite_teams(-5, 10) << '\n'; // negative id
    std::cout << (int)olympus.unite_teams(6, 0) << '\n'; // null id
    std::cout << (int)olympus.unite_teams(1, -2) << '\n'; // negative id
    std::cout << (int)olympus.unite_teams(1, 1) << '\n'; // same id

    std::cout << "Merging teams, expecting StatusType::FAILURE == 3..." << '\n';
    std::cout << (int)olympus.unite_teams(1, 4) << '\n'; // deleted team
    std::cout << (int)olympus.unite_teams(5, 10) << '\n'; // deleted teams
    std::cout << (int)olympus.unite_teams(1, 7) << '\n'; // incompatible countrie
    std::cout << (int)olympus.unite_teams(7, 3) << '\n'; // incompatible sports

    std::cout << "Last game: Argentina vs Jamaica, in Acrobatics." << '\n';
    std::cout << (int)olympus.play_match(1, 7) << '\n';
    std::cout << "How many medals does Jamaica have?" << '\n';
    output_t<int> value_game7 = olympus.get_medals(1658);
    std::cout << '(' << (int)value_game7.status() << ',' << value_game7.ans() << ')' << "\n";
    std::cout << "How many medals does Argentina have?" << '\n';
    output_t<int> value_game8 = olympus.get_medals(54);
    std::cout << '(' << (int)value_game8.status() << ',' << value_game8.ans() << ')' << std::endl;
}