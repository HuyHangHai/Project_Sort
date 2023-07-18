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
void command1(char** argv)
{
	string require = argv[2];
	string fp = argv[3];
	string requireOutput = argv[4];




	// ===== print in the format =====
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << require << endl;
	cout << "Input file: " << fp << endl;
	//cout << "Input size: " << 
	cout << "-------------------\n";
	if (requireOutput == "-time") {
		cout << "Running time: " << endl;
	}
	else if (requireOutput == "-comp") {
		cout << "Comparisons: " << endl;
	}
	else if (requireOutput == "-both") {
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