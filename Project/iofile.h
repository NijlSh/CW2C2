#pragma once

#include <memory>
#include <vector>
#include <fstream>
#include <filesystem>

#include "algorithm.h"
#include "check.h"

void fileOutput(std::vector<std::shared_ptr<figure>>& shp, int counter);
void fileInput(std::vector<std::shared_ptr<figure>>& shp);
void fileOutputFin(std::vector<std::shared_ptr<figure>>& shp);