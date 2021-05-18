#pragma once
#include <iostream>


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

};

