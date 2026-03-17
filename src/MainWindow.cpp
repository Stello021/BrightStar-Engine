#include "MainWindow.h"

#include <QScreen>
#include <QGuiApplication>
#include <QApplication>
#include <QShowEvent>
#include <QTimer>
#include "GameProject/QProjectBrowserDialog.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	// Set up the main window (e.g., set title, size, etc.)
	setWindowTitle("Brightstar Engine Editor");

	// Use parent widget's screen if available, otherwise use the primary screen
	const QScreen* targetScreen = parentWidget() ? parentWidget()->screen() : QGuiApplication::primaryScreen();

	// Center the dialog on the target screen
	const QRect screenRect = targetScreen->availableGeometry();
	move(screenRect.center() - rect().center());
}

void MainWindow::showEvent(QShowEvent* event)
{
	// Always call the base implementation first for Qt internal logic
	QMainWindow::showEvent(event);

	if (!m_projectBrowserShown)
	{
		m_projectBrowserShown = true;

		// Zero Delay; this posts the openProjectBrowserDialog call to the end of the current event loop iteration.
		// This guarantees the main window is fully drawn before the modal dialog appears
		QTimer::singleShot(0, this, &MainWindow::openProjectBrowserDialog);
	}
}

void MainWindow::openProjectBrowserDialog()
{
	QProjectBrowserDialog projectBrowser(this);

	// exec() runs a nested event loop and blocks until the dialog closes.
	//It returns QDialog::Accepted if the user confirmed, Rejected otherwise.
	if (projectBrowser.exec() == QDialog::Rejected)
	{
		QApplication::quit();
	}

}
