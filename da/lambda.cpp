#include <iostream>
#include <vector>
#include <functional>

class Point {
public:
	Point() {
		x = rand() % 10;
		y = rand() % 10;
	}
	friend std::ostream& operator<< (std::ostream& out, const Point& point) {
		out << " x =  " << point.x << " | y = " << point.y << std::endl;
		return out;
	}
	bool operator ==(const Point& other)const {
		return (x == other.x && y == other.y);
	}
	bool operator>(Point other) {
		return x > other.x;
	}
	int getX()const{
		return x;
	}
	int getY()const {
		return y;
	}
private:
	int x;
	int y;
};

template<typename T>
bool SearchElem(const std::vector<T> vect, T key, std::function<bool(T a, T b)>predic) {
	for (size_t i = 0; i < vect.size(); i++){
		if (predic(vect[i], key)) {
			return true;
		}
	}
	return false;
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
	std::vector<Point> pointVector;
	std::vector<int> vect;

	/*for (size_t i = 0; i < 25; i++){
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

	std::cout << "Search = " << SearchElem<int>(vect, 8, [](int a, int b) {return a == b; }) << std::endl;*/

	for (size_t i = 0; i < 5; i++) {
		pointVector.push_back(Point());
	}

	for (auto itr : pointVector) {
		std::cout<< " x = " << itr.getX() << " | y = " << itr.getY() << std::endl;
	}

	std::cout << std::endl << "======================================" << std::endl;
	SortElem<Point>(pointVector, [](Point a, Point b) {return a > b; });
	for (auto itr : pointVector) {
		std::cout << " x = " << itr.getX() << " | y = " << itr.getY() <<std::endl;
	}

	Point randPoint;
	std::cout << "Search random point" << randPoint << std::endl;
	std::cout << "Search = " <<
		SearchElem<Point>(pointVector, randPoint , [](Point a, Point b) {return a == b; })
		<< std::endl;
}