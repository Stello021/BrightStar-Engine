#pragma once

#include <QDialog>

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
	Ui::QProjectBrowserDialog* ui;
};
