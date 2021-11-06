//
// Created by Jared Bourgeois on 10/20/21.
//

#include "../public/MVCMenu.h"

MVCMenu::Controller::Controller(Model& model, View &view, bool deleteMembers) {
    this->models = std::make_unique<std::vector<Model*>>(std::vector(1, &model));
    this->currentModel = &model;
    this->view = &view;
    this->deleteMembers = deleteMembers;
}

MVCMenu::Controller::~Controller() {
    if (!deleteMembers) { return; }
    for (auto& model : *models) {
        delete model;
    }
    delete view;
}

void MVCMenu::Controller::displayView() {
    bool modelInModels;
    while (currentModel != nullptr) {
        currentModel = view->presentModel(*currentModel);
        modelInModels = false;
        for (auto model : *models) {
            if (model == currentModel) {
                modelInModels = true;
                break;
            }
        }
        if (!modelInModels) {
            models->push_back(currentModel);
        }
    }
}
