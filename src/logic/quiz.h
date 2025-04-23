#ifndef QUIZ_H
#define QUIZ_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QStackedWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QRadioButton>
#include <QMessageBox>
#include <QStringTokenizer>
#include <QButtonGroup>
#include <QDirIterator>
#include <QDir>
// #include <QAbstractButton>

struct Question {
    QString questionText;
    QVector<QString> choices;
    char correctAnswer;
};

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class Quiz;
// }
// QT_END_NAMESPACE

class Quiz : public QMainWindow
{
    Q_OBJECT

public:
    Quiz(QWidget *parent = nullptr);
    ~Quiz();

public slots:
    void onStartButtonClicked();

private:
    void runQuiz();
    QWidget* buildQuizQuestionPage(const Question& question, int questionIndex, Quiz* quizWindow);
    QWidget *buildQuizSplashPage();
    QVector<Question> loadQuestions();
    QWidget* buildQuizScorePage();
    void goToNextQuestion();
    void resetQuiz();

    int score, numQuestions;
    QStackedWidget *quizPages;
    QPushButton *splashPageStartButton;
    // Ui::Quiz *ui;
};
#endif // QUIZ_H
