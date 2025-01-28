cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Task_2")

set(main Task_2_main)
set(testing Task_2_test)
set(any Any_type_lib)

add_executable (${main} "Main.cpp" )
add_library(${any} STATIC "Any_type.cpp")

target_link_libraries(${main} ${any})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${main} PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(${testing} Test.cpp)
target_link_libraries(${testing} ${any} gtest_main)
add_test(NAME Any_type_testing COMMAND ${testing})
