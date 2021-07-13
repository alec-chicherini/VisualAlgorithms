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
	
	out <<"QLibraryInfo::PrefixPath" << QLibraryInfo::location(QLibraryInfo::PrefixPath)<<endl;
	out << "QLibraryInfo::DocumentationPath" << QLibraryInfo::location(QLibraryInfo::DocumentationPath) << endl;
	out << "QLibraryInfo::HeadersPath" << QLibraryInfo::location(QLibraryInfo::HeadersPath) << endl;
	out << "QLibraryInfo::LibrariesPath" << QLibraryInfo::location(QLibraryInfo::LibrariesPath) << endl;
	out << "QLibraryInfo::LibraryExecutablesPath" << QLibraryInfo::location(QLibraryInfo::LibraryExecutablesPath) << endl;
	out << "QLibraryInfo::BinariesPath" << QLibraryInfo::location(QLibraryInfo::BinariesPath) << endl;
	out << "QLibraryInfo::PluginsPath" << QLibraryInfo::location(QLibraryInfo::PluginsPath) << endl;
	out << "QLibraryInfo::ImportsPath" << QLibraryInfo::location(QLibraryInfo::ImportsPath) << endl;
	out << "QLibraryInfo::Qml2ImportsPath" << QLibraryInfo::location(QLibraryInfo::Qml2ImportsPath) << endl;
	out << "QLibraryInfo::ArchDataPath" << QLibraryInfo::location(QLibraryInfo::ArchDataPath) << endl;
	out << "QLibraryInfo::DataPath" << QLibraryInfo::location(QLibraryInfo::DataPath) << endl;
	out << "QLibraryInfo::TranslationsPath" << QLibraryInfo::location(QLibraryInfo::TranslationsPath) << endl;
	out << "QLibraryInfo::ExamplesPath" << QLibraryInfo::location(QLibraryInfo::ExamplesPath) << endl;
	out << "QLibraryInfo::TestsPath" << QLibraryInfo::location(QLibraryInfo::TestsPath) << endl;
	out << "QLibraryInfo::SettingsPath" << QLibraryInfo::location(QLibraryInfo::SettingsPath) << endl;
	log.close();

	main_window window;
	window.show();

	return app.exec();
}