#pragma once

#include <QDialog>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class QProjectBrowserDialog; };
QT_END_NAMESPACE

class QProjectBrowserDialog : public QDialog
{
	Q_OBJECT

public:
	QProjectBrowserDialog(QWidget *parent = nullptr);
	~QProjectBrowserDialog();

private:
	//Manage mutual exclusivity between the nav buttons
	QButtonGroup* m_buttonGroup;

	Ui::QProjectBrowserDialog* ui;
};
