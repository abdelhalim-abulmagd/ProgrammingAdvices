# CMakeLists.txt for BankSystem project
cmake_minimum_required(VERSION 3.31)

# Define the project name
project(BankSystem)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Set the source files for the project
set(SOURCE_FILES

    # Global
    ${CMAKE_SOURCE_DIR}/Include/Global.h
    ${CMAKE_SOURCE_DIR}/Source/Global.cpp

    # main file
    ${CMAKE_SOURCE_DIR}/Source/main.cpp

    # utility files
    ${CMAKE_SOURCE_DIR}/Include/clsString.h
    ${CMAKE_SOURCE_DIR}/Source/clsString.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsDate.h
    ${CMAKE_SOURCE_DIR}/Source/clsDate.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsInput.h
    ${CMAKE_SOURCE_DIR}/Source/clsInput.cpp

    # object files
    ${CMAKE_SOURCE_DIR}/Include/clsPerson.h
    ${CMAKE_SOURCE_DIR}/Source/clsPerson.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsUser.h
    ${CMAKE_SOURCE_DIR}/Source/clsUser.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsClint.h
    ${CMAKE_SOURCE_DIR}/Source/clsClint.cpp

    # screen files
    ${CMAKE_SOURCE_DIR}/Include/clsScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsLoginScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsLoginScreen.cpp

    # clint screen
    ${CMAKE_SOURCE_DIR}/Include/clsClintMainScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsClintMainScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsUpdateClintScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsUpdateClintScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsAddClintScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsAddClintScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsDeleteClintScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsDeleteClintScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsListClintScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsListClintScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsLogScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsLogScreen.cpp


    # transaction screen
    ${CMAKE_SOURCE_DIR}/Include/clsTransactionMenuScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsTransactionMenuScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsDepositScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsDepositScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsWithdrawScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsWithdrawScreen.cpp

    # manage users screen
    ${CMAKE_SOURCE_DIR}/Include/clsManageUsersScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsManageUsersScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsListUserScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsListUserScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsAddUserScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsAddUserScreen.cpp

    ${CMAKE_SOURCE_DIR}/Include/clsDeleteUserScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsDeleteUserScreen.cpp    

    ${CMAKE_SOURCE_DIR}/Include/clsUpdateUserScreen.h
    ${CMAKE_SOURCE_DIR}/Source/clsUpdateUserScreen.cpp    

)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Include directories for header files
include_directories(
    ${CMAKE_SOURCE_DIR}/Include
)