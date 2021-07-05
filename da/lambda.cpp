#include <iostream>
#include <vector>
#include <functional>


int SearchElem(const std::vector<int> vect, int key, std::function<bool(int a, int b)>predic) {
	for (size_t i = 0; i < vect.size(); i++){
		if (predic(vect[i], key)) {
			return vect[i];
		}
	}
	return 0;
}

void SortElem(std::vector<int> &vect, std::function<bool(int a, int b)> predic) {
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
	SortElem(vect, [](int a, int b) {return a > b; });
	for (auto itr : vect) {
		std::cout << itr << " ";
	}
	std::cout << std::endl;

	std::cout << "Search = " << SearchElem(vect, 8, [](int a, int b) {return a == b; }) << std::endl;
}