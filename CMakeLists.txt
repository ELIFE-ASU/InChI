cmake_minimum_required(VERSION 2.8)
project(inchi C)

set(${PROJECT_NAME}_MAJOR 1)
set(${PROJECT_NAME}_MINOR 05)
set(${PROJECT_NAME}_PATCH 0)
set(${PROJECT_NAME}_VERSION ${${PROJECT_NAME}_MAJOR}.${${PROJECT_NAME}_MINOR}.${${PROJECT_NAME}_PATCH})

message(STATUS "inchi version: ${${PROJECT_NAME}_VERSION}")

if (UNIX AND NOT APPLE)
    add_definitions("-std=gnu1x -DTARGET_API_LIB")
    add_compile_options("-fPIC")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -pg")
elseif (APPLE)
    add_definitions("-std=gnu1x -DTARGET_API_LIB")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
	set(CMAKE_MACOSX_RPATH ON)
elseif (MSVC)
    add_definitions("-std=gnu1x -DTARGET_API_LIB")
endif()

include_directories(include include/inchi/api include/inchi/base include/inchi/api/ixa)
add_subdirectory(src/inchi/api)
add_subdirectory(src/inchi/base)

if (BUILD_DYNAMIC)
    add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCES})
endif()

add_library(${PROJECT_NAME}_static ${${PROJECT_NAME}_SOURCES})

if (BUILD_DYNAMIC)
    set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME} VERSION ${${PROJECT_NAME}_VERSION})
endif()

set_target_properties(${PROJECT_NAME}_static PROPERTIES VERSION ${${PROJECT_NAME}_VERSION})
if (MSVC AND BUILD_DYNAMIC)
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "/DLIBRARY_EXPORTS")
else()
    set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
endif()

if (UNIX AND BUILD_DYNAMIC)
    target_link_libraries(${PROJECT_NAME} m)
endif()

if (BUILD_DYNAMIC)
    install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
endif()

install(TARGETS ${PROJECT_NAME}_static EXPORT ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
