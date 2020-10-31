cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
if(${CMAKE_VERSION} VERSION_LESS 3.18)
cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
cmake_policy(VERSION 3.18)
endif()

project(HiCalendar LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

install(FILES
  cmake/proconfig.cmake
  DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)

configure_file (
    "${PROJECT_SOURCE_DIR}/include/config.hpp.in"
    "${PROJECT_BINARY_DIR}/include/config.hpp"
)

add_library(project_warnings INTERFACE)
add_library(project_error INTERFACE)
add_library(project_options INTERFACE)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets Quick Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Quick Sql REQUIRED)

if(ENABLE_SAFE_ONLY)
    SET (CMAKE_CXX_FLAGS "-Werror")
endif()

if(ENABLE_SAFTY_MODE)
    SET (CMAKE_CXX_FLAGS "-Wall")
endif()

set(PREFIX_EXTRA *.in)
set(PREFIX_HPPHEADER *.hpp)
set(PREFIX_SOURCE *.cpp)
set(PREFIX_QRC *.qrc)

file(GLOB HEADERS
    include/${PREFIX_HPPHEADER}
    include/hi/${PREFIX_HPPHEADER}
)
file(GLOB SOURCES
    src/${PREFIX_SOURCE}
    src/hi/${PREFIX_SOURCE}
)
file(GLOB PREFIX_QRC
    ${PREFIX_QRC}
)

if(ANDROID)
    add_library(HiCalendar SHARED
	${HEADERS}
	${SOURCES}
	${PREFIX_QRC}
    )
else()
    add_executable(HiCalendar
	${HEADERS}
	${SOURCES}
	${PREFIX_QRC}
    )
target_include_directories(HiCalendar
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#  $<INSTALL_INTERFACE:include>
)
endif()

target_compile_definitions(HiCalendar
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(HiCalendar
  PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Widgets
  Qt${QT_VERSION_MAJOR}::Gui
  Qt${QT_VERSION_MAJOR}::Sql
  Qt${QT_VERSION_MAJOR}::Quick
  Qt${QT_VERSION_MAJOR}::Qml
  )
