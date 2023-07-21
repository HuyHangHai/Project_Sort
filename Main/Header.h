#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <string>

using namespace std;


//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n);

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n);

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n);

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);

// ===== handle input =====
string handle_algorithm_name(string require);
string handle_input_order(string s);


// ===== Command line =====
// check type of command line
int check_command(int argc, char** argv);
// All command lines
void command1(char** argv);
void command2(char** argv);
void command3(char** argv);
void command4(char** argv);
void command5(char** argv);

//================SORTING====================

void InsertionSort(int* a, int n);
void ShellSort(int* a, int n);
void ShakerSort(int a[], int n, double &count);
void Heapify(int arr[], int n, int i, double &count);
void HeapSort(int arr[], int n, double &count);
