#ifndef TD_MAINWINDOW_H
#define TD_MAINWINDOW_H

#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMainWindow>
#include <QProcess>
#include <QTimer>

#include "mywidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief The MainWindow class provides the main interface for the application.
 *
 * This class handles user interactions, display updates, and manages
 * the underlying data visualization through the MyWidget component.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

 public slots:
  /**
   * @brief Handles keyboard press events.
   *
   * This function overrides the keyPressEvent to capture
   * keyboard inputs for custom functionality.
   *
   * @param[in] event The QKeyEvent object that represents the keyboard event.
   */
  void keyPressEvent(QKeyEvent *event) override;

  /**
   * @brief Slot triggered when a file has been loaded.
   *
   * This slot processes the loaded file and updates the user interface,
   * specifically the number of vertices and segments to be displayed.
   *
   * @param[in] fileName The name of the file that was loaded.
   * @param[in] num_vertices_show The number of vertices to be shown.
   * @param[in] num_segments_show The number of segments to be shown.
   */
  void onFileIsLoaded(const QString &fileName, int num_vertices_show,
                      int num_segments_show);

  // Scaling related slots
  void on_scaleMinusButton_clicked();  ///< Decrements the scaling factor.
  void on_scalePlusButton_clicked();   ///< Increments the scaling factor.

  // Movement related slots
  void on_moveLeftButton_clicked();      ///< Moves the view to the left.
  void on_moveRightButton_clicked();     ///< Moves the view to the right.
  void on_moveUpButton_clicked();        ///< Moves the view upwards.
  void on_moveDownButton_clicked();      ///< Moves the view downwards.
  void on_moveForwardButton_clicked();   ///< Moves the view forward.
  void on_moveBackwardButton_clicked();  ///< Moves the view backward.

  // Rotation related slots
  void on_rotateLeftButton_clicked();       ///< Rotates the view to the left.
  void on_rotateRightButton_clicked();      ///< Rotates the view to the right.
  void on_rotateUpButton_clicked();         ///< Rotates the view upwards.
  void on_rotateDownButton_clicked();       ///< Rotates the view downwards.
  void on_rotateClockwiseButton_clicked();  ///< Rotates the view clockwise.
  void on_rotateCounterclockwiseButton_clicked();  ///< Rotates the view
                                                   ///< counterclockwise.

  // Edge properties slots
  void on_edgesColorButton_clicked();  ///< Opens a dialog to select edge color.
  void on_edgesSolidRadioButton_clicked();   ///< Sets edges to solid style.
  void on_edgesDashedRadioButton_clicked();  ///< Sets edges to dashed style.
  void on_edgesSpinBox_valueChanged();  ///< Updates edge thickness based on
                                        ///< spin box value.

  // Vertex properties slots
  void
  on_verticesColorButton_clicked();  ///< Opens a dialog to select vertex color.
  void on_verticesNoneRadioButton_clicked();  ///< Hides vertex representation.
  void
  on_verticesCircleRadioButton_clicked();  ///< Sets vertices to circular shape.
  void
  on_verticesSquareRadioButton_clicked();  ///< Sets vertices to square shape.
  void on_verticesSpinBox_valueChanged();  ///< Updates vertex size based on
                                           ///< spin box value.

  // Projection mode slots
  void
  on_projectionCentralRadioButton_clicked();  ///< Enables central projection.
  void
  on_projectionParallelRadioButton_clicked();  ///< Enables parallel projection.

  // Background and reset slots
  void on_backgroundColorButton_clicked();  ///< Opens a dialog to select
                                            ///< background color.
  void on_resetButton_clicked();            ///< Resets all settings to default.
  void on_screenshotButton_clicked();       ///< Triggers screenshot capture.
  void on_recordButton_clicked();  ///< Starts recording the current view.

  /**
   * @brief Captures screenshots of the current visualization.
   *
   * This function is responsible for handling the capturing and
   * saving of screenshots.
   */
  void captureScreenshots();

  /**
   * @brief Creates a GIF from the captured screenshots.
   *
   * This function compiles the screenshots into a GIF file format for
   * easy sharing.
   */
  void createGif();

  /**
   * @brief Opens a file dialog to load a file.
   *
   * This function allows the user to select and load a file.
   */
  void on_openButton_clicked();

  /**
   * @brief Sets control values for various UI components.
   *
   * This function initializes the state of UI controls based on
   * current settings or selections.
   */
  void setControlValues();

 public:
  /**
   * @brief Constructor for the MainWindow class
   *
   * This constructor initializes the main form,
   * connects the timer, file upload and option load events
   * to the corresponding methods.
   *
   * @param[in] parent The parent QWidget for this MainWindow.
   */
  MainWindow(QWidget *parent = nullptr);

  /**
   * @brief Destructor for the MainWindow class
   *
   * This destructor saves the program's settings before closing it.
   */
  ~MainWindow();

 private:
  Ui::MainWindow *ui;  ///< Pointer to the UI elements defined in the UI file.
  MyWidget *widget;    ///< Pointer to the MyWidget instance for rendering.
  QTimer *timer;       ///< Timer for periodic updates.
  int image_count;     ///< Counter for the number of images.
  QStringList image_list;  ///< List of image file paths.
};

#endif  // TD_MAINWINDOW_H
