#pragma once

#include <QWidget>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qcomponent.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DExtras/qphongmaterial.h>

#include "enums.h"

#include "qlinemesh.h"

#include <tuple>

//cameras environment
#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <Qt3DExtras/qorbitcameracontroller.h>
#include <Qt3DExtras/qabstractcameracontroller.h>

//real world algorithms
#include "../../Real_World_Algorithms/Real_World_Algorithms.h"

//light
#include <Qt3DRender/qpointlight.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DExtras/qspheremesh.h>
// 

//object picker
#include <Qt3DRender/qobjectpicker.h>
#include <Qt3DRender/qpickevent.h>
//

#include <Qt3DExtras/qt3dwindow.h>

/// @brief 3d scene for graphs visualisation entities. Hold all entities use in this scene and cnnection between them and tis scene materials and meshes. 
class scene_entities_common_graph : public QWidget
{
	Q_OBJECT

public:
	/// @brief default constructor
	scene_entities_common_graph(Qt3DCore::QEntity*  root,QWidget *parent = Q_NULLPTR);
	/// @brief default destructor
	~scene_entities_common_graph();

	/// @brief Get root of common graph scene.
	/// @return pointer to this root
	Qt3DCore::QEntity* getRoot();

private:

	Qt3DCore::QEntity* rootEntity;
	Qt3DCore::QEntity* vertexes_root_entity;
	std::vector<QVector3D> vertexes_possitions;
	std::vector<Qt3DCore::QEntity*> vertexes;
	std::vector<Qt3DCore::QEntity*> edges;
	std::vector <std::vector<Qt3DCore::QEntity*>> vertex_vertex_edge;
	Qt3DCore::QEntity* plane;

	Qt3DCore::QComponent* vertex_material;
	Qt3DCore::QComponent* vertex_mesh;
	Qt3DCore::QComponent* edge_material;
	std::vector<QLineMesh*>edge_meshes;
	Qt3DCore::QComponent* plane_material;
	Qt3DCore::QComponent* plane_mesh;
	
	Qt3DRender::QCamera* camera;
	Qt3DRender::QCamera* dummy_camera;
	Qt3DExtras::QAbstractCameraController* camera_controller;

	Qt3DRender::QObjectPicker* picker_scene;

	Qt3DExtras::Qt3DWindow* viewport_;

	Qt3DRender::QAbstractLight* light_;
	Qt3DCore::QEntity* light;
	Qt3DCore::QTransform* transform_light;
	

	void update_edges_possitions(Qt3DCore::QEntity* vertex)
	{
		for (auto& vve : vertex_vertex_edge)
		{
			if (vve[0] == vertex || vve[1] == vertex)
			{
				auto newPossition = std::pair<QVector3D,QVector3D>(vve[0]->componentsOfType<Qt3DCore::QTransform>().front()->translation(),
					vve[1]->componentsOfType<Qt3DCore::QTransform>().front()->translation());
				vve[2]->componentsOfType<QLineMesh>()[0]
					  ->setPossition(newPossition);
			}
		}
	
	};

	inline void re_gen_graph(graph<int>& gr, under_GP& options)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		for (int i = 0; i < gr.V.size(); i++)
		{
			qDebug() << i;
			Qt3DCore::QEntity* vertex = new Qt3DCore::QEntity(vertexes_root_entity);
			vertex->addComponent(vertex_material);
			vertex->addComponent(vertex_mesh);

			Qt3DCore::QTransform* transform = new Qt3DCore::QTransform(vertex);
			QVector3D coord = { float(gr.RAND(10, 90)), float(gr.RAND(10, 90)), 50.f };
			transform->setTranslation(coord);

			vertex->addComponent(transform);

			vertexes.push_back(vertex);
			vertexes_possitions.push_back(coord);
		}

		for (int i = 0; i < gr.E.size(); i++)
		{
			qDebug() << i;
			Qt3DCore::QEntity* edge = new Qt3DCore::QEntity(rootEntity);
			edge->addComponent(edge_material);

			auto first_point = gr.E[i].first;
			auto second_point = gr.E[i].second;

			auto pos = std::pair<QVector3D, QVector3D>(vertexes_possitions[first_point], vertexes_possitions[second_point]);
			qDebug() << "pos = " << pos.first.x() << pos.first.y() << pos.first.z() << " - " << pos.second.x() << pos.second.y() << pos.second.z();
			QLineMesh* line = new QLineMesh(pos, rootEntity);
			
			edge->addComponent(line);

			edges.push_back(edge);

			vertex_vertex_edge.push_back(std::vector<Qt3DCore::QEntity*>({ vertexes[gr.E[i].first],vertexes[gr.E[i].second],edge}));
		}

		qDebug() << Q_FUNC_INFO << " END";
	};


	inline void scene_entities_clear()
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		if (vertexes.size()) {
			for (auto& vertex : vertexes) {

				vertex->removeComponent(vertex_material);
				vertex->removeComponent(vertex_mesh);
				delete vertex;
			}
			vertexes.clear();
		}

		if (edges.size()) {
			for (auto& edge : edges) {

				edge->removeComponent(edge_material);

				delete edge;
			}
			edges.clear();
		}

		if (vertexes_possitions.size())
			vertexes_possitions.clear();

		qDebug() << Q_FUNC_INFO << " END";

	}

public slots:

	void scene_entities_common_graph_light_possition_slot(QVector3D pos)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		transform_light->setTranslation(pos);
	};

	void scene_entities_common_graph_viewport_size_slot(Qt3DExtras::Qt3DWindow* view)
	{
		viewport_ = view;
	};

	void scene_entities_common_graph_camera_slot(Qt3DRender::QCamera* camera_)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! "; 
		camera = camera_;
		//camera->viewAll();
		//qDebug() << camera << "<<<<--- camera scene_entities pointer ";
	}

	/// @brief get the graph with options and construct current scene states for entities their meshes and materials.
	/// @return void
	void scene_entities_common_graph_type_slot(int& type, graph<int>& gr, under_GP& options)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";

		scene_entities_clear();
		re_gen_graph(gr, options);

		qDebug() << Q_FUNC_INFO << " END";
		
	}

	/// @brief recive pointer to changed QComponent with specific entity
	/// @return void
	void scene_entities_common_graph_vertex_material_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		for (auto& vertex : vertexes) {
		vertex->removeComponent(vertex_material);
		vertex->addComponent(component);
		
	}
		vertex_material = component;

	}
	/// @brief recive pointer to changed QComponent with specific entity
	/// @return void
	void scene_entities_common_graph_vertex_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		for (auto& vertex : vertexes) {
			
			vertex->removeComponent(vertex_mesh);
			vertex->addComponent(component);
		}
		vertex_mesh = component;

	}
	/// @brief recive pointer to changed QComponent with specific entity
	/// @return void
	void scene_entities_common_graph_edge_material_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		for (auto& edge : edges) {
			
			edge->removeComponent(edge_material);
			edge->addComponent(component);
			
		}
		edge_material = component;
	
	}
	
	/// @brief recive pointer to changed QComponent with specific entity
	/// @return void
	void scene_entities_common_graph_plane_material_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		plane->removeComponent(plane_material);
		plane->addComponent(component);
		plane_material = component;
	 
	}
	/// @brief recive pointer to changed QComponent with specific entity
	/// @return void
	void scene_entities_common_graph_plane_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		plane->removeComponent(plane_mesh);
		plane->addComponent(component);
		plane_mesh = component;
	}

	/// @brief recive pointer to changed QComponent with specific entity
	/// @return void
	void scene_entities_common_graph_camera_camera_controller_type_slot(Qt3DExtras::QAbstractCameraController* controller)
	{
		if(camera_controller!=Q_NULLPTR)
		camera_controller->setCamera(dummy_camera);
		camera_controller = controller;
		controller->setCamera(camera);

		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		
	}

	/// @brief dummy to prevent changing macrogeneration behaviour
	/// @return void
	void scene_entities_common_graph_camera_camera_type_slot()
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";

	}


	/// @brief dummy to prevent changing macrogeneration behaviour
	/// @return void
	void scene_entities_common_graph_light_light_type_slot(Qt3DRender::QAbstractLight* current)
	{
		qDebug() << Q_FUNC_INFO << " CALLED !!! ";
		light_ = current;
		
		
		for(auto&l:light->componentsOfType<Qt3DRender::QAbstractLight>())
				light->removeComponent(l);
	if(light_!=Q_NULLPTR)
		light->addComponent(light_);

	}
};
