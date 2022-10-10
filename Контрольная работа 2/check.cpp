#include "check.h"



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
			if (value == 0 || value == 1)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
			else throw std::out_of_range("");
		}
		catch (std::invalid_argument&)
		{
			std::cout << "����������� ��� ������. ��������� ����: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		catch (std::out_of_range&)
		{
			std::cout << "������ ������ ���� ���. ��������� ����: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		catch (std::exception&)
		{
			std::cout << "����������� ��� ������. ��������� ����: ";
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
			if (value == 0 || value == 1 || value == 2 || value == 3)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return value;
			}
			else throw std::out_of_range("");
		}
		catch (std::invalid_argument&)
		{
			std::cout << "������ ��� ����� ������. ��������� ����: " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		catch (std::out_of_range&)
		{
			std::cout << "������ ������ � ���� ���. ��������� ����: " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		catch (std::exception&)
		{
			std::cout << "����������� ��� ������. ��������� ����: ";
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
        std::cout << "������ ��� ������ ���������� �� �����." << std::endl;
        throw 1;
    }
    try
    {
        temp_i = stoi(temp_s);
        if (temp_i <= 0) throw 1;
        else return temp_i;
    }
	catch (int) 
	{
		std::cout << "�� ������ ��� ������." << std::endl;
		throw 1;
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
        std::cout << "������ ��� ������ ���������� �� �����." << std::endl;
        throw 1;
    }
    try
    {
        temp_d = stod(temp_s);
        if (temp_d < 0) throw  1;
        else return temp_d;
    }
    catch (int)
    {
        std::cout << "������������ ������ ������." << std::endl;
        throw 1;
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
        std::cout << "������ ��� ������ ���������� �� �����." << std::endl;
        throw 1;
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
				std::cout << "�������� ��� �����. ��������� ����." << std::endl;
				throw 1;
			}
		}
		else
		{
			std::cout << "�������� ��� �����. ��������� ����." << std::endl;
			throw 1;
		}

		for (int i = 0; i < WIN_NAME_SIZE; i++)
		{
			std::string temp1 = win_name[i] + txt;
			std::string temp2 = str;
			if (temp1 == temp2)
			{
				std::cout << "������� ����������������� ������������ �������� Windows �����. ��������� ����." << std::endl;
				throw 1;
			}
			else if (temp1.size() == temp2.size())
			{
				std::transform(temp1.begin(), temp1.end(), temp1.begin(), ::toupper);
				std::transform(temp2.begin(), temp2.end(), temp2.begin(), ::toupper);
				if (temp1 == temp2)
				{
					std::cout << "������� ����������������� ������������ �������� Windows �����. ��������� ����." << std::endl;
					throw 1;
				}
			}
		}
	}

	catch (std::exception&)
	{
		std::cout << "Unexpexted error" << std::endl;
		throw 1;
	}
	catch (int)
	{
		throw 1;
	}
}
void checkFileExistance(const std::string file_name, const std::string stream_type) 
{
	if (std::ifstream(file_name))
	{
		if (stream_type == op)
		{
			std::cout << "���� ��� ����������. �� ������ ����������� ���?" << std::endl
				<< "0 - ���." << std::endl
				<< "1 - ��." << std::endl;
			std::cout << "����: ";
			int userChoise = getBinChoice();
			if (userChoise == !yes) throw 1;
		}
	}
	else if (stream_type == ip)
	{
		std::cout << "����� � ����� ��������� �� ����������. ��������� ����." << std::endl;
		throw 1;
	}
}