#pragma once

#include <string>
#include <vector>
#include "List.h"

using namespace std;

vector<string> read_file(const string& FILEPATH);
void getting_cities(string str, List<string>* vertex);
void make_matrix_bases(unsigned short** matr, size_t v_num);
void make_matrix(string str, List<string>* vertices, unsigned short** matrix);
void print_matrix(size_t v_num, unsigned short** matrix);
unsigned short** find_min_paths(size_t v_num, unsigned short** matrix);  //create minimal paths matrix