#include "MainWindow.h"

#include <QScreen>
#include <QGuiApplication>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	// Set up the main window (e.g., set title, size, etc.)
	setWindowTitle("BEngine Editor");
	resize(1280, 720);

	// Use parent widget's screen if available, otherwise use the primary screen
	const QScreen* targetScreen = parentWidget() ? parentWidget()->screen() : QGuiApplication::primaryScreen();

	// Center the dialog on the target screen
	const QRect screenRect = targetScreen->availableGeometry();
	move(screenRect.center() - rect().center());
}
