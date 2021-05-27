#pragma once
#include <string>
#include <iostream>
#include "../Util_JSON/JSON_Management.h"
#include "../DataStructures/Matrix_bp.h"

using namespace std;

class BP_Controller
{

public: 
 
	static void generate_Random(int players) {

		int half = players / 2;
		int totalleft = 0;
		int	totalright = 0;
		bool exist = false;
		bool exist2 = false;
		SimplyLinkedList<Random_Box*>* player_positions = new SimplyLinkedList<Random_Box*>;
	
		while (totalleft < half)
		{
			exist = false;
			auto pos = new Random_Box();
			pos->setPosx(random_row(0,10));
			pos->setPosy(random_col(0,7));

			if (player_positions->getLen() != 0) {
				for (size_t i = 0; i < player_positions->getLen(); i++)
				{
					if (player_positions->get(i)->getPosx() == pos->getPosx() and player_positions->get(i)->getPosy() == pos->getPosy()) {
						exist = true;
					}
				}
			}
			else {
				player_positions->append(pos);
				totalleft++;
				exist = true;
			}
			
			if (!exist and player_positions->getLen() != 0) {
				player_positions->append(pos);
				totalleft++;
				exist = true;
			}
		}

		while (totalright < half)
		{
			exist2 = false;
			auto pos1 = new Random_Box();
			pos1->setPosx(random_row(0, 10));
			pos1->setPosy(random_col(8,15));

			if (player_positions->getLen() != 0) {
				for (size_t i = 0; i < player_positions->getLen(); i++)
				{
					if (player_positions->get(i)->getPosx() == pos1->getPosx() and player_positions->get(i)->getPosy() == pos1->getPosy()) {
						exist2 = true;
					}
				}
			}
			else {
				player_positions->append(pos1);
				exist2 = true;
				totalright++;
			}

			if (!exist2 and player_positions->getLen() != 0) {
				player_positions->append(pos1);
				totalright++;
				exist2 = true;
			}
		}

		cout << "[ ";
		for (size_t i = 0; i < player_positions->getLen(); i++)
		{
			cout << "( " << player_positions->get(i)->getPosx() << ", " << player_positions->get(i)->getPosy() << " )" ;
		}
		cout << " ] ";
	}

	static int random_row(int min,int max) {
		int randrow1 = rand() % (max - min + 1) + min;
		return randrow1;

	}
	static int random_col(int min, int max) {
		int randcol1 = rand() % (max - min + 1) + min;
		return randcol1;
	}
	
	static void Init_BP(const char *totalplayers) {
		int total_players = atoi(totalplayers);
		static auto bp_matrix = new Matrix_bp(11, 16);
		bp_matrix->printMatrix();
		bp_matrix->fill_Matrix();
		bp_matrix->printMatrixName();
		
		generate_Random(12);
		
	}

};

