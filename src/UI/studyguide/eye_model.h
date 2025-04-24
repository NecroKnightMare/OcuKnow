// eye_model.h
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
#include <QWindow>
#include <QDialog>

// Forward declaration
namespace Ui {
class Dialog;  // Match the class name in the UI file
}

class Eye_model : public QDialog
{
    Q_OBJECT
public:
    explicit Eye_model(QWidget *parent = nullptr);
    ~Eye_model();

private slots:
    void insertBoldText();
    void insertItalicText();
    void insertUnderlinedText();

private:
    Ui::Dialog *ui;  // Match the UI class name
};

#endif
