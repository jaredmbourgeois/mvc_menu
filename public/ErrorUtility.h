//
// Created by Jared Bourgeois on 10/31/21.
//

#ifndef MVC_MENU_ERRORUTILITY_H
#define MVC_MENU_ERRORUTILITY_H


#include "../private/mvc_menu_namespace.h"
#include "string"

enum ErrorType {
        answerInvalid
};

class ErrorUtility {
   public:
        static std::string messageForType(ErrorType type);
};

#endif //MVC_MENU_ERRORUTILITY_H
