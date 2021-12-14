cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME mvc_menu)
set(OBJECT_TARGET_NAME mvc_menu_objects)
set(SHARED_TARGET_NAME mvc_menu_shared)
set(STATIC_TARGET_NAME mvc_menu_static)
set(PROJECT_DESCRIPTION "MVC Menu. Build a Menu by subclassing MVC::Model.")
set(PROJECT_VERSION  1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

project(${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
        DESCRIPTION ${PROJECT_DESCRIPTION}
        LANGUAGES CXX
)

add_library(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/public)
set_target_properties(${PROJECT_NAME}
    PROPERTIES
        PUBLIC_HEADER public/MVCMenu.h
        LINKER_LANGUAGE CXX
        C_VISIBILITY_PRESET default
        CXX_VISIBILITY_PRESET default
)

add_library(${OBJECT_TARGET_NAME} OBJECT ${CMAKE_SOURCE_DIR}/public)
target_sources(${OBJECT_TARGET_NAME}
    PUBLIC
        public/MVCMenu.h
    PRIVATE
        private/Controller.cpp
        private/Model.cpp
        private/View.cpp
)
target_link_libraries(${PROJECT_NAME} ${OBJECT_TARGET_NAME})

add_library(${SHARED_TARGET_NAME} SHARED $<TARGET_OBJECTS:${OBJECT_TARGET_NAME}>)
target_link_libraries(${PROJECT_NAME} ${SHARED_TARGET_NAME})

add_library(${STATIC_TARGET_NAME} STATIC $<TARGET_OBJECTS:${OBJECT_TARGET_NAME}>)
target_link_libraries(${PROJECT_NAME} ${STATIC_TARGET_NAME})

include(GNUInstallDirs)

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/distribution
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/public/*.h ${CMAKE_SOURCE_DIR}/distribution/
)

add_custom_command(
    TARGET ${STATIC_TARGET_NAME}
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/distribution
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/build/*.a ${CMAKE_SOURCE_DIR}/distribution/
)

add_custom_command(
    TARGET ${SHARED_TARGET_NAME}
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/distribution
        POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/build/*.dylib ${CMAKE_SOURCE_DIR}/distribution/
)

install(
    TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)