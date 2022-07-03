#include <iostream>
int main() {
	int x, y, sum, max = 0; std::cin >> x >> y;
	int* arr = (int*)malloc(sizeof(int) * x);
	for (int i = 0; i < x; i++)
		std::cin >> *(arr + i);

	for (int i = 0; i < x - 2; i++)
		for (int j = i + 1; j < x - 1; j++)
			for (int k = j + 1; k < x; k++) {
				sum = *(arr + i) + *(arr + j) + *(arr + k);
				if (sum > max && sum <= y) max = sum;
			}
	std::cout << max;
}