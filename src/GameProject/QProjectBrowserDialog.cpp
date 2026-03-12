#include "GameProject/QProjectBrowserDialog.h"
#include "ui_QProjectBrowserDialog.h"

#include <QScreen>
#include <QGuiApplication>
#include <QButtonGroup>

QProjectBrowserDialog::QProjectBrowserDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QProjectBrowserDialog())
	, m_buttonGroup(new QButtonGroup(this))
{
	ui->setupUi(this);

	// Set flag to disable resize border and disabled maximize button at OS level
	setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

	// Set the fixed size of the dialog to its size hint, preventing resizing
	setFixedSize(sizeHint());

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
}

QProjectBrowserDialog::~QProjectBrowserDialog()
{
	delete ui;
}
