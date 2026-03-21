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

private:



private:
	/* Data members */
	Ui::OpenProjectWidget* ui;
};
