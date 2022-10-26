#include "algorithm.h"

void circleChoice(std::vector<std::shared_ptr<figure>>& shp) 
{
	auto temp = std::make_shared<circle>();
	std::cout << "Введите радиус: ";
	temp->setRadius(getPositiveValue<double>());

	shp.push_back(temp);
}
void rectangleChoice(std::vector<std::shared_ptr<figure>>& shp)
{
	auto temp = std::make_shared<rectangle>();
	std::cout << "Введите высоту: ";
	temp->setHeight(getPositiveValue<double>());
	std::cout << "Введите ширину: ";
	temp->setWidth(getPositiveValue<double>());

	shp.push_back(temp);
}
void trapezoidChoice(std::vector<std::shared_ptr<figure>>& shp) 
{
	while (true) {
		auto temp = std::make_shared<trapezoid>();
		std::cout << "Введите значение большего основания: ";
		temp->setLargeBase(getPositiveValue<double>());
		std::cout << "Введите значение левой стороны: ";
		temp->setLeftSide(getPositiveValue<double>());
		std::cout << "Введите значение правой стороны: ";
		temp->setRightSide(getPositiveValue<double>());
		std::cout << "Введите значение меньшего основания: ";
		temp->setSmallerBase(getPositiveValue<double>());
		if (!(temp->checkTrapezoid(temp->getLargeBase(), temp->getLeftSide(), temp->getRightSide(), temp->getSmallerBase())))
		{
			std::cout << "Введены некорректные данные: ";
			temp->getSmallerBase() >= temp->getLargeBase() 
				? std::cout << "меньшее основание больше большего основания." << std::endl 
				: std::cout << "длина одной из сторон больше суммы длин остальных сторон." << std::endl;
			continue;
		}

		shp.push_back(temp);
		break;
	}
}

void showResult(std::vector<std::shared_ptr<figure>>& shp)
{
	int index = 1;
	std::cout << "Результат работы программы:" << std::endl;
	for (auto& elem : shp) {
		std::cout << "Объект № " << index << " Название фигуры: ";
		std::cout << elem->getName() << std::endl;
		std::cout << "Площадь: " << elem->getSquare() << std::endl;
		std::cout << "Периметр: " << elem->getPerimeter() << std::endl;
		std::cout << "" << std::endl;
		index++;
	}
}