//
// Created by Jared Bourgeois on 10/31/21.
//

#include "../public/ErrorUtility.h"

std::string ErrorUtility::messageForType(ErrorType type) {
    switch (type) {
        case ErrorType::answerInvalid:
            return "Error: please enter a valid answer";
    }
}