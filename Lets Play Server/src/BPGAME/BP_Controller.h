#pragma once
#include <string>
#include <iostream>
#include "../Util_JSON/JSON_Management.h"
#include "../DataStructures/Matrix_bp.h"

using namespace std;

class BP_Controller
{

public: 
	
	
	static void Init_BP(const char *totalplayers) {
		int total_players = atoi(totalplayers);
		static auto bp_matrix = new Matrix_bp(11, 16);
		bp_matrix->printMatrix();
		bp_matrix->fill_Matrix();
		bp_matrix->printMatrixName();
		//bp_matrix->generate_Random(total_players);
		
		
		


	}
};

