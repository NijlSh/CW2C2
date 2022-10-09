#include "program.h"

int program(void) 
{
	SetConsoleCP (1251);         //Установлена кодировка ввода
	SetConsoleOutputCP (1251);   //Установлена кодировка вывода на консооль
	setlocale (LC_CTYPE, "RU");    //Установка русской локали

	showGreetings();
	showTask();

	int user_choice = yes, counter = 0;
	bool is_con_input = false;
	std::vector<std::shared_ptr<figure>> shp;

	//Заполнение массива фигур
	do
	{
		while (user_choice == yes) {
			shp.clear();
			shp.resize(0);
			showInputChoice();
			user_choice = getBinChoice();
			if (user_choice == yes)
			{
				is_con_input = true;
				do
				{
					showFigureMenu();
					user_choice = getFigureChoice();
					if (user_choice == _circle) { circleChoice(shp); counter++; }
					else if (user_choice == _rectangle) { rectangleChoice(shp); counter++; }
					else if (user_choice == _trapezoid) { trapezoidChoice(shp); counter++; }
					else
					{
						user_choice = yes;
						break;
					}
					showContMenu();
					user_choice = getBinChoice();
				} while (user_choice != QUIT);
			}
			else fileInput(shp);
		}

		if (is_con_input) 
		{
			showOutputMenu();
			user_choice = getBinChoice();
			if (user_choice == yes) { fileOutput(shp, counter); }
		}

		showResult(shp);

		showFinOutputMenu();
		user_choice = getBinChoice();
		if(user_choice == yes) fileOutputFin(shp);

		showEndMenu();
		user_choice = getBinChoice();
	} while (user_choice == yes);

	return 0;
}
