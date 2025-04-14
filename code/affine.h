/**
 * @file affine.h
 * @author Team (TL: jaycemar@student.21-school.ru)
 * cainvene@student.21-school.ru
 * jafercav@student.21-school.ru
 * @brief s21 3dvewer affine header
 * @version 1.0
 * @date 2024-09-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef AFFINE_H
#define AFFINE_H

#include <math.h>

/**
 * @brief Function for moving an object along the X axis
 *
 * This function changes the coordinates along the X axis by the value
 * of the coefficient k.
 *
 * @param[in] vertices_v_arr pointer to an array with vertex coordinates
 * @param[in] vertices_v_count number of vertices
 * @param[in] k coefficient for changes
 */
void move_X(float* vertices_v_arr, int vertices_v_count, float k);

/**
 * @brief Function for moving an object along the Y axis
 *
 * This function changes the coordinates along the Y axis by the value
 * of the coefficient k.
 *
 * @param[in] vertices_v_arr pointer to an array with vertex coordinates
 * @param[in] vertices_v_count number of vertices
 * @param[in] k coefficient for changes
 */
void move_Y(float* vertices_v_arr, int vertices_v_count, float k);

/**
 * @brief Function for moving an object along the Z axis
 *
 * This function changes the coordinates along the Z axis by the value
 * of the coefficient k.
 *
 * @param[in] vertices_v_arr pointer to an array with vertex coordinates
 * @param[in] vertices_v_count number of vertices
 * @param[in] k coefficient for changes
 */
void move_Z(float* vertices_v_arr, int vertices_v_count, float k);

/**
 * @brief Function for scaling an object
 *
 * The function changes the scale of the object by a given factor.
 *
 * @param[in] vertices_v_arr pointer to an array with vertex coordinates
 * @param[in] vertices_v_count number of vertices
 * @param[in] k scale factor
 */
void scale_M(float* vertices_v_arr, int vertices_v_count, float k);

/**
 * @brief Function to rotate an object around the X axis
 *
 * This function changes the Y and Z coordinates taking into account the
 * rotation of the object around the X axis by a given angle
 *
 * @param[in] vertices_v_arr pointer to an array with vertex coordinates
 * @param[in] vertices_v_count number of vertices
 * @param[in] angle rotation angle in degrees
 */
void rotate_X(float* vertices_v_arr, int vertices_v_count, float angle);

/**
 * @brief Function to rotate an object around the Y axis
 *
 * This function changes the X and Z coordinates taking into account the
 * rotation of the object around the Y axis by a given angle
 *
 * @param[in] vertices_v_arr pointer to an array with vertex coordinates
 * @param[in] vertices_v_count number of vertices
 * @param[in] angle rotation angle in degrees
 */
void rotate_Y(float* vertices_v_arr, int vertices_v_count, float angle);

/**
 * @brief Function to rotate an object around the Z axis
 *
 * This function changes the X and Y coordinates taking into account the
 * rotation of the object around the Z axis by a given angle
 *
 * @param[in] vertices_v_arr pointer to an array with vertex coordinates
 * @param[in] vertices_v_count number of vertices
 * @param[in] angle rotation angle in degrees
 */
void rotate_Z(float* vertices_v_arr, int vertices_v_count, float angle);

#endif  // AFFINE_H