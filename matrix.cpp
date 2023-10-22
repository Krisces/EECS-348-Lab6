#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size, std::ifstream& inputFile) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    std::ifstream inputFile("matrix_input.txt");

    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    inputFile >> size;

    readMatrix(matrixA, size, inputFile);
    readMatrix(matrixB, size, inputFile);

    std::cout << "Kristin Boeckmann" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "\nMatrix A:" << std::endl;
    printMatrix(matrixA, size);

    std::cout << "\nMatrix B:" << std::endl;
    printMatrix(matrixB, size);

    std::cout << "\nMatrix Sum (A + B):" << std::endl;
    addMatrices(matrixA, matrixB, result, size);
    printMatrix(result, size);

    std::cout << "\nMatrix Product (A * B):" << std::endl;
    multiplyMatrices(matrixA, matrixB, result, size);
    printMatrix(result, size);

    std::cout << "\nMatrix Difference (A - B):" << std::endl;
    subtractMatrices(matrixA, matrixB, result, size);
    printMatrix(result, size);

    return 0;
}

