#ifndef MATRIX_H
#define MATRIX_H

typedef int* pInt;


namespace utils {

pInt* GenMatrix (int N, int M=1, bool random=true);

void PrintMatrix (pInt* Matrix, int N, int M=1, int w=4);

}

#endif