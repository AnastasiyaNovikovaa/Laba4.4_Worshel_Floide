#pragma once

#include <string>
#include <vector>
#include "List.h"

using namespace std;

vector<string> read_file(const string& FILEPATH); //считывание данных из файла
void getting_cities(string str, List<string>* vertex);  //получение городов и забивка в список
void make_matrix_bases(unsigned short** matr, size_t v_num); // создание скелета матрицы
void make_matrix(string str, List<string>* vertices, unsigned short** matrix);// матрица всех путей с прямыми перелетами
void print_matrix(size_t v_num, unsigned short** matrix); //вывод матрицы
unsigned short minimal_way(string sity1, string sity2, unsigned short** matrix2, List<std::string>* sities);
unsigned short** find_min_paths(size_t v_num, unsigned short** matrix);  //создание матрицы с минимальными ценами
