#pragma once

#include <QWidget>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qcomponent.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DExtras/qphongmaterial.h>

#include "enums.h"

#include "qlinemesh.h"

#include "qpair.h"

//real world algorithms
#include "../Real_World_Algorithms/Real_World_Algorithms.h"

class scene_entities_common_graph : public QWidget
{
	Q_OBJECT

public:
	scene_entities_common_graph(Qt3DCore::QEntity*  root,QWidget *parent = Q_NULLPTR);
	~scene_entities_common_graph();

	Qt3DCore::QEntity* getRoot();

private:

	Qt3DCore::QEntity* rootEntity;

	std::vector<QVector3D> vertexes_possitions;
	std::vector<Qt3DCore::QEntity*> vertexes;
	std::vector<Qt3DCore::QEntity*> edges;
	Qt3DCore::QEntity* plane;

	Qt3DCore::QComponent* vertex_material;
	Qt3DCore::QComponent* vertex_mesh;
	Qt3DCore::QComponent* edge_material;
	std::vector<QLineMesh*>edge_meshes;
	Qt3DCore::QComponent* plane_material;
	Qt3DCore::QComponent* plane_mesh;



public slots:

	void scene_entities_common_graph_type_slot(int type, graph<int> gr, under_GP options)
	{
		qDebug() << __FUNCSIG__ << " CALLED !!! ";

		if (vertexes.size()) {
			for (auto vertex : vertexes) {

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
		

		for (int i = 0; i < gr.V.size(); i++)
		{
			Qt3DCore::QEntity* vertex = new Qt3DCore::QEntity(rootEntity);
			vertex->addComponent(vertex_material);
			vertex->addComponent(vertex_mesh);
			
			Qt3DCore::QTransform* transform = new Qt3DCore::QTransform();
			QVector3D coord = { float(gr.RAND(10, 90)), float(gr.RAND(10, 90)), 50.f};:
			transform->setTranslation(coord);
			
			vertex->addComponent(transform);

			vertexes.push_back(vertex);
			vertexes_possitions.push_back(coord);
			
		}

		for (int i = 0; i < gr.E.size(); i++)
		{
			Qt3DCore::QEntity* edge = new Qt3DCore::QEntity(rootEntity);
			edge->addComponent(edge_material);

			auto pos = qMakePair(vertexes_possitions[gr.E[i].first], vertexes_possitions[gr.E[i].second]);
			qDebug() <<"pos = "<< pos.first.x() << pos.first.y() << pos.first.z() << " - " << pos.second.x() << pos.second.y() << pos.second.z();
			QLineMesh* line = new QLineMesh(pos, edge);
			//line->setWidth(0.05f);
			edge->addComponent(line);

			edges.push_back(edge);

		}

		qDebug() << "Adding entities to edges END";
		
	}

	void scene_entities_common_graph_vertex_material_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
		for (auto& vertex : vertexes) {
		vertex->removeComponent(vertex_material);
		vertex->addComponent(component);
		
	}
		vertex_material = component;

	}
	void scene_entities_common_graph_vertex_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
		for (auto& vertex : vertexes) {
			
			vertex->removeComponent(vertex_mesh);
			vertex->addComponent(component);
		}
		vertex_mesh = component;

	}
	void scene_entities_common_graph_edge_material_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
		for (auto& edge : edges) {
			
			edge->removeComponent(edge_material);
			edge->addComponent(component);
			
		}
		edge_material = component;
	
	}
	
	void scene_entities_common_graph_plane_material_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
		plane->removeComponent(plane_material);
		plane->addComponent(component);
		plane_material = component;
	 
	}
	void scene_entities_common_graph_plane_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		qDebug() << __FUNCSIG__ << " CALLED !!! ";
		plane->removeComponent(plane_mesh);
		plane->addComponent(component);
		plane_mesh = component;

		
	}
};
