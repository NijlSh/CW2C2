#include "program.h"

int program(void) 
{
	SetConsoleCP (1251);         //Установлена кодировка ввода
	SetConsoleOutputCP (1251);   //Установлена кодировка вывода на консооль
	setlocale (LC_CTYPE, "RU");    //Установка русской локали

	showGreetings();
	showTask();

	//Заполнение массива фигур
	while(true)
	{
		int user_choice = yes, counter = 0;
		bool is_con_input = false;
		std::vector<std::shared_ptr<figure>> shp;
		while (user_choice == yes) 
		{
			shp.clear();
			shp.resize(0);
			showInputChoice();
			user_choice = getStartChoice();
			if (user_choice == quit) exit(0);
			else if (user_choice == console) {
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
					showNextFigureMenu();
					user_choice = getBinChoice();
				} while (user_choice != quit);
			}
			else 
			{ 
				fileInput(shp); 
				user_choice = no;
			}
		}

		if (is_con_input) 
		{
			showOutputMenu();
			user_choice = getBinChoice();
			if (user_choice == yes) { fileOutput(shp, counter); }
		}

		showResult(shp);

		showFinalOutputMenu();
		user_choice = getBinChoice();
		if(user_choice == yes) fileOutputFin(shp);

		showEndMenu();
		user_choice = getBinChoice();
		if (user_choice == no) break;
	};

	return 0;
}
