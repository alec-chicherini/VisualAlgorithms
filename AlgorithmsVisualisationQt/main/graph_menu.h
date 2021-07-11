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
using namespace ENUMS_NAMESPACE;

//debug
#include "qdebug_helper.h"
/// @brief graph menu class holds controls to choose and set up generation of graphs visualisation
class graph_menu : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	graph_menu(QWidget *parent = Q_NULLPTR);
	
	/// @brief default destructor
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
	/// @brief send current graph properties choosen in this widget
	/// @param V number of vertexes
	/// @param E_left left edge of generated edges number. Result number of random edges will be in range [E_left, E_right]
	/// @param E_right right edge of generated edges number. Result number of random edges will be in range [E_left, E_right]
	/// @param properties bit flag with properties(GraphProperties enum) of generated graph. For example the buttons picked, conencted graph with loops than properties is @code GP::DIRECTED|GP::CONNECTED|GP::LOOPS @endcode
	void regen_data_signal(const int V, const int E_left, const  int E_right, const  under_GP& properties);

	/// @brief current graph type signal emmited after select the graph type
	void graph_type_signal(int);
};




