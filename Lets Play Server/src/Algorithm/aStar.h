#pragma once
#include <iostream>
#include <set>
#include "../BPGAME/BP_Controller.h"
#include "../DataStructures/bp_Box.h"
#include "../DataStructures/SimplyList.h"
#include <stack>

#define ROW 15 
#define COL 10 

using namespace std;

SimplyLinkedList<bp_Box*> *routeList = new SimplyLinkedList<bp_Box*>();


class aStar
{

public: 

	typedef pair<int, int> Pair;
	typedef pair<double, pair<int, int>> pPair;

	struct cell
	{
		int parent_i, parent_j;
		double f, g, h;
	};

	
	static bool isValid(int row, int col)
	{
		return (row >= 0) && (row < ROW) &&
			(col >= 0) && (col < COL);
	}
	
	static bool isUnBlocked(int row, int col)
	{
		// LLAMAR AL BP_MATRIX (SINGLETON)
		if (BP_Controller::getInstance()->getMatrix()->get(row)->get(col)->getValue() == 0)
			return (true);
		else
			return (false);
	}

	static bool isGoal(int row, int col)
	{
		if (row == 5 && col == 0 || row == 5 && col == 15)
			return (true);
		else
			return (false);
	}

	
	static double calc_Hvalue(int row,int col, string currentplayer)
	{
		if (currentplayer == "1") {
			return (double)abs(row - 5) + abs(15 - col);
		}
		else {
			return (double)abs(row - 5) + abs(0 - col);
		}
		
	}

	static void tracePath(cell cellDetails[][COL], string currentplayer) {

		int row, col;

		if (currentplayer == "1") {
			row = 5;
			col = 15;
		}
		else {
			row = 5;
			col = 0;
		}

		stack<bp_Box*> *Path;

		while (!(cellDetails[row][col].parent_i== row
			&& cellDetails[row][col].parent_j == col))
		{
			auto newNode = new bp_Box();
			newNode->setPosx(row);
			newNode->setPosy(col);
			Path->push(newNode);
			int temp_row = cellDetails[row][col].parent_i;
			int temp_col = cellDetails[row][col].parent_j;
			row = temp_row;
			col = temp_col;
		}

		auto newNode1 = new bp_Box();
		newNode1->setPosx(row);
		newNode1->setPosy(col);
		Path->push(newNode1);

		while (!Path->empty())
		{
			auto bp_pop = new bp_Box();
			bp_pop = Path->top();

			Path->pop();


			routeList->append(bp_pop);

		}

		return;

	}
	
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

	void printRoute()
	{
		cout << "-----------------------------------------------------------" << endl;
		for (int i = 0; i < routeList->getLen(); i++)
		{

			cout <<"( " << routeList->get(i)->getPosx()<< " , "<< routeList->get(i)->getPosx()<<" ) " << " ->";

		}
	}


};
