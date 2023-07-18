#include "Header.h"

int main(int argc, char** argv)
{
	if (argc < 2)	return 0;

	//
	int require = check_command(argc, argv);
	switch (require)
	{
		case 1:
		{
			command1(argv);
			break;
		}
		case 2:
		{
			command2(argv);
			break;
		}
		case 3:
		{
			/*command3(argv);*/
			break;
		}
		case 4:
		{
			/*command4(argv);*/
			break;
		}
		case 5:
		{
			/*command5(argv);*/
			break;
		}
	default:
		break;
	}

	return 0;
}