#include "StyleManager.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

bool StyleManager::applyStyleSheet(const QString& resourcesPath)
{
	QFile file(resourcesPath);

	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		qWarning() << "[StyleManager] Failed to open stylesheet file:" << resourcesPath;
		return false;
	}

	const QString styleSheet = QString::fromUtf8(file.readAll());

	qApp->setStyleSheet(styleSheet);

	qDebug() << "[StyleManager] Applied stylesheet from:" << resourcesPath;
	return true;
}

bool StyleManager::applyDefaultTheme()
{
	return applyStyleSheet(QStringLiteral(":/styles/BrightStarDark.qss"));
}
