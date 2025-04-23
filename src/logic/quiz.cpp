#include "quiz.h"

QFont headerFont("Orbitron", 24, QFont::Bold);
QFont questionFont("Orbitron", 18, QFont::Normal);
QFont textFont("Orbitron", 14, QFont::Normal);

QString buttonStyle = R"(
QPushButton {
    background-color: #4FA3E3;
    color: white;
    font-size: 20px;
    font-family: 'Orbitron', sans-serif;
    border: 2px solid white;
    border-radius: 10px;
    padding: 5px 20px;
}
QPushButton:hover {
    background-color: white;
    color: #4FA3E3;
})";

QVector<Question> Quiz::loadQuestions()
{
    QVector<Question> questions;
    Question newQuestion;

    QFile file(":/questions.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open questions.txt";
        return questions;
    }

    while (!file.atEnd()) {
        QString line = file.readLine();
        if (line.startsWith("Question")) {
            newQuestion.questionText = line.mid(9).trimmed();
            newQuestion.choices.clear();
        } else if (line.startsWith("Choice")) {
            newQuestion.choices.append(line.mid(8).trimmed());
        } else if (line.startsWith("Answer")) {
            newQuestion.correctAnswer = line.mid(7).trimmed().at(0).toLatin1();
            questions.append(newQuestion);
        }
    }

    return questions;
}

QWidget* Quiz::buildQuizSplashPage()
{
    QWidget *quizSplashPage = new QWidget;

    QLabel *splashPageHeader = new QLabel("Eye Quizlette");
    QLabel *splashPageInstruction = new QLabel("Over the next 100 pages you will be asked to answer multiple questions on the eye.\nClick 'Start' to begin!");
    splashPageStart = new QPushButton("Start");

    splashPageHeader->setAlignment(Qt::AlignCenter);
    splashPageHeader->setFont(headerFont);
    splashPageInstruction->setWordWrap(true);
    splashPageInstruction->setFont(textFont);
    splashPageInstruction->setAlignment(Qt::AlignCenter);
    splashPageStart->setFont(textFont);
    splashPageStart->setStyleSheet(buttonStyle);
    splashPageStart->setMaximumSize(QSize(200, 50));

    QVBoxLayout *splashLayout = new QVBoxLayout(quizSplashPage);
    splashLayout->addStretch();
    splashLayout->addWidget(splashPageHeader);
    splashLayout->addWidget(splashPageInstruction);
    splashLayout->addWidget(splashPageStart);
    splashLayout->addStretch();

    return quizSplashPage;
}

QWidget* Quiz::buildQuizQuestionPage(const Question& question, int questionIndex, Quiz* quizWindow) {
    QWidget *page = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(page);

    QLabel *header = new QLabel("Question " + QString::number(questionIndex + 1));
    header->setAlignment(Qt::AlignCenter);
    header->setFont(headerFont);
    mainLayout->addWidget(header);

    QLabel *questionLabel = new QLabel(question.questionText);
    questionLabel->setFont(questionFont);
    questionLabel->setAlignment(Qt::AlignCenter);
    questionLabel->setWordWrap(true);
    mainLayout->addWidget(questionLabel);

    QWidget *choicesContainer = new QWidget;
    QVBoxLayout *choicesLayout = new QVBoxLayout(choicesContainer);

    QVector<QRadioButton*> choiceButtons;
    QButtonGroup *buttonGroup = new QButtonGroup(page);
    for (int i = 0; i < question.choices.size(); ++i) {
        QRadioButton *radio = new QRadioButton(question.choices[i]);
        radio->setStyleSheet("font-family: 'Orbitron'; font-size: 14px; color: #4FA3E3;");
        choicesLayout->addWidget(radio);
        buttonGroup->addButton(radio, i);
        choiceButtons.append(radio);
    }

    choicesLayout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *centeringLayout = new QHBoxLayout;
    centeringLayout->addStretch();
    centeringLayout->addWidget(choicesContainer);
    centeringLayout->addStretch();

    mainLayout->addLayout(centeringLayout);

    QLabel *feedbackLabel = new QLabel("");
    feedbackLabel->setAlignment(Qt::AlignCenter);
    feedbackLabel->setFont(textFont);
    mainLayout->addWidget(feedbackLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *nextButton = new QPushButton("Next");
    nextButton->setEnabled(false);
    nextButton->setStyleSheet(buttonStyle);
    buttonLayout->addStretch();
    buttonLayout->addWidget(nextButton);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    QObject::connect(buttonGroup, QOverload<int>::of(&QButtonGroup::idClicked), [=](int id){
        char selected = 'A' + id;
        if (selected == question.correctAnswer) {
            feedbackLabel->setText("Correct!");
            feedbackLabel->setStyleSheet("color: #4FA3E3; font-weight: bold;");
            quizWindow->score++;
        } else {
            feedbackLabel->setText(QString("Incorrect! Correct answer: %1").arg(question.correctAnswer));
            feedbackLabel->setStyleSheet("color: red; font-weight: bold;");
        }
        nextButton->setEnabled(true);
    });

    QObject::connect(nextButton, &QPushButton::clicked, quizWindow, [=]() {
        quizWindow->goToNextQuestion();
    });

    return page;
}

QWidget* Quiz::buildQuizScorePage()
{
    QWidget *scorePage = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(scorePage);
    QLabel *header = new QLabel("Quiz Final Score");
    QLabel *scoreText = new QLabel();
    QLabel *colorText = new QLabel("That earned you a grade of ");
    QString colorTextGradeQuip = colorText->text();
    QPushButton *restartButton = new QPushButton("Restart Quiz");
    int percentScore = static_cast<int>(std::round((double)score / (double)numQuestions * 100.0));
    // QString *letterGrade = new QString();

    if (percentScore == 100) {
        colorTextGradeQuip += "A+.\nCongratulations! You are now an Opthalmologist Attending ready to conduct eye transplants!";
    } else if (percentScore >= 90) {
        colorTextGradeQuip += "A.\nCongratulations! You are now an Opthamologist Resident ready significantly participate in surgery!";
    } else if (percentScore >= 80) {
        colorTextGradeQuip += "B.\nCongratulations! You are now an Opthamologist Resident ready to hold the sweat sponge in surgery!";
    } else if (percentScore >= 70) {
        colorTextGradeQuip += "C.\nCongratulations! You are now an Opthamologist Intern ready to watch surgery from the observation room!";
    } else if (percentScore >= 60) {
        colorTextGradeQuip += "D.\nCongratulations! You graduated without prospects, but 'D' is for Diploma!";
    } else if (percentScore >= 50) {
        colorTextGradeQuip += "F.\nCongratulations! You get to retake your senior year!";
    } else if (percentScore >= 40) {
        colorTextGradeQuip += "F-\nCongratulations! You get to retake all of medical school!";
    } else if (percentScore >= 30) {
        colorTextGradeQuip += "F--\nCongratulations! You get to explore other medical schools!";
    } else if (percentScore >= 20) {
        colorTextGradeQuip += "F---\nCongratulations! You get to explore other career options!";
    } else if (percentScore >= 10) {
        colorTextGradeQuip += "F----\nCongratulations! You get to explore the career of junior high science teacher!";
    } else if (percentScore >= 0) {
        colorTextGradeQuip += "Zero\nCongratulations! You get to explore the career of Gym Teacher!";
    }

    colorText->setText(colorTextGradeQuip);

    layout->addWidget(header);
    layout->addWidget(scoreText);
    layout->addWidget(colorText);
    layout->addWidget(restartButton);

    scoreText->setText(QString("You successfully answered %1 out of %2. That's a %3%").arg(score).arg(numQuestions).arg(percentScore));
    header->setAlignment(Qt::AlignCenter);
    header->setFont(headerFont);
    scoreText->setAlignment(Qt::AlignCenter);
    scoreText->setFont(textFont);
    scoreText->setWordWrap(true);
    colorText->setAlignment(Qt::AlignCenter);
    colorText->setFont(textFont);
    colorText->setWordWrap(true);

    restartButton->setStyleSheet(buttonStyle);

    QObject::connect(restartButton, &QPushButton::clicked, this, &Quiz::runQuiz);

    return scorePage;
}

void Quiz::goToNextQuestion() {
    int nextIndex = quizPages->currentIndex() + 1;
    if (nextIndex < quizPages->count()) {
        quizPages->setCurrentIndex(nextIndex);
    } else {
        QWidget *scorePage = buildQuizScorePage();
        setCentralWidget(scorePage);
    }
}

void Quiz::onStartButtonClicked() {
    quizPages->setCurrentIndex(1);
}

void Quiz::resetQuiz() {
    score = 0;
    quizPages->setCurrentIndex(0);
}

void Quiz::runQuiz() {
    score = 0;

    QVector<Question> questions = loadQuestions();
    numQuestions = questions.count();

    QWidget *quizSplashPage = buildQuizSplashPage();
    quizPages = new QStackedWidget(this);
    quizPages->addWidget(quizSplashPage);
    for (int i = 0; i < numQuestions; i++)
        quizPages->addWidget(buildQuizQuestionPage(questions[i], i, this));

    quizPages->setCurrentWidget(quizSplashPage);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(quizPages);
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(splashPageStart, &QPushButton::clicked, this, &Quiz::onStartButtonClicked);
}

Quiz::Quiz(QWidget *parent) : QMainWindow(parent) {
    runQuiz();
}

Quiz::~Quiz() {}
