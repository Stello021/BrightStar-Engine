#pragma once
#include <QMainWindow>
/// @brief Top-level editor window
///
/// On first show, it launches the project browser dialog
/// if the user dismisses the dialog without selecting a project, the editor shuts down clearly
class MainWindow : public QMainWindow
{
	Q_OBJECT // Qt macro for enabling signals and slots

public:
	//param parent: The parent widget, nullptr if this is a top-level window
	explicit MainWindow(QWidget* parent = nullptr);
	~MainWindow() = default;

protected:
	/// @brief Overridden to trigger the project browser on first show,
	void showEvent(QShowEvent* event) override;

private slots:
	//Declared as a slot so it can be safely invoked via QTimer::singleShot (queued into the event loop)
	void openProjectBrowserDialog();

private:
	/// @brief Guard flag to ensure the dialog is shown only once,
	///		   even if showEvent fires multiple times
	bool m_projectBrowserShown = false;
};
