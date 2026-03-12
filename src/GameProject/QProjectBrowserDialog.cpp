#include "GameProject/QProjectBrowserDialog.h"
#include "ui_QProjectBrowserDialog.h"

QProjectBrowserDialog::QProjectBrowserDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QProjectBrowserDialog())
{
	ui->setupUi(this);
}

QProjectBrowserDialog::~QProjectBrowserDialog()
{
	delete ui;
}
