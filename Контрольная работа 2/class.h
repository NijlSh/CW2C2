#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <string>

class figure {
public:
	virtual double getSquare() = 0;
	virtual double getPerimeter() = 0;
	virtual std::string getName() = 0;
	virtual ~figure() = default;
};

class circle : public figure {
private:
	const std::string name_ = "круг";
	double radius_ = 0;
public:
	circle() = default;
	circle(double radius);//Конструктор
	void setRadius(double rad);
	double getRadius();
	double getSquare() override;
	double getPerimeter() override;
	std::string getName()override;
};
class rectangle : public figure {
private:
	const std::string name_ = "прямоугольник";
	double width_ = 0.0;
	double height_ = 0.0;
public:
	rectangle() = default;
	rectangle(double width, double height);
	void setWidth(double width);
	double getWidht();
	void setHeight(double height);
	double getHeight();
	double  getSquare() override;
	double getPerimeter() override;
	std::string getName()override;
};
class trapezoid : public figure {
private:
	const std::string name_ = "трапеция";
	double large_base_ = 0.0;
	double smaller_base_ = 0.0;
	double right_side_ = 0.0;
	double left_side_ = 0.0;

public:
	trapezoid() = default;
	trapezoid(double large_base_, double left_side_, double right_side_,  double smaller_base_);
	bool checkTrapezoid(double lb, double ls, double rs, double sb);
	void setLargeBase(double lb);
	double getLargeBase();
	void setSmallerBase(double sb);
	double getSmallerBase();
	void  setRightSide(double rs);
	double getRightSide();
	void  setLeftSide(double ls);
	double getLeftSide();
	double getSquare() override;
	double getPerimeter() override;
	std::string getName()override;
};