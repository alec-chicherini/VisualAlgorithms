#include "xyz_picker.h"

xyz_picker::xyz_picker(QString label, QWidget *parent)
	: QWidget(parent)
{
	spinbox_x = new QDoubleSpinBox;
	spinbox_y = new QDoubleSpinBox;
	spinbox_z = new QDoubleSpinBox;

	spinbox_x->setRange(-DBL_MAX, DBL_MAX); 
	spinbox_y->setRange(-DBL_MAX, DBL_MAX);
	spinbox_z->setRange(-DBL_MAX, DBL_MAX);

	QGridLayout* gridlayout_xyz = new QGridLayout;
	gridlayout_xyz->addWidget(new QLabel(label), 0, 0, 1, 1);
	gridlayout_xyz->addWidget(new QLabel("X:"), 0, 1, 1, 1, Qt::AlignRight);
	gridlayout_xyz->addWidget(new QLabel("Y:"), 1, 1, 1, 1, Qt::AlignRight);
	gridlayout_xyz->addWidget(new QLabel("Z:"), 2, 1, 1, 1, Qt::AlignRight);
	gridlayout_xyz->addWidget(spinbox_x, 0, 2, 1, 1);
	gridlayout_xyz->addWidget(spinbox_y, 1, 2, 1, 1);
	gridlayout_xyz->addWidget(spinbox_z, 2, 2, 1, 1);

	gridlayout_xyz->setAlignment(Qt::AlignTop);
	gridlayout_xyz->setSpacing(1);
	gridlayout_xyz->setColumnMinimumWidth(2, 25);
	gridlayout_xyz->setContentsMargins(0, 0, 0, 0);

	setLayout(gridlayout_xyz);

	connect(spinbox_x, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &xyz_picker::xyz_changed_);
	connect(spinbox_y, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &xyz_picker::xyz_changed_);
	connect(spinbox_z, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &xyz_picker::xyz_changed_);
	setContentsMargins(0, 0, 0, 0);
}

xyz_picker::~xyz_picker()
{
}
