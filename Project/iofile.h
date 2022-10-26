#pragma once

#include <memory>
#include <vector>
#include <fstream>

#include "algorithm.h"
#include "check.h"
#include "GetFileName.h"

bool fileOutput(std::vector<std::shared_ptr<figure>>& shp, int counter);
bool fileInput(std::vector<std::shared_ptr<figure>>& shp);
bool fileOutputFin(std::vector<std::shared_ptr<figure>>& shp);