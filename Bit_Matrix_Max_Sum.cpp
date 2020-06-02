#include <iostream>
#include <cmath>

using namespace std;

class Matrix {
private:
	int matrix[4][4] = {
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 }
	};
public:
	void toggle_row() {
		for (int i = 0; i < 4; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 0; j < 4; j++) {
					if (matrix[i][j] == 0) {
						matrix[i][j] = 1;
					}
					else if (matrix[i][j] == 1) {
						matrix[i][j] = 0;
					}
				}
			}
		}
	}
	void toggle_col() {
		int count_1 = 0;
		int count_0 = 0;
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 4; i++) {
					if (matrix[i][j] == 0) {
						count_0 += 1;
					}
					else if (matrix[i][j] == 1) {
						count_1 += 1;
					}
				}
				if (count_0 > count_1) {
			
					for (int i = 0; i < 4; i++) {
						if (matrix[i][j] == 0) {
							matrix[i][j] = 1;
						}
						else if (matrix[i][j] == 1) {
							matrix[i][j] = 0;
						}
					}
				}
				count_1 = 0;
				count_0 = 0;
			}

	}
	void print_matrix() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
	void sum() {
		int sum = 0;
		int num = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				num = matrix[i][j];
				sum = sum + (num * pow(2, (3 - j)));
			}
			
		}
		cout << sum << endl;
	}
};


int main() {

	Matrix obj;
	cout << "Original sum: ";
	obj.sum();
	cout << endl;
	
	obj.toggle_row();
	obj.toggle_col();
	
	cout << "Matrix after changes: " << endl;
	obj.print_matrix();
	cout << endl;
	
	cout << "Max sum: ";
	obj.sum();
	cout << endl;

	
	return 0;
}
