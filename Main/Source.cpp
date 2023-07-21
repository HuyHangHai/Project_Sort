#include "Header.h"

// ===== handle input =====
string handle_algorithm_name(string require)
{
	for (int i = 0; i < require.size(); i++) {
		if (i == 0) {
			require[0] -= 32;
		}
		if (require[i] == '-') {
			require[i] = ' ';
			require[i + 1] -= 32;
			break;
		}
	}
	return require;
}
string handle_input_order(string s)
{
	if (s == "-rand")
		return "Randomize";
	else if (s == "-nsorted")
		return "Nearly Sorted";
	else if (s == "-sorted")
		return "Sorted";
	else
		return "Reverse";
}


//void bubble_sort(int* a, int n)
//{
//	
//}

// ===== Command line =====
int check_command(int argc, char** argv)
{
	if ((string)argv[1] == "-a") {
		if (argc == 5) {
			string check = argv[3];
			if (check[check.size() - 1] >= '0' && check[check.size() - 1] <= '9')
				return 3;
			else
				return 1;
		}
		else return 2;
	}
	else if ((string)argv[1] == "-c") {
		if (argc == 5)	return 4;
		else
			return 5;
	}
}

void command1(char** argv)
{
	string require = handle_algorithm_name(argv[2]);
	string fp = argv[3];


	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << require << endl;
	cout << "Input file: " << fp << endl;
	//cout << "Input size: " << 
	cout << "-------------------\n";
	if (argv[4] == "-time") {
		cout << "Running time: " << endl;
	}
	else if (argv[4] == "-comp") {
		cout << "Comparisons: " << endl;
	}
	else if (argv[4] == "-both") {
		cout << "Running time: " << endl;
		cout << "Comparisons: " << endl;
	}
}

void command2(char** argv)
{
	string require = handle_algorithm_name(argv[2]);
	int inputSize = stoi(argv[3]);
	string inputOrder = handle_input_order(argv[4]);


	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << require << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << inputOrder << endl;
	cout << "-------------------\n";
	if (argv[5] == "-time") {
		cout << "Running time: " << endl;
	}
	else if (argv[5] == "-comp") {
		cout << "Comparisons: " << endl;
	}
	else if (argv[5] == "-both") {
		cout << "Running time: " << endl;
		cout << "Comparisons: " << endl;
	}
}

void command3(char** argv)
{
/*  – Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
	– Ex: a.exe -a binary-insertion-sort 70000 -comp  */
	string alg = handle_algorithm_name(argv[2]);
	int inputSize = stoi(argv[3]);
	string requireOutput = argv[4];

	int* a = new int[inputSize];
	GenerateData(a, inputSize, 0);
	WriteFile("input1.txt", a, inputSize);
	GenerateData(a, inputSize, 1);
	WriteFile("input2.txt", a, inputSize);
	GenerateData(a, inputSize, 2);
	WriteFile("input3.txt", a, inputSize);
	GenerateData(a, inputSize, 3);
	WriteFile("input4.txt", a, inputSize);
	
	//Sort


	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << alg << endl;
	cout << "Input size: " << inputSize << endl << endl;
	cout << "Input order: " << "Randomize" << endl;
	cout << "-------------------\n";
	if (requireOutput == "-time") {
		cout << "Running time: " << endl << endl;

		cout << "Input order: " << "Nearly Sorted" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << endl << endl;

		cout << "Input order: " << "Sorted" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << endl << endl;

		cout << "Input order: " << "Reserved" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << endl << endl;
	}
	else if (requireOutput == "-comp") {
		cout << "Comparisons: " << endl << endl;

		cout << "Input order: " << "Nearly Sorted" << endl;
		cout << "-------------------\n";
		cout << "Comparisons: " << endl << endl;
		
		cout << "Input order: " << "Sorted" << endl;
		cout << "-------------------\n";
		cout << "Comparisons: " << endl << endl;
		
		cout << "Input order: " << "Reserved" << endl;
		cout << "-------------------\n";
		cout << "Comparisons: " << endl << endl;
	}
	else if (requireOutput == "-both") {
		cout << "Running time: " << endl;
		cout << "Comparisons: " << endl << endl;

		cout << "Input order: " << "Nearly Sorted" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << endl;
		cout << "Comparisons: " << endl << endl;

		cout << "Input order: " << "Sorted" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << endl;
		cout << "Comparisons: " << endl << endl;

		cout << "Input order: " << "Reserved" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << endl;
		cout << "Comparisons: " << endl << endl;
	}
	delete[]a;
}

void command4(char** argv)
{
	//– Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
	//– Ex : a.exe - c heap - sort merge - sort input.txt
	string alg1 = handle_algorithm_name(argv[2]);
	string alg2 = handle_algorithm_name(argv[3]);
	string fileName = argv[4];

	int inputSize;
	fstream fp;
	fp.open(fileName, ios::in);
	fp >> inputSize;
	fp.close();

	//Sort

	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << alg1 << " | " << alg2 << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "-------------------\n";
	cout << "Running time: " << endl;
	cout << "Comparisons: " << endl << endl;
}

void command5(char** argv)
{
	//[Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
	string alg1 = handle_algorithm_name(argv[2]);
	string alg2 = handle_algorithm_name(argv[3]);
	int inputSize = stoi(argv[4]);
	string inputOrder = handle_input_order(argv[5]);
	int* a = new int[inputSize];
	string fileName = "input.txt";

	if (inputOrder == "Randomize")
	{
		GenerateData(a, inputSize, 0);
		WriteFile(fileName, a, inputSize);
	}
	else if (inputOrder == "Sorted")
	{
		GenerateData(a, inputSize, 1);
		WriteFile(fileName, a, inputSize);
	}
	else if (inputOrder == "Reverse")
	{
		GenerateData(a, inputSize, 2);
		WriteFile(fileName, a, inputSize);
	}
	else
	{
		GenerateData(a, inputSize, 3);
		WriteFile(fileName, a, inputSize);
	}

	//Sort
	

	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << alg1 << " | " << alg2 << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << inputOrder << endl;
	cout << "-------------------\n";
	cout << "Running time: " << endl;
	cout << "Comparisons: " << " | " << endl << endl;
	delete []a;
}

void WriteFile(string file_name, int a[], int n)
{
	fstream fp;
	fp.open(file_name, ios::out);
	fp << n;
	fp << '\n';
	for (int i = 0; i < n; i++)
	{
		fp << a[i];
		fp << ' ';
	}
	fp.close();
}


//================SORTING====================

void InsertionSort(int* a, int n)						//Khoi edited
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (a[j] > key && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void ShellSort(int* a, int n)							//Khoi edited
{
	for (int gap = n / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = a[i];
			int j = i - gap;
			while (j >= 0 && temp < a[j])
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = temp;
		}
	}
}

void ShakerSort(int a[], int n, double &count) 
{
	int left, right, k, i;
	left = 0;
	right = n - 1;
	k = 0;
	count = 0;
	while (left < right) 
	{
		count++;
		for (i = left; i < right; i++)
		{
			count++;
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
			count++;
		}
		right = k;

		for (i = right; i > left; i--)
		{
			count++;
			if (a[i] < a[i - 1]) 
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
			count++;
		}
		left = k;
	}
}

void Heapify(int arr[], int n, int i, double &count)
{
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	count++;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	count++;
	if (r < n && arr[r] > arr[largest])
		largest = r;

	count++;
	if (largest != i) 
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest, count);
	}
}

void HeapSort(int arr[], int n, double &count)
{
	// Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		count++;
		heapify(arr, n, i, count);
	}

	// One by one extract an element
	for (int i = n - 1; i > 0; i--) 
	{
		count++;
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, count);
	}
}
