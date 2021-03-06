//
// Created by Jared Bourgeois on 10/18/21.
//

#include <iostream>
#include "string"
#include "vector"
#include "../public/MVCMenu.h"

static std::string newLine = "\n";

std::string& line(std::string& string) {
    return string.append(newLine);
}

std::string textForAnswerNumber(MVCMenu::Answer& answer, int number) {
    return std::to_string(number).append(".\t").append(answer.text());
}

std::string textForModel(MVCMenu::Model& model) {
    auto answers = model.answers();
    int answersSize = static_cast<int>(answers.size());
    int numberOfLines = answersSize + 1;
    std::string text = newLine;
    std::string textForIndex;
    std::string textLine;
    std::vector<std::string> lines(numberOfLines, "");
    for (int index = 0; index < numberOfLines; index++) {
        textForIndex = index == 0 ?
                       model.question().text() :
                       textForAnswerNumber(*answers[index - 1], index);
        textLine = line(textForIndex);
        text.append(textLine);
    }
    return text;
}

int indexForInput(std::string& input, std::string& modelText, int answersSize, std::string& inputError) {
    int selectedAnswerNumber;
    int selectedAnswerIndex = -1;
    while (!(selectedAnswerIndex > -1 && selectedAnswerIndex < answersSize)) {
        try {
            selectedAnswerNumber = std::stoi(input);
        } catch (std::invalid_argument& error) {
            std::cerr << error.what() << std::endl;
            selectedAnswerNumber = 0;
        }

        selectedAnswerIndex = selectedAnswerNumber - 1;

        if (selectedAnswerIndex < 0 || selectedAnswerIndex >= answersSize) {
            std::cout << inputError << std::endl;
            std::cout << modelText << std::endl;
            std::cin >> input;
            std::cout << std::endl;
        }
    }
    return selectedAnswerIndex;
}

MVCMenu::Model* handleSelectedAnswer(const std::shared_ptr<MVCMenu::Answer>& answer) {
    answer->action();
    MVCMenu::Model* nextModel;
    try {
        nextModel = answer->nextModel();
    } catch (char *error) {
        nextModel = nullptr;
    }
    return nextModel;
}

MVCMenu::Model* MVCMenu::TextView::presentModel(Model& model, std::string& inputError) {
    std::string modelText = textForModel(model);
    std::cout << modelText << std::endl;

    std::string selectedAnswerText;
    std::cin >> selectedAnswerText;

    auto answers = model.answers();
    auto answersSize = static_cast<int>(answers.size());
    auto selectedAnswerIndex = indexForInput(selectedAnswerText, modelText, answersSize, inputError);
    auto selectedAnswer = answers[selectedAnswerIndex];
    auto nextModel = handleSelectedAnswer(selectedAnswer);
    return nextModel;
}

