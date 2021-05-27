#include "qlinemesh.h"

QLineMesh::QLineMesh(QPair<QVector3D, QVector3D>& pos, Qt3DCore::QNode* root)
	: QGeometryRenderer(root)
{
	geometry = new Qt3DCore::QGeometry(root);

	m_possition = pos;

	m_positionAttribute = new Qt3DCore::QAttribute(geometry);
	m_normalAttribute = new Qt3DCore::QAttribute(geometry);
	m_texCoordAttribute = new Qt3DCore::QAttribute(geometry);
	m_indexAttribute = new Qt3DCore::QAttribute(geometry);

    m_vertexBuffer = new Qt3DCore::QBuffer(geometry);
	m_indexBuffer = new Qt3DCore::QBuffer(geometry);

	m_vertexBuffer->setData(generateVertexData());
	m_indexBuffer->setData(generateIndexData());
	
	m_positionAttribute->setName(Qt3DCore::QAttribute::defaultPositionAttributeName());
	m_positionAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
	m_positionAttribute->setVertexSize(3);
	m_positionAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
	m_positionAttribute->setBuffer(m_vertexBuffer);
	m_positionAttribute->setByteStride(3*sizeof(float));
	m_positionAttribute->setCount(2);

	m_texCoordAttribute->setName(Qt3DCore::QAttribute::defaultTextureCoordinateAttributeName());
	m_texCoordAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
	m_texCoordAttribute->setVertexSize(3);
	m_texCoordAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
	m_texCoordAttribute->setBuffer(m_vertexBuffer);
	m_texCoordAttribute->setByteStride(3 * sizeof(float));
	m_texCoordAttribute->setCount(2);

	m_normalAttribute->setName(Qt3DCore::QAttribute::defaultNormalAttributeName());
	m_normalAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
	m_normalAttribute->setVertexSize(3);
	m_normalAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
	m_normalAttribute->setBuffer(m_vertexBuffer);
	m_normalAttribute->setByteStride(3 * sizeof(float));
	m_normalAttribute->setCount(2);

	m_indexAttribute->setAttributeType(Qt3DCore::QAttribute::IndexAttribute);
	m_indexAttribute->setVertexBaseType(Qt3DCore::QAttribute::UnsignedInt);
	m_indexAttribute->setBuffer(m_indexBuffer);
	m_indexAttribute->setCount(2);

	geometry->addAttribute(m_positionAttribute);
	geometry->addAttribute(m_indexAttribute);
	//geometry->addAttribute(m_normalAttribute);
	//geometry->addAttribute(m_texCoordAttribute);
	
	setGeometry(geometry);

	view = new Qt3DCore::QGeometryView(root);
	view->setGeometry(geometry);
	setView(view);
	setPrimitiveType(Qt3DRender::QGeometryRenderer::Lines);
	setInstanceCount(1);
	setFirstVertex(0);
	setFirstInstance(0);

	
}

QLineMesh::~QLineMesh()
{
}

QByteArray QLineMesh::generateVertexData() const
{
	QByteArray vertex_buf;
	vertex_buf.resize(3 * 2 * sizeof(float));
	float* possitions = reinterpret_cast<float*>(vertex_buf.data());
	*possitions++ = m_possition.first.x();
	*possitions++ = m_possition.first.y();
	*possitions++ = m_possition.first.z();
	*possitions++ = m_possition.second.x();
	*possitions++ = m_possition.second.y();
	*possitions++ = m_possition.second.z();

	return vertex_buf;
};

QByteArray QLineMesh::generateIndexData() const
{
	QByteArray index_buf;
	index_buf.resize(2 * sizeof(unsigned int));
	unsigned int* indeces = reinterpret_cast<unsigned int*>(index_buf.data());
	*indeces++ = 0;
	*indeces++ = 1;

	return index_buf;
}