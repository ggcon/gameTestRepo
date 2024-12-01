#include "transform.h"

// 회전 행렬 생성 함수
Matrix3x3 createRotationMatrix(float angle) {
    Matrix3x3 matrix = {
        .m = {
            {cos(angle), -sin(angle), 0},
            {sin(angle), cos(angle), 0},
            {0, 0, 1}
        }
    };
    return matrix;
}

// 벡터에 행렬을 적용하는 함수
Vector2 applyTransformation(Vector2 v, Matrix3x3 m) {
    Vector2 result;
    result.x = v.x * m.m[0][0] + v.y * m.m[0][1] + m.m[0][2];
    result.y = v.x * m.m[1][0] + v.y * m.m[1][1] + m.m[1][2];
    return result;
}
