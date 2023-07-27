#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <string>
#include <iomanip>

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
void WriteFile(string file_name, int a[], int n);
void CalAlg(string alg, int arr[], int arr1[], int n, long long& comp, double& time);


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
void InsertionSort(int* a, int n, long long& comp);

void ShellSort(int* a, int n);
void ShellSort(int* a, int n, long long& comp);

void ShakerSort(int a[], int n, long long &count);
void ShakerSort(int a[], int n);

void Heapify(int arr[], int n, int i, long long &count);
void HeapSort(int arr[], int n, long long &count);
void Heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);

void BubbleSort(int arr[], int n, long long& countCompare);
void BubbleSort(int arr[], int n);

void SelectionSort(int* a, int n, long long& countCompare);
void SelectionSort(int* a, int n);

// -----Radix Sort-----
int get_max_value(int* a, int n, long long& countCompare);
int get_max_value(int* a, int n);
void CountingSort2(int* a, int n, int exp, long long& countCompare);
void CountingSort2(int* a, int n, int exp);
void RadixSort(int* a, int n, long long& countCompare);
void RadixSort(int* a, int n);


void FlashSort(int* a, int n);
void FlashSort(int* a, int n, long long& comp);
