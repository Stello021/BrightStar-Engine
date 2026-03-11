#include <QApplication>
#include "MainWindow.h"

int main(int argc, char** argv)
{
	//Manage event loop and Qt application's resources
	QApplication app(argc, argv);

	MainWindow mainWindow;
	mainWindow.show();

	// Start the event loop and wait for user interactions
	return app.exec();
}