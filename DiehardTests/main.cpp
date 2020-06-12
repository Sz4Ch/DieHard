#include <iostream>


void SqueezeTest();
void OverlappingSumsTest();
void BirthdaySpacingsTest();
void SqueezeTestv2();
void SqueezeTestNextPart();
void BirthdaySpacingTestNextPart();


int main()
{
	while (true)
	{
		system("CLS");
		int task = 0;
		//print menu
		std::cout << "1. Uruchom 1 czêœæ testu BirthdayTest" << std::endl;
		std::cout << "2. Uruchom 2 czêœæ testu BirthdayTest" << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "3. Uruchom test OverlappingSums" << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "4. Uruchom 1 czêœæ testu SqueezeTest " << std::endl;
		std::cout << "5. Uruchom 2 czêœæ testu SqueezeTest" << std::endl;



		std::cin >> task;

		switch (task)
		{
		case 1:
		{
			

			BirthdaySpacingsTest();

			system("PAUSE");
			break;
		}
		case 2:
		{
			
			BirthdaySpacingTestNextPart();
			
			system("PAUSE");
			break;
		}
		case 3:
		{
			OverlappingSumsTest();
			system("PAUSE");
			break;
		}
		case 4:
		{
			SqueezeTestv2();
			
			system("PAUSE");
			break;
		}
		case 5:
		{
			
			SqueezeTestNextPart();
			system("PAUSE");
			break;
		}

		}

		return 0;
	}
}
