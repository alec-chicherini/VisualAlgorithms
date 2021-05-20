#pragma once

#include <QWidget>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qcomponent.h>
#include <Qt3DCore/qtransform.h>

class scene_entities_common_graph : public QWidget
{
	Q_OBJECT

public:
	scene_entities_common_graph(Qt3DCore::QEntity*  root,QWidget *parent = Q_NULLPTR);
	~scene_entities_common_graph();

	Qt3DCore::QEntity* getRoot();

private:

	Qt3DCore::QEntity* rootEntity;
	Qt3DCore::QEntity* vertex;
	Qt3DCore::QEntity* edge;
	Qt3DCore::QEntity* plane;

	Qt3DCore::QComponent* vertex_material;
	Qt3DCore::QComponent* vertex_mesh;
	Qt3DCore::QComponent* edge_material;
	Qt3DCore::QComponent* edge_mesh;
	Qt3DCore::QComponent* plane_material;
	Qt3DCore::QComponent* plane_mesh;


public slots:

	void scene_entities_common_graph_vertex_material_type_slot(Qt3DCore::QComponent* component)
	{
		vertex->removeComponent(vertex_material);
		vertex->addComponent(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! "; \
	}
	void scene_entities_common_graph_vertex_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		vertex->removeComponent(vertex_mesh);
		vertex->addComponent(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! "; \
	}
	void scene_entities_common_graph_edge_material_type_slot(Qt3DCore::QComponent* component)
	{
		edge->removeComponent(edge_material);
		edge->addComponent(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! "; \
	}
	void scene_entities_common_graph_edge_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		edge->removeComponent(edge_mesh);
		edge->addComponent(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! "; \
	}
	void scene_entities_common_graph_plane_material_type_slot(Qt3DCore::QComponent* component)
	{
		plane->removeComponent(plane_material);
		plane->addComponent(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! "; \
	}
	void scene_entities_common_graph_plane_mesh_type_slot(Qt3DCore::QComponent* component)
	{
		plane->removeComponent(plane_mesh);
		plane->addComponent(component);
		qDebug() << __FUNCSIG__ << " CALLED !!! "; \
	}
};
