//
// Created by Jared Bourgeois on 10/25/21.
//

#include <memory>
#include "vector"
#include "../public/mvc_menu.h"

MVCMenu::Question& MVCMenu::Model::question() {
    return *_question;
}

std::vector<std::shared_ptr<MVCMenu::Answer>>& MVCMenu::Model::answers() {
    return *_answers;
}

MVCMenu::Model* MVCMenu::Model::previousModel() {
    return _previousModel;
}

std::string& MVCMenu::Question::text() { return _text; }

std::string& MVCMenu::Answer::text() { return _text; }

MVCMenu::Model* MVCMenu::Answer::nextModel() { return _nextModel; };
