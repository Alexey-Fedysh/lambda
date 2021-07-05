#include <iostream>
#include <vector>
#include <functional>

template<typename T>
T SearchElem(const std::vector<T> vect, T key, std::function<bool(T a, T b)>predic) {
	for (size_t i = 0; i < vect.size(); i++){
		if (predic(vect[i], key)) {
			return vect[i];
		}
	}
	return 0;
}

template <typename T1>
void SortElem(std::vector<T1> &vect, std::function<bool(T1 a, T1 b)> predic) {
	for (size_t i = 0; i < vect.size() - 1; i++) {
		for (size_t j = i; j < vect.size() - 1; j++) {
			if (predic(vect[i], vect[j + 1])) {
				std::swap(vect[i], vect[j + 1]);
			}
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	std::vector<int> vect;
	for (size_t i = 0; i < 25; i++){
		vect.push_back(rand() % 50);
	}
	for (auto itr : vect) {
		std::cout << itr << " ";
	}
	std::cout << std::endl;
	SortElem<int>(vect, [](int a, int b) {return a > b; });
	for (auto itr : vect) {
		std::cout << itr << " ";
	}
	std::cout << std::endl;

	std::cout << "Search = " << SearchElem<int>(vect, 8, [](int a, int b) {return a == b; }) << std::endl;
}