#pragma once

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class NewProjectWidget; };
QT_END_NAMESPACE

class NewProjectWidget : public QWidget
{
	Q_OBJECT

public:
	explicit NewProjectWidget(QWidget* parent = nullptr);
	~NewProjectWidget();

	/* Accessors */

	[[nodiscard]] QString projectName() const;

	[[nodiscard]] QString projectPath() const;

	/// @returns The identifier of the template currently selected in the list,
	[[nodiscard]] QString selectedTemplate() const;

	/* Mutators */

	/// Pre-fills the path field with @p path (e.g. from a user preference).
	void setDefaultPath(const QString& path);

signals:
	/// Emitted when the user clicks "Create" and all fields pass validation.
	/// @param tmplId    Identifier of the chosen template.
	void projectCreationRequested(const QString& name,
		const QString& path,
		const QString& tmplId);

	/// Emitted when validation fails so the parent dialog can show a status bar
	/// message without this widget having to know about the dialog's UI.
	void validationFailed(const QString& reason);

private slots:
	/* Internal slot wired to btnBrowse::clicked */
	/// Opens a native QFileDialog and writes the chosen directory into inputPath.
	void onBrowseClicked();

	/* Internal slot wired to btnCreate::clicked */
	/// Validates all fields; emits projectCreationRequested or validationFailed.
	void onCreateClicked();

	/* Internal slot wired to templateList::currentRowChanged */
	/// Updates the preview pane when the user selects a different template.
	void onTemplateSelectionChanged(int row);

private:

	/// Populates templateList with the built-in project templates.
	/// Called once from the constructor; extend here when new templates land.
	void populateTemplates();

	/// @returns true if name and path are non-empty and the path is writable.
	[[nodiscard]] bool validateInputs(QString& outReason) const;

private:
	/* Data members */
	Ui::NewProjectWidget* ui;
};
