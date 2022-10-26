#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

#undef max
#define QUIT 0

enum binChoise { no = 0, yes = 1 };
enum startChoise { file = 1, console = 2 };
enum figureChoise { _circle = 1, _rectangle = 2, _trapezoid = 3 };

const int quit = 0;
const int error = 1;

int getStartChoice();
int getBinChoice();
int getFigureChoice();

int getLineI(std::ifstream& file);
double getLineD(std::ifstream& file);
std::string getLineS(std::ifstream& file);

template<typename T>
T getPositiveValue()
{
    T temp = 0.0;
    do
    {
        try
        {
            std::cin >> temp;
			std::cout << std::endl;
			if (std::cin.peek() != '\n') throw std::invalid_argument("");
            if (temp <= 0) throw std::out_of_range("");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return temp;
        }
		catch (const std::out_of_range&)
		{
			std::cout << "Число должно быть положительным. Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
        catch (const std::exception&)
        {
            std::cout << "Введены некорректные данные. Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (true);
}
