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

	// read data from input file
	ifstream f(argv[3]);

	int inputSize = 0;
	f >> inputSize;

	int* a = new int[inputSize];
	int* a1 = new int[inputSize];
	for (int i = 0; i < inputSize; i++) {
		f >> a[i];
		a1[i] = a[i];
	}
		
	f.close();

	// calculate running time and comparisons
	long long countCompare = 0;
	double calculateTime = 0;
	CalAlg(require, a, a1, inputSize, countCompare, calculateTime);


	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << require << endl;
	cout << "Input file: " << argv[3] << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "-------------------\n";
	if ((string)argv[4] == "-time") {
		cout << "Running time: " << setprecision(5) << fixed << calculateTime << endl;
	}
	else if ((string)argv[4] == "-comp") {
		cout << "Comparisons: " << countCompare << endl;
	}
	else if ((string)argv[4] == "-both") {
		cout << "Running time: " << setprecision(5) << fixed << calculateTime << endl;
		cout << "Comparisons: " << countCompare << endl;
	}

	// ====== record data to file =====
	//WriteFile("output.txt", a, inputSize);

	delete[] a, a1;
}

void command2(char** argv)
{
	string require = handle_algorithm_name(argv[2]);
	int inputSize = stoi(argv[3]);
	int* a = new int[inputSize];
	int* a1 = new int[inputSize];
	string inputOrder = handle_input_order(argv[4]);

	// handle input
	if ((string)argv[4] == "-rand") {
		GenerateRandomData(a, inputSize);
		for (int i = 0; i < inputSize; i++)
			a1[i] = a[i];
	}
	else if ((string)argv[4] == "-nsorted") {
		GenerateNearlySortedData(a, inputSize);
		for (int i = 0; i < inputSize; i++)
			a1[i] = a[i];
	}
	else if ((string)argv[4] == "-sorted") {
		GenerateSortedData(a, inputSize);
		for (int i = 0; i < inputSize; i++)
			a1[i] = a[i];
	}
	else if ((string)argv[4] == "-rev") {
		GenerateReverseData(a, inputSize);
		for (int i = 0; i < inputSize; i++)
			a1[i] = a[i];
	}

	// ====== record data to file =====
	//WriteFile("input.txt", a1, inputSize);

	// ====== calculate running time and comparisons ======


	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << require << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << inputOrder << endl;
	cout << "-------------------\n";
	if ((string)argv[5] == "-time") {
		cout << "Running time: " << endl;
	}
	else if ((string)argv[5] == "-comp") {
		cout << "Comparisons: " << endl;
	}
	else if ((string)argv[5] == "-both") {
		cout << "Running time: " << endl;
		cout << "Comparisons: " << endl;
	}

	delete[] a;
	delete[] a1;
}

void command3(char** argv)
{
	/*  – Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
		– Ex: Main.exe -a shell-sort 100000 -both  */
	string alg = handle_algorithm_name(argv[2]);
	int inputSize = stoi(argv[3]);
	string requireOutput = argv[4];

	long long comp0 = 0, comp1 = 0, comp2 = 0, comp3 = 0;
	double time0, time1, time2, time3;

	int* arr = new int[inputSize];
	int* arr1 = new int[inputSize];

	GenerateData(arr, inputSize, 0);
	GenerateData(arr1, inputSize, 0);
	WriteFile("input_1.txt", arr, inputSize);
	CalAlg(alg, arr, arr1, inputSize, comp0, time0);

	GenerateData(arr, inputSize, 1);
	GenerateData(arr1, inputSize, 1);
	WriteFile("input_3.txt", arr, inputSize);
	CalAlg(alg, arr, arr1, inputSize, comp1, time1);

	GenerateData(arr, inputSize, 2);
	GenerateData(arr1, inputSize, 2);
	WriteFile("input_4.txt", arr, inputSize);
	CalAlg(alg, arr, arr1, inputSize, comp2, time2);

	GenerateData(arr, inputSize, 3);
	GenerateData(arr1, inputSize, 3);
	WriteFile("input_2.txt", arr, inputSize);
	CalAlg(alg, arr, arr1, inputSize, comp3, time3);

	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << alg << endl;
	cout << "Input size: " << inputSize << endl << endl;
	cout << "Input order: " << "Randomize" << endl;
	cout << "-------------------\n";
	if (requireOutput == "-time") {
		cout << "Running time: " << time0 << endl << endl;

		cout << "Input order: " << "Nearly Sorted" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << time3 << endl << endl;

		cout << "Input order: " << "Sorted" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << time1 << endl << endl;

		cout << "Input order: " << "Reserved" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << time2 << endl << endl;
	}
	else if (requireOutput == "-comp") {
		cout << "Comparisons: " << comp0 << endl << endl;

		cout << "Input order: " << "Nearly Sorted" << endl;
		cout << "-------------------\n";
		cout << "Comparisons: " << comp3 << endl << endl;

		cout << "Input order: " << "Sorted" << endl;
		cout << "-------------------\n";
		cout << "Comparisons: " << comp1 << endl << endl;

		cout << "Input order: " << "Reserved" << endl;
		cout << "-------------------\n";
		cout << "Comparisons: " << comp2 << endl << endl;
	}
	else if (requireOutput == "-both") {
		cout << "Running time: " << time0 << endl;
		cout << "Comparisons: " << comp0 << endl << endl;

		cout << "Input order: " << "Nearly Sorted" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << time3 << endl;
		cout << "Comparisons: " << comp3 << endl << endl;

		cout << "Input order: " << "Sorted" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << time1 << endl;
		cout << "Comparisons: " << comp1 << endl << endl;

		cout << "Input order: " << "Reserved" << endl;
		cout << "-------------------\n";
		cout << "Running time: " << time2 << endl;
		cout << "Comparisons: " << comp2 << endl << endl;
	}
	delete[] arr;
	delete[] arr1;
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
	int* arr = new int[inputSize];
	for (int i = 0; i < inputSize; i++)
	{
		fp >> arr[i];
	}
	fp.close();

	int* arr1 = new int[inputSize];
	for (int i = 0; i < inputSize; i++)
	{
		arr1[i] = arr[i];
	}

	//Sort
	double time1, time2;
	long long comp1 = 0, comp2 = 0;
	CalAlg(alg1, arr, arr1, inputSize, comp1, time1);
	CalAlg(alg2, arr, arr1, inputSize, comp2, time2);

	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << alg1 << " | " << alg2 << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "-------------------\n";
	cout << "Running time: " << time1 << " | " << time2 << endl;
	cout << "Comparisons: " << comp1 << " | " << comp2 << endl;
	delete[]arr;
	delete[]arr1;
}

void command5(char** argv)
{
	//[Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
	string alg1 = handle_algorithm_name(argv[2]);
	string alg2 = handle_algorithm_name(argv[3]);
	int inputSize = stoi(argv[4]);
	string inputOrder = handle_input_order(argv[5]);
	int* arr = new int[inputSize];
	int* arr1 = new int[inputSize];
	string fileName = "input.txt";

	if (inputOrder == "Randomize")
	{
		GenerateData(arr, inputSize, 0);
		GenerateData(arr1, inputSize, 0);
		WriteFile(fileName, arr, inputSize);
	}
	else if (inputOrder == "Sorted")
	{
		GenerateData(arr, inputSize, 1);
		GenerateData(arr1, inputSize, 1);
		WriteFile(fileName, arr, inputSize);
	}
	else if (inputOrder == "Reverse")
	{
		GenerateData(arr, inputSize, 2);
		GenerateData(arr1, inputSize, 2);
		WriteFile(fileName, arr, inputSize);
	}
	else
	{
		GenerateData(arr, inputSize, 3);
		GenerateData(arr1, inputSize, 3);
		WriteFile(fileName, arr, inputSize);
	}

	//Sort
	double time1, time2;
	long long comp1 = 0, comp2 = 0;
	CalAlg(alg1, arr, arr1, inputSize, comp1, time1);
	CalAlg(alg2, arr, arr1, inputSize, comp2, time2);

	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << alg1 << " | " << alg2 << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << inputOrder << endl;
	cout << "-------------------\n";
	cout << "Running time: " << time1 << " | " << time2 << endl;
	cout << "Comparisons: " << comp1 << " | " << comp2 << endl;
	delete[]arr;
	delete[]arr1;
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

void CalAlg(string alg, int arr[], int arr1[], int n, long long& comp, double& time)
{
	clock_t start, end;
	if (alg == "Selection Sort")
	{
		SelectionSort(arr, n, comp);
		start = clock();
		SelectionSort(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Bubble Sort")
	{
		BubbleSort(arr, n, comp);
		start = clock();
		BubbleSort(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Insertion Sort")
	{
		InsertionSort(arr, n, comp);
		start = clock();
		InsertionSort(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Heap Sort")
	{
		HeapSort(arr, n, comp);
		start = clock();
		HeapSort1(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Merge Sort")
	{
		//MergeSort(arr, n, comp);
		start = clock();
		//MergeSort1(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Quick Sort")
	{
		//QuickSort(arr, n, comp);
		start = clock();
		//QuickSort1(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Shaker Sort")
	{
		ShakerSort(arr, n, comp);
		start = clock();
		ShakerSort1(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Shell Sort")
	{
		ShellSort(arr, n, comp);
		start = clock();
		ShellSort(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Counting Sort")
	{
		//CountingSort(arr, n, comp);
		start = clock();
		//CountingSort1(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else if (alg == "Radix Sort")
	{
		RadixSort(arr, n, comp);
		start = clock();
		RadixSort(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}

	else
	{
		FlashSort(arr, n, comp);
		start = clock();
		FlashSort(arr1, n);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return;
	}
}




//================SORTING====================

void InsertionSort(int* a, int n)
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
void InsertionSort(int* a, int n, long long& comp)
{
	comp = 0;
	for (int i = 1; ++comp && i < n; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (++comp && a[j] > key && ++comp && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void ShellSort(int* a, int n)
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
void ShellSort(int* a, int n, long long& comp)
{
	comp = 0;
	for (int gap = n / 2; ++comp && gap >= 1; gap /= 2)
	{
		for (int i = gap; ++comp && i < n; i++)
		{
			int temp = a[i];
			int j = i - gap;
			while (++comp && j >= 0 && ++comp && temp < a[j])
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = temp;
		}
	}
}

void ShakerSort(int a[], int n, long long& count)
{
	int left, right, k, i;
	left = 0;
	right = n - 1;
	k = 0;
	count = 0;
	while (++count && left < right)
	{
		for (i = left; ++count && i < right; i++)
		{
			if (++count && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		right = k;

		for (i = right; ++count && i > left; i--)
		{
			if (++count && a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		left = k;
	}
}
void ShakerSort1(int a[], int n)
{
	int left, right, k, i;
	left = 0;
	right = n - 1;
	k = 0;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		right = k;

		for (i = right; i > left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		left = k;
	}
}

void Heapify(int arr[], int n, int i, long long& count)
{
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	if ((++count && l < n) && (++count && arr[l] > arr[largest]))
		largest = l;

	if ((++count && r < n) && (++count && arr[r] > arr[largest]))
		largest = r;

	if (++count && largest != i)
	{
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest, count);
	}
}
void HeapSort(int arr[], int n, long long& count)
{
	// Build heap
	for (int i = n / 2 - 1; ++count && i >= 0; i--)
	{
		Heapify(arr, n, i, count);
	}

	// One by one extract an element
	for (int i = n - 1; ++count && i > 0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0, count);
	}
}

void Heapify1(int arr[], int n, int i)
{
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		Heapify1(arr, n, largest);
	}
}
void HeapSort1(int arr[], int n)
{
	// Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapify1(arr, n, i);
	}

	// One by one extract an element
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify1(arr, i, 0);
	}
}

void BubbleSort(int arr[], int n, long long& countCompare)
{
	for (int i = n - 1; ++countCompare && i >= 1; i--) {
		// compare adjacent pairs of items
		for (int j = 1; ++countCompare && j <= i; j++) {
			if (++countCompare && arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]); //if items are out of order
		}
	}
}
void BubbleSort(int arr[], int n)
{
	for (int i = n - 1; i >= 1; i--) {
		// compare adjacent pairs of items
		for (int j = 1; j <= i; j++) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]); //if items are out of order
		}
	}
}

void SelectionSort(int* a, int n, long long& countCompare)
{
	for (int i = 0; ++countCompare && i < n - 1; i++) {
		int minPos = i;
		for (int j = i + 1; ++countCompare && j < n; j++) {
			if (++countCompare && a[j] < a[minPos])
				minPos = j;
		}
		swap(a[i], a[minPos]);
	}
}
void SelectionSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++) {
		int minPos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minPos])
				minPos = j;
		}
		swap(a[i], a[minPos]);
	}
}

// ----- Radix Sort -----
int get_max_value(int* a, int n, long long& countCompare)
{
	int maxValue = a[0];

	for (int i = 1; ++countCompare && i < n; i++) {
		if (++countCompare && a[i] > maxValue)
			maxValue = a[i];
	}
	return maxValue;
}
int get_max_value(int* a, int n)
{
	int maxValue = a[0];

	for (int i = 1; i < n; i++) {
		if (a[i] > maxValue)
			maxValue = a[i];
	}
	return maxValue;
}

void CountingSort2(int* a, int n, int exp, long long& countCompare)
{

	int count[10] = { 0 };

	for (int i = 0; ++countCompare && i < n; i++)
		count[(a[i] / exp) % 10]++;

	for (int i = 1; ++countCompare && i < 10; i++)
		count[i] = count[i - 1] + count[i];


	int* temp = new int[n];

	for (int i = n - 1; ++countCompare && i >= 0; i--) {
		temp[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}


	// update for array a after sorting by current unit
	for (int i = 0; ++countCompare && i < n; i++)
		a[i] = temp[i];

	delete[] temp;
}
void CountingSort2(int* a, int n, int exp)
{

	int count[10] = { 0 };

	for (int i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] = count[i - 1] + count[i];


	int* temp = new int[n];

	for (int i = n - 1; i >= 0; i--) {
		temp[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}


	// update for array a after sorting by current unit
	for (int i = 0; i < n; i++)
		a[i] = temp[i];

	delete[] temp;
}

void RadixSort(int* a, int n, long long& countCompare)
{
	int maxValue = get_max_value(a, n, countCompare);

	for (int i = 1; ++countCompare && (maxValue / i) > 0; i *= 10)
		CountingSort2(a, n, i, countCompare);
}
void RadixSort(int* a, int n)
{
	int maxValue = get_max_value(a, n);

	for (int i = 1; (maxValue / i) > 0; i *= 10)
		CountingSort2(a, n, i);
}



//---------------------FLASH SORT------------------------
void FlashSort(int* a, int n)
{
	//find min, max of Array a
	int minn = a[0];
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		maxx = max(maxx, a[i]);
		minn = min(minn, a[i]);
	}

	//define number of buckets
	int m = 0.43 * n;
	int* Bucket = new int[m];
	for (int i = 0; i < m; i++)
	{
		Bucket[i] = 0;
	}

	//define number of keys in each bucket
	for (int i = 0; i < n; i++)
	{
		int k = (m - 1) * (a[i] - minn) / (maxx - minn);		//later explaining :D
		Bucket[k]++;
	}

	//same as Counting Sort, find the LAST INDEX of each bucket
	for (int i = 1; i < m; i++)
	{
		Bucket[i] += Bucket[i - 1];
	}

	//now move all keys that not in correct bucket to the correct one
	int j = 0;
	int move = 0;
	int k = (m - 1) * (a[j] - minn) / (maxx - minn);		//later explaining :D
	while (move < n)
	{
		while (j < n && Bucket[k] == 0)
		{
			j++;
			k = (m - 1) * (a[j] - minn) / (maxx - minn);
		}

		while (Bucket[k] != 0)
		{
			//swapping
			int tmp = a[Bucket[k] - 1];
			a[Bucket[k] - 1] = a[j];
			a[j] = tmp;

			Bucket[k]--;
			k = (m - 1) * (a[j] - minn) / (maxx - minn);
			move++;
		}


	}

	delete[]Bucket;

	//now every keys are in the correct bucket, just implement Insertion Sort here :D
	InsertionSort(a, n);
}
void FlashSort(int* a, int n, long long& comp)
{
	comp = 0;
	//find min, max of Array a
	int minn = a[0];
	int maxx = 0;
	for (int i = 0; ++comp && i < n; i++)
	{
		if (++comp && minn > a[i])
			minn = a[i];
		if (++comp && maxx < a[i])
			maxx = a[i];
	}

	//define number of buckets
	int m = 0.43 * n;
	int* Bucket = new int[m];
	for (int i = 0; ++comp && i < m; i++)
	{
		Bucket[i] = 0;
	}

	//define number of keys in each bucket
	for (int i = 0; ++comp && i < n; i++)
	{
		int k = (m - 1) * (a[i] - minn) / (maxx - minn);		//later explaining :D
		Bucket[k]++;
	}

	//same as Counting Sort, find the LAST INDEX of each bucket
	for (int i = 1; ++comp && i < m; i++)
	{
		Bucket[i] += Bucket[i - 1];
	}

	//now move all keys that not in correct bucket to the correct one
	int j = 0;
	int move = 0;
	int k = (m - 1) * (a[j] - minn) / (maxx - minn);		//later explaining :D
	while (++comp && move < n)
	{
		while (++comp && j < n && ++comp && Bucket[k] == 0)
		{
			j++;
			k = (m - 1) * (a[j] - minn) / (maxx - minn);
		}

		while (++comp && Bucket[k] != 0)
		{
			//swapping
			int tmp = a[Bucket[k] - 1];
			a[Bucket[k] - 1] = a[j];
			a[j] = tmp;

			Bucket[k]--;
			k = (m - 1) * (a[j] - minn) / (maxx - minn);
			move++;
		}


	}

	delete[]Bucket;

	//now every keys are in the correct bucket, just implement Insertion Sort here :D
	InsertionSort(a, n, comp);
}