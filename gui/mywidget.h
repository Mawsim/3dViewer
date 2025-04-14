#ifndef TD_MYWIDGET_H
#define TD_MYWIDGET_H

#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QString>

#ifdef __cplusplus
extern "C" {
#endif
#include "../code/affine.h"
#include "../code/parser.h"
#ifdef __cplusplus
}
#endif

/**
 * @class MyWidget
 * @brief The MyWidget class renders the 3D model
 *
 * This class draws a 3D model of an object using data loaded from an .obj file.
 */
class MyWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  /**
   * @brief Constructor for the MyWidget class
   *
   * This constructor initializes the OpenGL widget.
   *
   * @param[in] parent The parent QWidget for this MyWidget.
   */
  explicit MyWidget(QWidget* parent = nullptr);

  /**
   * @brief Destructor for the MyWidget class
   *
   * This destructor frees memory allocated for vertex and index arrays.
   */
  ~MyWidget();

  /**
   * @brief Function for loading a model from a file
   *
   * This function configures transformation matrices depending on the
   * installed projection type (Central or Parallel).
   */
  void fillingOutMatrices();

  /**
   * @brief Model drawing function
   *
   * This function draws a model of an object using the
   * coordinates of points from an array of vertices and
   * using data on vertex indices to display faces.
   */
  void drawObject();

  /**
   * @brief Function for loading a model from a file
   *
   * This function opens the model file and loads the data into the program.
   *
   * @param[in] fileName Name of the file to be opened.
   */
  void fileLoad(const QString& fileName);

  /**
   * @enum VerticesDisplayMethod
   * @brief Methods of displaying vertices.
   *
   * The enumeration defines various methods for displaying the vertices of a
   * graph.
   */
  enum VerticesDisplayMethod {
    None,    ///< don't draw vertices = 0
    Circle,  ///< draw vertices as circle = 1
    Square   ///< draw vertices as square = 2
  };

  /**
   * @enum EdgesDisplayMetod
   * @brief Methods of displaying edges.
   *
   * The enumeration defines various methods for displaying the edges of a
   * graph.
   */
  enum EdgesDisplayMetod {
    Solid = 0xFFFF,  ///< draw edges with a solid line = 0xFFFF
    Dashed = 0x00FF  ///< draw edges with a dotted line = 0x00FF
  };

  /**
   * @enum ProjectionType
   * @brief Specifies the type of projection used for rendering a model.
   *
   * This enumeration defines the different projection types available for use
   * in the rendering process.
   */
  enum ProjectionType {
    Parallel,  ///< draw a model in parallel projection = 0
    Central    ///< draw a model in central projection = 1
  };

  /**
   * @brief Function to get background color
   *
   * This function returns the current background color.
   *
   * @return Сurrent background color
   */
  QColor getBackgroundColor() const { return background_color; }

  /**
   * @brief Function to get edges color
   *
   * This function returns the current edges color.
   *
   * @return Сurrent edges color
   */
  QColor getEdgesColor() const { return edges_color; }

  /**
   * @brief Function to get vertices color
   *
   * This function returns the current vertices color.
   *
   * @return Сurrent vertices color
   */
  QColor getVerticesColor() const { return vertices_color; }

  /**
   * @brief Function to set background color
   *
   * This function sets the new background color.
   *
   * @param[in] newColor New background color
   */
  void setBackgroundColor(const QColor& newColor) {
    background_color = newColor;
  }

  /**
   * @brief Function to set edges color
   *
   * This function sets the new edges color.
   *
   * @param[in] newColor New edges color
   */
  void setEdgesColor(const QColor& newColor) { edges_color = newColor; };

  /**
   * @brief Function to set vertices color
   *
   * This function sets the new vertices color.
   *
   * @param[in] newColor New vertices color
   */
  void setVerticesColor(const QColor& newColor) { vertices_color = newColor; };

  /**
   * @brief Function to get vertices display method
   *
   * This function returns the current vertices display method.
   *
   * @return Сurrent vertices display method
   */
  VerticesDisplayMethod getVerticesDisplayMethod() const {
    return vertices_display_method;
  }

  /**
   * @brief Function to set vertices display method
   *
   * This function sets the new vertices display method.
   *
   * @param[in] newMethod New vertices display method
   */
  void setVerticesDisplayMethod(VerticesDisplayMethod newMethod);

  /**
   * @brief Function to get size of the vertices
   *
   * This function returns the current size of the vertices to draw.
   *
   * @return Сurrent size of the vertices
   */
  int getVerticesSize() const { return vertices_size; }

  /**
   * @brief Function to set size of the vertices
   *
   * This function sets the new size of the vertices.
   *
   * @param[in] newValue New size of the vertices
   */
  void setVerticesSize(int newValue);

  /**
   * @brief Function to get edges display method
   *
   * This function returns the current edges display method.
   *
   * @return Сurrent edges display method
   */
  EdgesDisplayMetod getEdgesDisplayMethod() const {
    return edges_display_method;
  }

  /**
   * @brief Function to set edges display method
   *
   * This function sets the new edges display method.
   *
   * @param[in] newMethod New edges display method
   */
  void setEdgesDisplayMethod(EdgesDisplayMetod newMethod);

  /**
   * @brief Function to get edges thickness
   *
   * This function returns the current edges thickness.
   *
   * @return Сurrent edges thickness
   */
  int getEdgesThickness() const { return edges_thickness; }

  /**
   * @brief Function to set edges thickness
   *
   * This function sets the new edges thickness.
   *
   * @param[in] newValue New edges thickness
   */
  void setEdgesThickness(int newValue);

  /**
   * @brief Function to get projection type
   *
   * This function returns the current projection type.
   *
   * @return Сurrent projection type
   */
  ProjectionType getProjectionType() const { return projection_type; }

  /**
   * @brief Function to set projection type
   *
   * This function sets the new projection type.
   *
   * @param[in] newType New projection type
   */
  void setProjectionType(ProjectionType newType);

  /**
   * @brief Pointer to an affine transformation function.
   *
   * This function takes three arguments:
   * - a pointer to an array of type float (data for transformation)
   * - an integer (size of the array)
   * - a float value (transformation parameter)
   *
   * @param[in] float* pointer to the data array
   * @param[in] int size of the array or number of elements
   * @param[in] float transformation value
   */
  using func_ptr = void (*)(float*, int, float);

  /**
   * @brief Function for calling the affine transformation function
   *
   * This function calls affine transformation functions on the model's
   * vertex coordinate array.
   *
   * @param[in] c_function Pointer to an affine transformation function
   * @param[in] value Coefficient for the affine transformation function
   */
  void affine(func_ptr c_function, float value);

  /**
   * @brief Function to get scale factor
   *
   * This function returns the current scale factor.
   *
   * @return Сurrent scale factor
   */
  float getScaleValue() const { return scale_value; }

  /**
   * @brief Function to get rotate step
   *
   * This function returns the current rotate step.
   *
   * @return Сurrent rotate step
   */
  int getRotateStep() const { return rotate_step; }

  /**
   * @brief Function to set rotate step
   *
   * This function sets the new rotate step.
   *
   * @param[in] newValue New rotate step
   */
  void setRotateStep(int newValue) { rotate_step = newValue; }

  /**
   * @brief Function to get move step
   *
   * This function returns the current move step.
   *
   * @return Сurrent move step
   */
  float getMoveStep() const { return move_step; }

  /**
   * @brief Function to set move step
   *
   * This function sets the new move step.
   *
   * @param[in] newValue New move step
   */
  void setMoveStep(float newValue) { move_step = newValue; }

  /**
   * @brief Function for downloading settings
   *
   * This function loads previously saved program settings.
   */
  void loadSettings();

  /**
   * @brief Function for saving settings
   *
   * This feature saves settings between program launches.
   */
  void saveSettings();

  /**
   * @brief Reset function
   *
   * This function sets the settings to default values.
   */
  void resetSettings();

 signals:
  /**
   * @brief Signal emitted when a file is successfully loaded
   *
   * This signal provides the filename along with the counts of vertices
   * and segments that were shown.
   *
   * @param[in] fileName Name of the loaded file
   * @param[in] num_vertices_show Count of vertices displayed
   * @param[in] num_segments_show Count of segments displayed
   */
  void fileIsLoaded(const QString& fileName, int num_vertices_show,
                    int num_segments_show);

  /**
   * @brief Signal emitted when settings are successfully loaded
   *
   * This signal indicates that the settings have been restored from storage.
   */
  void settingsIsLoaded();

 protected:
  /**
   * @brief Initializes OpenGL settings
   *
   * This overridden function sets up the necessary OpenGL context parameters.
   */
  void initializeGL() override;

  /**
   * @brief Resizes the OpenGL viewport
   *
   * This overridden function adjusts the OpenGL viewport based on the new
   * window dimensions.
   *
   * @param[in] w New width of the OpenGL widget
   * @param[in] h New height of the OpenGL widget
   */
  void resizeGL(int w, int h) override;

  /**
   * @brief Renders the OpenGL scene
   *
   * This overridden function is called to update and paint the OpenGL scene.
   */
  void paintGL() override;

 private:
  float* vertices;    ///< Pointer to the vertex coordinates
  unsigned* indices;  ///< Pointer to the index array for vertex connectivity
  int num_vertices;   ///< Total number of vertices
  int num_indices;    ///< Total number of indices
  QString file_name;  ///< Currently loaded model file name
  QColor background_color;  ///< Current background color
  QColor vertices_color;    ///< Current color for displaying vertices
  QColor edges_color;       ///< Current color for displaying edges
  VerticesDisplayMethod
      vertices_display_method;  ///< Current method to display vertices
  EdgesDisplayMetod edges_display_method;  ///< Current method to display edges
  ProjectionType projection_type;          ///< Currently used projection type
  QMatrix4x4 projectionMatrix;  ///< Matrix for projection transformations
  QMatrix4x4 cameraMatrix;      ///< Matrix for camera transformations
  float scale_value;            ///< Current scale factor
  float move_step;              ///< Current move step value
  int rotate_step;              ///< Current rotation step value
  int edges_thickness;          ///< Thickness of edges
  int vertices_size;            ///< Size of displayed vertices
};

#endif  // TD_MYWIDGET_H
