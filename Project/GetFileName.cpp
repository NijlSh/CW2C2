#include "GetFileName.h"

bool IsValidName(std::string name)
{
	std::cout << std::endl;
	try
	{
		if (name.find(".txt") >= std::string::npos)
		{
			std::cout << "Неверный тип файла. Повторите ввод." << std::endl;
			return false;
		}

		std::string temp1 = "", temp2 = name;
		for (int i = 0; i < WIN_NAME_SIZE; i++)
		{
			temp1 = win_name[i] + ".TXT";
			if (temp1.size() == temp2.size())
			{
				for (int j = 0; temp2[j]; j++)
				{
					temp2[j] = static_cast<char>(toupper(temp2[j]));
				}
				if (temp1 == temp2)
				{
					std::cout << "Введено зарезервированное операционной системой Windows слово. Повторите ввод." << std::endl;
					return false;
				}
			}
		}

		return true;
	}

	catch (std::exception&)
	{
		std::cout << "Ошибка." << std::endl;
		return false;
	}
}

bool IsCanOpenFile(const std::string file_name, const int stream_type)
{
	const int this_file = 2;

	try {
		if (std::ifstream(file_name))
		{
			if (stream_type == output)
			{
				std::cout << "Файл уже существует. Вы хотите пересоздать его?" << std::endl
					<< "1 - Нет." << std::endl
					<< "2 - Да." << std::endl;
				int user_choice = CheckMenu(2);
				if (user_choice != this_file)
					return false;
			}
		}
		else if (stream_type == input)
		{
			std::cout << "Файла с таким названием не существует. Потворите ввод." << std::endl;
			return false;
		}
		return true;
	}
	catch (std::exception&) 
	{
		std::cout << "Ошибка." << std::endl;
		return false;
	}
}

std::string GetFileName(int stream_type)
{
	std::string name; //Название файла

	while (true)
	{
		std::cout << "Введите название файла или полный путь до него." << std::endl << "Ввод: "; 
		std::getline(std::cin, name); //Ввод 

		if (!IsValidName(name)) //Если введённое название недоступно
		{
			std::cin.sync(); //Очистить поток cin
			continue; //Уйти на новый цикл
		}
		try
		{
			if (IsCanOpenFile(name, stream_type)) //Если можно открывать файл
				return name; //Вернуть имя
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка." << std::endl;
		}
	}
}
