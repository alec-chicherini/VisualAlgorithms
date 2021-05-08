#pragma once

#include <QWidget>

#include <qpushbutton.h>
#include <qgridlayout.h>

class sorting_menu : public QWidget
{
	Q_OBJECT

public:
	sorting_menu(QWidget *parent = Q_NULLPTR);
	~sorting_menu();

private:

	QPushButton* push_button_bubble;
	QPushButton* push_button_merge;
	QPushButton* push_button_qsort;
};
