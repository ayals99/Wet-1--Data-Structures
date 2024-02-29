cmake_minimum_required(VERSION 3.27)
project(Wet_1__Data_Structures)

set(CMAKE_CXX_STANDARD 14)

include_directories("AVL Tree")
include_directories("GR files/Scripts")

add_executable(Wet_1__Data_Structures
        "AVL Tree/AVL_Node.h"
        "AVL Tree/AVL_Tree.h"
        "Olympicsa1.h"
        "wet1util.h"
        "Olympicsa1.cpp"
        "Contestant_Country_ID_Strength_Team.cpp"
        "Contestant_Country_ID_Strength_Team.h"
        "our_Main.cpp"
)
