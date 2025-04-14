/**
 * @file parser.h
 * @author Team (TL: jaycemar@student.21-school.ru)
 * cainvene@student.21-school.ru
 * jafercav@student.21-school.ru
 * @brief s21 3dvewer parser header
 * @version 1.0
 * @date 2024-09-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef PARSER_H
#define PARSER_H

#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct POINT
 * @brief Represents a point in 3D space.
 *
 * The POINT structure holds the coordinates of a point in a three-dimensional
 * space defined by its x, y, and z coordinates.
 */
typedef struct {
  float x;  ///< The x coordinate of the point.
  float y;  ///< The y coordinate of the point.
  float z;  ///< The z coordinate of the point.
} POINT;

/**
 * @struct MINMAX
 * @brief Represents a 3D bounding box defined by minimum and maximum points.
 *
 * The MINMAX structure defines a bounding box in 3D space using two points:
 * `min` is the point with the minimum coordinates, and `max` is the point with
 * the maximum coordinates. The structure also includes a range attribute which
 * can represent the distance between the min and max points.
 */
typedef struct {
  POINT min;    ///< Point with minimum possible coordinates x, y, z
  POINT max;    ///< Point with maximum possible coordinates x, y, z
  float range;  ///< The maximum range (distance) between the min and max points
                ///< on x, y or x axes.
} MINMAX;

/**
 * @enum step
 * @brief Defines the step size for calculations.
 *
 * A constant integer value used for setting the step size in calculations.
 * This can be used in loop iterations or to define intervals in algorithms.
 */
enum {
  step =
      10  ///< Number of elements for primary and secondary memory allocation.
};

/**
 * @brief Function for loading a 3D model from a file
 *
 * This function parse .obj file and determines
 * the number of vertices and indices, allocates memory for arrays of the
 * required size, and fills the arrays.
 *
 * @param[in] filename file name to open
 * @param[out] vertices pointer to an array with vertex coordinates
 * @param[out] num_vertices number of vertices
 * @param[out] indices pointer to an array with vertex indices
 * @param[out] num_indices number of indices
 */
int load_from_file(const char *filename, float **vertices, int *num_vertices,
                   unsigned **indices, int *num_indices);

/**
 * @brief Function for the first pass through the .obj file
 *
 * This function determines the number of vertices, the minimum and maximum
 * coordinates of the vertices, the maximum range (the difference between the
 * minimum and maximum) along any of the x, y or z axes.
 *
 * @param[in] file pointer to a file
 * @param[out] num_vertices number of indices
 * @return MINMAX struct whith minimum and maximum coordinates of the vertices
 * and range
 */
MINMAX first_reading(FILE *file, int *num_vertices);

/**
 * @brief Function for allocating memory for a temporary array
 *
 * This function allocates memory for a temporary array to store data about
 * vertex indices.
 *
 * @param[in] num_vertices number of indices
 * @return pointer to unsigned ** array
 */
unsigned **matrix_alloc(int *num_vertices);

/**
 * @brief Function for parsing a line with vertex coordinates
 *
 * This function parse a line starting with 'v' reads the coordinates of the
 * vertex and puts it into the points array.
 *
 * @param[out] points pointer to a vertices array
 * @param[in] str line for parsing
 * @param[in] mm struct whith minimum and maximum coordinates of the vertices
 * and range
 * @param[in] vertex_count vertex counter
 */
void read_vertex(POINT **points, char *str, MINMAX mm, int *vertex_count);

/**
 * @brief Function for parsing a line with surface data
 *
 * This function parse a line starting with 'f' reads the indices of the vertex
 * and puts it into the temporary array.
 *
 * @param[out] matrix pointer to a temporary array to store data about vertex
 * indices
 * @param[in] str line for parsing
 * @param[in] num_indices indices counter
 */
void read_surface(unsigned **matrix, char *str, int *num_indices, int num_vertices);

/**
 * @brief Function for adding a segment to a temporary array
 *
 * The function adds a segment to a temporary array without duplication. If
 * necessary, additional memory is allocated for the temporary array.
 *
 * @param[out] matrix pointer to a temporary array to store data about vertex
 * indices
 * @param[in] line pointer to a string in a temporary array, the index of the
 * string coincides with the beginning of the segment
 * @param[in] value index of the vertex that is the end of the segment
 */
void add_segment(unsigned **line, unsigned value);

#endif  // PARSER_H
