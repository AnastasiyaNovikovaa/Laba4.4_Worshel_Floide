#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include "Floide_Worshel.h"
using namespace std;
#pragma once

vector<string> read_file(const string& file)// ������ ����� �� ������
{
	
	vector<string> strings;    //������� ������ �����
	fstream input_file(file);
	
    if (input_file.is_open())  //���� ���� ��� ������,���������
	{
		while (!input_file.eof()) {
			string line;
			getline(input_file, line);
			if (!line.empty())
				strings.push_back(line);
		}
	}
	else
		throw runtime_error("Sorry, do not open file");
	input_file.close();
	return strings;
}


void make_matrix(string str, List<string>* vertices, unsigned short** matrix) 
{
	short flag = 0;
	unsigned short city_1, city_2;
	string v_name = "";  //�������� �������
	string weight = "";   //��� ����� ����� ���������
	for (int i = 0; i < str.size() + 1; i++)
	{
		if (flag == 0) //���������� ������ �����
		{
			if (str[i] != ';')
				v_name += str[i];  //��������� ����������� �������� ������, ��� ������ ��������� �������,���������� ��� city_1
			else {
				city_1 = vertices->find(v_name);
				flag++;
				v_name = "";
			}
		}
		else if (flag == 1) //���������� ������ ����� 
		{
			if (str[i] != ';')
				v_name += str[i];
			else {
				city_2 = vertices->find(v_name);//���������� ������ ������
				flag++;
			}
		}
		else if (flag == 2) 
		{
			if (str[i] != ';')//���� ����
				weight += str[i];
			else {
				if (weight != "N/A")
					matrix[city_1][city_2] =stoi(weight);//���������� ���, �������������� ������ � �����
				flag++;
				weight = "";
			}
		}
		else {
			if (str[i] != '\0')
				weight += str[i];//���� �����
			else {
				if (weight != "N/A")
					matrix[city_2][city_1] = stoi(weight);
			}
		}
	}
}
void getting_cities(string str, List <string> *cities)  //���������� ������ �� ��������� ������
{  
	//������ � ������
	
	string name_of_cities = "";   //�������� ������
	short flag = 0;
	unsigned i = 0;
	while (flag < 2) {
		if (str[i] != ';')
			name_of_cities += str[i];
		else {
			flag++;
			if (!cities->is_in(name_of_cities))//���� ����� �������� ���,��������� � ������
			{
				cities->push_back(name_of_cities);
			}
			name_of_cities = "";
		}
		i++;
	}
}
unsigned short** find_min_paths(size_t v_num, unsigned short** matrix) {
	//������ ����� ������� ���������
	unsigned short** min_paths = new unsigned short* [v_num];
	for (int i = 0; i < v_num; i++)
		min_paths[i] = new unsigned short[v_num];
	for (int i = 0; i < v_num; i++) {
		for (int j = 0; j < v_num; j++)
			min_paths[i][j] = matrix[i][j];
	}


	for (int k = 1; k < v_num; k++) {
		for (int i = 0; i < v_num; i++) {
			for (int j = 0; j < v_num; j++) {
				if (((min_paths[i][k] + min_paths[k][j]) < min_paths[i][j]) && (i != j))
					min_paths[i][j] = min_paths[i][k] + min_paths[k][j];
			}
		}
	}
	return min_paths;
}
void print_matrix(size_t v_num, unsigned short** matrix) {
	for (int i = 0; i < v_num; i++) {
		for (int j = 0; j < v_num; j++) {
			if (matrix[i][j] == 65535)
				cout << "--" << ' ';
			else
				cout << matrix[i][j] << ' ';
		}
		cout <<endl;
	}
}
void make_matrix_bases(unsigned short** matr, size_t size) {
	
	for (int i = 0; i < size; i++)  //������� ��������� �������
	{
		matr[i] = new unsigned short[size];
	}
	//��������� ���� �������
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matr[i][j] = 65535;
		}
	}
}