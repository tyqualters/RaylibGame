# CMakeList.txt : CMake project for LearningRaylib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("LearningRaylib")

find_package(raylib CONFIG REQUIRED)

file(GLOB SOURCE_FILES src/*)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Add source to this project's executable.
# VisualStudio HATES this lol
add_executable (LearningRaylib ${SOURCE_FILES} "src/Collider.h")

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LearningRaylib PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
