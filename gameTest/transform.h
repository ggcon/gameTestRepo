#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <math.h>

#define PI 3.14159265358979323846

// 3x3 ��� ����ü
typedef struct {
    float m[3][3];
} Matrix3x3;

// 2D ���� ����ü
typedef struct {
    float x, y;
} Vector2;

// ���͸� ��ķ� ��ȯ (ȸ�� ��� ����)
Vector2 applyTransformation(Vector2 v, Matrix3x3 m);

// ȸ�� ��� ����
Matrix3x3 createRotationMatrix(float angle);

#endif // TRANSFORM_H
