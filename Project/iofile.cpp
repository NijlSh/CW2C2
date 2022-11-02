#include "iofile.h"

bool fileOutput(std::vector<std::shared_ptr<figure>>& shp, int counter) 
{
	std::ofstream file;
	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	bool is_stream_opened = false;
	std::string file_name = "";

	do
	{
		try
		{
			file_name = GetFileName(output);
			file.open(file_name);
			is_stream_opened = true;
		}
		catch (const std::exception&) 
		{
			std::cout << "Ошибка при попытке открыть файл." << std::endl;
			continue;
		}
	} while (!is_stream_opened);

	while (true)
	{

		file << counter << std::endl;
		try {
			for (auto& elem : shp) {
				if (elem->getName() == "круг") {
					auto tmp = std::dynamic_pointer_cast<circle>(elem);
					file << tmp->getName() << std::endl;
					file << tmp->getRadius() << std::endl;
				}
				else if (elem->getName() == "прямоугольник") {
					auto tmp = std::dynamic_pointer_cast<rectangle>(elem);
					file << tmp->getName() << std::endl;
					file << tmp->getHeight() << std::endl;
					file << tmp->getWidht() << std::endl;
				}
				else {
					auto tmp = std::dynamic_pointer_cast<trapezoid>(elem);
					file << tmp->getName() << std::endl;
					file << tmp->getLargeBase() << std::endl;
					file << tmp->getLeftSide() << std::endl;
					file << tmp->getRightSide() << std::endl;
					file << tmp->getSmallerBase() << std::endl;
				}

			}
			std::cout << "Данные успешно сохранены." << std::endl;
			file.close();
			return false;
		}
		catch (const std::exception&) 
		{
			std::cout << "Ошибка при записи информации в файл." << std::endl;
			file.close();
			return true;
		}
	}
}

bool fileInput(std::vector<std::shared_ptr<figure>>& shp) 
{
	std::ifstream file;
	file.exceptions(std::istream::badbit | std::ifstream::failbit);
	bool is_stream_opened = false;
	std::string file_name = "";

	do
	{
		try
		{
			file_name = GetFileName(input);
			file.open(file_name);
			is_stream_opened = true;
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка при попытке открыть файл." << std::endl;
			continue;
		}
	} while (!is_stream_opened);

	while (true)
	{
		
		try 
		{
			int size = getLineI(file);
			for (int i = 0; i < size; i++)
			{
				std::string name = getLineS(file);
				if (name == "круг")
				{
					auto c_ptr = std::make_shared<circle>();
					c_ptr->setRadius(getLineD(file));
					shp.push_back(c_ptr);
				}
				else if (name == "прямоугольник")
				{
					auto r_ptr = std::make_shared<rectangle>();
					r_ptr->setHeight(getLineD(file));
					r_ptr->setWidth(getLineD(file));
					shp.push_back(r_ptr);
				}
				else if (name == "трапеция")
				{
					auto t_ptr = std::make_shared<trapezoid>();
					t_ptr->setLargeBase(getLineD(file));
					t_ptr->setLeftSide(getLineD(file));
					t_ptr->setRightSide(getLineD(file));
					t_ptr->setSmallerBase(getLineD(file));
					if (!(t_ptr->checkTrapezoid(t_ptr->getLargeBase(), t_ptr->getLeftSide(), t_ptr->getRightSide(), t_ptr->getSmallerBase()))) throw 1;

					shp.push_back(t_ptr);
				}
				else throw 1;
			}
			file.close();
			return false;
		}
		catch (int)
		{
			std::cout << "Ошибка при чтении информации из файла." << std::endl;
			file.close();
			return true;
		}
		catch (const std::exception&) 
		{
			std::cout << "Ошибка при чтении информации из файла." << std::endl;
			file.close();
			return true;
		}
	}
}

bool fileOutputFin(std::vector<std::shared_ptr<figure>>& shp)
{
	int index = 1;
	std::ofstream  file;
	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	bool is_stream_opened = false;
	std::string file_name = "";

	do
	{
		try
		{
			file_name = GetFileName(output);
			file.open(file_name);
			is_stream_opened = true;
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка при попытке открыть файл." << std::endl;
			continue;
		}
	} while (!is_stream_opened);

	while (true)
	{
		try
		{
			for (auto&& elem : shp) {
				file << "Объект № " << index << " Название фигуры: ";
				file << elem->getName() << std::endl;
				file << "Площадь: " << elem->getSquare() << std::endl;
				file << "Периметр: " << elem->getPerimeter() << std::endl;
				file << "" << std::endl;
				index++;
			}
			std::cout << "Данные успешно записаны." << std::endl;

			file.close();
			return false;
		}
		catch (int) 
		{
			std::cout << "Ошибка при записи информации в файл." << std::endl;
			file.close();
			return true;
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка при записи информации в файл." << std::endl;
			file.close();
			return true;
		}
	}
}


