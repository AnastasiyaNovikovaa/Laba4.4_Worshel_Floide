#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "List.h"
#include "Floide_Worshel.h"
using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	cout << "������ ����!\n";
	cout << "������������ ������ �� ����. �������� ������-��������\n";
	cout << "������ ��������� �������� ���������, ��.7302\n";
	cout << endl;
	vector<string> strings_for_reading;
	auto* cities = new List<string>;  //������� �����
	unsigned short** matrix_all_itinerary;  // ������� ���� �����
	unsigned short** min_itenerary;  //������� ����������� �����

	strings_for_reading = read_file("Input.txt"); //��������� ������ �� �����

	for (int i = 0; i < strings_for_reading.size(); i++) {
		getting_cities(strings_for_reading[i], cities);  //��������� ���� �������
	}
	
	cout << endl << "������ ���� �������: ";
	cout << cities;
	size_t  num = cities->get_size();
	cout << "���������� ��������� �������:" << num << "\n";
	matrix_all_itinerary = new unsigned short* [cities->get_size()]; 
	
	make_matrix_bases(matrix_all_itinerary, cities->get_size());//������� ���� �����

	for (int i = 0; i < strings_for_reading.size(); i++) {
		make_matrix(strings_for_reading[i], cities, matrix_all_itinerary);
	}

	cout << endl << "������� ���� ��������� � ������ �� ������� " << endl;
	print_matrix(cities->get_size(), matrix_all_itinerary);
	cout << endl;
	cout << "********************************************************************************\n";

	min_itenerary = find_min_paths(cities->get_size(), matrix_all_itinerary);
	cout << endl << "������� ��������� ����� �������� � ��������� ���������� ���������: " << endl;
	print_matrix(cities->get_size(), min_itenerary);
	cout << "������� �� ��������! �� ��������!\n";
	cout << "********************************************************************************\n";
	
}