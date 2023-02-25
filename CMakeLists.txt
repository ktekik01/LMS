cmake_minimum_required(VERSION 3.21)
project(LeagueManagementSystem)

set(CMAKE_CXX_STANDARD 98)

add_executable(LeagueManagementSystem main.cpp LeagueManagementSystem.cpp LeagueManagementSystem.h Player.cpp Player.h Team.cpp Team.h)
