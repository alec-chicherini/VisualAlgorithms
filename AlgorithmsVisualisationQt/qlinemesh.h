#pragma once

#include <Qt3DRender/qgeometryrenderer.h>
#include <qpair.h>
#include <qvector3d.h>
#include <Qt3DCore/qattribute.h>
#include <Qt3DCore/qgeometry.h>
#include <Qt3DCore/qbuffer.h>
#include <qquaternion.h>




	class QLineMesh : public Qt3DRender::QGeometryRenderer
	{
		Q_OBJECT
			//Q_PROPERTY(QPair<QVector3D,QVector3D> possition MEMBER m_possition READ possition WRITE setPossition NOTIFY possitionChanged)
			//Q_PROPERTY(float width MEMBER m_width READ width WRITE setWidth NOTIFY widthChanged)
			
	public:
		QPair<QVector3D, QVector3D> m_possition;
		float m_width;

		Qt3DCore::QAttribute* m_positionAttribute;
		Qt3DCore::QAttribute* m_normalAttribute;
		Qt3DCore::QAttribute* m_texCoordAttribute;
		Qt3DCore::QAttribute* m_indexAttribute;
		Qt3DCore::QBuffer* m_vertexBuffer;
		Qt3DCore::QBuffer* m_indexBuffer;

		Qt3DCore::QGeometryView* view;
		Qt3DCore::QGeometry* geometry;

		Qt3DRender::QGeometryRenderer* line;

		QByteArray* vertex_buf=nullptr;
		QByteArray* index_buf = nullptr;

	private:
		inline void generateVertexData() ;
		inline void generateIndexData() ;

	signals:
		void possitionChanged(const QPair<QVector3D, QVector3D>&);
		void widthChanged(const float&);

	public slots:

		void setPossition(QPair<QVector3D, QVector3D>& pos)
		{
			m_possition = pos;
		    generateVertexData();
			m_vertexBuffer->setData(*vertex_buf);
		}

		void setWidth(float w)
		{
			m_width = w;
			generateVertexData();
			m_vertexBuffer->setData(*vertex_buf);
		}


	public:
		QLineMesh(QPair<QVector3D, QVector3D>& pos, Qt3DCore::QNode* root = Q_NULLPTR);
		~QLineMesh();

		QPair<QVector3D, QVector3D> possition() const 
		{
			return m_possition;
		};

		float width() const
		{
			return m_width;
		}

	};

