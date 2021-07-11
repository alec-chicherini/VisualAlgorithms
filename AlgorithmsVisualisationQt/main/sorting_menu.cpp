#include "sorting_menu.h"

sorting_menu::sorting_menu(QWidget *parent)
	: QWidget(parent)
{
	push_button_bubble = new QPushButton("Start bubble sort");
	push_button_merge = new QPushButton("Start merge sort");
	push_button_qsort = new QPushButton("Start qsort");

	//main layout
	QGridLayout* grid_layout_main = new QGridLayout;

	grid_layout_main->addWidget(push_button_bubble, 0, 0);
	grid_layout_main->addWidget(push_button_merge, 1, 0);
	grid_layout_main->addWidget(push_button_qsort, 2, 0);
	
	grid_layout_main->setAlignment(Qt::AlignTop);
	setLayout(grid_layout_main);
	//

}

sorting_menu::~sorting_menu()
{
}
