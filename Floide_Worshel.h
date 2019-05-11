#pragma once

#include <string>
#include <vector>
#include "List.h"

using namespace std;

vector<string> read_file(const string& FILEPATH); //reading data from a file
void getting_cities(string str, List<string>* vertex);  //getting cities and scoring in the list
void make_matrix_bases(unsigned short** matr, size_t v_num); // the creation of the skeleton matrix
void make_matrix(string str, List<string>* vertices, unsigned short** matrix);// matrix of all routes with direct flights
void print_matrix(size_t v_num, unsigned short** matrix); //the output matrix
unsigned short minimal_way(string sity1, string sity2, unsigned short** matrix2, List<std::string>* sities);
unsigned short** find_min_paths(size_t v_num, unsigned short** matrix);  //create a matrix with minimum prices
