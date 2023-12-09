#include<iostream>
#include<fstream>
#include"Stack.h"
#include"Stack.cpp"
using namespace std;

int main() {
	Stack<int> obj(100);
	//for (int i = 0; i < 22; i++) {
	//	obj.push(i);
	//}
	//obj.display();
	//obj.pop();
	//cout << endl << "After poping top is: " << endl;
	//obj.display();
	fstream file;
	bool flag = true;
	int a, b, c, d, e;
	file.open("in.txt", ios::in);
	file >> a;
	file >> b;
	file >> c;
	file >> d;
	file >> e;
	int** matrix = new int* [a];
	for (int i = 0; i < a; i++) {
		matrix[i] = new int[a];
	}
	while (!file.eof()) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				file >> matrix[i][j];
			}
		}
	}
	file.close();
	cout << "MATRIX IS: " << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int i = b;
	int j = c;
	while (i != d || j!= e) {
		if (j<a-1&&matrix[i][j + 1] == 0) {
						//obj.push((char)40);//(i,j)
						obj.push(i);
						//obj.push((char)44);
						obj.push(j);
						//obj.push((char)41);
						matrix[i][j] = 2;// if track is found then it will replace the value with 2 so that we have been trought this coordinate.
						j = j + 1;
		}
		else if(i < a - 1 && matrix[i+1][j] == 0) {
			obj.push(i);
			obj.push(j);
			matrix[i][j] = 2;
			i = i + 1;
		}
		else if (i > 0 && matrix[i -1][j] == 0) {
			obj.push(i);
			obj.push(j);
			matrix[i][j] = 2;
			i = i - 1;
		}
		else if (j > 0 && matrix[i][j - 1] == 0) {
			obj.push(i);
			obj.push(j);
			matrix[i][j] = 2;
			j = j - 1;
		}
		else {
			matrix[i][j] = 1; // while poping it will replace the index with 1 for retracking that at this index we aready have visited
			if (!obj.isEmpty()){
				j = obj.Top();
				obj.pop();
				i = obj.Top();
				obj.pop();
			}
			else{
					flag = false;
					break;
			}
		}
	}
	// if dead end appears then else part will run showing ended values replaced by 1 otherwise correct path. 
	if (flag){
		obj.push(i);
		obj.push(j);
		matrix[i][j] = 2;
		cout << "MATRIX IS: " << endl;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		cout << "Dead end\n";
		cout << "MATRIX IS: " << endl;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	Stack<int> temp(100);

	while (!obj.isEmpty())
	{
		temp.push(obj.Top());
		obj.pop();
	}
	// writting data in output file.
	fstream out;
	out.open("out.txt", ios::out);
	out << "--------------------------------------------Track is----------------------------------------" << endl;
	out << a << endl;
	out << b << " " << c << endl;
	out << d << " " << e << endl;
	while (!temp.isEmpty())
	{
		i = temp.Top();
		temp.pop();
		j = temp.Top();
		temp.pop();
		out << "(" << i << "," << j << ")" << "  ";
	}
	out.close();
}