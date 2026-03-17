#include "GameProject/QProjectBrowserDialog.h"
#include "ui_QProjectBrowserDialog.h"

#include <QScreen>
#include <QGuiApplication>
#include <QButtonGroup>
#include <GameProject/NewProjectWidget.h>

QProjectBrowserDialog::QProjectBrowserDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QProjectBrowserDialog())
	, m_buttonGroup(new QButtonGroup(this))
{
	ui->setupUi(this);

	// Set flag to disable resize border and disabled maximize button at OS level
	setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

	// Use parent widget's screen if available, otherwise use the primary screen
	const QScreen* targetScreen = parentWidget() ? parentWidget()->screen() : QGuiApplication::primaryScreen();

	// Center the dialog on the target screen
	const QRect screenRect = targetScreen->availableGeometry();
	move(screenRect.center() - rect().center());

	m_buttonGroup->setExclusive(true);
	m_buttonGroup->addButton(ui->btnOpenProject, 0);
	m_buttonGroup->addButton(ui->btnNewProject, 1);

	connect(m_buttonGroup, &QButtonGroup::idToggled,
		this, [this](int id, bool checked)
		{
			if (checked)
			{
				ui->contentStack->setCurrentIndex(id);
			}
		});

	//Set the initial page to "Open Project"
	ui->contentStack->setCurrentIndex(0);

	ui->navigationLayout->setSpacing(30);

	NewProjectWidget* newProjectWidget = new NewProjectWidget(this);

	ui->contentStack->removeWidget(ui->pageNewProject);
	ui->contentStack->insertWidget(1, newProjectWidget);

	connect(newProjectWidget, &NewProjectWidget::projectCreationRequested,
		this, [this](const QString& name, const QString& path, const QString& tmplId)
		{
			accept();
		});

	connect(newProjectWidget, &NewProjectWidget::validationFailed,
		this, [this](const QString& reason)
		{

		});
}

QProjectBrowserDialog::~QProjectBrowserDialog()
{
	delete ui;
}
