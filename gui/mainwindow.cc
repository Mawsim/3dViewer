#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  widget = ui->widget;
  timer = new QTimer(this);
  image_count = 0;
  connect(timer, &QTimer::timeout, this, &MainWindow::captureScreenshots);
  connect(widget, &MyWidget::fileIsLoaded, this, &MainWindow::onFileIsLoaded);
  connect(widget, &MyWidget::settingsIsLoaded, this,
          &MainWindow::setControlValues);
}
MainWindow::~MainWindow() {
  widget->setMoveStep(ui->moveSpinBox->value());
  widget->setRotateStep(ui->rotateSpinBox->value());
  widget->saveSettings();
  delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Escape) {
    QApplication::quit();
  } else if (event->key() == Qt::Key_Enter) {
    if (ui->scaleSpinBox->hasFocus())
      widget->affine(scale_M, ui->scaleSpinBox->value());
  } else {
    QMainWindow::keyPressEvent(event);
  }
}
void MainWindow::onFileIsLoaded(const QString &fileName, int numVertices,
                                int numEdges) {
  QFileInfo fileInfo(fileName);
  ui->fileNameLabel->setText(QString("File: %1").arg(fileInfo.fileName()));
  ui->numVerticesLabel->setText(QString("Vertices: %1").arg(numVertices));
  ui->numEdgesLabel->setText(QString("Edges: %1").arg(numEdges));
}

void MainWindow::on_scaleMinusButton_clicked() {
  widget->affine(scale_M, 0.9f);
}
void MainWindow::on_scalePlusButton_clicked() { widget->affine(scale_M, 1.1f); }
void MainWindow::on_moveLeftButton_clicked() {
  widget->affine(move_X, ui->moveSpinBox->value() * -1);
}
void MainWindow::on_moveRightButton_clicked() {
  widget->affine(move_X, ui->moveSpinBox->value());
}
void MainWindow::on_moveUpButton_clicked() {
  widget->affine(move_Y, ui->moveSpinBox->value());
}
void MainWindow::on_moveDownButton_clicked() {
  widget->affine(move_Y, ui->moveSpinBox->value() * -1);
}
void MainWindow::on_moveForwardButton_clicked() {
  widget->affine(move_Z, ui->moveSpinBox->value());
}
void MainWindow::on_moveBackwardButton_clicked() {
  widget->affine(move_Z, ui->moveSpinBox->value() * -1);
}
void MainWindow::on_rotateLeftButton_clicked() {
  widget->affine(rotate_Y, ui->rotateSpinBox->value() * -1);
}
void MainWindow::on_rotateRightButton_clicked() {
  widget->affine(rotate_Y, ui->rotateSpinBox->value());
}
void MainWindow::on_rotateUpButton_clicked() {
  widget->affine(rotate_X, ui->rotateSpinBox->value());
}
void MainWindow::on_rotateDownButton_clicked() {
  widget->affine(rotate_X, ui->rotateSpinBox->value() * -1);
}
void MainWindow::on_rotateClockwiseButton_clicked() {
  widget->affine(rotate_Z, ui->rotateSpinBox->value());
}
void MainWindow::on_rotateCounterclockwiseButton_clicked() {
  widget->affine(rotate_Z, ui->rotateSpinBox->value() * -1);
}

void MainWindow::on_edgesColorButton_clicked() {
  QColor oldColor = widget->getEdgesColor();
  QColor newColor =
      QColorDialog::getColor(oldColor, this, tr("Select Edges Color"));

  if (newColor.isValid()) {
    widget->setEdgesColor(newColor);
    widget->update();
  }
}
void MainWindow::on_edgesSolidRadioButton_clicked() {
  widget->setEdgesDisplayMethod(MyWidget::Solid);
}
void MainWindow::on_edgesDashedRadioButton_clicked() {
  widget->setEdgesDisplayMethod(MyWidget::Dashed);
}
void MainWindow::on_edgesSpinBox_valueChanged() {
  widget->setEdgesThickness(ui->edgesSpinBox->value());
  widget->update();
}

void MainWindow::on_verticesColorButton_clicked() {
  QColor oldColor = widget->getVerticesColor();
  QColor newColor =
      QColorDialog::getColor(oldColor, this, tr("Select Vertices Color"));

  if (newColor.isValid()) {
    widget->setVerticesColor(newColor);
    widget->update();
  }
}
void MainWindow::on_verticesNoneRadioButton_clicked() {
  widget->setVerticesDisplayMethod(MyWidget::None);
}
void MainWindow::on_verticesCircleRadioButton_clicked() {
  widget->setVerticesDisplayMethod(MyWidget::Circle);
}
void MainWindow::on_verticesSquareRadioButton_clicked() {
  widget->setVerticesDisplayMethod(MyWidget::Square);
}
void MainWindow::on_verticesSpinBox_valueChanged() {
  widget->setVerticesSize(ui->verticesSpinBox->value());
  widget->update();
}

void MainWindow::on_projectionCentralRadioButton_clicked() {
  widget->setProjectionType(MyWidget::Central);
}
void MainWindow::on_projectionParallelRadioButton_clicked() {
  widget->setProjectionType(MyWidget::Parallel);
}

void MainWindow::on_backgroundColorButton_clicked() {
  QColor oldColor = widget->getBackgroundColor();
  QColor newColor =
      QColorDialog::getColor(oldColor, this, tr("Select Background Color"));

  if (newColor.isValid()) {
    widget->setBackgroundColor(newColor);
    widget->update();
  }
}
void MainWindow::on_resetButton_clicked() {
  widget->resetSettings();
  widget->update();
  setControlValues();
}
void MainWindow::on_screenshotButton_clicked() {
  QImage image = widget->grabFramebuffer();
  QString filter = "Image Files (*.bmp *.jpg *.jpeg);;All Files (*)";
  QString fileName =
      QFileDialog::getSaveFileName(this, tr("Save Screenshot"), "", filter);

  if (!fileName.isEmpty()) {
    QFileInfo fileInfo(fileName);
    QString fileExtension = fileInfo.suffix().toLower();
    if (fileExtension == "bmp") {
      image.save(fileName, "BMP");
    } else if (fileExtension == "jpg" || fileExtension == "jpeg") {
      image.save(fileName, "JPEG", 90);
    }
  }
}
void MainWindow::on_recordButton_clicked() {
  if (!timer->isActive()) {
    image_count = 0;
    timer->start(100);
  }
}
void MainWindow::captureScreenshots() {
  QImage image = widget->grabFramebuffer();
  QImage scaledImage = image.scaled(640, 480, Qt::KeepAspectRatio);

  QString fileName = QString::number(image_count++) + ".png";
  if (scaledImage.save(fileName)) {
    image_list << fileName;
  } else {
    qDebug() << "Failed to save file:" << fileName;
  }

  if (image_count > 49) createGif();
}
void MainWindow::createGif() {
  timer->stop();

  QString fileFilter = "GIF Files (*.gif);;All Files (*)";
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save gif-animation "), "", fileFilter);

  if (!fileName.isEmpty()) {
    if (!fileName.endsWith(".gif", Qt::CaseInsensitive)) fileName += ".gif";
    QProcess process;
    QString program = "convert";
    QStringList arguments;
    arguments << "-delay"
              << "10" << image_list << fileName;
    process.start(program, arguments);

    if (!process.waitForStarted())
      qDebug() << "Failed to start process:" << process.errorString();

    process.waitForFinished();

    QString errorOutput = process.readAllStandardError();
    if (errorOutput.isEmpty()) {
      qDebug() << "Created:" << fileName;
    } else {
      qDebug() << "Error:" << errorOutput;
    }
  }

  for (const QString &filename : image_list) QFile::remove(filename);
}
void MainWindow::on_openButton_clicked() {
  QString fileFilter = "Model Files (*.obj);;All Files (*)";
  QString fileName =
      QFileDialog::getOpenFileName(this, tr("Load Model File"), "", fileFilter);

  if (!fileName.isEmpty()) widget->fileLoad(fileName);
}
void MainWindow::setControlValues() {
  if (widget->getProjectionType() == MyWidget::Central)
    ui->projectionCentralRadioButton->setChecked(true);
  else
    ui->projectionParallelRadioButton->setChecked(true);

  if (widget->getVerticesDisplayMethod() == MyWidget::Circle) {
    ui->verticesCircleRadioButton->setChecked(true);
  } else if (widget->getVerticesDisplayMethod() == MyWidget::Square) {
    ui->verticesSquareRadioButton->setChecked(true);
  } else {
    ui->verticesNoneRadioButton->setChecked(true);
  }

  if (widget->getEdgesDisplayMethod() == MyWidget::Solid)
    ui->edgesSolidRadioButton->setChecked(true);
  else
    ui->edgesDashedRadioButton->setChecked(true);

  ui->scaleSpinBox->setValue(widget->getScaleValue());
  ui->moveSpinBox->setValue(widget->getMoveStep());
  ui->rotateSpinBox->setValue(widget->getRotateStep());
  ui->verticesSpinBox->setValue(widget->getVerticesSize());
  ui->edgesSpinBox->setValue(widget->getEdgesThickness());
}