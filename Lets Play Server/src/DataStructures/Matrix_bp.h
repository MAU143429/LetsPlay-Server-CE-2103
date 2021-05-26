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
	

	Matrix_bp(int lenghtRow, int lenghtColumn) {

		SimplyLinkedList<bp_Box*>* newListRow;
		this->matrixRows = lenghtRow;
		this->matrixColumns = lenghtColumn;

		this->bpMatrix = new SimplyLinkedList<SimplyLinkedList<bp_Box*>*>();
		

		newListRow = createBlankRow(lenghtColumn);
		
		

		for (size_t i = 0; i < lenghtRow; i++)
		{
			bpMatrix->append(newListRow);

		}
		
		

	}
	SimplyLinkedList<bp_Box*>* createBlankRow(int lenght) {
		auto rowList = new SimplyLinkedList<bp_Box*>();
		

		for (size_t i = 0; i < lenght; i++)
		{
			auto box = new bp_Box();
			rowList->append(box);
		}

		return rowList;
	}

	int getValor(int pos_i, int pos_j) {
		int result;

		for (size_t i = 0; i < matrixRows; i++){

			if (i == pos_i) {
				for (size_t j = 0; j < matrixColumns; j++) {
					result = bpMatrix->get(i)->get(j)->getValue();
					return result;
				}
			}
		}
		cout<<"VALOR NO ENCONTRADO"<<endl; 
	}
	void printMatrix() {
		if (this->matrixRows == 0 and this->matrixColumns == 0) {
			cout << "[]" << endl;
		}
		else
		{
			cout << "[ " << endl;
			for (size_t i = 0; i < matrixRows; i++)
			{
				for (size_t j = 0; j < matrixColumns; j++) {
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


	void printMatrixName() {
		if (this->matrixRows == 0 and this->matrixColumns == 0) {
			cout << "[]" << endl;
		}
		else
		{
			cout << "[ " << endl;
			for (size_t i = 0; i < matrixRows; i++)
			{
				for (size_t j = 0; j < matrixColumns; j++) {
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
	void fill_Matrix() {

		int cont = 1;

		for (size_t i = 0; i < matrixRows; i++) {

			for (size_t j = 0; j < matrixColumns; j++) {
				
				bpMatrix->get(i)->get(j)->setName(cont);
				bpMatrix->get(i)->get(j)->setPosx(i);
				bpMatrix->get(i)->get(j)->setPosy(j);
				cont++;
				cout << cont;
			}
		}
	}

	SimplyLinkedList<Random_Box*> generate_Random(int players) {

		

	}





};

