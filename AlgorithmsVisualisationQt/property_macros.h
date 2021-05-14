#pragma once

//#define ADD_SIGNALS_FOR_ENTITY(ENTITY, HEAD)\
//void property_mesh_##ENTITY##_##HEAD##_signal(auto);
//
//#define ADD_SIGNALS_FOR_ENTITY(ENTITY, HEAD, ...)\
// void property_mesh_##ENTITY##_##HEAD##_signal(auto);\
// ADD_SIGNALS_FOR_ENTITY(ENTITY,__VA_ARGS__)

#define ADD_ENTITY(ENTITY) \
	QWidget* ENTITY##_properties = new QWidget(this);\
	QGridLayout* ENTITY##_properties_layout = new QGridLayout;\
	ENTITY##_properties_layout->setAlignment(Qt::AlignTop);\
    ENTITY##_properties->setLayout(ENTITY##_properties_layout);

#define ADD_DOUBLE_SPIN_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME, ROW)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ROW, 0);\
QDoubleSpinBox* spinbox_##ENTITY##_##NAME = new QDoubleSpinBox;\
ENTITY##_properties_layout->addWidget(spinbox_##ENTITY##_##NAME, ROW, 1);\
connect(spinbox_##ENTITY##_##NAME, &QDoubleSpinBox::valueChanged, this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);

#define ADD_SPIN_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME, ROW)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ROW, 0);\
QSpinBox* spinbox_##ENTITY##_##NAME = new QSpinBox;\
ENTITY##_properties_layout->addWidget(spinbox_##ENTITY##_##NAME, ROW, 1);\
connect(spinbox_##ENTITY##_##NAME, &QSpinBox::valueChanged, this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);

#define ADD_CHECK_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME, ROW)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ROW, 0);\
QCheckBox* checkbox_##ENTITY##_##NAME = new QCheckBox;\
ENTITY##_properties_layout->addWidget(checkbox_##ENTITY##_##NAME, ROW, 1);\
connect(checkbox_##ENTITY##_##NAME, &QCheckBox::stateChanged, this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);

#define ADD_COLOR_PICKER_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME, ROW)\
color_picker* color_picker_##ENTITY##_##NAME## = new color_picker(#stringNAME);\
ENTITY##_properties_layout->addWidget(color_picker_##ENTITY##_##NAME##, ROW, 0,1,-1);\
connect(color_picker_##ENTITY##_##NAME, &color_picker::color_picker_signal, this, &property_##PROPERTY::property_##PROPERTY##_##ENTITY##_##NAME##_signal);

#define ADD_SIGNAL_FOR_ENTITY(PROPERTY,ENTITY,NAME,TYPE)\
void property_##PROPERTY##_##ENTITY##_##NAME##_signal(TYPE);