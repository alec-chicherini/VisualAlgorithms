#include <QtWidgets/QApplication>
#include <QLibraryInfo>
#include <qfile.h>
#include <QTextStream>
#include <qsettings.h>
#include "main_window.h"

int main(int argc, char* argv[]) 
{
	QApplication app(argc, argv);

	QCoreApplication::setOrganizationName("Chicherin inc");
	QCoreApplication::setOrganizationDomain("chicherin.rf");
	QCoreApplication::setApplicationName("AlgorithmVisualisation");

	//logging dependencies
	QFile log("QLibraryInfo_dependencies.txt");
	QTextStream out(&log);
	if(!log.open(QIODevice::WriteOnly | QIODevice::Text))return -1;
	
	out << "QLibraryInfo::PrefixPath" << QLibraryInfo::location(QLibraryInfo::PrefixPath)<<Qt::endl;
	out << "QLibraryInfo::DocumentationPath" << QLibraryInfo::location(QLibraryInfo::DocumentationPath) << Qt::endl;
	out << "QLibraryInfo::HeadersPath" << QLibraryInfo::location(QLibraryInfo::HeadersPath) << Qt::endl;
	out << "QLibraryInfo::LibrariesPath" << QLibraryInfo::location(QLibraryInfo::LibrariesPath) << Qt::endl;
	out << "QLibraryInfo::LibraryExecutablesPath" << QLibraryInfo::location(QLibraryInfo::LibraryExecutablesPath) << Qt::endl;
	out << "QLibraryInfo::BinariesPath" << QLibraryInfo::location(QLibraryInfo::BinariesPath) << Qt::endl;
	out << "QLibraryInfo::PluginsPath" << QLibraryInfo::location(QLibraryInfo::PluginsPath) << Qt::endl;
	out << "QLibraryInfo::ImportsPath" << QLibraryInfo::location(QLibraryInfo::ImportsPath) << Qt::endl;
	out << "QLibraryInfo::Qml2ImportsPath" << QLibraryInfo::location(QLibraryInfo::Qml2ImportsPath) << Qt::endl;
	out << "QLibraryInfo::ArchDataPath" << QLibraryInfo::location(QLibraryInfo::ArchDataPath) << Qt::endl;
	out << "QLibraryInfo::DataPath" << QLibraryInfo::location(QLibraryInfo::DataPath) << Qt::endl;
	out << "QLibraryInfo::TranslationsPath" << QLibraryInfo::location(QLibraryInfo::TranslationsPath) << Qt::endl;
	out << "QLibraryInfo::ExamplesPath" << QLibraryInfo::location(QLibraryInfo::ExamplesPath) << Qt::endl;
	out << "QLibraryInfo::TestsPath" << QLibraryInfo::location(QLibraryInfo::TestsPath) << Qt::endl;
	out << "QLibraryInfo::SettingsPath" << QLibraryInfo::location(QLibraryInfo::SettingsPath) << Qt::endl;
	log.close();

	main_window window;
	window.show();

	return app.exec();
}