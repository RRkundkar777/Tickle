#======================= CMakeLists for tickle  =======================#

# CMake version
cmake_minimum_required(VERSION 3.16)

# Settings for both windows and Linux
if (WIN32)
    project(tickle LANGUAGES CXX)
elseif(UNIX)
    project(tickle)
endif()

# C++ Standard
set(CMAKE_CXX_STANDARD 14)

# Project Configuration (Specifies the available build types)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

#======================= INCLUSION OF Qt =======================#
# Include project directory
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include meta object compiler and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Location of QT .cmake files
set(CMAKE_PREFIX_PATH "/home/rushikesh/Qt/5.9.9/gcc_64/lib/cmake/")

# Find required Qt Packages 
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

#=================== INCLUSION OF Project Files ====================#

# Add relevant directories
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/headers")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/sources")
set(RES_DIR,"${CMAKE_SOURCE_DIR}/resources")

# Include that directories
include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})
include_directories(${RES_DIR})

# Put relevant files inside the respective directories
file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${RES_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#=================== SETUP EXECTUABLE ====================#

# Enable debug logging on DEBUG configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:DEBUG>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${RES_DIR})

# Add the executable
if (WIN32)
    # Exe without command line
    add_executable(tickle WIN32 ${SOURCES})
elseif(UNIX)
    # Exe with command line
    add_executable(tickle ${SOURCES})
endif()

# Add the target includes for tickle
target_include_directories(tickle PRIVATE ${FORMS_DIR})
target_include_directories(tickle PRIVATE ${INCLUDE_DIR})
target_include_directories(tickle PRIVATE ${SOURCE_DIR})
target_include_directories(tickle PRIVATE ${RES_DIR})

#===================== LINKING LIBRARIES =======================#

# Link required Qt libraries
target_link_libraries(tickle Qt5::Core)
target_link_libraries(tickle Qt5::Widgets)