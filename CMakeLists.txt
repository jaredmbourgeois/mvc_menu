cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME mvc_menu)
#set(STATIC_TARGET_NAME mvc_menu_static)
set(PROJECT_DESCRIPTION "MVC Menu. Build a Menu by subclassing MVC::Model.")
set(PROJECT_VERSION  1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

project(${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
        DESCRIPTION ${PROJECT_DESCRIPTION}
        LANGUAGES CXX
)

# SHARED
add_library(${PROJECT_NAME} SHARED ${CMAKE_SOURCE_DIR}/public)
target_sources(${PROJECT_NAME}
    PUBLIC
        public/MVCMenu.h
    PRIVATE
        private/Controller.cpp
        private/Model.cpp
        private/View.cpp
)
set_target_properties(${PROJECT_NAME}
    PROPERTIES
        PUBLIC_HEADER public/MVCMenu.h
        LINKER_LANGUAGE CXX
        C_VISIBILITY_PRESET default
        CXX_VISIBILITY_PRESET default
)

## STATIC
#add_library(${STATIC_TARGET_NAME} STATIC ${CMAKE_SOURCE_DIR}/public)
#target_sources(${STATIC_TARGET_NAME}
#    PUBLIC
#        public/MVCMenu.h
#    PRIVATE
#        private/Controller.cpp
#        private/Model.cpp
#        private/View.cpp
#)
#set_target_properties(${STATIC_TARGET_NAME}
#    PROPERTIES
#        PUBLIC_HEADER public/MVCMenu.h
#        LINKER_LANGUAGE CXX
#        C_VISIBILITY_PRESET default
#        CXX_VISIBILITY_PRESET default
#)

#target_include_directories(${PROJECT_NAME}
#    PRIVATE
#        ${CMAKE_SOURCE_DIR}/private
#    PUBLIC
#        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/public>
#        $<INSTALL_INTERFACE:${CMAKE_SOURCE_DIR}/public>
#)
#
#if(DEFINED CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/build"
#            CACHE PATH "mvc_menu install location" FORCE)
#endif()

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME} #${STATIC_TARGET_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

add_custom_command(
    TARGET ${PROJECT_NAME}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/distribution
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/public/*.h ${CMAKE_SOURCE_DIR}/distribution/
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/build/*.dylib ${CMAKE_SOURCE_DIR}/distribution/
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/build/*.a ${CMAKE_SOURCE_DIR}/distribution/
)