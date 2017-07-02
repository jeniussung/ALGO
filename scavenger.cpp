#include <iostream>

using namespace std;

bool goleft(int **&matrix, int &r, int &c, int &d);
void gostraight(int **&matrix, int &r, int &c, int &d);
void rotate(int &d);
void goback(int **&matrix, int &r, int &c, int &d, int &var);

int main()
{
   int n, m;
   int r, c, d;
   int clean = 1;
   int re = 0;
   int returnvar = 1;
   cin >> n >> m;
   cin >> r >> c >> d;
   int **matrix = new int*[n];
   
   for (int i = 0; i < n; i++)
      matrix[i] = new int[m];

   
   for (int i = 0; i < n;i++)
      for (int j = 0; j < m; j++)
         cin >> matrix[i][j];

      matrix[r][c] = 2;

      while (returnvar)
      {
         if (re == 4)
         {
            goback(matrix, r, c, d, returnvar);
            re = 0;
         }

         if (goleft(matrix, r, c, d))
         {
            rotate(d);
            gostraight(matrix, r, c, d);
            clean++;
            re = 0;
         }
         else
         {
            re++;
             rotate(d);
         }
         
      }

      cout << clean << endl;
}


void rotate(int &d)
{
   if (d == 0)
      d = 3;
   else if (d == 1)
      d = 0;
   else if (d == 2)
      d = 1;
   else if (d == 3)
      d = 2;
}


bool goleft(int **&matrix, int &r, int &c, int &d)
{
   if (d == 0)
   {
      if (matrix[r][c - 1] == 0)
         return true;
      else
         return false;
   }
   else if (d == 1)
   {
      if (matrix[r - 1][c] == 0)
         return true;
      else
         return false;
   }
   else if (d == 2)
   { 
      if(matrix[r][c + 1] == 0)
         return true;
      else
         return false;
   }
   else if (d == 3)
   {
      if (matrix[r + 1][c] == 0)
         return true;
      else
         return false;
   }
   else
      return false;
}

void gostraight(int **&matrix, int &r, int &c, int &d)
{
   if (d == 0)
   {
      r -= 1;
      matrix[r][c] = 2;      
   }
   else if (d == 1)
   {
      c += 1;
      matrix[r][c] = 2;
   }
   else if (d == 2)
   {
      r += 1;
      matrix[r][c] = 2;
   }
   else if (d == 3)
   {
      c -= 1;
      matrix[r][c] = 2;
   }
   
}

void goback(int **&matrix, int &r, int &c, int &d, int &  var)
{
   if (d == 0)
   {
      if (matrix[r + 1][c] != 1)
         r += 1;
      else
         var = 0;
   }
   else if (d == 1)
   {
      if (matrix[r][c-1] != 1)
      c -= 1;
      else
         var = 0;
   }
   else if (d == 2)
   {
      if (matrix[r - 1][c] != 1)
      r -= 1;
      else
         var = 0;
   }
   else if (d == 3)
   {
      if (matrix[r][c+1] != 1)
      c += 1;
      else
         var = 0;
   }
}
