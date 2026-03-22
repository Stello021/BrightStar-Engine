#pragma once

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class OpenProjectWidget; };
QT_END_NAMESPACE

class OpenProjectWidget : public QWidget
{
	Q_OBJECT

public:
	explicit OpenProjectWidget(QWidget* parent = nullptr);
	~OpenProjectWidget();

	/* Accessors */

	/// <returns>
	/// The file-system path of the project currently selected in the list
	/// </returns>
	[[nodiscard]] QString selectedProjectPath() const;

	/* Mutators */

	/// <summary>
	/// Typically called by the parent dialog once the recent-project registry has been loaded
	/// </summary>
	/// <param name="paths">
	/// New project list contents
	/// </param>
	void setProjectList(const QStringList& paths);

signals:

	/// <summary>
	/// Emitted when the user double-clicks an item or clicks "Open" with a valid selection
	/// </summary>
	/// <param name="projectPath">
	/// Absolute path to the chosen project directory.
	/// </param>
	void projectOpenRequested(const QString& projectPath);

	/// <summary>
	/// Emitted when the user clicks "Open" without a valid selection so the
	/// parent dialog can display a status bar message without this widget having to know about it
	/// </summary>
	void validationFailed(const QString& reason);

private slots:

	/// <summary>
	/// Vaidate the current selection; emits projectOpenRequested or validationFailed
	/// </summary>
	void onOpenClicked();

	/// <summary>
	/// Convenience shortcut: same logic as clicking "Open" button
	/// </summary>
	void onItemDoubleClicked();

	/// <summary>
	/// Updates the preview pane when the user selects a different project
	/// </summary>
	/// <param name="row"></param>
	void onSelectionChanged(int row);

private:
	/* Helpers */
	

	/// <returns> true if a project is selected and its path exists. </returns>
	[[nodiscard]] bool validateSelection(QString& outReason) const;

	/// <param name="projectPath"> where metadata to update preview pane content are located </param>
	void updatePreview(const QString& projectPath);

private:
	/* Data members */
	Ui::OpenProjectWidget* ui;
};
