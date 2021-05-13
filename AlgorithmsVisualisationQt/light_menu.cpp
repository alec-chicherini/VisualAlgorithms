#include "light_menu.h"

light_menu::light_menu(QWidget *parent)
	: QWidget(parent)
{

	QGroupBox* groupbox_light=new QGroupBox;
	groupbox_light->setTitle("Light");
	spinbox_r = new QSpinBox;
	spinbox_g = new QSpinBox;
	spinbox_b = new QSpinBox;
	spinbox_r->setRange(0, 255);
	spinbox_g->setRange(0, 255);
	spinbox_b->setRange(0, 255);

	QGridLayout* gridlayout_color = new QGridLayout;
	gridlayout_color->addWidget(new QLabel("Color "), 0, 0, 1, 1);
	gridlayout_color->addWidget(new QLabel("R:"), 0, 1, 1, 1, Qt::AlignRight);
	gridlayout_color->addWidget(new QLabel("G:"), 1, 1, 1, 1, Qt::AlignRight);
	gridlayout_color->addWidget(new QLabel("B:"), 2, 1, 1, 1, Qt::AlignRight);
	gridlayout_color->addWidget(spinbox_r, 0, 2, 1, 1);
	gridlayout_color->addWidget(spinbox_g, 1, 2, 1, 1);
	gridlayout_color->addWidget(spinbox_b, 2, 2, 1, 1);

	gridlayout_color->setAlignment(Qt::AlignTop);
	gridlayout_color->setSpacing(1);
	gridlayout_color->setColumnMinimumWidth(2, 25);

	spinbox_intensity = new QDoubleSpinBox;
	spinbox_intensity->setRange(-FLT_MAX, FLT_MAX);

	QGridLayout* gridlayout_this = new QGridLayout;
	gridlayout_this->addLayout(gridlayout_color, 0, 0, 1, -1);
	gridlayout_this->addWidget(new QLabel("Intensity"), 1, 0, 1, 1);
	gridlayout_this->addWidget(spinbox_intensity, 1, 2, 1, -1);

	groupbox_light->setLayout(gridlayout_this);

	QGridLayout* layout = new QGridLayout;
	layout->addWidget(groupbox_light);
	layout->setAlignment(Qt::AlignTop);

	setLayout(layout);

	connect(spinbox_r, &QSpinBox::valueChanged, this, &light_menu::light_color_changed_);
	connect(spinbox_g, &QSpinBox::valueChanged, this, &light_menu::light_color_changed_);
	connect(spinbox_b, &QSpinBox::valueChanged, this, &light_menu::light_color_changed_);

	connect(spinbox_intensity, &QDoubleSpinBox::valueChanged, this, &light_menu::light_intencity_signal);
}

light_menu::~light_menu()
{
}
