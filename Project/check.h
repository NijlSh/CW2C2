#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

#undef max
#define WIN_NAME_SIZE 22
#define QUIT 0

enum binChoise { no = 0, yes = 1 };
enum startChoise { file = 1, console = 2 };
enum figureChoise { _circle = 1, _rectangle = 2, _trapezoid = 3 };

const std::string op = "output";
const std::string ip = "input";
const std::string txt = ".txt";
const std::string win_name[WIN_NAME_SIZE] = { "CON", "PRN", "AUX", "NUL",
								"COM1", "COM2", "COM3", "COM4", "COM5",
								"COM6", "COM7", "COM8", "COM9", "LPT1",
								"LPT2", "LPT3", "LPT4", "LPT5", "LPT6",
								"LPT7", "LPT8", "LPT9" };
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

void checkFileName(std::string str);
void checkFileExistance(std::string file_name, const std::string stream_type);