#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "class.h"
#include "interface.h"
#include "iofile.h"
#include "check.h"

void circleChoice(std::vector<std::shared_ptr<figure>>& shp);
void rectangleChoice(std::vector<std::shared_ptr<figure>>& shp);
void trapezoidChoice(std::vector<std::shared_ptr<figure>>& shp);

void showResult(std::vector<std::shared_ptr<figure>>& shp);
