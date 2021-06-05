#pragma once

#include <Qt3DRender/qgeometryrenderer.h>
#include <tuple>
#include <qvector3d.h>
#include <Qt3DCore/qattribute.h>
#include <Qt3DCore/qgeometry.h>
#include <Qt3DCore/qbuffer.h>
#include <qquaternion.h>



	/// @brief custom mesh for Qt3D - draw looks like line triangular prism
	class QLineMesh : public Qt3DRender::QGeometryRenderer
	{
		Q_OBJECT
			Q_PROPERTY(std::pair<QVector3D,QVector3D> possition MEMBER m_possition READ possition WRITE setPossition NOTIFY possitionChanged)
			Q_PROPERTY(float width MEMBER m_width READ width WRITE setWidth NOTIFY widthChanged)
			
	public:
		std::pair<QVector3D, QVector3D> m_possition;
		float m_width;

		Qt3DCore::QAttribute* m_positionAttribute;
		Qt3DCore::QAttribute* m_normalAttribute;
		Qt3DCore::QAttribute* m_texCoordAttribute;
		Qt3DCore::QAttribute* m_indexAttribute;
		Qt3DCore::QBuffer* m_vertexBuffer;
		Qt3DCore::QBuffer* m_indexBuffer;

		Qt3DCore::QGeometryView* view;
		Qt3DCore::QGeometry* geometry;

		QByteArray vertex_buf;
		QByteArray index_buf;


		/// @brief generate vertexes data to QGeometryRenderer from input
		/// @return void
		inline void generateVertexData();
		
		/// @brief generate indexes data to QGeometryRenderer from input
		/// @return void
		inline void generateIndexData();
	
	signals:
		/// @brief mesh coordinates signal
		void possitionChanged(const std::pair<QVector3D, QVector3D>&);

		/// @brief line mesh width signal
		void widthChanged(const float&);

	public slots:


		/// @brief set new line coordinates
		/// @param pos line coordinates from <first point, second point>
		/// @return void
		void setPossition(std::pair<QVector3D, QVector3D>& pos)
		{
			m_possition = pos;
		    generateVertexData();
			m_vertexBuffer->setData(vertex_buf);
		}
		/// @brief set triangular prism edge width
		/// @param w size of edge
	    /// @return void
		void setWidth(float w)
		{
			m_width = w;
			generateVertexData();
			m_vertexBuffer->setData(vertex_buf);
		}


	public:
		
		/// @brief default constructor
		/// @param pos line coordinates
		/// @param root root entity for this mesh
		explicit QLineMesh(std::pair<QVector3D, QVector3D>& pos, Qt3DCore::QNode* root = Q_NULLPTR);

		/// @param default destructor
		~QLineMesh();

		/// @brief get current possition of line points
		/// @return pair of two QVector3D points
		std::pair<QVector3D, QVector3D> possition() const 
		{
			return m_possition;
		};

		/// @brief get current line width
		/// @return value of width
		float width() const
		{
			return m_width;
		}



	};

