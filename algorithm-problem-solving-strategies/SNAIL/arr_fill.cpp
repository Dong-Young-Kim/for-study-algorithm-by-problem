#include <iostream>

int main() {
    const int rows = 3; // 배열의 행 개수
    const int cols = 4; // 배열의 열 개수

    double arr[rows][cols];

    std::cout << "Address of arr:       " << arr << std::endl; // 배열 이름 arr은 첫 번째 행의 시작 주소를 가리킵니다.
    std::cout << "Address of arr[0]:    " << arr[0] << std::endl; // arr[0]은 첫 번째 행의 시작 주소를 가리킵니다.
    std::cout << "Address of arr[0][0]: " << &arr[0][0] << std::endl; // arr[0][0]은 첫 번째 요소의 주소를 가리킵니다.

    // 배열을 -1.5로 초기화
    std::fill_n(&arr[0][0], rows * cols, -1.5);

    // 배열의 내용 출력 (확인용)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    /*
        arr과 &arr[0][0]은 실제 지칭하는 메모리의 위치는 동일하지만
        갖는 의미가 다르다

        arr: arr은 2차원 배열의 이름 자체를 가리키는 포인터이다.
        이는 첫 번째 행의 시작 주소를 가리키는 것과 동일

        arr[0]: arr[0]은 2차원 배열의 첫 번째 행을 가리키는 포인터이다.
        arr[0]은 &arr[0][0]과 동일한 값을 가리키며, 
        이는 첫 번째 요소의 주소를 가리킴
    */

    return 0;
}