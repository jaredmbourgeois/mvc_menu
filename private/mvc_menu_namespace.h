//
// Created by Jared Bourgeois on 10/28/21.
//

#ifndef MVC_MENU_MVC_MENU_NAMESPACE_H
#define MVC_MENU_MVC_MENU_NAMESPACE_H

namespace MVCMenu { }

#endif //MVC_MENU_MVC_MENU_NAMESPACE_H


#ifdef _WIN32
#ifdef _EXPORTING
    #define MVC_MENU_EXPORT __declspec(dllexport)
#else
    #define MVC_MENU_EXPORT __declspec(dllimport)
#endif
#elif __GNUC__ >= 4
    #define MVC_MENU_EXPORT __attribute__((visibility("default")))
#else
    #define MVC_MENU_EXPORT __attribute__((visibility("default")))
#endif //MVC_MENU_EXPORT


#if defined(_WIN32)
#define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
#define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
#define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__ANDROID__)
#define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
#elif defined(__linux__)
#define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
#include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif
#elif defined(__hpux)
#define PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
#define PLATFORM_NAME "aix" // IBM AIX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
#include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif
#elif defined(__sun) && defined(__SVR4)
#define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#else
#define PLATFORM_NAME NULL
#endif //PLATFORM_NAME