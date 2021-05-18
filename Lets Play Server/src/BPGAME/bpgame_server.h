#pragma once
#include <iostream>
#include "../DataStructures/Matrix_Utilities.h"

using namespace std;

class  bpgame_server
{
	
public:

	 static void Create_Matrix() {
			
		 int matriz1[11][18];

		Matrix_Utilities::FillMatrix(matriz1);
		Matrix_Utilities::showMatrix(matriz1);
		cout << "LA MATRIZ SE CREO CON EXITO";
		                                 
	 }

	

};

