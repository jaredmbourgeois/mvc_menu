#ifndef MVC_MENU_LIBRARY_H
#define MVC_MENU_LIBRARY_H


#include <string>
#include <vector>

namespace MVCMenu {
    class Question;
    class Answer;

    class Model {
    protected:
        std::unique_ptr<Question> _question;
        std::unique_ptr<std::vector<std::shared_ptr<Answer>>> _answers;
        Model* _previousModel;
    public:
        Question& question();
        std::vector<std::shared_ptr<Answer>>& answers();
        Model* previousModel();
    };

    class Question {
    protected:
        std::unique_ptr<std::string> _text;
    public:
        std::string& text();
    };

    class Answer {
    protected:
        std::unique_ptr<std::string> _text;
        Model* _nextModel;
    public:
        std::string& text();
        Model* nextModel();
        virtual void action() { };
    };

    class View {
    public:
        virtual ~View() = default;
        virtual Model* presentModel(Model& model, std::string& inputError) = 0;
    };

    enum ViewPresentationType {
        text = 0
    };

    class TextView: public View {
    public:
        TextView() = default;
        Model* presentModel(Model& model, std::string& inputError) override;
    };

    class Controller {
    private:
        std::unique_ptr<std::vector<Model*>> models;
        Model* currentModel;
        View* view;
        std::unique_ptr<std::string> inputError;
    public:
        Controller(Model&& model, View&& view, std::string&& inputError);
        ~Controller();
        void displayView();
    };
}

#endif //MVC_MENU_LIBRARY_H
