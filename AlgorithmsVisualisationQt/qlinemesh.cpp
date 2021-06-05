#include "qlinemesh.h"

QLineMesh::QLineMesh(std::pair<QVector3D, QVector3D>& pos, Qt3DCore::QNode* root)
	: QGeometryRenderer(root)
{
	qDebug() << "QLineMesh CTOR BEGIN";
	geometry = new Qt3DCore::QGeometry(this);

	m_width = 1.0f;

	m_possition = pos;

	m_positionAttribute = new Qt3DCore::QAttribute(geometry);
	m_normalAttribute = new Qt3DCore::QAttribute(geometry);
	m_texCoordAttribute = new Qt3DCore::QAttribute(geometry);
	m_indexAttribute = new Qt3DCore::QAttribute(geometry);

    m_vertexBuffer = new Qt3DCore::QBuffer(geometry);
	m_indexBuffer = new Qt3DCore::QBuffer(geometry);

	generateVertexData();
	m_vertexBuffer->setData(vertex_buf);

	generateIndexData();
	m_indexBuffer->setData(index_buf);
	
	m_positionAttribute->setName(Qt3DCore::QAttribute::defaultPositionAttributeName());
	m_positionAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
	m_positionAttribute->setVertexSize(3);
	m_positionAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
	m_positionAttribute->setBuffer(m_vertexBuffer);
	m_positionAttribute->setByteStride(6*sizeof(float));
	m_positionAttribute->setByteOffset(0);
	m_positionAttribute->setCount(6);

	//m_texCoordAttribute->setName(Qt3DCore::QAttribute::defaultTextureCoordinateAttributeName());
	//m_texCoordAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
	//m_texCoordAttribute->setVertexSize(3);
	//m_texCoordAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
	//m_texCoordAttribute->setBuffer(m_vertexBuffer);
	//m_texCoordAttribute->setByteStride(3 * sizeof(float));
	//m_texCoordAttribute->setCount(2);

	m_normalAttribute->setName(Qt3DCore::QAttribute::defaultNormalAttributeName());
	m_normalAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
	m_normalAttribute->setVertexSize(3);
	m_normalAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
	m_normalAttribute->setBuffer(m_vertexBuffer);
	m_normalAttribute->setByteStride(6 * sizeof(float));
	m_normalAttribute->setByteOffset(3 * sizeof(float));
	m_normalAttribute->setCount(6);

	m_indexAttribute->setAttributeType(Qt3DCore::QAttribute::IndexAttribute);
	m_indexAttribute->setVertexBaseType(Qt3DCore::QAttribute::UnsignedShort);
	m_indexAttribute->setBuffer(m_indexBuffer);
	m_indexAttribute->setByteOffset(0);
	m_indexAttribute->setByteStride(0);
	m_indexAttribute->setVertexSize(1);
	m_indexAttribute->setCount(24);

	geometry->addAttribute(m_positionAttribute);
	geometry->addAttribute(m_indexAttribute);
	geometry->addAttribute(m_normalAttribute);
	//geometry->addAttribute(m_texCoordAttribute);

	setInstanceCount(1);
	setFirstVertex(0);
	setFirstInstance(0);
	setPrimitiveType(Qt3DRender::QGeometryRenderer::Triangles);
	setGeometry(geometry);

	view = new Qt3DCore::QGeometryView(root);
	view->setGeometry(geometry);
	setView(view);
	qDebug() << "QLineMesh CTOR END";
}


QLineMesh::~QLineMesh()
{
	delete m_positionAttribute;
	delete m_normalAttribute;
	delete m_texCoordAttribute;
	delete m_indexAttribute;
	delete m_vertexBuffer;
	delete m_indexBuffer;

	delete view;
	delete geometry;

}


inline void QLineMesh::generateIndexData()
{
	index_buf.clear();
	index_buf.resize(3 * 8 * sizeof(ushort));
	ushort* indeces = reinterpret_cast<ushort*>(index_buf.data());

	//021
	*indeces++ = 0;
	*indeces++ = 2;
	*indeces++ = 1;

	//014
	*indeces++ = 0;
	*indeces++ = 1;
	*indeces++ = 4;

	//045
	*indeces++ = 0;
	*indeces++ = 4;
	*indeces++ = 5;

	//435
	*indeces++ = 4;
	*indeces++ = 3;
	*indeces++ = 5;

	//052
	*indeces++ = 0;
	*indeces++ = 5;
	*indeces++ = 2;

	//253
	*indeces++ = 2;
	*indeces++ = 5;
	*indeces++ = 3;

	//123
	*indeces++ = 1;
	*indeces++ = 2;
	*indeces++ = 3;

	//134
	*indeces++ = 1;
	*indeces++ = 3;
	*indeces++ = 4;

}

inline void QLineMesh::generateVertexData()
{
	float r = m_width * qSqrt<float>(3.f) / 6.f;
	float R = r * 2.f;
	float wd2 = m_width / 2.f;
	/*
	  m_possition.first is center of 0-1-2, m_possition.second is center of 3-4-5.

		  1 ________________________________4
		   |\                              /|
		   | \                            / |
		   |  \                          /  |
		   |  0\________________________/5  |
		   |   /                        \   |
		   |  /                          \  |
		   | /                            \ |
		  2|/______________________________\|3

		*/
		//vertexes coord of mesh
	QVector3D A = m_possition.first;
	QVector3D B = m_possition.second;

	QVector3D v0(A.x(), A.y() + R, A.z());
	QVector3D v1(A.x() - wd2, A.y() - r, A.z());
	QVector3D v2(A.x() + wd2, A.y() - r, A.z());
	QVector3D v3(B.x() + wd2, B.y() - r, B.z());
	QVector3D v4(B.x() - wd2, B.y() - r, B.z());
	QVector3D v5(B.x(), B.y() + R, B.z());

	QVector3D B_ = B - A;
	QVector3D A_ = A - B;

	//move to new basis
	QVector3D v0_ = v0 - A;
	QVector3D v1_ = v1 - A;
	QVector3D v2_ = v2 - A;

	QVector3D v3_ = v3 - B;
	QVector3D v4_ = v4 - B;
	QVector3D v5_ = v5 - B;

	QVector3D normalA = QVector3D::normal(v0_, v1_, v2_);
	QVector3D normalB = QVector3D::normal(v3_, v4_, v5_);

	QQuaternion qRotationA = QQuaternion::rotationTo(normalA, B_);
	QQuaternion qRotationB = QQuaternion::rotationTo(normalB, A_);

	v0_ = qRotationA.rotatedVector(v0_);
	v1_ = qRotationA.rotatedVector(v1_);
	v2_ = qRotationA.rotatedVector(v2_);

	v3_ = qRotationB.rotatedVector(v3_);
	v4_ = qRotationB.rotatedVector(v4_);
	v5_ = qRotationB.rotatedVector(v5_);

	//after rotation move to old basis
	v0 = v0_ + A;
	v1 = v1_ + A;
	v2 = v2_ + A;
	v3 = v3_ + B;
	v4 = v4_ + B;
	v5 = v5_ + B;

	//face normals
	QVector3D n021 = QVector3D::normal(v0, v2, v1);
	QVector3D n014 = QVector3D::normal(v0, v1, v4);
	QVector3D n045 = QVector3D::normal(v0, v4, v5);
	QVector3D n435 = QVector3D::normal(v4, v3, v5);
	QVector3D n052 = QVector3D::normal(v0, v5, v2);
	QVector3D n253 = QVector3D::normal(v2, v5, v3);
	QVector3D n123 = QVector3D::normal(v1, v2, v3);
	QVector3D n134 = QVector3D::normal(v1, v3, v4);

	//vector normals
	QVector3D n0 = QVector3D(n021 + n014 + n045 + n052).normalized();
	QVector3D n1 = QVector3D(n021 + n014 + n123 + n134).normalized();
	QVector3D n2 = QVector3D(n021 + n123 + n253 + n052).normalized();
	QVector3D n3 = QVector3D(n435 + n253 + n123 + n134).normalized();
	QVector3D n4 = QVector3D(n435 + n014 + n045 + n134).normalized();
	QVector3D n5 = QVector3D(n435 + n253 + n045 + n052).normalized();

	QVector<QVector3D> vertices = QVector<QVector3D>() <<
		v0 << n0 <<
		v1 << n1 <<
		v2 << n2 <<
		v3 << n3 <<
		v4 << n4 <<
		v5 << n5;

	vertex_buf.clear();
	
	vertex_buf.resize((3 + 3) * 6 * sizeof(float));
	float* possitions = reinterpret_cast<float*>(vertex_buf.data());
	int index = 0;

	for (auto& v : vertices)
	{
		possitions[index++] = v.x();
		possitions[index++] = v.y();
		possitions[index++] = v.z();
	}

};

