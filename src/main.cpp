#include <QApplication>
#include "GameProject/QProjectBrowserDialog.h"
#include "StyleManager.h"

int main(int argc, char** argv)
{
	//Manage event loop and Qt application's resources
	QApplication app(argc, argv);

	StyleManager::applyDefaultTheme();

	QProjectBrowserDialog projectBrowerDialog;
	projectBrowerDialog.show();

	// Start the event loop and wait for user interactions
	return app.exec();
}