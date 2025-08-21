#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QApplication>
#include <QDialog>
// <<<<<<< Ariel
// #include "eye_model.h"
// #include "ui_eye_model.h"

// EyeModel::EyeModel(QWidget *parent) : QWidget(parent),
//     ui(new Ui::EyeModel)
// {   
//     QLabel *background = new QLabel(this);
//     QPixmap pixmap(":/halfeyeimage2.png");
//     background->setPixmap(pixmap);
//     background->setScaledContents(true); 
//     background->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//     stack->addWidget(background);

//     ui->setupUi(this);
// =======
#include <QFileInfo>
#include "eyemodel.h"
#include "ui_eyemodel.h"

EyeModel::EyeModel(QWidget *parent)
	: QDialog(parent), ui = new Ui::EyeModel;
{
	ui->setupUi(this);
    // QPixmap pixmap("C:/Users/Alexa/OneDrive/Desktop/Eye Project/OcuKnow/src/assets/halfeyeimage2.png");

    QPixmap pixmap(":/assets/halfeyeimage2.png");
    qDebug() << "Image exists:" << QFileInfo(":/assets/halfeyeimage2.png").exists();
    ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // ui->label->setPixmap(image);

    if (pixmap.isNull())
    {
        qDebug() << "Error";
    } else {
    	ui->label->setPixmap(pixmap);
    	qDebug() << "Success";
    }


	QMediaPlayer *player = new QMediaPlayer(this);
	QAudioOutput *audioOutput = new QAudioOutput(this);
	player->setAudioOutput(audioOutput);
	player->setSource(QUrl("qrc:/assets/vibin_chosic.ogg"));
	audioOutput->setVolume(0.5);
	player->play();

	ui->Iris->setToolTip("Iris"
"<ul>"
"<li>ir/o - iris</li>"
"<li>irid/o - iris</li>"
"<li>iridal - pertaining to the iris</li>"
"<li>iridectomy - excision of the iris</li>"
"<li>Regulates the amount of light that enters your eye by controlling dilation and constriction. It is the coloured, visible part of your eye in front of the lens. Located behind the cornea and in front of the crystalline lens, this structure separates the anterior and posterior chambers of the eye.</li>"
"</ul>)");

	ui->Pupil->setToolTip(R"DELIM(Pupil
<ul>
<li>pupill/o - pupil</li>
<li>pupillary - pertaining to the pupil</li>
<li>pupilloplasty - surgical repair of the pupil</li>
<li>Regulates how much light enters the eye. Its size is automatically varied. It is the dark center in the middle of the iris.</li>
</ul>)DELIM");

	ui->Cornea->setToolTip(R"DELIM(Cornea
<ul>
<li>corne/o - cornea</li>
<li>kerat/o - cornea</li>
<li>corneal - pertaining to the cornea</li>
<li>keratitis - inflammation of the cornea</li>
<li>keratoplasty - surgical repair of the cornea</li>
<li>Transparent circular part of the front eye, refracts the light entering the eye onto the lens and then onto the retina. Contains no blood vessels and is extremely sensitive to pain.</li>
</ul>)DELIM");

	ui->Sclera->setToolTip(R"DELIM(Sclera
<ul>
<li>scler/o - sclera</li>
<li>scleral - pertaining to the sclera</li>
<li>scleritis - inflammation of the sclera</li>
<li>sclerotomy - incision of the sclera</li>
<li>White part of the eye, protects the inner structures of the eye and maintains the shape of the eyeball.</li>
</ul>)DELIM");

	ui->Choroid->setToolTip(R"DELIM(Choroid
<ul>
<li>choroid/o - choroid</li>
<li>choroidal - pertaining to the choroid</li>
<li>choroiditis - inflammation of the choroid</li>
<li>choroidopathy - disease of the choroid</li>
<li>choroidectomy - excision of the choroid</li>
<li>Middle layer of the eye, contains blood vessels and connective tissue. It is located between the sclera and retina.</li>
</ul>)DELIM");

	ui->Lens->setToolTip(R"DELIM(Lens
<ul>
<li>phac/o - lens</li>
<li>phak/o - lens</li>
<li>lenticular - pertaining to the lens</li>
<li>phacitis - inflammation of the lens</li>
<li>phacoemulsification - process of using ultrasound to break up a lens</li>
<li>Transparent structure located behind the iris and pupil, refracts light onto the retina.\n
It is flexible and can change shape to focus on objects at different distances.</li>
<ul>)DELIM");

    ui->Retina->setToolTip(R"DELIM(Retina
<ul>
<li>retin/o - retina</li>
<li>retinal - pertaining to the retina</li>
<li>retinitis - inflammation of the retina</li>
<li>retinopathy - disease of the retina</li>
<li>retinal detachment - separation of the retina from the underlying tissue</li>
<li>Inner layer of the eye, contains photoreceptor cells (rods and cones) that convert light into electrical signals.\nThese signals are sent to the brain via the optic nerve.</li>
</ul>)DELIM");

    ui->VitreousBody->setToolTip(R"DELIM(Vitreous Body
<ul>
<li>vitre/o - vitreous</li>
<li>vitreous humor - clear gel-like substance that fills the space between the lens and retina</li>
<li>vitrectomy - surgical removal of the vitreous humor</li>
<li>vitreous body - the clear gel-like substance that fills the space between the lens and retina</li>
<li>vitreous cavity - the space filled with vitreous humor</li>
<li>Vitreous humor is a clear gel-like substance that fills the space between the lens and retina.\nIt helps maintain the shape of the eye and provides support to the retina.</li>
</ul>)DELIM");

    ui->OpticDisk->setToolTip(R"DELIM(Optic Disk
<ul>
<li>papill/o - optic disk</li>
<li>Known as the blind spot, located on the retina. Visible point where the optic nerve leaves the eyeball and where retinal blood vessels enter and leave.</li>
</ul>)DELIM");
    
    ui->OpticNerve->setToolTip(R"DELIM(Optic Nerve)DELIM");
}

// Prob don't need this

// QToolButton *toolButton = new QToolButton(this);
// toolButton->setText("Insert Text");
// toolButton->setPopupMode(QToolButton::MenuButtonPopup);

