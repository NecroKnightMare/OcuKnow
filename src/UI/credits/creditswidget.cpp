

#include "creditswidget.h"
#include "../intro/introwidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

CreditsWidget::CreditsWidget(QWidget *parent) : QWidget(parent)
{
	setWindowTitle("Credits");
	setStyleSheet("background-color: white; color: #4FA3E3; font-family: 'Orbitron', sans-serif; font-size: 16px;");
	setMinimumSize(1200, 800);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QVBoxLayout *layout = new QVBoxLayout(this);
	QLabel *title = new QLabel("OcuKnow - Credits", this);
	title->setAlignment(Qt::AlignCenter);
	title->setStyleSheet("font-size: 24px; color: #4FA3E3;");

	QLabel *body = new QLabel(this);
	body->setText(
		"<b>Development Team</b><br>Ariel Lopez<br>Stephen Newby<br>Nash Thames<br><br><b>Special Thanks</b><br>Qt Framework<br>Atlas School");
	body->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	body->setWordWrap(true);

	layout->addWidget(title);
	layout->addSpacing(15);

	QPushButton *returnButton = new QPushButton("Return", this);
	returnButton->setStyleSheet(R"(
	QPushButton {
		background-color: white;
		color: #4FA3E3;
		font-size: 16px;
		font-family: 'Orbitron', sans-serif;
		border: 2px solid #4FA3E3;
		border-radius: 8px;
		padding: 5px 20px;
	}
	QPushButton:hover {
		background-color: #4FA3E3;
		color: white;
	}
)");
	connect(returnButton, &QPushButton::clicked, this, [this]()
			{
    emit returnToIntro();
    this->close(); });

	layout->addWidget(body);
	layout->addWidget(returnButton, 0, Qt::AlignCenter);

	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}