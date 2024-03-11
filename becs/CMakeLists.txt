# CMakeList.txt : CMake project for becs, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("becs")


# add headers for development
include_directories(${PROJECT_SOURCE_DIR}/include)


# Add sources and headers to executable
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# Add source to this project's executable.
add_executable (becs "becs.cc" "becs.hh" ${sources} ${headers})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET becs PROPERTY CXX_STANDARD 20)
endif()


# ////////////////////////////
# GLFW3 FOR OPENGL
# ////////////////////////////

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
  FetchContent_Populate(glfw)

  add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

target_link_libraries(becs PRIVATE glfw)
