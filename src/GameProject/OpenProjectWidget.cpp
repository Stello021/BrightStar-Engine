#include "GameProject/OpenProjectWidget.h"
#include "ui_OpenProjectWidget.h"

#include <QDir>
#include <QFileDialog>

OpenProjectWidget::OpenProjectWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::OpenProjectWidget)
{
	ui->setupUi(this);

	ui->btnOpen->setDefault(true);

}

OpenProjectWidget::~OpenProjectWidget()
{
	delete ui;
}