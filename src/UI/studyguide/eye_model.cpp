// eye_model.cpp
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>  // For Qt 6
#include <QApplication>
#include <QWidget>
#include "eye_model.h"
#include "../../build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/OcuKnow_autogen/include/UI/studyguide/ui_eyemodel.h"

Eye_model::Eye_model(QWidget *parent) : QDialog(parent),
    ui(new Ui::Dialog)  // Use Dialog to match the UI file
{
    ui->setupUi(this);  // Setup UI first!

    QPixmap pixmap(":/halfeyeimage2.png");

    if (pixmap.isNull()) {
        qDebug() << "Error loading image";
    } else {
        ui->label->setPixmap(pixmap);
        qDebug() << "Success loading image";
    }

    // Qt 6 media player setup
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("/Vibin-chosic favorite.mp3"));
    audioOutput->setVolume(0.5);  // 50%
    player->loops(); // Loop continuously

    // Now we need to use the actual widget names from your UI file
    // Based on the UI file, the names are toolButton, toolButton_2, etc.
    // Let's map them to the eye parts

    // For example, if toolButton_15 is the Iris:
    ui->toolButton_15->setToolTip("Iris"
                                  "<ul>"
                                  "<li>ir/o - iris</li>"
                                  "<li>irid/o - iris</li>"
                                  "<li>iridal - pertaining to the iris</li>"
                                  "<li>iridectomy - excision of the iris</li>"
                                  "<li>regulates the amount of light that enters your eye by controlling dilation and constriction. "
                                  "It is the coloured, visible part of your eye in front of the lens. "
                                  "Located behind the cornea and in front of the chrystalline lens, this structure separates the anterior and posterior chambers of the eye.</li>"
                                  "</ul>");

    // For the pupil, it appears to be toolButton_16 based on the UI file
    ui->toolButton_16->setToolTip("Pupil"
                                  "<ul>"
                                  "<li>pupill/o - pupil</li>"
                                  "<li>pupillary - pertaining to the pupil</li>"
                                  "<li>pupilloplasty - surgical repair of the pupil</li>"
                                  "<li>Regulates how much light enters the eye. "
                                  "It's size is automatically varied to regulate the amount of light entering the eye. "
                                  "It is the dark center in the middle of the iris.</li>"
                                  "</ul>");

    // Continue with the rest of the tooltips, mapping them to the correct toolButtons
    // I'll do a few more as examples:

    // Assuming toolButton_8 is Sclera based on UI text
    ui->toolButton_8->setToolTip("Sclera"
                                 "<ul>"
                                 "<li>scler/o - sclera</li>"
                                 "<li>scleral - pertaining to the sclera</li>"
                                 "<li>scleritis - inflammation of the sclera</li>"
                                 "<li>sclerotomy - incision of the sclera</li>"
                                 "<li>White part of the eye, protects the inner structures of the eye and maintains the shape of the eyeball.</li>"
                                 "</ul>");

    // Assuming toolButton_7 is Choroid based on UI text
    ui->toolButton_7->setToolTip("Choroid"
                                 "<ul>"
                                 "<li>choroid/o - choroid</li>"
                                 "<li>choroidal - pertaining to the choroid</li>"
                                 "<li>choroiditis - inflammation of the choroid</li>"
                                 "<li>choroidopathy - disease of the choroid</li>"
                                 "<li>choroidectomy - excision of the choroid</li>"
                                 "<li>Middle layer of the eye, contains blood vessels and connective tissue. It is located between the sclera and retina.</li>"
                                 "</ul>");

    // Add the rest of your tooltips with the correct toolButton IDs
}

Eye_model::~Eye_model()
{
    delete ui;
}

// Implement your slot methods
void Eye_model::insertBoldText() {
    // Implementation
}

void Eye_model::insertItalicText() {
    // Implementation
}

void Eye_model::insertUnderlinedText() {
    // Implementation
}
