#include "check.h"

int getStartChoice() 
{
	while (true)
	{
		try
		{
			int value = 0;
			std::cin >> value;
			std::cout << std::endl;
			if (std::cin.peek() != '\n') throw std::invalid_argument("");
			if (value == quit || value == file || value == console)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
			else throw std::out_of_range("");
		}
		catch (const std::out_of_range&)
		{
			std::cout << "Такого пункта меню нет. Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		catch (const std::exception&)
		{
			std::cout << "Некоректный тип данных. Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
}

int getBinChoice() 
{
	while(true)
	{
		try
		{
			int value = 0;
			std::cin >> value;
			std::cout << std::endl;
			if (std::cin.peek() != '\n') throw std::invalid_argument("");
			if (value == no || value == yes)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
			else throw std::out_of_range("");
		}
		catch (const std::out_of_range&)
		{
			std::cout << "Такого пункта меню нет. Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		catch (const std::exception&)
		{
			std::cout << "Некоректный тип данных. Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
}

int getFigureChoice() 
{
	int value = 0;
	do {
		try
		{
			value = 0;
			std::cin >> value;
			std::cout << std::endl;
			if (std::cin.peek() != '\n') throw std::invalid_argument("");
			if (value == quit || value == _circle || value == _rectangle || value == _trapezoid)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
			else throw std::out_of_range("");
		}
		catch (const std::out_of_range&)
		{
			std::cout << "Такого пункта в меню нет. Повторите ввод: " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		catch (const std::exception&)
		{
			std::cout << "Некоректный тип данных. Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	} while (true);
}

int getLineI(std::ifstream& file)
{
    std::string temp_s = "";
    int temp_i = 0;
    try
    {
        std::getline(file, temp_s);
    }
    catch (const std::exception&)
    {
        std::cout << "Ошибка при чтении информации из файла." << std::endl;
        throw error;
    }
    try
    {
        temp_i = stoi(temp_s);
        if (temp_i <= 0) throw error;
        else return temp_i;
    }
	catch (int) 
	{
		std::cout << "Некорректный формат данных." << std::endl;
		throw error;
	}
}

double getLineD(std::ifstream& file)
{
    std::string temp_s = "";
    double temp_d = 0.0;
    try
    {
        std::getline(file, temp_s);
    }
    catch (const std::exception&)
    {
        std::cout << "Ошибка при чтении информации из файла." << std::endl;
        throw error;
    }
    try
    {
        temp_d = stod(temp_s);
        if (temp_d < 0) throw  error;
        else return temp_d;
    }
    catch (int)
    {
        std::cout << "Некорректный формат данных." << std::endl;
        throw error;
    }
}

std::string getLineS(std::ifstream& file)
{
    std::string temp_1 = "";
    try
    {
        std::getline(file, temp_1);
		return temp_1;
    }
    catch (const std::exception&)
    {
        std::cout << "Ошибка при чтении информации из файла." << std::endl;
        throw error;
    }
}

void checkFileName(std::string str)
{
	std::cout << std::endl;
	try 
	{
		if (!(str.find(txt) == std::string::npos))
		{
			std::size_t temp_sz = str.find(txt);
			std::string temp_st = str.substr(temp_sz);
			if (temp_st.size() != txt.size())
			{
				std::cout << "Неверный тип файла. Повторите ввод." << std::endl;
				throw error;
			}
		}
		else
		{
			std::cout << "Неверный тип файла. Повторите ввод." << std::endl;
			throw error;
		}

		for (int i = 0; i < WIN_NAME_SIZE; i++)
		{
			std::string temp1 = win_name[i] + txt;
			std::string temp2 = str;
			if (temp1 == temp2)
			{
				std::cout << "Введено зарезервированное операционной системой Windows слово. Повторите ввод." << std::endl;
				throw error;
			}
			else if (temp1.size() == temp2.size())
			{
				std::transform(temp1.begin(), temp1.end(), temp1.begin(), ::toupper);
				std::transform(temp2.begin(), temp2.end(), temp2.begin(), ::toupper);
				if (temp1 == temp2)
				{
					std::cout << "Введено зарезервированное операционной системой Windows слово. Повторите ввод." << std::endl;
					throw error;
				}
			}
		}
	}

	catch (std::exception&)
	{
		std::cout << "Ошибка." << std::endl;
		throw 1;
	}
	catch (int)
	{
		std::cout << "Ошибка." << std::endl;
		throw 1;
	}
}

void checkFileExistance(const std::string file_name, const std::string stream_type) 
{
	if (std::ifstream(file_name))
	{
		if (stream_type == op)
		{
			std::cout << "Файл уже существует. Вы хотите пересоздать его?" << std::endl
				<< "0 - Нет." << std::endl
				<< "1 - Да." << std::endl;
			std::cout << "Ввод: ";
			int userChoise = getBinChoice();
			if (userChoise == !yes) throw 1;
		}
	}
	else if (stream_type == ip)
	{
		std::cout << "Файла с таким названием не существует. Потворите ввод." << std::endl;
		throw 1;
	}
}