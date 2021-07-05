#include <iostream>
#include <vector>
#include <functional>


int SearchElem(std::vector<int> vect, int key, std::function<bool(int a, int b)>predic) {
	for (size_t i = 0; i < vect.size(); i++){
		if (predic(vect[i], key)) {
			return vect[i];
		}
	}
	return 0;
}


bool isEqual(int a, int b) {
	return a == b;
}

int main() {
	std::vector<int> vect;
	for (size_t i = 0; i < 10; i++){
		vect.push_back(i);
	}
	
	std::cout << SearchElem(vect, 3, [](int a, int b) {return a == b; }) << std::endl;
}