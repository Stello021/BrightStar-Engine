#pragma once

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class OpenProjectWidget; };
QT_END_NAMESPACE

class OpenProjectWidget : public QWidget
{
	Q_OBJECT

public:
	explicit OpenProjectWidget(QWidget* parent = nullptr);
	~OpenProjectWidget();

	/* Accessors */

	/* Mutators */

signals:

private slots:

private:

	

private:
	/* Data members */
	Ui::OpenProjectWidget* ui;
};
