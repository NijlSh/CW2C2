#include "GetFileName.h"

std::string FileInput()
{
	while (true)
	{
		std::string file_path;

		std::cout << "Ввод: ";
		getline(std::cin, file_path);

		if (file_path.find(".txt") >= std::string::npos)
		{
			std::cout << "Не текстовый файл. Повторите ввод." << std::endl;
			return false;
		}

		if (!std::ifstream(file_path)) {
			std::cout << "Файл не существует. Повторите ввод." << std::endl;
			continue;
		}

		std::error_code ec;
		if (!is_regular_file(file_path, ec))
		{
			std::cout << "Адрес содержит недопустимые значения. Повторите ввод." << std::endl;
			continue;
		}

		std::ifstream myFile(file_path);
		if (!myFile) {
			std::cout << "Загрузка запрещена. Повторите ввод." << std::endl;
			myFile.close();
			continue;
		}
		myFile.close();
		return file_path;
	}
}

std::string FileOutput()
{
	const int get_name = 2;

	while (true)
	{
		std::string file_path;

		std::cout << "Сохранить из: ";
		getline(std::cin, file_path);

		if (file_path.find(".txt") >= std::string::npos) 
		{
			std::cout << "Не текстовый файл. Повторите ввод." << std::endl;
			return false;
		}

		if (std::ifstream(file_path))
		{
			std::cout << "Файл уже существует." << std::endl;
			std::cout << "[1] - Перезаписать существующий файл." << std::endl;
			std::cout << "[2] - Повторить ввод." << std::endl;
			int tryAnotherFile = CheckMenu(2);
			if (tryAnotherFile == get_name)
			{
				continue;
			}
		}

		std::ofstream myFile(file_path, std::ofstream::app);

		std::error_code ec;
		if (!is_regular_file(file_path, ec))
		{
			std::cout << "Адрес содержит недопустимые значения. Повторите ввод." << std::endl;
			continue;
		}
		if (!myFile)
		{
			std::cout << "Запись запрещена. Повторите ввод." << std::endl;
			myFile.close();
			continue;
		}
		myFile.close();
		return file_path;
	}
}

std::string GetFileName(int stream_type)
{
	while (true) {
		std::string file_path;

		switch (stream_type)
		{
		case input:
			return file_path = FileInput();
		case output:
			return file_path = FileOutput();
		}
	}
}