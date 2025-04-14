#include "mywidget.h"

MyWidget::MyWidget(QWidget* parent)
    : QOpenGLWidget(parent),
      vertices(nullptr),
      indices(nullptr),
      num_vertices(0),
      num_indices(0) {}

MyWidget::~MyWidget() {
  if (vertices) {
    free(vertices);
    vertices = NULL;
  }

  if (indices) {
    free(indices);
    indices = NULL;
  }
}

void MyWidget::initializeGL() {
  resetSettings();
  loadSettings();
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void MyWidget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void MyWidget::paintGL() {
  glClearColor(background_color.redF(), background_color.greenF(),
               background_color.blueF(), 1.0f);
  fillingOutMatrices();
  drawObject();
}
void MyWidget::fillingOutMatrices() {
  cameraMatrix.setToIdentity();
  projectionMatrix.setToIdentity();

  if (projection_type == Central) {
    projectionMatrix.perspective(45.0f, width() / float(height()), 0.01f,
                                 100.0f);
    cameraMatrix.translate(0, 0, -5);
  } else {
    float top = 1.0f, bottom = -top, ratio = width() / float(height()),
          right = top * ratio, left = -right;
    int k = 2;
    cameraMatrix.ortho(left * k, right * k, bottom * k, top * k, -100.0f,
                       100.0f);
  }

  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(projectionMatrix.constData());
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixf(cameraMatrix.constData());
}
void MyWidget::drawObject() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);

  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1, edges_display_method);

  glColor3f(vertices_color.redF(), vertices_color.greenF(),
            vertices_color.blueF());
  glPointSize(vertices_size);

  if (vertices_display_method == Circle) {
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glDrawArrays(GL_POINTS, 0, num_vertices);
    glDisable(GL_PROGRAM_POINT_SIZE);
    glDisable(GL_POINT_SMOOTH);
  } else if (vertices_display_method == Square) {
    glDrawArrays(GL_POINTS, 0, num_vertices);
  }

  glColor3f(edges_color.redF(), edges_color.greenF(), edges_color.blueF());
  glLineWidth(edges_thickness);
  glDrawElements(GL_LINES, num_indices, GL_UNSIGNED_INT, indices);

  glDisableClientState(GL_VERTEX_ARRAY);
  glFlush();
}

void MyWidget::fileLoad(const QString& fileName) {
  QByteArray byteArray = fileName.toUtf8();
  const char* cFileName = byteArray.constData();

  if (vertices) {
    free(vertices);
    vertices = NULL;
  }

  if (indices) {
    free(indices);
    indices = NULL;
  }

  int err_load = load_from_file(cFileName, &vertices, &num_vertices, &indices,
                                &num_indices);
  if (vertices && indices && !err_load) {
    emit fileIsLoaded(fileName, num_vertices, num_indices / 2);
    update();
  }
}

void MyWidget::setVerticesDisplayMethod(VerticesDisplayMethod newMethod) {
  vertices_display_method = newMethod;
  update();
}
void MyWidget::setEdgesDisplayMethod(EdgesDisplayMetod newMethod) {
  edges_display_method = newMethod;
  update();
}

void MyWidget::setVerticesSize(int newValue) {
  if (newValue < 1) {
    newValue = 1;
  }
  if (newValue > 50) {
    newValue = 50;
  }

  vertices_size = newValue;
  update();
}
void MyWidget::setEdgesThickness(int newValue) {
  if (newValue < 1) {
    newValue = 1;
  }
  if (newValue > 8) {
    newValue = 8;
  }

  edges_thickness = newValue;
  update();
}

void MyWidget::setProjectionType(ProjectionType newType) {
  projection_type = newType;
  update();
}
void MyWidget::affine(func_ptr c_function, float value) {
  c_function(vertices, num_vertices, value);
  update();
}

void MyWidget::loadSettings() {
  QSettings settings("Viewer_jjc", "C8_3DViewer_v1.0");
  background_color =
      settings.value("background_color", background_color).value<QColor>();
  vertices_color =
      settings.value("vertices_color", vertices_color).value<QColor>();
  edges_color = settings.value("edges_color", edges_color).value<QColor>();
  vertices_display_method = static_cast<VerticesDisplayMethod>(
      settings.value("vertices_display_method", vertices_display_method)
          .toInt());
  edges_display_method = static_cast<EdgesDisplayMetod>(
      settings.value("edges_display_method", edges_display_method).toInt());
  projection_type = static_cast<ProjectionType>(
      settings.value("projection_type", projection_type).toInt());
  move_step = settings.value("move_step", move_step).toFloat();
  rotate_step = settings.value("rotate_step", rotate_step).toInt();
  edges_thickness = settings.value("edges_thickness", edges_thickness).toInt();
  vertices_size = settings.value("vertices_size", vertices_size).toInt();
  emit settingsIsLoaded();
}
void MyWidget::saveSettings() {
  QSettings settings("Viewer_jjc", "C8_3DViewer_v1.0");
  settings.setValue("background_color", background_color);
  settings.setValue("vertices_color", vertices_color);
  settings.setValue("edges_color", edges_color);
  settings.setValue("vertices_display_method", vertices_display_method);
  settings.setValue("edges_display_method", edges_display_method);
  settings.setValue("projection_type", projection_type);
  settings.setValue("move_step", move_step);
  settings.setValue("rotate_step", rotate_step);
  settings.setValue("edges_thickness", edges_thickness);
  settings.setValue("vertices_size", vertices_size);
}
void MyWidget::resetSettings() {
  background_color = Qt::black;  // QColor(0, 0, 0);
  vertices_color = QColor(0, 128, 255);
  edges_color = Qt::white;  // QColor(255, 255, 255)
  vertices_size = 5;
  vertices_display_method = None;
  edges_display_method = Solid;
  edges_thickness = 1;
  projection_type = Parallel;
  scale_value = 1.0f;
  rotate_step = 5;
  move_step = 0.1f;
}
