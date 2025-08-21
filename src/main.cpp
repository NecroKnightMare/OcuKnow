#include <QApplication>
#include <QDialog>
#include "UI/credits/creditswidget.h"
#include "UI/intro/introwidget.h"
#include "UI/quiz/quiz.h"
#include "UI/studyguide/ui_eyemodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Quiz q; //starts directly with Quiz (for quiz debugging)
    // q.show();

    IntroWidget intro;
    intro.show();

    QObject::connect(&intro, &IntroWidget::takeQuizClicked, [&]() {
        Quiz *quiz = new Quiz();
        quiz->show();
        intro.hide();
    });

    QObject::connect(&intro, &IntroWidget::enterStudyGuideClicked, [&]() {
        QDialog *studyGuide = new QDialog();
        Ui::Dialog *ui = new Ui::Dialog();
        ui->setupUi(studyGuide);
        studyGuide->setWindowTitle("Study Guide");
        studyGuide->setAttribute(Qt::WA_DeleteOnClose);
        studyGuide->show();
        intro.hide();
    });

    QObject::connect(&intro, &IntroWidget::creditsClicked, [&]() {
        CreditsWidget *credits = new CreditsWidget();
        credits->setWindowTitle("Credits");

        QObject::connect(credits, &CreditsWidget::returnToIntro, [&]() { intro.show(); });

        credits->show();
        intro.hide();
    });

    return app.exec();
}
