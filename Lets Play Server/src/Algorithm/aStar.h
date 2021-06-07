#pragma once
#include <iostream>
#include <set>
#include "../BPGAME/BP_Controller.h"
#include "../DataStructures/bp_Box.h"
#include "../DataStructures/SimplyList.h"
#include "../DataStructures/Matrix_bp.h"
#include <stack>

#define ROW 12 
#define COL 17 

using namespace std;

static SimplyLinkedList<Random_Box*>* routeList = new SimplyLinkedList<Random_Box*>();

class aStar
{

public: 
	typedef pair<int, int> Pair;
	typedef pair<double, pair<int, int>> pPair;
	

	/**
	 * @brief A structure to hold the neccesary parameters
	*/
	struct cell
	{
		int parent_i, parent_j;
		double f, g, h;
	};

	/**
	 * @brief A Utility Function to check whether given cell (row, col) is a valid cell or not.
	 * @param row the position of the row
	 * @param col the position of the column
	 * @return true if the row and column inserted as parameters is contained in the lenght of the rows and columns of the matrix
	*/
	static bool isValid(int row, int col)
	{
		return (row >= 0) && (row < ROW) &&
			(col >= 0) && (col < COL);
	}
	
	/**
	 * @brief A Utility Function to check whether the given cell is blocked or not  
	 * @param row the position of the row 
	 * @param col the position of the column
	 * @return true if its unblucked false if its blocked
	*/
	static bool isUnBlocked(int row, int col)
	{
		
		if (BP_Controller::getInstance()->getMatrix()->get(row)->get(col)->getValue() == 0)
			return (true);
		else
			return (false);
	
		
	}

	/**
	 * @brief A Utility Function to check whether destination cell has been reached or not 
	 * @param row the position of the row 
	 * @param col the position of the column 
	 * @return true if its contained in the goal position, false if its not
	*/
	static bool isGoal(int row, int col)
	{
		if (row == 5 && col == 0 || row == 5 && col == 16)
			return (true);
		else
			return (false);
	}

	/**
	 * @brief A Utility Function to calculate the 'h' heuristics.
	 * @param row the position of the row 
	 * @param col the position of the column 
	 * @param currentplayer the currentplayer to locate in which sided its on
	 * @return the H value
	*/
	static double calc_Hvalue(int row,int col, string currentplayer)
	{
		if (currentplayer == "1") {
			return (double)abs(row - 5) + abs(16 - col);
		}
		else {
			return (double)abs(row - 5) + abs(0 - col);
		}
		
	}

	/**
	 * @brief A Utility Function to trace the path from the source to destination 
	 * @param cellDetails the cell matrix
	 * @param currentplayer the current player 
	*/
	static void tracePath(cell cellDetails[][COL], string currentplayer) {

		int row, col;

		if (currentplayer == "1") {
			row = 5;
			col = 16;
		}
		else {
			row = 5;
			col = 0;
		}

		stack<Pair> Path;

		while (!(cellDetails[row][col].parent_i== row
			&& cellDetails[row][col].parent_j == col))
		{
			Path.push(make_pair(row, col));
			int temp_row = cellDetails[row][col].parent_i;
			int temp_col = cellDetails[row][col].parent_j;
			row = temp_row;
			col = temp_col;
		}

		Path.push(make_pair(row, col));

		while (!Path.empty())
		{

			pair<int, int> p = Path.top();
			Path.pop();

			auto bp_pop = new Random_Box();
			bp_pop->setPosx(p.first);
			bp_pop->setPosy(p.second);

			routeList->append(bp_pop);
			

		}

		return;

	}
	/**
	 * @brief A Function to find the shortest path between a given source cell to a destination cell according to A* Search Algorithm 
	 * @param currentcell the location of the current bp_Box cell
	 * @param goal the goal destination
	 * @param currplayers the current players 
	*/
	static void aStarSearch(bp_Box *currentcell, bp_Box *goal, string currplayers ) {

		// If the cell is out of range 
		if (isValid(currentcell->getPosx(), currentcell->getPosy()) == false)
		{
			printf("Cell is invalid\n");
			return;
		}
		// If the goal position is out of range 
		if (isValid(goal->getPosx(), goal->getPosy()) == false)
		{
			printf("Goal position is invalid\n");
			return;
		}
		// If the destination cell is the same as source cell 
		if (isGoal(currentcell->getPosx(),currentcell->getPosy()) == true)
		{
			printf("We are already at the destination\n");
			return;
		}


		bool closedList[ROW][COL];
		memset(closedList, false, sizeof(closedList));


		cell cellDetails[ROW][COL];

		int i, j;

		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				cellDetails[i][j].f = FLT_MAX;
				cellDetails[i][j].g = FLT_MAX;
				cellDetails[i][j].h = FLT_MAX;
				cellDetails[i][j].parent_i = -1;
				cellDetails[i][j].parent_j = -1;
			}
		}

		i = currentcell->getPosx(), j = currentcell->getPosy();
		cellDetails[i][j].f = 0.0;
		cellDetails[i][j].g = 0.0;
		cellDetails[i][j].h = 0.0;
		cellDetails[i][j].parent_i = i;
		cellDetails[i][j].parent_j = j;


		set<pPair> openList;
		openList.insert(make_pair(0.0, make_pair(i, j)));


		bool foundDest = false;

		while (!openList.empty())
		{
			pPair p = *openList.begin();

			
			openList.erase(openList.begin());

			
			i = p.second.first;
			j = p.second.second;
			closedList[i][j] = true;

			double gNew, hNew, fNew;

			//----------- 1st Successor (North) ------------ 

			if (isValid(i - 1, j) == true)
			{
				
				if (isGoal(i - 1, j) == true)
				{
					cellDetails[i - 1][j].parent_i = i;
					cellDetails[i - 1][j].parent_j = j;
					printf("The destination cell is found\n");
					tracePath(cellDetails, currplayers);
					foundDest = true;
					return;
				}
				
				else if (closedList[i - 1][j] == false &&
					isUnBlocked(i - 1, j) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calc_Hvalue(i - 1, j, currplayers);
					fNew = gNew + hNew;
 
					if (cellDetails[i - 1][j].f == FLT_MAX ||
						cellDetails[i - 1][j].f > fNew)
					{
						openList.insert(make_pair(fNew,
							make_pair(i - 1, j)));

						cellDetails[i - 1][j].f = fNew;
						cellDetails[i - 1][j].g = gNew;
						cellDetails[i - 1][j].h = hNew;
						cellDetails[i - 1][j].parent_i = i;
						cellDetails[i - 1][j].parent_j = j;
					}
				}
			}

			//----------- 2nd Successor (South) ------------ 
 
			if (isValid(i + 1, j) == true)
			{
				if (isGoal(i + 1, j) == true)
				{
					cellDetails[i + 1][j].parent_i = i;
					cellDetails[i + 1][j].parent_j = j;
					printf("The destination cell is found\n");
					tracePath(cellDetails, currplayers);
					foundDest = true;
					return;
				}
				else if (closedList[i + 1][j] == false &&
					isUnBlocked(i + 1, j) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calc_Hvalue(i + 1, j, currplayers);
					fNew = gNew + hNew;

					if (cellDetails[i + 1][j].f == FLT_MAX ||
						cellDetails[i + 1][j].f > fNew)
					{
						openList.insert(make_pair(fNew, make_pair(i + 1, j)));
				
						cellDetails[i + 1][j].f = fNew;
						cellDetails[i + 1][j].g = gNew;
						cellDetails[i + 1][j].h = hNew;
						cellDetails[i + 1][j].parent_i = i;
						cellDetails[i + 1][j].parent_j = j;
					}
				}
			}
				//----------- 3rd Successor (East) ------------ 
 
			if (isValid(i, j + 1) == true)
			{
				if (isGoal(i, j + 1) == true)
				{
					cellDetails[i][j + 1].parent_i = i;
					cellDetails[i][j + 1].parent_j = j;
					printf("The destination cell is found\n");
					tracePath(cellDetails, currplayers);
					foundDest = true;
					return;
				}

				else if (closedList[i][j + 1] == false &&
					isUnBlocked(i, j + 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calc_Hvalue(i, j + 1, currplayers);
					fNew = gNew + hNew;

					if (cellDetails[i][j + 1].f == FLT_MAX ||
						cellDetails[i][j + 1].f > fNew)
					{
						openList.insert(make_pair(fNew,
							make_pair(i, j + 1)));

						
						cellDetails[i][j + 1].f = fNew;
						cellDetails[i][j + 1].g = gNew;
						cellDetails[i][j + 1].h = hNew;
						cellDetails[i][j + 1].parent_i = i;
						cellDetails[i][j + 1].parent_j = j;
					}
				}
			}

					//----------- 4th Successor (West) ------------ 

					
			if (isValid(i, j - 1) == true)
			{

				if (isGoal(i, j - 1) == true)
				{
					
					cellDetails[i][j - 1].parent_i = i;
					cellDetails[i][j - 1].parent_j = j;

					tracePath(cellDetails, currplayers);
					foundDest = true;
					return;
				}

				else if (closedList[i][j - 1] == false &&
					isUnBlocked(i, j - 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.0;
					hNew = calc_Hvalue(i, j - 1, currplayers);
					fNew = gNew + hNew;

					if (cellDetails[i][j - 1].f == FLT_MAX ||
						cellDetails[i][j - 1].f > fNew)
					{
						openList.insert(make_pair(fNew,
							make_pair(i, j - 1)));

						cellDetails[i][j - 1].f = fNew;
						cellDetails[i][j - 1].g = gNew;
						cellDetails[i][j - 1].h = hNew;
						cellDetails[i][j - 1].parent_i = i;
						cellDetails[i][j - 1].parent_j = j;
					}
				}
			}

			//----------- 5th Successor (North-East) ------------ 

			if (isValid(i - 1, j + 1) == true)
			{
				if (isGoal(i - 1, j + 1) == true)
				{
					cellDetails[i - 1][j + 1].parent_i = i;
					cellDetails[i - 1][j + 1].parent_j = j;
					
					tracePath(cellDetails, currplayers);
					foundDest = true;
					return;
				}

				else if (closedList[i - 1][j + 1] == false &&
					isUnBlocked(i - 1, j + 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calc_Hvalue(i - 1, j + 1, currplayers);
					fNew = gNew + hNew;

					if (cellDetails[i - 1][j + 1].f == FLT_MAX ||
						cellDetails[i - 1][j + 1].f > fNew)
					{
						openList.insert(make_pair(fNew,
							make_pair(i - 1, j + 1)));

						cellDetails[i - 1][j + 1].f = fNew;
						cellDetails[i - 1][j + 1].g = gNew;
						cellDetails[i - 1][j + 1].h = hNew;
						cellDetails[i - 1][j + 1].parent_i = i;
						cellDetails[i - 1][j + 1].parent_j = j;
					}
				}
			}

			//----------- 6th Successor (North-West) ------------ 

			
			if (isValid(i - 1, j - 1) == true)
			{
				if (isGoal(i - 1, j - 1) == true)
				{
					cellDetails[i - 1][j - 1].parent_i = i;
					cellDetails[i - 1][j - 1].parent_j = j;
					
					tracePath(cellDetails, currplayers);
					foundDest = true;
					return;
				}

				else if (closedList[i - 1][j - 1] == false &&
					isUnBlocked(i - 1, j - 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calc_Hvalue(i - 1, j - 1, currplayers);
					fNew = gNew + hNew;

					if (cellDetails[i - 1][j - 1].f == FLT_MAX ||
						cellDetails[i - 1][j - 1].f > fNew)
					{
						openList.insert(make_pair(fNew, make_pair(i - 1, j - 1)));
						
						cellDetails[i - 1][j - 1].f = fNew;
						cellDetails[i - 1][j - 1].g = gNew;
						cellDetails[i - 1][j - 1].h = hNew;
						cellDetails[i - 1][j - 1].parent_i = i;
						cellDetails[i - 1][j - 1].parent_j = j;
					}
				}
			}

			//----------- 7th Successor (South-East) ------------ 
 
			if (isValid(i + 1, j + 1) == true)
			{
			
				if (isGoal(i + 1, j + 1) == true)
				{
					cellDetails[i + 1][j + 1].parent_i = i;
					cellDetails[i + 1][j + 1].parent_j = j;
					
					tracePath(cellDetails, currplayers);
					foundDest = true;
					return;
				}

				else if (closedList[i + 1][j + 1] == false &&
					isUnBlocked(i + 1, j + 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calc_Hvalue(i + 1, j + 1, currplayers);
					fNew = gNew + hNew;

					if (cellDetails[i + 1][j + 1].f == FLT_MAX ||
						cellDetails[i + 1][j + 1].f > fNew)
					{
						openList.insert(make_pair(fNew,
							make_pair(i + 1, j + 1)));
 
						cellDetails[i + 1][j + 1].f = fNew;
						cellDetails[i + 1][j + 1].g = gNew;
						cellDetails[i + 1][j + 1].h = hNew;
						cellDetails[i + 1][j + 1].parent_i = i;
						cellDetails[i + 1][j + 1].parent_j = j;
					}
				}
			}

			//----------- 8th Successor (South-West) ------------ 

			if (isValid(i + 1, j - 1) == true)
			{
				if (isGoal(i + 1, j - 1) == true)
				{
					cellDetails[i + 1][j - 1].parent_i = i;
					cellDetails[i + 1][j - 1].parent_j = j;
					
					tracePath(cellDetails, currplayers);
					foundDest = true;
					return;
				}

				else if (closedList[i + 1][j - 1] == false &&
					isUnBlocked(i + 1, j - 1) == true)
				{
					gNew = cellDetails[i][j].g + 1.414;
					hNew = calc_Hvalue(i + 1, j - 1, currplayers);
					fNew = gNew + hNew;
 
					if (cellDetails[i + 1][j - 1].f == FLT_MAX ||
						cellDetails[i + 1][j - 1].f > fNew)
					{
						openList.insert(make_pair(fNew,
							make_pair(i + 1, j - 1)));

						cellDetails[i + 1][j - 1].f = fNew;
						cellDetails[i + 1][j - 1].g = gNew;
						cellDetails[i + 1][j - 1].h = hNew;
						cellDetails[i + 1][j - 1].parent_i = i;
						cellDetails[i + 1][j - 1].parent_j = j;
					}
				}

			}

		} 

		if (foundDest == false)
			printf("Failed to find the Destination Cell\n");

		return;
	}

	/**
	 * @brief Prints the calculated route according to the algorithm
	*/
	static void printRoute()
	{
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < routeList->getLen(); i++)
		{

			cout <<"( " << routeList->get(i)->getPosx()<< " , "<< routeList->get(i)->getPosy()<<" ) " << " ->";

		}
	}

	static SimplyLinkedList<Random_Box*>* getRouteList() {
		return routeList;
	}
	

};
