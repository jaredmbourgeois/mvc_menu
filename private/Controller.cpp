//
// Created by Jared Bourgeois on 10/20/21.
//

#include "../public/MVCMenu.h"

MVCMenu::Controller::Controller(Model &model, View &view, bool deleteMembers) {
    std::vector<Model*> firstModel(1, &model);
    this->models = firstModel;
    this->currentModel = &model;
    this->view = &view;
    this->deleteMembers = deleteMembers;
}

MVCMenu::Controller::~Controller() {
    if (!deleteMembers) { return; }
    for (auto& model : models) {
        delete model;
    }
    delete view;
}

void MVCMenu::Controller::displayView() {
    bool modelInModels;
    while (currentModel != nullptr) {
        currentModel = view->presentModel(*currentModel);
        modelInModels = false;
        for (auto model : models) {
            if (model == currentModel) {
                modelInModels = true;
                break;
            }
        }
        if (!modelInModels) {
            models.push_back(currentModel);
        }
    }
}
