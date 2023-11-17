#include <iostream>
int main()
{
    int a, b ,T;
    char c;
    std::cin >> T;
    while(T--)
    {
        std::cin >> a >> c >> b;
        std::cout << a + b << "\n";
    }
}

// comma로 구분되어진 input을 받을 때는 char 변수를 선언하고 ,를 처리하는 식으로 작성한다.