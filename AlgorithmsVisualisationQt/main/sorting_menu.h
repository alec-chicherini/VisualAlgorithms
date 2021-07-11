#pragma once

#include <QWidget>

#include <qpushbutton.h>
#include <qgridlayout.h>

/// @brief widget for choose sorting generation propertes
class sorting_menu : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	sorting_menu(QWidget *parent = Q_NULLPTR);
	/// @brief default destructor
	~sorting_menu();

private:

	QPushButton* push_button_bubble;
	QPushButton* push_button_merge;
	QPushButton* push_button_qsort;
};
