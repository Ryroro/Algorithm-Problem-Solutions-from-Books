#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
struct Matrix {
	char name;
	int row;
	int column;
};

struct matrix_pair {
	int row;
	int column;
};

int main()
{
	char c;
	int a,b;
	map<char, Matrix> matrix_map;
	while (cin >> c && c != 'q') {
		cin >> a >> b;
		Matrix temp;
		temp.name = c;
		temp.row = a;
		temp.column = b;
		matrix_map[c] = temp;
	}
	list <matrix_pair> stack;
	int sum = 0;
	cout << "input expression" << endl;
	while (cin >> c) {
		if (c != ')' && c != '(') {
			matrix_pair p1;
			p1.row = matrix_map[c].row;
			p1.column = matrix_map[c].column;
			stack.push_back(p1);
		}
		if (c == ')') {
			matrix_pair d = stack.back();
			stack.pop_back();
			matrix_pair e = stack.back();
			stack.pop_back();
			if (e.column == d.row) {
				matrix_pair p2;
				p2.row = e.row;
				p2.column = d.column;
				stack.push_back(p2);
				sum += e.row*e.column*d.column;
			}
		}
	}
	cout << sum << endl;
	return 0;
}

			
