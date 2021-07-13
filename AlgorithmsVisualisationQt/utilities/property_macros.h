#pragma once
//MACROSES FOR PROPERTY GENERATION

///@brief macro for QSettings
#include <QSettings>

#define SETTINGS_INIT()\
QSettings settings;


///@brief macro used to add new properties entity
#define ADD_ENTITY(ENTITY) \
	QWidget* ENTITY##_properties = new QWidget(this);\
	QGridLayout* ENTITY##_properties_layout = new QGridLayout;\
	ENTITY##_properties_layout->setAlignment(Qt::AlignTop);\
    ENTITY##_properties->setLayout(ENTITY##_properties_layout);\
    size_t ENTITY##_row=0;


#define ADD_DOUBLE_SPIN_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ENTITY##_row++, 0);\
QDoubleSpinBox* spinbox_##ENTITY##_##NAME = new QDoubleSpinBox;\
ENTITY##_properties_layout->addWidget(spinbox_##ENTITY##_##NAME, ENTITY##_row++, 1);\
connect(spinbox_##ENTITY##_##NAME, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);\
connect(spinbox_##ENTITY##_##NAME, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [&](double value) {\
QSettings settings;\
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("value")), value);});\
spinbox_##ENTITY##_##NAME->setValue(settings.value(parentPath+QString(QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("value"))).toDouble());


#define ADD_SPIN_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ENTITY##_row++, 0);\
QSpinBox* spinbox_##ENTITY##_##NAME = new QSpinBox;\
ENTITY##_properties_layout->addWidget(spinbox_##ENTITY##_##NAME, ENTITY##_row++, 1);\
connect(spinbox_##ENTITY##_##NAME, QOverload<int>::of(&QSpinBox::valueChanged), this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);\
connect(spinbox_##ENTITY##_##NAME, QOverload<int>::of(&QSpinBox::valueChanged), this, [&,this](int value){\
QSettings settings;\
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("value")), value);});\
spinbox_##ENTITY##_##NAME->setValue(settings.value(parentPath+QString(QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("value"))).toInt());


#define ADD_CHECK_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ENTITY##_row++, 0);\
QCheckBox* checkbox_##ENTITY##_##NAME = new QCheckBox;\
ENTITY##_properties_layout->addWidget(checkbox_##ENTITY##_##NAME, ENTITY##_row++, 1,Qt::AlignRight);\
connect(checkbox_##ENTITY##_##NAME, &QCheckBox::stateChanged, this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);\
connect(checkbox_##ENTITY##_##NAME, &QCheckBox::stateChanged, this, [&, this](bool value) {\
QSettings settings; \
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("value")), value); });\
checkbox_##ENTITY##_##NAME->setChecked(settings.value(parentPath + QString(QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("value"))).toBool());

#define ADD_COLOR_PICKER_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME)\
color_picker* color_picker_##ENTITY##_##NAME## = new color_picker(#stringNAME);\
ENTITY##_properties_layout->addWidget(color_picker_##ENTITY##_##NAME##, ENTITY##_row++, 0,1,-1);\
connect(color_picker_##ENTITY##_##NAME, &color_picker::color_picker_signal, this, &property_##PROPERTY::property_##PROPERTY##_##ENTITY##_##NAME##_signal);\
connect(color_picker_##ENTITY##_##NAME, &color_picker::color_picker_signal_int, this, [&, this](int r, int g, int b) {\
QSettings settings; \
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("R")), r); ;\
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("G")), g); ;\
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("B")), b); ;\
    }); \
color_picker_##ENTITY##_##NAME##->setColor(\
settings.value(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("R"))).toInt(),\
settings.value(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("G"))).toInt(),\
settings.value(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("B"))).toInt());



#define ADD_XYZ_PICKER_PROPERTY_DEFINITION(PROPERTY,ENTITY, NAME)\
xyz_picker* xyz_picker_##ENTITY##_##NAME;\
bool bool_##PROPERTY##_##ENTITY##_##NAME;

#define ADD_XYZ_PICKER_PROPERTY_DECLARATION(PROPERTY,ENTITY, NAME, stringNAME)\
xyz_picker_##ENTITY##_##NAME## = new xyz_picker(#stringNAME);\
ENTITY##_properties_layout->addWidget(xyz_picker_##ENTITY##_##NAME##, ENTITY##_row++, 0,1,-1);\
bool_##PROPERTY##_##ENTITY##_##NAME = true;\
connect(xyz_picker_##ENTITY##_##NAME, &xyz_picker::xyz_picker_signal, this,\
 [&,this]( QVector3D vec){\
   if(bool_##PROPERTY##_##ENTITY##_##NAME)\
    emit property_##PROPERTY##_##ENTITY##_##NAME##_signal(vec);\
    });\
connect(xyz_picker_##ENTITY##_##NAME, &xyz_picker::xyz_picker_signal_double, this, [&, this](double x, double y, double z) {\
QSettings settings; \
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("X")), x); ;\
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("Y")), y); ;\
settings.setValue(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("Z")), z); ;\
    }); \
xyz_picker_##ENTITY##_##NAME##->setXYZ(\
settings.value(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("X"))).toDouble(),\
settings.value(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("Y"))).toDouble(),\
settings.value(QString(QString(parentPath_) + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("Z"))).toDouble());

#define ADD_SIGNAL_FOR_ENTITY(PROPERTY,ENTITY,NAME,TYPE)\
/*!
* @brief ROPERTY##_##ENTITY signal for NAME
*/\
void property_##PROPERTY##_##ENTITY##_##NAME##_signal(TYPE);


#define ADD_SLOT_FOR_ENTITY(PROPERTY,ENTITY,NAME,FUNCNAME,TYPE)\
/*!
@brief Set value for PROPERTY##_##ENTITY using FUNCNAME
@code
try{PROPERTY##_##ENTITY->FUNCNAME##(value);}
@endcode
@code
catch(std::exception& e){qDebug() << Q_FUNC_INFO<< "ERROR: " << e.what();}
@endcode
*/\
void property_##PROPERTY##_##ENTITY##_##NAME##_slot(TYPE value)\
{qDebug()<<QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("->")+QString(#FUNCNAME)+QString("(")<<value<<QString(")");\
try{PROPERTY##_##ENTITY->FUNCNAME##(value);}\
catch(std::exception& e){\
qDebug() << Q_FUNC_INFO<< "ERROR: " << e.what(); \
return;}};

#define ADD_CONNECTION_PROPERTY_TO_STATE(ENTITY,COMPONENT,TYPE,PROPERTY)\
connect(##ENTITY##_##COMPONENT##, &property_##COMPONENT##::property_##COMPONENT##_##TYPE##_##PROPERTY##_signal,\
        component_states_##ENTITY##, &component_states::property_##COMPONENT##_##TYPE##_##PROPERTY##_slot);


//MACROSES FOR SCENE GENERATION IN QTREEWIDGET
#define ADD_ROOT(ROOT, NAME)\
QTreeWidgetItem* treeitem_##NAME## = new QTreeWidgetItem(##ROOT##);\
treeitem_##NAME##->setText(0, QString(#NAME).replace(0, 1, QString(#NAME)[0].toUpper()));\
ROOT##->insertTopLevelItem(0, treeitem_##NAME##);\
component_states_##NAME = new component_states(root,this);\
if(QString(#NAME)==QString("camera")){\
connect(this,&scene_properties_common_graph::scene_properties_common_graph_camera_signal,\
        component_states_camera, &component_states::component_states_camera_slot);}

#define ADD_LEAF_BEGIN(TYPE,PARENT,NAME)\
property_##NAME##* ##PARENT##_##NAME## = new property_##NAME##(QString("settings/")+QString(#TYPE)+QString("/")+QString(#PARENT)+QString("/")+QString(#NAME)+QString("/"));\
QTreeWidgetItem* treeitem_##PARENT##_##NAME## = new QTreeWidgetItem(treeitem_##PARENT##);\
treeitem_##PARENT##_##NAME##->setText(0, QString(#NAME).replace(0, 1, QString(#NAME)[0].toUpper()));\
QTreeWidgetItem* treeitem_##PARENT##_##NAME##_property = new QTreeWidgetItem(treeitem_##PARENT##_##NAME##);\
tree_widget->setItemWidget(treeitem_##PARENT##_##NAME##_property, 0, ##PARENT##_##NAME##);\
connect(##PARENT##_##NAME##, &property_##NAME##::property_##NAME##_type_signal,\
component_states_##PARENT##, &component_states::component_states_##NAME##_type_slot);\
connect(component_states_##PARENT##, &component_states::component_states_##NAME##_type_signal,\
scene_entities_common_graph_, &scene_entities_common_graph::scene_entities_common_graph_##PARENT##_##NAME##_type_slot);

#define ADD_LEAF_END(TYPE,PARENT,NAME) //PARENT##_##NAME##->send_initialization_data();
