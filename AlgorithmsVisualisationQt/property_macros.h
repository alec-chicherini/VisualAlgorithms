#pragma once
//MACROSES FOR PROPERTY GENERATION
// 
//#define ADD_SIGNALS_FOR_ENTITY(ENTITY, HEAD)\
//void property_mesh_##ENTITY##_##HEAD##_signal(auto);
//
//#define ADD_SIGNALS_FOR_ENTITY(ENTITY, HEAD, ...)\
// void property_mesh_##ENTITY##_##HEAD##_signal(auto);\
// ADD_SIGNALS_FOR_ENTITY(ENTITY,__VA_ARGS__)

///@brief macro used to add new properties entity
#define ADD_ENTITY(ENTITY) \
	QWidget* ENTITY##_properties = new QWidget(this);\
	QGridLayout* ENTITY##_properties_layout = new QGridLayout;\
	ENTITY##_properties_layout->setAlignment(Qt::AlignTop);\
    ENTITY##_properties->setLayout(ENTITY##_properties_layout);


#define ADD_JSON_LOADER(ENTITY) \
    template<typename T>\
    QJsonValue read_write_##ENTITY##_json_(QIODevice::OpenModeFlag mode,QString key, T value={}){\
    if(mode==QIODevice::ReadOnly){\
        if (!QDir().exists(parentPath_ + QString(#ENTITY)))QDir().mkpath(parentPath_); \
            QFile ENTITY##_settings_file(parentPath_ + QString(#ENTITY) + QString("_settings.json")); \
    if(ENTITY##_settings_file.open(QIODevice::ReadWrite) && ENTITY##_settings_file.exists())\
    /*qDebug()<<"File Oppened:"<<parentPath_+QString(#ENTITY)+QString("_settings.json")*/;\
    else qDebug()<<"Can`t open:"<<parentPath_+QString(#ENTITY)+QString("_settings.json");\
    QByteArray ENTITY##_data = ENTITY##_settings_file.readAll();\
    QJsonDocument doc(QJsonDocument::fromJson(ENTITY##_data));\
    return doc.object().take(key);}\
    else if(mode==QIODevice::WriteOnly){\
    if(!QDir().exists(parentPath_+QString(#ENTITY)))QDir().mkpath(parentPath_);\
    QFile ENTITY##_settings_file (parentPath_+QString(#ENTITY)+QString("_settings.json"));\
    if(ENTITY##_settings_file.open(QIODevice::ReadOnly) && ENTITY##_settings_file.exists())\
    /*qDebug()<<"File Oppened:"<<parentPath_+QString(#ENTITY)+QString("_settings.json")*/;\
    else qDebug()<<"Can`t open:"<<parentPath_+QString(#ENTITY)+QString("_settings.json");\
    QByteArray ENTITY##_data = ENTITY##_settings_file.readAll();\
    QJsonDocument doc(QJsonDocument::fromJson(ENTITY##_data));\
    QJsonObject obj(doc.object());\
    obj.insert(key, value);\
    QFile ENTITY##_settings_file2(parentPath_ + QString(#ENTITY) + QString("_settings.json")); \
    if(ENTITY##_settings_file2.open(QIODevice::WriteOnly) && ENTITY##_settings_file.exists())\
    /*qDebug()<<"File Oppened:"<<parentPath_+QString(#ENTITY)+QString("_settings.json")*/;\
    else qDebug()<<"Can`t open:"<<parentPath_+QString(#ENTITY)+QString("_settings.json");\
    ENTITY##_settings_file2.write(QJsonDocument(obj).toJson());\
    return QJsonValue(1); }; return QJsonValue(1);};
  
   

#define ADD_DOUBLE_SPIN_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME, ROW)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ROW, 0);\
QDoubleSpinBox* spinbox_##ENTITY##_##NAME = new QDoubleSpinBox;\
ENTITY##_properties_layout->addWidget(spinbox_##ENTITY##_##NAME, ROW, 1);\
connect(spinbox_##ENTITY##_##NAME, &QDoubleSpinBox::valueChanged, this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);\
connect(spinbox_##ENTITY##_##NAME, &QDoubleSpinBox::valueChanged, this, [&](double value){\
read_write_##ENTITY##_json_(QIODevice::WriteOnly,QString(QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("value")), value);\
});\
spinbox_##ENTITY##_##NAME->setValue(read_write_##ENTITY##_json_(QIODevice::ReadOnly,\
QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("value"),double()).toDouble());\
if((QString(#NAME)=="x_extent")||(QString(#NAME)=="y_extent")||(QString(#NAME)=="z_extent")||\
   (QString(#NAME)=="height")||(QString(#NAME)=="width"))\
{\
    spinbox_##ENTITY##_##NAME->setMinimum(0.01f);\
    if(spinbox_##ENTITY##_##NAME->value()<1.0)spinbox_##ENTITY##_##NAME->setValue((double)1.0);\
}\
if((QString(#ENTITY)=="cone"))\
{\
    spinbox_##ENTITY##_##NAME->setMinimum(0.00f);\
}\
e_vec_func_double.push_back({QString("property_")+QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_signal"), spinbox_##ENTITY##_##NAME->value()});


#define ADD_SPIN_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME, ROW)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ROW, 0);\
QSpinBox* spinbox_##ENTITY##_##NAME = new QSpinBox;\
ENTITY##_properties_layout->addWidget(spinbox_##ENTITY##_##NAME, ROW, 1);\
connect(spinbox_##ENTITY##_##NAME, &QSpinBox::valueChanged, this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);\
connect(spinbox_##ENTITY##_##NAME, &QSpinBox::valueChanged, this, [&,this](int value){\
read_write_##ENTITY##_json_(QIODevice::WriteOnly,QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("value"), value);\
});\
spinbox_##ENTITY##_##NAME->setValue(read_write_##ENTITY##_json_(QIODevice::ReadOnly,\
QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("value"),double()).toInt());\
if(QString(#NAME)=="rings"||QString(#NAME)=="slices")\
{\
    spinbox_##ENTITY##_##NAME->setRange(10,100);\
   if(spinbox_##ENTITY##_##NAME->value()<10)spinbox_##ENTITY##_##NAME->setValue((int)10);\
}\
e_vec_func_int.push_back({QString("property_")+QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_signal"), spinbox_##ENTITY##_##NAME->value()});


#define ADD_CHECK_BOX_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME, ROW)\
ENTITY##_properties_layout->addWidget(new QLabel(#stringNAME), ROW, 0);\
QCheckBox* checkbox_##ENTITY##_##NAME = new QCheckBox;\
ENTITY##_properties_layout->addWidget(checkbox_##ENTITY##_##NAME, ROW, 1,Qt::AlignRight);\
connect(checkbox_##ENTITY##_##NAME, &QCheckBox::stateChanged, this, &property_##PROPERTY##::property_##PROPERTY##_##ENTITY##_##NAME##_signal);\
connect(checkbox_##ENTITY##_##NAME, &QCheckBox::stateChanged, this, [&,this](bool value){\
read_write_##ENTITY##_json_(QIODevice::WriteOnly,QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("value"), value);});\
checkbox_##ENTITY##_##NAME->setChecked(read_write_##ENTITY##_json_(QIODevice::ReadOnly,\
QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("value"),bool()).toBool());\
e_vec_func_int.push_back({QString("property_")+QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_signal"), checkbox_##ENTITY##_##NAME->isChecked()});


#define ADD_COLOR_PICKER_PROPERTY(PROPERTY,ENTITY, NAME, stringNAME, ROW)\
color_picker* color_picker_##ENTITY##_##NAME## = new color_picker(#stringNAME);\
ENTITY##_properties_layout->addWidget(color_picker_##ENTITY##_##NAME##, ROW, 0,1,-1);\
connect(color_picker_##ENTITY##_##NAME, &color_picker::color_picker_signal, this, &property_##PROPERTY::property_##PROPERTY##_##ENTITY##_##NAME##_signal);\
color_picker_##ENTITY##_##NAME##->setColor(\
read_write_##ENTITY##_json_(QIODevice::ReadOnly,QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("r_value"),int()).toInt(),\
read_write_##ENTITY##_json_(QIODevice::ReadOnly,QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("g_value"),int()).toInt(),\
read_write_##ENTITY##_json_(QIODevice::ReadOnly,QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("b_value"),int()).toInt()\
);\
connect(color_picker_##ENTITY##_##NAME, &color_picker::color_picker_signal_int, this, [&, this](int r, int g, int b) {\
read_write_##ENTITY##_json_(QIODevice::WriteOnly,QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("_")+QString(#NAME)+QString("_")+QString("r_value"), r);\
read_write_##ENTITY##_json_(QIODevice::WriteOnly, QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("g_value"), g);\
read_write_##ENTITY##_json_(QIODevice::WriteOnly, QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_") + QString("b_value"), b);\
});\
e_vec_func_QColor.push_back({ QString("property_") + QString(#PROPERTY) + QString("_") + QString(#ENTITY) + QString("_") + QString(#NAME) + QString("_signal"), color_picker_##ENTITY##_##NAME->getColor() });
 //emit property_##PROPERTY##_##ENTITY##_##NAME##_signal(color_picker_##ENTITY##_##NAME##->color_picker_color());


//MACROSES FOR SIGNAL-SLOT-CONNECTION GENERATION 

/// @brief macro epanded to 
#define ADD_SIGNAL_FOR_ENTITY(PROPERTY,ENTITY,NAME,TYPE)\
void property_##PROPERTY##_##ENTITY##_##NAME##_signal(TYPE);

#define ADD_SLOT_FOR_ENTITY(PROPERTY,ENTITY,NAME,FUNCNAME,TYPE)\
void property_##PROPERTY##_##ENTITY##_##NAME##_slot(TYPE value)\
{\
qDebug()<<QString(#PROPERTY)+QString("_")+QString(#ENTITY)+QString("->")+QString(#FUNCNAME)+QString("(")<<value<<QString(")");\
try{PROPERTY##_##ENTITY->FUNCNAME##(value);}\
catch(std::exception& e){\
qDebug() << __FUNCSIG__<< "ERROR: " << e.what(); \
return;}\
};

#define ADD_CONNECTION_PROPERTY_TO_STATE(ENTITY,COMPONENT,TYPE,PROPERTY)\
connect(##ENTITY##_##COMPONENT##, &property_##COMPONENT##::property_##COMPONENT##_##TYPE##_##PROPERTY##_signal,\
        component_states_##ENTITY##, &component_states::property_##COMPONENT##_##TYPE##_##PROPERTY##_slot);


//#define ADD_CONNECTION_TYPE_TO_TYPE(ENTITY,COMPONENT)\
//connect(##ENTITY##_##COMPONENT##, &property_##COMPONENT##::property_##COMPONENT##_type_signal,component_states_##ENTITY##, &component_states::component_states_##COMPONENT##_type_slot);


//MACROSES FOR SCENE GENERATION IN QTREEWIDGET
#define ADD_ROOT(ROOT, NAME)\
QTreeWidgetItem* treeitem_##NAME## = new QTreeWidgetItem(##ROOT##);\
treeitem_##NAME##->setText(0, QString(#NAME).replace(0, 1, QString(#NAME)[0].toUpper()));\
tree_widget->insertTopLevelItem(0, treeitem_##NAME##);\
component_states_##NAME = new component_states(root,this);

#define ADD_LEAF_BEGIN(TYPE,PARENT,NAME)\
property_##NAME##* ##PARENT##_##NAME## = new property_##NAME##(QString("settings/")+QString(#TYPE)+QString("/")+QString(#PARENT)+QString("/")+QString(#NAME)+QString("/"));\
QTreeWidgetItem* treeitem_##PARENT##_##NAME## = new QTreeWidgetItem(treeitem_##PARENT##);\
treeitem_##PARENT##_##NAME##->setText(0, QString(#NAME).replace(0, 1, QString(#NAME)[0].toUpper()));\
QTreeWidgetItem* treeitem_##PARENT##_##NAME##_property = new QTreeWidgetItem(treeitem_##PARENT##_##NAME##);\
tree_widget->setItemWidget(treeitem_##PARENT##_##NAME##_property, 0, ##PARENT##_##NAME##);\
connect(##PARENT##_##NAME##, &property_##NAME##::property_##NAME##_type_signal,component_states_##PARENT##, &component_states::component_states_##NAME##_type_slot);\
connect(component_states_##PARENT##, &component_states::component_states_##NAME##_type_signal,\
scene_entities_common_graph_, &scene_entities_common_graph::scene_entities_common_graph_##PARENT##_##NAME##_type_slot);

#define ADD_LEAF_END(TYPE,PARENT,NAME) PARENT##_##NAME##->send_initialization_data();


