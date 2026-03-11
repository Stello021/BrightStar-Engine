#pragma once
#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT // Qt macro for enabling signals and slots

public:

	//param parent: The parent widget, nullptr if this is a top-level window
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow() = default;
};
