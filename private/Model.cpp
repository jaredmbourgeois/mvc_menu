//
// Created by Jared Bourgeois on 10/25/21.
//

#include <memory>
#include "vector"
#include "../public/mvc_menu.h"

Question& Model::question() {
    return *_question;
}

std::vector<std::shared_ptr<Answer>>& Model::answers() {
    return *_answers;
}

Model* Model::previousModel() {
    return _previousModel;
}

std::string& Question::text() { return _text; }

std::string& Answer::text() { return _text; }

Model* Answer::nextModel() { return _nextModel; };
