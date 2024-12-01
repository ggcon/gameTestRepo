#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define NUM_POINTS 100  // 원을 그리기 위한 점의 개수

// 2D 벡터 구조체 정의
typedef struct {
    float x, y;
} Vector2;

// 3x3 행렬 구조체 정의
typedef struct {
    float m[3][3];
} Matrix3x3;

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

int main() {
    Vector2 points[NUM_POINTS];
    float radius = 10.0f; // 원의 반지름

    // 원의 각 점을 (x, y) 좌표로 설정
    for (int i = 0; i < NUM_POINTS; ++i) {
        float angle = (i * 2 * PI) / NUM_POINTS; // 각도를 계산
        points[i].x = radius * cos(angle);
        points[i].y = radius * sin(angle);
    }

    // 원을 회전시키기 위한 회전 각도 (30도)
    float rotationAngle = 30.0f * (PI / 180.0f);  // 라디안으로 변환
    Matrix3x3 rotationMatrix = createRotationMatrix(rotationAngle);

    // 회전된 원의 점들 출력
    printf("원 회전 결과:\n");
    for (int i = 0; i < NUM_POINTS; ++i) {
        Vector2 rotatedPoint = applyTransformation(points[i], rotationMatrix);
        printf("(%f, %f)\n", rotatedPoint.x, rotatedPoint.y);
    }

    return 0;
}
