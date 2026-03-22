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

	//Wire up internal slots
	connect(ui->btnOpen, &QPushButton::clicked, this, &OpenProjectWidget::onOpenClicked);
	connect(ui->projectList, &QListWidget::itemDoubleClicked, this, [this](QListWidgetItem*) { onItemDoubleClicked(); });
	connect(ui->projectList, &QListWidget::currentRowChanged, this, &OpenProjectWidget::onSelectionChanged);

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

void OpenProjectWidget::onOpenClicked()
{
	QString reason;
	if (!validateSelection(reason))
	{
		emit validationFailed(reason);
		return;
	}

	emit projectOpenRequested(selectedProjectPath());
}

void OpenProjectWidget::onItemDoubleClicked()
{
	onOpenClicked();
}

void OpenProjectWidget::onSelectionChanged(int row)
{
	Q_UNUSED(row)

	const QString path = selectedProjectPath();
	updatePreview(path);

	//Disable Open button when noting is selected to give clear visual feedback
	//before the user even tries to confirm.
	ui->btnOpen->setEnabled(!path.isEmpty());

}

bool OpenProjectWidget::validateSelection(QString& outReason) const
{
	const QString path = selectedProjectPath();

	if (path.isEmpty())
	{
		outReason = tr("Please select a project from the list.");
		return false;
	}

	if (!QDir(path).exists())
	{
		outReason = tr("The selected project path no longer exists: %1").arg(path);
		return false;
	}

	return true;
}

void OpenProjectWidget::updatePreview(const QString& projectPath)
{
	//Placeholder
	Q_UNUSED(projectPath);
}


