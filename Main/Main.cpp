#include "Header.h"

int main(int argc, char** argv)
{
	//if (argc < 2)	return 0;

	//int require = check_command(argc, argv);
	//switch (require)
	//{
	//	case 1:
	//	{
	//		command1(argv);
	//		break;
	//	}
	//	case 2:
	//	{
	//		command2(argv);
	//		break;
	//	}
	//	case 3:
	//	{
	//		command3(argv);
	//		break;
	//	}
	//	case 4:
	//	{
	//		command4(argv);
	//		break;
	//	}
	//	case 5:
	//	{
	//		command5(argv);
	//		break;
	//	}
	//default:
	//	break;
	//}

	int n = 100000;
	long long count = 0;
	int* arr = new int[n];
	GenerateData(arr, n, 2);
	clock_t start, end;
	start = clock();
	HeapSort1(arr, n);
	end = clock();
	double time = double((end - start) / CLOCKS_PER_SEC);
	cout << time;
	delete[]arr;

	return 0;
}
