#ifndef CREDITSWIDGET_H
#define CREDITSWIDGET_H

#include <QWidget>

class CreditsWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CreditsWidget(QWidget *parent = nullptr);

signals:
	void returnToIntro();
};

#endif // CREDITSWIDGET_H
