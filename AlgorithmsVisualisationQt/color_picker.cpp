#include "color_picker.h"

color_picker::color_picker(QString label, QWidget *parent)
	: QWidget(parent)
{
	spinbox_r = new QSpinBox;
	spinbox_g = new QSpinBox;
	spinbox_b = new QSpinBox;
	spinbox_r->setRange(0, 255);
	spinbox_g->setRange(0, 255);
	spinbox_b->setRange(0, 255);

	QGridLayout* gridlayout_color = new QGridLayout;
	gridlayout_color->addWidget(new QLabel(label), 0, 0, 1, 1);
	gridlayout_color->addWidget(new QLabel("R:"), 0, 1, 1, 1, Qt::AlignRight);
	gridlayout_color->addWidget(new QLabel("G:"), 1, 1, 1, 1, Qt::AlignRight);
	gridlayout_color->addWidget(new QLabel("B:"), 2, 1, 1, 1, Qt::AlignRight);
	gridlayout_color->addWidget(spinbox_r, 0, 2, 1, 1);
	gridlayout_color->addWidget(spinbox_g, 1, 2, 1, 1);
	gridlayout_color->addWidget(spinbox_b, 2, 2, 1, 1);

	gridlayout_color->setAlignment(Qt::AlignTop);
	gridlayout_color->setSpacing(1);
	gridlayout_color->setColumnMinimumWidth(2, 25);
	gridlayout_color->setContentsMargins(0, 0, 0, 0);

	setLayout(gridlayout_color);

	connect(spinbox_r, &QSpinBox::valueChanged, this, &color_picker::color_changed_);
	connect(spinbox_g, &QSpinBox::valueChanged, this, &color_picker::color_changed_);
	connect(spinbox_b, &QSpinBox::valueChanged, this, &color_picker::color_changed_);
	setContentsMargins(0, 0, 0, 0);
}

color_picker::~color_picker()
{
}
