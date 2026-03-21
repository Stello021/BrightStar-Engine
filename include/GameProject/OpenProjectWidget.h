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

private slots:

private:



private:
	/* Data members */
	Ui::OpenProjectWidget* ui;
};
