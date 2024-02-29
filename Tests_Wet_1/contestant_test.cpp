#include "Contestant.hpp"
#include "Country.hpp"
#include <iostream>
#include "AVLTree.hpp"
#include "Olympicsa1.h"
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

    std::cout << "trying to get medal count successfully\n";
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

    std::cout << "trying to get StatusType::FAILURE == 3 by removing vietnam when it still has active players" << '\n';
    std::cout << (int)olympus.remove_country(84) << '\n'; // vietnam

    std::cout << "Removing contestants..." << '\n';
    std::cout << (int)olympus.remove_contestant(0xaba) << '\n'; // grzegorz
    std::cout << (int)olympus.remove_contestant(0xabb) << '\n'; // wladyslaw
    std::cout << (int)olympus.remove_contestant(0xabf) << '\n'; // wladyslawa
    std::cout << (int)olympus.remove_contestant(0xab7) << '\n'; // fryderyk
    std::cout << (int)olympus.remove_contestant(0xabc) << '\n'; // chinh
    std::cout << "trying to get StatusType::FAILURE == 3 by removing vietnam when it still has active players" << '\n';
    std::cout << (int)olympus.remove_country(84) << '\n'; // vietnam
    std::cout << "Removing contestants..." << '\n';
    std::cout << (int)olympus.remove_contestant(0xbbb) << '\n'; // nhung
    std::cout << "trying to get StatusType::FAILURE == 3 by removing vietnam when it still has active players" << '\n';
    std::cout << (int)olympus.remove_country(84) << '\n'; // vietnam
    std::cout << "Removing contestants..." << '\n';
    std::cout << (int)olympus.remove_contestant(0xccc) << '\n'; // truong
    std::cout << "trying to remove vietnam when it has no active players" << '\n';
    std::cout << (int)olympus.remove_country(84) << '\n'; // vietnam

    std::cout << "trying to get StatusType::INVALID_INPUT == 2" << '\n';
    std::cout << (int)olympus.remove_contestant(0) << '\n'; // null id
    std::cout << (int)olympus.remove_contestant(-0xff) << '\n'; // negative id

    std::cout << "trying to get StatusType::FAILURE == 3" << '\n';
    std::cout << (int)olympus.remove_contestant(0xfff) << '\n'; // no such contestant
    std::cout << (int)olympus.remove_contestant(0xaba) << '\n'; // grzegorz was deleted already
    return 0;
}