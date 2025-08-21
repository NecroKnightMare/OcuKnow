#ifndef EYE_MODEL_H
#define EYE_MODEL_H

#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>

class EyeModel : public QDialog
{
    Q_OBJECT
public:
    explicit EyeModel(QWidget *parent = nullptr);
    ~EyeModel();

signals:
	void takeQuizClicked();
	void creditsClicked();
	void returnToIntro();

private slots:
	void handleTakeQuiz();
	void handleCredits();

private:
	Ui::EyeModel *ui;
	QPushButton *takeQuizButton;
	QPushButton *creditsButton;

};

#endif
