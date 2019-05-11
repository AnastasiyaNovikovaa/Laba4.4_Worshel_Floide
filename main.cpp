#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "List.h"
#include "Floide_Worshel.h"
using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	cout << "Добрый день!\n";
	cout << "Лабораторная работа по теме. Алгоритм Флойда-Уоршелла\n";
	cout << "Работу выполнила Новикова Анастасия, гр.7302\n";
	cout << endl;
	vector<string> strings_for_reading;
	auto* cities = new List<string>;  //graph vertex
	unsigned short** matrix_all_itinerary;  // matrix of all paths
	unsigned short** min_itenerary;  //minimum path matrix

	strings_for_reading = read_file("Input.txt"); //read data from file

	for (int i = 0; i < strings_for_reading.size(); i++) {
		getting_cities(strings_for_reading[i], cities);  //Getting all cities
	}
	
	cout << endl << "Список всех городов: ";
	cout << cities;
	size_t  num = cities->get_size();
	cout << "Количество считанных городов:" << num << "\n";
	matrix_all_itinerary = new unsigned short* [cities->get_size()]; 
	
	make_matrix_bases(matrix_all_itinerary, cities->get_size());//matrix of all paths

	for (int i = 0; i < strings_for_reading.size(); i++) {
		make_matrix(strings_for_reading[i], cities, matrix_all_itinerary);
	}

	cout << endl << "Таблица всех маршрутов с ценами на перелет " << endl;
	print_matrix(cities->get_size(), matrix_all_itinerary);
	cout << endl;

	
	cout << "********************************************************************************\n";

	min_itenerary = find_min_paths(cities->get_size(), matrix_all_itinerary);
	cout << endl << "Таблица маршрутов между городами с указанием наименьшей стоимости: " << endl;
	print_matrix(cities->get_size(), min_itenerary);
	cout << endl;
	string city1;
	string city2;
	cout << "Введите первый город ";
	cin >> city1;
	cout << endl;
	cout << "Введите второй город ";
	cin >> city2;
	cout << endl;

	cout << "Кратчайшее расстояние между городом " << city1 << " и городом " << city2 << "=";
	unsigned short minimal_way_ = minimal_way(city1, city2,  min_itenerary, cities);
	std::cout << minimal_way_;
	cout << endl;
	cout << "Спасибо за внимание! До свидания!\n";
	cout << "********************************************************************************\n";
	
}
