#pragma once
#include <iostream>
#include <cstdlib>
#include "SimplyList.h"


using namespace std;



class Matrix_Utilities
{ 
public:
	int matrixRows, matrixColumns;
    SimplyLinkedList<SimplyLinkedList<int>*>* bpMatrix;

	Matrix_Utilities(int lenghtRow, int lenghtColumn) {

		SimplyLinkedList<int>* newListRow;
		this->matrixRows = lenghtRow;
		this->matrixColumns = lenghtColumn;

		this->bpMatrix = new SimplyLinkedList<SimplyLinkedList<int>*>();
		

		newListRow = createBlankRow(lenghtColumn);
		


		for (size_t i = 0; i < lenghtRow; i++)
		{
			bpMatrix->append(newListRow);

		}

	}
	SimplyLinkedList<int>* createBlankRow(int lenght) {
		auto rowList = new SimplyLinkedList<int>();

		for (size_t i = 0; i < lenght; i++)
		{
			rowList->append(0);
		}

		return rowList;
	}
	int getValor(int pos_i, int pos_j) {
		int result;

		for (size_t i = 0; i < matrixRows; i++){
			for (size_t j = 0; j < matrixColumns; j++){
				result = bpMatrix->get(i)->get(j);
			}
		}
		return result;
	}
	void printMatrix() {
		if (this->matrixRows == 0 and this->matrixColumns == 0) {
			cout << "[]" << endl;
		}
		else
		{
			cout << "[" << endl;
			for (size_t i = 0; i < matrixRows; i++)
			{
				this->bpMatrix->get(i)->show();
				
				
			}
			cout << "]" << endl;
		}
	}

	


};

