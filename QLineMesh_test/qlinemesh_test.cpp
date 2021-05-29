

#include "qlinemesh_test.h"


qlinemesh_test::qlinemesh_test(QWidget* parent)
	: QWidget(parent)
{
	
	rootEntity = new Qt3DCore::QEntity();
	//

   // // Transform
   // Qt3DCore::QTransform* transform = new Qt3DCore::QTransform;
   // transform->setScale(8.0f);

   // // Custom Mesh (TetraHedron)
   // Qt3DRender::QGeometryRenderer* customMeshRenderer = new Qt3DRender::QGeometryRenderer;
   // Qt3DCore::QGeometry* customGeometry = new Qt3DCore::QGeometry(customMeshRenderer);

   // Qt3DCore::QBuffer* vertexDataBuffer = new Qt3DCore::QBuffer(customGeometry);
   // Qt3DCore::QBuffer* indexDataBuffer = new Qt3DCore::QBuffer( customGeometry);

   // // vec3 for position
   // // vec3 for colors
   // // vec3 for normals

   // /*          2
   //            /|\
   //           / | \
   //          / /3\ \
   //          0/___\ 1
   // */

   // // 4 distinct vertices
   // QByteArray vertexBufferData;
   // vertexBufferData.resize(4 * (3 + 3 + 3) * sizeof(float));

   // // Vertices
   // QVector3D v0(-1.0f, 0.0f, -1.0f);
   // QVector3D v1(1.0f, 0.0f, -1.0f);
   // QVector3D v2(0.0f, 1.0f, 0.0f);
   // QVector3D v3(0.0f, 0.0f, 1.0f);

   // // Faces Normals
   // QVector3D n023 = QVector3D::normal(v0, v2, v3);
   // QVector3D n012 = QVector3D::normal(v0, v1, v2);
   // QVector3D n310 = QVector3D::normal(v3, v1, v0);
   // QVector3D n132 = QVector3D::normal(v1, v3, v2);

   // // Vector Normals
   // QVector3D n0 = QVector3D(n023 + n012 + n310).normalized();
   // QVector3D n1 = QVector3D(n132 + n012 + n310).normalized();
   // QVector3D n2 = QVector3D(n132 + n012 + n023).normalized();
   // QVector3D n3 = QVector3D(n132 + n310 + n023).normalized();

   // // Colors
   // QVector3D red(1.0f, 0.0f, 0.0f);
   // QVector3D green(0.0f, 1.0f, 0.0f);
   // QVector3D blue(0.0f, 0.0f, 1.0f);
   // QVector3D white(1.0f, 1.0f, 1.0f);

   // QVector<QVector3D> vertices = QVector<QVector3D>()
   //     << v0 << n0 << red
   //     << v1 << n1 << blue
   //     << v2 << n2 << green
   //     << v3 << n3 << white;

   // float* rawVertexArray = reinterpret_cast<float*>(vertexBufferData.data());
   // int idx = 0;

   // Q_FOREACH(const QVector3D & v, vertices) {
   //     rawVertexArray[idx++] = v.x();
   //     rawVertexArray[idx++] = v.y();
   //     rawVertexArray[idx++] = v.z();
   // }

   // // Indices (12)
   // QByteArray indexBufferData;
   // indexBufferData.resize(4 * 3 * sizeof(ushort));
   // ushort* rawIndexArray = reinterpret_cast<ushort*>(indexBufferData.data());

   // // Front
   // rawIndexArray[0] = 0;
   // rawIndexArray[1] = 1;
   // rawIndexArray[2] = 2;
   // // Bottom
   // rawIndexArray[3] = 3;
   // rawIndexArray[4] = 1;
   // rawIndexArray[5] = 0;
   // // Left
   // rawIndexArray[6] = 0;
   // rawIndexArray[7] = 2;
   // rawIndexArray[8] = 3;
   // // Right
   // rawIndexArray[9] = 1;
   // rawIndexArray[10] = 3;
   // rawIndexArray[11] = 2;

   // vertexDataBuffer->setData(vertexBufferData);
   // indexDataBuffer->setData(indexBufferData);

   // // Attributes
   // Qt3DCore::QAttribute* positionAttribute = new Qt3DCore::QAttribute();
   // positionAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
   // positionAttribute->setBuffer(vertexDataBuffer);
   // positionAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
   // positionAttribute->setVertexSize(3);
   // positionAttribute->setByteOffset(0);
   // positionAttribute->setByteStride(9 * sizeof(float));
   // positionAttribute->setCount(4);
   // positionAttribute->setName(Qt3DCore::QAttribute::defaultPositionAttributeName());

   // Qt3DCore::QAttribute* normalAttribute = new Qt3DCore::QAttribute();
   // normalAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
   // normalAttribute->setBuffer(vertexDataBuffer);
   // normalAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
   // normalAttribute->setVertexSize(3);
   // normalAttribute->setByteOffset(3 * sizeof(float));
   // normalAttribute->setByteStride(9 * sizeof(float));
   // normalAttribute->setCount(4);
   // normalAttribute->setName(Qt3DCore::QAttribute::defaultNormalAttributeName());

   // Qt3DCore::QAttribute* colorAttribute = new Qt3DCore::QAttribute();
   // colorAttribute->setAttributeType(Qt3DCore::QAttribute::VertexAttribute);
   // colorAttribute->setBuffer(vertexDataBuffer);
   // colorAttribute->setVertexBaseType(Qt3DCore::QAttribute::Float);
   // colorAttribute->setVertexSize(3);
   // colorAttribute->setByteOffset(6 * sizeof(float));
   // colorAttribute->setByteStride(9 * sizeof(float));
   // colorAttribute->setCount(4);
   // colorAttribute->setName(Qt3DCore::QAttribute::defaultColorAttributeName());

   // Qt3DCore::QAttribute* indexAttribute = new Qt3DCore::QAttribute();
   // indexAttribute->setAttributeType(Qt3DCore::QAttribute::IndexAttribute);
   // indexAttribute->setBuffer(indexDataBuffer);
   // indexAttribute->setVertexBaseType(Qt3DCore::QAttribute::UnsignedShort);
   // indexAttribute->setVertexSize(1);
   // indexAttribute->setByteOffset(0);
   // indexAttribute->setByteStride(0);
   // indexAttribute->setCount(12);

   // customGeometry->addAttribute(positionAttribute);
   // customGeometry->addAttribute(normalAttribute);
   // customGeometry->addAttribute(colorAttribute);
   // customGeometry->addAttribute(indexAttribute);

   // customMeshRenderer->setInstanceCount(1);
   // customMeshRenderer->setFirstVertex(0);
   // customMeshRenderer->setFirstInstance(0);
   // customMeshRenderer->setPrimitiveType(Qt3DRender::QGeometryRenderer::Triangles);
   // customMeshRenderer->setGeometry(customGeometry);
   // // 4 faces of 3 points
   //// customMeshRenderer->setPrimitiveCount(12);
//


    auto sphere_material = new Qt3DExtras::QPhongMaterial;
    sphere_material->setDiffuse(QColor(0, 128, 0));
	
	//////////////////////////////////////////////////////////////////////////
	auto line_data = qMakePair(QVector3D(0, 0, 0), QVector3D(3, 0, 3));
	line = new QLineMesh(line_data, rootEntity);
	line->setWidth(0.5f);

	auto sphere_mesh = new Qt3DExtras::QSphereMesh;
	sphere_mesh->setRadius(1.0f);
	sphere_mesh->setRings(20);
	sphere_mesh->setSlices(20);

	Qt3DCore::QEntity* sphere_entity = new Qt3DCore::QEntity(rootEntity);

	sphere_entity->addComponent(line);
	sphere_entity->addComponent(sphere_material);

	view = new Qt3DExtras::Qt3DWindow();
	view->defaultFrameGraph()->setClearColor(QColor(0, 128, 128, 0));

	camera = view->camera();
	camera->setPosition(QVector3D(0, 0, 10.f));
	camera->setViewCenter(QVector3D(0, 0, 0));
    camera->viewAll();

	camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
	camController->setCamera(camera);

	Qt3DCore::QEntity* lightEntity = new Qt3DCore::QEntity(rootEntity);
	Qt3DRender::QPointLight* light = new Qt3DRender::QPointLight(lightEntity);

	light->setColor(QColor(0, 0, 0));
	light->setIntensity(1.f);
	lightEntity->addComponent(light);
	Qt3DCore::QTransform* lightTransform = new Qt3DCore::QTransform(lightEntity);
	lightTransform->setTranslation(camera->position());
	lightEntity->addComponent(lightTransform);

	view->setRootEntity(rootEntity);
	//

	//Add container to show window as widget
	container = createWindowContainer(view, this);
	container->setFixedSize(128, 128);
	container->setFocusPolicy(Qt::TabFocus);
	container->setContentsMargins(0, 0, 0, 0);

	QGridLayout* layout = new QGridLayout;
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(container);

	this->setContentsMargins(1, 1, 1, 1);

	setLayout(layout);
	//
}

qlinemesh_test::~qlinemesh_test()
{
}

void qlinemesh_test::resizeEvent(QResizeEvent* event)
{
	container->setMaximumSize(4096, 4096);
	container->setMinimumSize(128, 128);

	auto value = this->y();
	OutputDebugStringW(LPCWSTR(std::to_wstring(value).c_str()));
	OutputDebugStringW(L" <----- this->y()\n");

	auto value2 = container->y();
	OutputDebugStringW(LPCWSTR(std::to_wstring(value2).c_str()));
	OutputDebugStringW(L" <----- container->y()\n");
}
