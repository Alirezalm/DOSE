cmake_minimum_required(VERSION 3.22)
project(DOSE VERSION 1.0.0 DESCRIPTION "Distributed Operator Splitting Engine")
find_package(MPI REQUIRED)
#set(CMAKE_CXX_FLAGS "-march=native -O2")
set(CMAKE_CXX_COMPILER mpicxx)
set(CMAKE_CXX_STANDARD 17)
add_library(DOSE STATIC
        src/LinRSolver.cpp
        src/LogRSolver.cpp
        src/DistEngine.cpp
        src/DOSE.cpp
        src/Utilities.cpp
        src/LogRegStrategy.cpp
        src/LinRegStrategy.cpp
        src/AlgorithmManager.cpp
        src/RandomDataGenerator.cpp
        )
#add_executable(DOSE main.cpp
#        src/LinRSolver.cpp
#        src/LogRSolver.cpp
#        src/DistEngine.cpp
#        src/DOSE.cpp
#        src/Utilities.cpp
#        src/LogRegStrategy.cpp
#        src/LinRegStrategy.cpp
#        src/AlgorithmManager.cpp
#        src/RandomDataGenerator.cpp
#        )