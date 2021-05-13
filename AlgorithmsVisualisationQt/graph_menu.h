#pragma once

#include <QWidget>

#include <qgridlayout.h>
#include <qgroupbox.h>
#include <qstackedlayout.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qspinbox.h>
#include <qlabel.h>

//enums
#include"enums.h"

//debug
#include "qdebug_helper.h"

class graph_menu : public QWidget
{
	Q_OBJECT

public:
	graph_menu(QWidget *parent = Q_NULLPTR);
	~graph_menu();

private:
	QCheckBox* checkbox_loops;
	QCheckBox* checkbox_connected;
	QCheckBox* checkbox_directed;
	QCheckBox* checkbox_weighted;

	QSpinBox* spinbox_vertex_num;
	QSpinBox* spinbox_edges_num_left;
	QSpinBox* spinbox_edges_num_right;
private slots:
	void regen_graph_button_pushed()
	{

		std::underlying_type_t<GP> options = GP::NONE | GP::NONE;
		if (checkbox_loops->isChecked())options = options | GP::LOOPS;
		if (checkbox_connected->isChecked())options = options | GP::CONNECTED;
		if (checkbox_weighted->isChecked())options = options | GP::WEIGHTED;
		if (checkbox_directed->isChecked())options = options | GP::DIRECTED;
	
		emit regen_data_signal(spinbox_vertex_num->value(),
			spinbox_edges_num_left->value(),
			spinbox_edges_num_right->value(),
			options);
	}

signals:
	void regen_data_signal(const int V, const int E_left, const  int E_right, const  under_GP& properties);
	void graph_type_signal(int);
};




