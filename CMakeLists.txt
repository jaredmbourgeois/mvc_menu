cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME mvc_menu)
set(PROJECT_DESCRIPTION "MVC Menu. Build a Menu by subclassing MVC::Model.")
set(PROJECT_VERSION  1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 1)

project(${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
        DESCRIPTION ${PROJECT_DESCRIPTION}
        LANGUAGES CXX
)

add_library(${PROJECT_NAME} SHARED ${CMAKE_SOURCE_DIR}/public)

target_sources(${PROJECT_NAME}
    PRIVATE
        private/Controller.cpp
        private/Model.cpp
        private/View.cpp
        private/ErrorUtility.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/private
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/public>
        $<INSTALL_INTERFACE:${CMAKE_SOURCE_DIR}/public>
)

if(DEFINED CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/build"
            CACHE PATH "mvc_menu install location" FORCE)
endif()

set(PUBLIC_HEADERS
        public/mvc_menu.h
        public/ErrorUtility.h
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        PUBLIC_HEADER "${PUBLIC_HEADERS}"
        LINKER_LANGUAGE CXX
        C_VISIBILITY_PRESET default
        CXX_VISIBILITY_PRESET default
#        DEBUG_POSTFIX "_debug"
)

include(GNUInstallDirs)
#include_directories(${CMAKE_SOURCE_DIR}/public)
#include_directories(${CMAKE_SOURCE_DIR}/private)

#add_library(${PROJECT_NAME} STATIC public/mvc_menu.h)

#target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/public)
#configure_file(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

#target_include_directories(${PROJECT_NAME} PUBLIC
#        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
#        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
#)

#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/public)
#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/private)

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

#set_target_properties(MVCMenu PROPERTIES
#        INTERFACE_INCLUDE_DIRECTORIES ${_IMPORT_PREFIX}/public
#)

#install(EXPORT ${PROJECT_NAME}Targets
#        FILE ${PROJECT_NAME}Targets.cmake
#        NAMESPACE ${namespace}::MVCMenu
#        DESTINATION cmake
#)

#install(FILES ${CMAKE_BINARY_DIR}/mvc_menu.pc
#        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
#)