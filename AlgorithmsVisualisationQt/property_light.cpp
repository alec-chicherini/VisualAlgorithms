#include "property_light.h"

property_light::property_light(QWidget *parent)
	: QWidget(parent)
{

	QGroupBox* groupbox_light=new QGroupBox;
	groupbox_light->setTitle("Light");

	property_color = new color_picker("Color ");

	spinbox_intensity = new QDoubleSpinBox;
	spinbox_intensity->setRange(-FLT_MAX, FLT_MAX);

	QGridLayout* gridlayout_this = new QGridLayout;
	gridlayout_this->addWidget(property_color, 0, 0, 1, -1);
	gridlayout_this->addWidget(new QLabel("Intensity"), 1, 0, 1, 1);
	gridlayout_this->addWidget(spinbox_intensity, 1, 2, 1, -1);

	groupbox_light->setLayout(gridlayout_this);

	QGridLayout* layout = new QGridLayout;
	layout->addWidget(groupbox_light);
	layout->setAlignment(Qt::AlignTop);

	setLayout(layout);

	connect(property_color, &color_picker::color_picker_signal, this, &property_light::light_color_signal);
	connect(spinbox_intensity, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &property_light::light_intencity_signal);
}

property_light::~property_light()
{
}
