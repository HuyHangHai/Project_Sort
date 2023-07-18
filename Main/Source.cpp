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

	//Sort

	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << alg1 << " | " << alg2 << endl;
	cout << "Input size: " << inputSize << endl;
	cout << "Input order: " << inputOrder << endl;
	cout << "-------------------\n";
	cout << "Running time: " << endl;
	cout << "Comparisons: " << endl << endl;
}
