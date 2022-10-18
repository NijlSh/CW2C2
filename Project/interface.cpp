#include "interface.h"

void showGreetings(void) 
{
	std::cout << "Контрольная работа №2, вариант 5, сделано студентом группы 415 Шарашидзе Н.Л." << std::endl;
}

void showTask(void) 
{
	std::cout << "Создать базовый класс фигура, производные классы: круг, прямоугольник, трапеция." << std::endl;
	std::cout << "Определить виртуальные функции для вычисления площади и периметра." << std::endl;
}

void showInputChoice(void) 
{
	std::cout << "Выберете способ ввода данных:" << std::endl;
	std::cout << "0 - Завершить работу" << std::endl;
	std::cout << "1 - Из файла" << std::endl;
	std::cout << "2 - На консоль" << std::endl;
	std::cout << "Ввод: ";
}

void showFigureMenu(void) 
{
	std::cout << "Выберете, что хотите сделать:" << std::endl;
	std::cout << "0 - Вернуться к предыдущиму выбору" << std::endl;
	std::cout << "1 - Круг" << std::endl;
	std::cout << "2 - Прямоугольник" << std::endl;
	std::cout << "3 - Трапеция" << std::endl;
	std::cout << "Ввод: ";

}

void showOutputMenu(void) 
{
	std::cout << "Вы хотите записать данные в исходном виде в файл?" << std::endl;
	std::cout << "0 - Нет" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "Ввод: ";
}

void showContMenu(void) 
{
	std::cout << "Хотите ввести новую фигуру?" << std::endl;
	std::cout << "0 - Нет" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "Ввод: ";
}

void showFinOutputMenu(void)
{
	std::cout << "Хотите записать данные в красиво офрмленном виде в новый файл" << std::endl;
	std::cout << "0 - Нет" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "Ввод: ";
}

void showEndMenu(void) 
{
	std::cout << "Вы хотите выполнить программу снова?" << std::endl;
	std::cout << "0 - Нет" << std::endl;
	std::cout << "1 - Да" << std::endl;
	std::cout << "Ввод: ";
}