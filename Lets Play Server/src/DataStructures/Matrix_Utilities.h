#pragma once
#include <iostream>
#include <cstdlib>



using namespace std;

class Matrix_Utilities
{
    
public:
       
   //##################################//
   /**
              0 = Empty Space
              1 = PlayerSpot (Obstacle)
              2 = Goal Box
              3 = Hitbox space
   */
   //##################################//

    static void FillMatrix(int M[11][18])
    {
        for (int i = 0; i < 11; i++)
        {
            
            for (int j = 0; j < 18; j++)
            {
                if (j == 0 and i == 5 or j == 17 and i == 5) {
                    M[i][j] = 2;
                }
                else if (j == 0 or j == 17 and i != 5) {

                    M[i][j] = 3;
                }
                else{
                    M[i][j] = 0;
                }
                
                
            }
            
        }

    }

    static void showMatrix(int M[11][18])
    {

        for (int i = 0; i < 11; i++)
        {
            cout << "[";
            for (int j = 0; j < 18; j++)
            {
                if (j == 17) {
                    cout << M[i][j];
                }
                else {
                    cout << M[i][j] << " , ";
                }
                
            }
            
            cout << "]," << endl;
        }

    }


    static void RandomMatrix(int M[11][18],int players)
    {
        // Create a random number of players in right field
        for (int i = 0; i < players; i++)
        {
            int randrow = rand() % (9 - 0 + 1) + 0;
            int randcol = rand() % (8 - 1 + 1) + 1;

            cout << " EL JUGADOR VA APARECER EN LA POSICION   (" << randrow << " , " << randcol << ")" <<endl;

            /**
            cout << "[";
            for (int j = 0; j < 18; j++)
            {
                if (j == 17) {
                    cout << M[i][j];
                }
                else {
                    cout << M[i][j] << " , ";
                }

            }

            cout << "]," << endl;
            */
        }

        // Create a random number of players in left field


    }

};

