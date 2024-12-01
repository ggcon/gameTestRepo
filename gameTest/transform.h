#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <math.h>

#define PI 3.14159265358979323846

// 3x3 행렬 구조체
typedef struct {
    float m[3][3];
} Matrix3x3;

// 2D 벡터 구조체
typedef struct {
    float x, y;
} Vector2;

// 벡터를 행렬로 변환 (회전 행렬 적용)
Vector2 applyTransformation(Vector2 v, Matrix3x3 m);

// 회전 행렬 생성
Matrix3x3 createRotationMatrix(float angle);

#endif // TRANSFORM_H
