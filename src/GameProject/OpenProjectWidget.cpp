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

QString OpenProjectWidget::selectedProjectPath() const
{
	const QListWidgetItem* item = ui->projectList->currentItem();
	if (!item)
	{
		return QString();
	}

	//The full path is stored in the UserRole so the display text can be
	//a human-friendly project name decoupled from filesystem path
	return item->data(Qt::UserRole).toString();
}

void OpenProjectWidget::setProjectList(const QStringList& paths)
{
	ui->projectList->clear();

	for (const QString& path : paths)
	{
		//Display only the final directory component as  the project name so
		//long paths do not overflow the fixed-width list widget.
		const QString displayName = QDir(path).dirName();

		QListWidgetItem* item = new QListWidgetItem(displayName, ui->projectList);
		item->setData(Qt::UserRole, path); //Store full path for retrieval
	}
}
