cmake_minimum_required(VERSION 3.27)
project(Wet_1__Data_Structures)

set(CMAKE_CXX_STANDARD 14)

include_directories("AVL Tree")
include_directories("GR files/Scripts")

add_executable(Wet_1__Data_Structures
        "AVL Tree/AVL_Node.h"
        "GR files/Scripts/maina1.cpp"
        "GR files/Scripts/Olympicsa1.cpp"
        "GR files/Scripts/Olympicsa1.h"
        "GR files/Scripts/wet1util.h"
        "AVL Tree/AVL_Tree.h"
        "AVL Tree/Contestant_Liaison.h"
        Classes/Contestant.cpp
        Classes/Contestant.h
        Classes/Team.cpp
        Classes/Team.h
        Classes/Strength.cpp
        Classes/Strength.h
        Classes/Country.cpp
        Classes/Country.h
        Classes/ID.cpp
        Classes/ID.h
)
