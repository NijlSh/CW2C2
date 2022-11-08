#include "GetFileName.h"

std::string FileInput()
{
	while (true)
	{
		std::string file_path;

		std::cout << "Ââîä: ";
		getline(std::cin, file_path);

		if (file_path.find(".txt") >= std::string::npos)
		{
			std::cout << "Íå òåêñòîâûé ôàéë. Ïîâòîðèòå ââîä." << std::endl;
			return false;
		}

		if (!std::ifstream(file_path)) {
			std::cout << "Ôàéë íå ñóùåñòâóåò. Ïîâòîðèòå ââîä." << std::endl;
			continue;
		}

		std::error_code ec;
		if (!is_regular_file(file_path, ec))
		{
			std::cout << "Àäðåñ ñîäåðæèò íåäîïóñòèìûå çíà÷åíèÿ. Ïîâòîðèòå ââîä." << std::endl;
			continue;
		}

		std::ifstream myFile(file_path);
		if (!myFile) {
			std::cout << "Çàãðóçêà çàïðåùåíà. Ïîâòîðèòå ââîä." << std::endl;
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

		std::cout << "Ñîõðàíèòü èç: ";
		getline(std::cin, file_path);

		if (file_path.find(".txt") >= std::string::npos) 
		{
			std::cout << "Íå òåêñòîâûé ôàéë. Ïîâòîðèòå ââîä." << std::endl;
			return false;
		}

		if (std::ifstream(file_path))
		{
			std::cout << "Ôàéë óæå ñóùåñòâóåò." << std::endl;
			std::cout << "[1] - Ïåðåçàïèñàòü ñóùåñòâóþùèé ôàéë." << std::endl;
			std::cout << "[2] - Ïîâòîðèòü ââîä." << std::endl;
			int tryAnotherFile = getBinChoice();
			if (tryAnotherFile == get_name)
			{
				continue;
			}
		}

		std::ofstream myFile(file_path, std::ofstream::app);

		std::error_code ec;
		if (!is_regular_file(file_path, ec))
		{
			std::cout << "Àäðåñ ñîäåðæèò íåäîïóñòèìûå çíà÷åíèÿ. Ïîâòîðèòå ââîä." << std::endl;
			continue;
		}
		if (!myFile)
		{
			std::cout << "Çàïèñü çàïðåùåíà. Ïîâòîðèòå ââîä." << std::endl;
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
