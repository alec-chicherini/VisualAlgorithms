#include "qlinemesh.h"

QLineMesh::QLineMesh(std::pair<QVector3D, QVector3D>& pos, Qt3DCore::QNode* root)
	: QGeometryRenderer(root)
{
	qDebug() << "QLineMesh CTOR BEGIN";
	geometry = new GEOMETRY_TYPE(this);

	m_width = 1.0f;

	m_possition = pos;

	m_positionAttribute = new ATTRIBUTE_TYPE(geometry);
	m_normalAttribute = new ATTRIBUTE_TYPE(geometry);
	m_texCoordAttribute = new ATTRIBUTE_TYPE(geometry);
	m_indexAttribute = new ATTRIBUTE_TYPE(geometry);

    m_vertexBuffer = new BUFFER_TYPE(geometry);
	m_indexBuffer = new BUFFER_TYPE(geometry);

	m_vertexBuffer->setData(generateVertexData());

	m_indexBuffer->setData(generateIndexData());
	
	m_positionAttribute->setName(ATTRIBUTE_TYPE::defaultPositionAttributeName());
	m_positionAttribute->setVertexBaseType(ATTRIBUTE_TYPE::Float);
	m_positionAttribute->setVertexSize(3);
	m_positionAttribute->setAttributeType(ATTRIBUTE_TYPE::VertexAttribute);
	m_positionAttribute->setBuffer(m_vertexBuffer);
	m_positionAttribute->setByteStride(6*sizeof(float));
	m_positionAttribute->setByteOffset(0);
	m_positionAttribute->setCount(6);

	//m_texCoordAttribute->setName(ATTRIBUTE_TYPE::defaultTextureCoordinateAttributeName());
	//m_texCoordAttribute->setVertexBaseType(ATTRIBUTE_TYPE::Float);
	//m_texCoordAttribute->setVertexSize(3);
	//m_texCoordAttribute->setAttributeType(ATTRIBUTE_TYPE::VertexAttribute);
	//m_texCoordAttribute->setBuffer(m_vertexBuffer);
	//m_texCoordAttribute->setByteStride(3 * sizeof(float));
	//m_texCoordAttribute->setCount(2);

	m_normalAttribute->setName(ATTRIBUTE_TYPE::defaultNormalAttributeName());
	m_normalAttribute->setVertexBaseType(ATTRIBUTE_TYPE::Float);
	m_normalAttribute->setVertexSize(3);
	m_normalAttribute->setAttributeType(ATTRIBUTE_TYPE::VertexAttribute);
	m_normalAttribute->setBuffer(m_vertexBuffer);
	m_normalAttribute->setByteStride(6 * sizeof(float));
	m_normalAttribute->setByteOffset(3 * sizeof(float));
	m_normalAttribute->setCount(6);

	m_indexAttribute->setAttributeType(ATTRIBUTE_TYPE::IndexAttribute);
	m_indexAttribute->setVertexBaseType(ATTRIBUTE_TYPE::UnsignedShort);
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

#if QT_VERSION == QT_VERSION_CHECK(6,1,0)
	view = new Qt3DCore::QGeometryView(root);
	view->setGeometry(geometry);
	setView(view);
#elif QT_VERSION == QT_VERSION_CHECK(5,15,2)

	setGeometry(geometry);
#endif
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

#if QT_VERSION == QT_VERSION_CHECK(6,1,0)
	delete view;
#endif
	delete geometry;

}


 QByteArray  QLineMesh::generateIndexData()
{
	QByteArray index_buf;
	index_buf.resize(3 * 8 * sizeof(quint16));
	quint16* indeces = reinterpret_cast<quint16*>(index_buf.data());

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

	indeces = nullptr;

	return index_buf;

}

 QByteArray QLineMesh::generateVertexData()
{
	float r = m_width * sqrt(3.f) / 6.f;
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

	QVector3D _v0(A.x(), A.y() + R, A.z());
	QVector3D _v1(A.x() - wd2, A.y() - r, A.z());
	QVector3D _v2(A.x() + wd2, A.y() - r, A.z());
	QVector3D _v3(B.x() + wd2, B.y() - r, B.z());
	QVector3D _v4(B.x() - wd2, B.y() - r, B.z());
	QVector3D _v5(B.x(), B.y() + R, B.z());

	QVector3D B_ = B - A;
	QVector3D A_ = A - B;

	//move to new basis
	QVector3D v0_ = _v0 - A;
	QVector3D v1_ = _v1 - A;
	QVector3D v2_ = _v2 - A;

	QVector3D v3_ = _v3 - B;
	QVector3D v4_ = _v4 - B;
	QVector3D v5_ = _v5 - B;

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
	const QVector3D v0 = v0_ + A;
	const QVector3D v1 = v1_ + A;
	const QVector3D v2 = v2_ + A;
	const QVector3D v3 = v3_ + B;
	const QVector3D v4 = v4_ + B;
	const QVector3D v5 = v5_ + B;

	//face normals
	const QVector3D n021 = QVector3D::normal(v0, v2, v1);
	const QVector3D n014 = QVector3D::normal(v0, v1, v4);
	const QVector3D n045 = QVector3D::normal(v0, v4, v5);
	const QVector3D n435 = QVector3D::normal(v4, v3, v5);
	const QVector3D n052 = QVector3D::normal(v0, v5, v2);
	const QVector3D n253 = QVector3D::normal(v2, v5, v3);
	const QVector3D n123 = QVector3D::normal(v1, v2, v3);
	const QVector3D n134 = QVector3D::normal(v1, v3, v4);

	//vector normals
	const QVector3D n0 = QVector3D(n021 + n014 + n045 + n052).normalized();
	const QVector3D n1 = QVector3D(n021 + n014 + n123 + n134).normalized();
	const QVector3D n2 = QVector3D(n021 + n123 + n253 + n052).normalized();
	const QVector3D n3 = QVector3D(n435 + n253 + n123 + n134).normalized();
	const QVector3D n4 = QVector3D(n435 + n014 + n045 + n134).normalized();
	const QVector3D n5 = QVector3D(n435 + n253 + n045 + n052).normalized();

	const quint32 vertexSize = (3 + 3) * 6 * sizeof(float);

	QByteArray vertex_buf;

	vertex_buf.resize(vertexSize);
	float* possitions = reinterpret_cast<float*>(vertex_buf.data());
	
	*possitions++ = v0.x();
	*possitions++ = v0.y();
	*possitions++ = v0.z();
	*possitions++ = n0.x();
	*possitions++ = n0.y();
	*possitions++ = n0.z();

	*possitions++ = v1.x();
	*possitions++ = v1.y();
	*possitions++ = v1.z();
	*possitions++ = n1.x();
	*possitions++ = n1.y();
	*possitions++ = n1.z();

	*possitions++ = v2.x();
	*possitions++ = v2.y();
	*possitions++ = v2.z();
	*possitions++ = n2.x();
	*possitions++ = n2.y();
	*possitions++ = n2.z();

	*possitions++ = v3.x();
	*possitions++ = v3.y();
	*possitions++ = v3.z();
	*possitions++ = n3.x();
	*possitions++ = n3.y();
	*possitions++ = n3.z();

	*possitions++ = v4.x();
	*possitions++ = v4.y();
	*possitions++ = v4.z();
	*possitions++ = n4.x();
	*possitions++ = n4.y();
	*possitions++ = n4.z();

	*possitions++ = v5.x();
	*possitions++ = v5.y();
	*possitions++ = v5.z();
	*possitions++ = n5.x();
	*possitions++ = n5.y();
	*possitions++ = n5.z();
	possitions = nullptr;


	return vertex_buf;

};

