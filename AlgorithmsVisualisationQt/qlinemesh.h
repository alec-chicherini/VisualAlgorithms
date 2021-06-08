#pragma once

#include <QtGlobal>
#include <Qt3DRender/qgeometryrenderer.h>
#include <tuple>
#include <qvector3d.h>
#if QT_VERSION == QT_VERSION_CHECK(6,1,0)
#include <Qt3DCore/qattribute.h>
#include <Qt3DCore/qgeometry.h>
#include <Qt3DCore/qbuffer.h>
using ATTRIBUTE_TYPE = Qt3DCore::QAttribute;
using GEOMETRY_TYPE = Qt3DCore::QGeometry;
using BUFFER_TYPE = Qt3DCore::QBuffer;

#elif QT_VERSION == QT_VERSION_CHECK(5,15,2)
#include <Qt3dRender/qattribute.h>
#include <Qt3dRender/qgeometry.h>
#include <Qt3dRender/qbuffer.h>
using ATTRIBUTE_TYPE = Qt3DRender::QAttribute;
using GEOMETRY_TYPE = Qt3DRender::QGeometry;
using BUFFER_TYPE = Qt3DRender::QBuffer;

#endif


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

		ATTRIBUTE_TYPE* m_positionAttribute;
		ATTRIBUTE_TYPE* m_normalAttribute;
		ATTRIBUTE_TYPE* m_texCoordAttribute;
		ATTRIBUTE_TYPE* m_indexAttribute;
		BUFFER_TYPE* m_vertexBuffer;
		BUFFER_TYPE* m_indexBuffer;

#if QT_VERSION == QT_VERSION_CHECK(6,1,0)
		Qt3DCore::QGeometryView* view;
#endif
		GEOMETRY_TYPE* geometry;

		/// @brief generate vertexes data to QGeometryRenderer from input
		/// @return void
		 QByteArray generateVertexData();
		
		/// @brief generate indexes data to QGeometryRenderer from input
		/// @return void
		 QByteArray generateIndexData();
	
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
		    
			m_vertexBuffer->setData(this->generateVertexData());
		}
		/// @brief set triangular prism edge width
		/// @param w size of edge
	    /// @return void
		void setWidth(float w)
		{
			m_width = w;
			
			m_vertexBuffer->setData(this->generateVertexData());
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

