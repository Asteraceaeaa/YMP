#ifndef FILES_H
#define FILES_H

#include <string>
#include "matrix.h"

typedef int* pInt;
namespace utils {

pInt* ReadMatrixFromFile(const std::string& filename, int N, int M);




}

#endif