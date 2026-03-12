#pragma once

#include <QString>

// StyleManager is a pure static utility class that load and apply QSS stylesheets
// from the Qt Resources system to the QApplication instance.
class StyleManager
{
public:

	/// <summary>
	/// Loads the given QRC Path and applies it application-wide.
	/// Must be called after QApplication is contructed, before any widgets is shown.
	/// </summary>
	/// <param name="resourcesPath"></param>
	/// <returns> return false if loading fails </returns>
	static bool applyStyleSheet(const QString& resourcesPath);

	static bool applyDefaultTheme();

private:
	// This class is just a namespace with access control
	StyleManager() = delete; // Prevent instantiation of this class
};
