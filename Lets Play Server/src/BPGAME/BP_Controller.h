#pragma once
#include <string>
#include <iostream>
#include "../Util_JSON/JSON_Management.h"
#include "../DataStructures/Matrix_bp.h"
#include <mutex>

using namespace std;


class BP_Controller
{

protected:
	BP_Controller();
	~BP_Controller();
private:
	static BP_Controller* unique_instance;
	static mutex mutex_;

public:

	int rows = 12;
	int column = 17;
	Matrix_bp* bp_matrix = new Matrix_bp(rows, column);;
	

	static BP_Controller* getInstance();

	/**
	 * @brief Method that doesn't let the server instance be cloneable.
	 */
	void operator=(const BP_Controller&) = delete;

	/**
	 * @brief Method that doesn't let the server be assignable.
	 * @param other
	 */
	BP_Controller(BP_Controller& other) = delete;

    /**
     * @brief Generates a list that contains Random_Box.h objects in random positions
     * @param players the amount of players used for assigning the random positions
     * @return the player_positions list
    */
    SimplyLinkedList<Random_Box*>* generate_Random(int players) {

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
			pos->setPosx(random_row(0,11));
			pos->setPosy(random_col(0,8));

			if (player_positions->getLen() != 0) {
				for (int i = 0; i < player_positions->getLen(); i++)
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
			pos1->setPosx(random_row(0, 11));
			pos1->setPosy(random_col(9,16));

			if (player_positions->getLen() != 0) {
				for (int i = 0; i < player_positions->getLen(); i++)
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

		return player_positions;
	}

	/**
	 * @brief Creates a random integer in a specified range used for rows
	 * @param min the mininimun value for the random positions
	 * @param max the maximun value for the random positions
	 * @return the random integer
	*/
	int random_row(int min,int max) {
		int randrow1 = rand() % (max - min + 1) + min;
		return randrow1;

	}

	/**
	 * @brief Creates a random integer in a specified range used for cols
	 * @param min the mininimun value for the random positions
	 * @param max the maximun value for the random positions
	 * @return the random integer
	*/
	int random_col(int min, int max) {
		int randcol1 = rand() % (max - min + 1) + min;
		return randcol1;
	}

	/**
	 * @brief Grabs the player list with random positions and adds it to the logical matrix
	 * @param p_locations the simply linked list of the players
	*/
	void Pin_up(SimplyLinkedList<Random_Box*>* p_locations) {
		
		for (int i = 0; i < p_locations->getLen(); i++)
		{
			int varx = p_locations->get(i)->getPosx();
			int vary = p_locations->get(i)->getPosy();
			bp_matrix->setValue(varx, vary, 1);

		}

	}

	/**
	 * @brief Getter for the matrix linked list
	 * @return the linked list
	*/
	SimplyLinkedList<SimplyLinkedList<bp_Box*>*> *getMatrix() {

		return bp_matrix->getMatrix_list();
	}
	
	/**
	 * @brief Initializes the matrix 
	 * @param totalplayers the amount of players 
	 * @return the simply linked list matrix
	*/
	SimplyLinkedList<Random_Box*>* Init_BP(const char *totalplayers) {
		int total_players = atoi(totalplayers);
		bp_matrix->printMatrix();
		bp_matrix->fill_Matrix();
		SimplyLinkedList<Random_Box*>* newplayers_location = generate_Random(total_players);
		Pin_up(newplayers_location);
		bp_matrix->printMatrix();
		bp_matrix->printMatrixName();
		return newplayers_location;

	}

};

