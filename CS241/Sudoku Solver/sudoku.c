/***************
 *Ron Crisman
 *CS 241
 *Standard back tracking
 *Sudoku solver
 ***************/

#include <stdio.h>
#include <string.h>
//Sub square size
#define SUBSQ 3
//Size of the grid (std sudoku is 9)
#define STDGRD 9
//True and false because it makes more sense
#define TRUE 1
#define FALSE 0
//Empty space is zero as zero is not a valid sudoku number
#define EMPTY 0

int sudoku[STDGRD][STDGRD]; //Storage for the puzzle

int solved = 0;

//Checks for repeat of number on given row
int chkRow(int row, int num)
{
  int col; //grumble grumble can't initilize vars in loops (wtb C99)

  for(col = 0; col < STDGRD; col++)
    {
      if(sudoku[row][col] == num)
	{
	  return FALSE;
	}
      else
	{
	  return TRUE;
	}
    }
}

//Checks for given number on given column
int chkCol(int num, int col)
{
  int row;
  
  for(row = 0; row < STDGRD; row++)
    {
      if(sudoku[row][col] == num)
	{
	  return FALSE;
	}
      else
	{
	  return TRUE;
	}
    }
}

/**Ok, trickier part. Checking to see if the number fits in the 3x3
 *grid. First, finding the initial point of the 3x3 grid
 *Orignally using much more complicated method until the (row/3)*3
 *was mentioned in class. Got rid of all my stupid if statements!
 */

int chkGrd(int row, int col, int num)
{
  int r;
  int c;

  row = (row/3)*3;
  col = (col/3)*3;

  //loops through subsquare. If the number is present, return FULL
  for(c = 0; c < SUBSQ; c++)
    for (r = 0; r < SUBSQ; r++)
      if(sudoku[row + r][col + c] == num)
	{
	return FALSE; 
	}
      else
	{
	  return TRUE;
	}
}

//Moves the solver to the next cell if one is filled
void gtPoint(int row, int col)
{
  if (col < (STDGRD-1))
    {
      solve(row, (col+1));
    }	    
		  else
		    {
		      solve((row+1),0);
		    }
}

void solve(int row, int col)
{
  //Yay! We're done! Print the complete puzzle!
  if(row > (STDGRD-1))
    {    
      printSudoku();
    }
  if(sudoku[row][col] != EMPTY)
    {
      gtPoint(row, col);
    }
  else
    {
      int i;
      for(i = 1; i <= 9; i++)
	{
	  if((chkRow(row, i) == 1) && (chkCol(i, col) == 1) && 
	     (checkgrid(row, col, i) == 1))
	    {
	      sudoku[row][col] = ctr;
	      gtPoint(row,col);
	    }
	}
      //Not doing cleanup in recursion was causing me problems!
      sudoku[row][col] = 0;
    }
}

//Write this next!
void printSudoku()
{


}

int main()
{





}
