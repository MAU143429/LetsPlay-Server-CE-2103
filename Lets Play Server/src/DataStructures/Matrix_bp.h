#pragma once
#include <iostream>
#include <cstdlib>
#include "SimplyList.h"
#include "bp_Box.h"
#include "Random_Box.h"


using namespace std;

class Matrix_bp
{ 
public:
	int matrixRows, matrixColumns;
    SimplyLinkedList<SimplyLinkedList<bp_Box*>*>* bpMatrix;
	
	/**
	 * @brief the constructor of the Matrix_bp.h class that initializes the matrix 
	 * @param lenghtRow 
	 * @param lenghtColumn 
	*/
	Matrix_bp(int lenghtRow, int lenghtColumn) {

		SimplyLinkedList<bp_Box*>* newListRow;
		this->matrixRows = lenghtRow;
		this->matrixColumns = lenghtColumn;

		this->bpMatrix = new SimplyLinkedList<SimplyLinkedList<bp_Box*>*>();
		
		for (size_t i = 0; i < lenghtRow; i++)
		{
			newListRow = createBlankRow(lenghtColumn);
			bpMatrix->append(newListRow);
		}
	}
	/**
	 * @brief Method that creates a row filled with bp_Box.h objects
	 * @param lenght the leght used for creating the row
	 * @return the row created
	*/
	SimplyLinkedList<bp_Box*>* createBlankRow(int lenght) {
		auto rowList = new SimplyLinkedList<bp_Box*>();
		
		for (int i = 0; i < lenght; i++)
		{
			auto box = new bp_Box();
			rowList->append(box);
		}

		return rowList;
	}
	/**
	 * @brief Gets the value searched in the matrix using two indexes
	 * @param pos_i the index in the row postiion 
	 * @param pos_j the index in the column position
	 * @return the value containing an integer
	*/
	int getValue(int pos_i, int pos_j) {
		int result;

		for (int i = 0; i < matrixRows; i++){

			if (i == pos_i) {
				for (int j = 0; j < matrixColumns; j++) {
					result = bpMatrix->get(i)->get(j)->getValue();
					return result;
				}
			}
		}
		cout<<"VALOR NO ENCONTRADO"<<endl; 
	}
	/**
	 * @brief Sets the value searched in the matrix using two indexes
	 * @param pos_i the index in the row postiion
	 * @param pos_j the index in the row postiion
	 * @param value the value used for modifying the value contained in the matrix
	*/
	void setValue(int pos_i, int pos_j, int value) {

		for (int i = 0; i < matrixRows; i++) {

			if (i == pos_i) {
				for (int j = 0; j < matrixColumns; j++) {
					if (j == pos_j) {
						bpMatrix->get(i)->get(j)->setValue(value);
					}
				}
			}
		}
	}
	/**
	 * @brief Prints the matrix in the console
	*/
	void printMatrix() {
		if (this->matrixRows == 0 and this->matrixColumns == 0) {
			cout << "[]" << endl;
		}
		else
		{
			cout << "[ " << endl;
			for (int i = 0; i < matrixRows; i++)
			{
				for (int j = 0; j < matrixColumns; j++) {
					if (j == matrixColumns - 1) {
						cout << bpMatrix->get(i)->get(j)->getValue() << " ] ";
					}
					else if (j == 0) {
						cout << " [ " << bpMatrix->get(i)->get(j)->getValue() << " , ";
					}
					else{
						cout << bpMatrix->get(i)->get(j)->getValue() << " , ";
					}
				}
				cout << endl;
			}
			cout << " ]" << endl;
		}
	}

	/**
	 * @brief Prints the names contained in the different positions of the matrix
	*/
	void printMatrixName() {
		if (this->matrixRows == 0 and this->matrixColumns == 0) {
			cout << "[]" << endl;
		}
		else
		{
			cout << "[ " << endl;
			for (int i = 0; i < matrixRows; i++)
			{
				for (int j = 0; j < matrixColumns; j++) {
					if (j == matrixColumns - 1) {
						cout << bpMatrix->get(i)->get(j)->getName() << " ] ";
					}
					else if (j == 0) {
						cout << " [ " << bpMatrix->get(i)->get(j)->getName() << " , ";
					}
					else {
						cout << bpMatrix->get(i)->get(j)->getName() << " , ";
					}
				}
				cout << endl;
			}
			cout << " ]" << endl;
		}
	}
	/**
	 * @brief Fills all the parameters contained in the matrix.
	*/
	void fill_Matrix() {

		int cont = 1;

		for (int i = 0; i < matrixRows; i++) {


			for (int j = 0; j < matrixColumns; j++) {
				
				bpMatrix->get(i)->get(j)->setName(cont);
				bpMatrix->get(i)->get(j)->setPosx(i);
				bpMatrix->get(i)->get(j)->setPosy(j);
				bpMatrix->get(i)->get(j)->setParentx(-1);
				bpMatrix->get(i)->get(j)->setParenty(-1);
				bpMatrix->get(i)->get(j)->setValue(0);
				cont++;
				
			}
		}
	}
	/**
	 * @brief Getter for the matrix
	 * @return the simply linked list that containes the matrix
	*/
	SimplyLinkedList<SimplyLinkedList<bp_Box*>*>* getMatrix_list() {

		return bpMatrix;
	}

	
};

