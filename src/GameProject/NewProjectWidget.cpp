#include "GameProject/NewProjectWidget.h"
#include "ui_NewProjectWidget.h"

#include <QDir>
#include <QFileDialog>

NewProjectWidget::NewProjectWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::NewProjectWidget)
{
	ui->setupUi(this);

	// Given that this widget lived into the "Project Browser" dialog,
	// Qt automatically re-parented the "Create" button to the dialog context as default button
	ui->btnCreate->setDefault(true);

	populateTemplates();

	//Wire up internal slots

	connect(ui->btnBrowse, &QPushButton::clicked, this, &NewProjectWidget::onBrowseClicked);
	connect(ui->btnCreate, &QPushButton::clicked, this, &NewProjectWidget::onCreateClicked);
	connect(ui->templateList, &QListWidget::currentRowChanged, this, &NewProjectWidget::onTemplateSelectionChanged);

}

NewProjectWidget::~NewProjectWidget()
{
	delete ui;
}

QString NewProjectWidget::projectName() const
{
	return ui->inputName->text().trimmed();
}

QString NewProjectWidget::projectPath() const
{
	return ui->inputPath->text().trimmed();
}

QString NewProjectWidget::selectedTemplate() const
{
	const QListWidgetItem* item = ui->templateList->currentItem();

	//An item stores the template ID in its UserRole data,
	//so that the display text can be localized independently of the internal id
	return item ? item->data(Qt::UserRole).toString() : QString();
}



void NewProjectWidget::setDefaultPath(const QString& path)
{
	ui->inputPath->setText(path);
}

void NewProjectWidget::onBrowseClicked()
{
	//Opens the native folder-picker dialog, if input path is empty
	const QString startDir = ui->inputPath->text().isEmpty() ? QDir::homePath() : ui->inputPath->text();

	const QString chosenDir = QFileDialog::getExistingDirectory(this, tr("Select Project Location"), startDir,
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	//Update only if user confirmed a choice
	if (!chosenDir.isEmpty())
	{
		ui->inputPath->setText(chosenDir);
	}
}

void NewProjectWidget::onCreateClicked()
{
	QString reason;

	if (!validateInputs(reason))
	{
		emit validationFailed(reason);
		return;
	}

	emit projectCreationRequested(projectName(), projectPath(), selectedTemplate());

}

void NewProjectWidget::onTemplateSelectionChanged(int row)
{
	Q_UNUSED(row);
}

void NewProjectWidget::populateTemplates()
{

}

bool NewProjectWidget::validateInputs(QString& outReason) const
{
	if (projectName().isEmpty())
	{
		outReason = tr("Please enter a project name.");
		return false;
	}

	if (projectPath().isEmpty())
	{
		outReason = tr("Please choose a project location.");
		return false;
	}

	if (!QDir(projectPath()).exists())
	{
		outReason = tr("The specified path does not exist: %1").arg(projectPath());
		return false;
	}

	if (selectedTemplate().isEmpty())
	{
		outReason = tr("Please select a project template.");
		return false;
	}

	return true;
}
