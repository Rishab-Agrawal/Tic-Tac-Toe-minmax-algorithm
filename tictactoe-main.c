#include<stdio.h>
#include<stdlib.h>

int box(char s[3][3])
{
    printf("-------------------\n|     |     |     |\n|  %c  |  %c  |  %c  |\n|     |     |     |\n-------------------\n|     |     |     |\n|  %c  |  %c  |  %c  |\n|     |     |     |\n-------------------\n|     |     |     |\n|  %c  |  %c  |  %c  |\n|     |     |     |\n-------------------\n", s[0][0], s[0][1], s[0][2], s[1][0], s[1][1], s[1][2], s[2][0], s[2][1], s[2][2]);
    return 0;
}

int max(int a, int b)
{
  if(a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int min(int a, int b)
{
  if(a > b)
  {
    return b;
  }
  else
  {
    return a;
  }
}

int gameplay(int k, char tokens[3][3], int j, int r)
{
  if(j == 1)
  {
    if(k == 1 && tokens[0][0] == ' ')
    {
        tokens[0][0] = 'x';
        box(tokens);
    }
    else if(k == 2 && tokens[0][1] == ' ')
    {
      tokens[0][1] = 'x';
      box(tokens);
    }
    else if(k == 3 && tokens[0][2] == ' ')
    {
      tokens[0][2] = 'x';
      box(tokens);
    }
    else if(k == 4 && tokens[1][0] == ' ')
    {
      tokens[1][0] = 'x';
      box(tokens);
    }
    else if(k == 5 && tokens[1][1] == ' ')
    {
      tokens[1][1] = 'x';
      box(tokens);
    }
    else if(k == 6 && tokens[1][2] == ' ')
    {
      tokens[1][2] = 'x';
      box(tokens);
    }
    else if(k == 7 && tokens[2][0] == ' ')
    {
      tokens[2][0] = 'x';
      box(tokens);
    }
    else if(k == 8 && tokens[2][1] == ' ')
    {
      tokens[2][1] = 'x';
      box(tokens);
    }
    else if(k == 9 && tokens[2][2] == ' ')
    {
      tokens[2][2] = 'x';
      box(tokens);
    }
    else
    {
      if(r == 0)
      {
        printf("Invalid\a\n");
        return j;
      }
      else
      {
        return j;
      }
    }
  }

  else if(j == -1)
  {
    if(k == 1 && tokens[0][0] == ' ')
    {
      tokens[0][0] = 'o';
      box(tokens);
    }
    else if(k == 2 && tokens[0][1] == ' ')
    {
      tokens[0][1] = 'o';
      box(tokens);
    }
    else if(k == 3 && tokens[0][2] == ' ')
    {
      tokens[0][2] = 'o';
      box(tokens);
    }
    else if(k == 4 && tokens[1][0] == ' ')
    {
      tokens[1][0] = 'o';
      box(tokens);
    }
    else if(k == 5 && tokens[1][1] == ' ')
    {
      tokens[1][1] = 'o';
      box(tokens);
    }
    else if(k == 6 && tokens[1][2] == ' ')
    {
      tokens[1][2] = 'o';
      box(tokens);
    }
    else if(k == 7 && tokens[2][0] == ' ')
    {
      tokens[2][0] = 'o';
      box(tokens);
    }
    else if(k == 8 && tokens[2][1] == ' ')
    {
      tokens[2][1] = 'o';
      box(tokens);
    }
    else if(k == 9 && tokens[2][2] == ' ')
    {
      tokens[2][2] = 'o';
      box(tokens);
    }
    else
    {
      if(r == 0)
      {
        printf("Invalid\a\n");
        return j;
      }
      else
      {
        return j;
      }
    }
  }
  return j*(-1);
}

int isMovesLeft(char s[3][3])
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(s[i][j] == ' ')
      {
        return 20;
      }
    }
  }
  return -20;
}

int wincheck(char s[3][3])
{
    for(int row = 0; row < 3; row++)
    {
      if(s[row][0] == s[row][1] && s[row][1] == s[row][2])
      {
        if(s[row][0] == 'x')
        {
          return 10;
        }
        else if(s[row][0] == 'o')
        {
          return -10;
        }
      }
    }

    for(int col = 0; col < 3; col++)
    {
      if(s[0][col] == s[1][col] && s[1][col] == s[2][col])
      {
        if(s[0][col] == 'x')
        {
          return 10;
        }
        else if(s[0][col] == 'o')
        {
          return -10;
        }
      }
    }

    if(s[0][0] == s[1][1] && s[1][1] == s[2][2])
    {
      if(s[0][0] == 'x')
      {
        return 10;
      }
      else if(s[0][0] == 'o')
      {
        return -10;
      }
    }
     if(s[0][2] == s[1][1] && s[1][1] == s[2][0])
     {
       if(s[0][2] == 'x')
       {
         return 10;
       }
       else if(s[0][2] == 'o')
       {
         return -10;
       }
     }
    return 0;
}

int minimax(char s[3][3], int depth, int isMax, int level)
{
  int score = wincheck(s);

  if(score == 10)
  return score;

  if(score == -10)
  return score;

  if(isMovesLeft(s) == -20)
  return 0;

  if(isMax == 1)
  {
    int best = -1000;
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if(s[i][j] == ' ')
        {
          s[i][j] = 'x';
          if(level == 2)
          {
            if(depth < 2)
            {
              best = max(best, minimax(s, depth + 1, -isMax, level));
            }
            else
            {
              best = 0;
            }
          }
          else if(level == 3)
          {
            best = max(best, minimax(s, depth + 1, -isMax, level));
          }
          s[i][j] = ' ';
        }
      }
    }
    return best;
  }

  else
  {
    int best = 1000;
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if(s[i][j] == ' ')
        {
          s[i][j] = 'o';
          if(level == 2)
          {
            if(depth < 2)
            {
              best = min(best, minimax(s, depth + 1, -isMax, level));
            }
            else
            {
              best = 0;
            }
          }
          else if(level == 3)
          {
            best = min(best, minimax(s, depth + 1, -isMax, level));
          }
          s[i][j] = ' ';
        }
      }
    }
    return best;
  }
}

int findBestMove(char s[3][3], int level)
{
  int bestVal = -1000;
  int move_row = -1;
  int move_column = -1;
  int bestMove;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(s[i][j] == ' ')
      {
        s[i][j] = 'x';
        int moveVal = minimax(s, 0, -1, level);
        s[i][j] = ' ';

        if(moveVal > bestVal)
        {
          move_row = i;
          move_column = j;
          bestVal = moveVal;
          bestMove = 10*i + j;
        }
      }
    }
  }
  return bestMove;
}

int main()
{
    printf("\nLet's play Tic-Tac-Toe!\n\n");
    printf("Instructions:\n1. Player 1 uses the 'x' token by default. Player 2 uses the 'o' token.\n2. When it is your turn, enter the number corresponding to the desired box.\n\nThe structure of the grid is as follows:\n");
    printf("-------------------\n|     |     |     |\n|  1  |  2  |  3  |\n|     |     |     |\n-------------------\n|     |     |     |\n|  4  |  5  |  6  |\n|     |     |     |\n-------------------\n|     |     |     |\n|  7  |  8  |  9  |\n|     |     |     |\n-------------------\n\n");
    label_game:
    printf("\n");
    int replay;
    char tokens[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int j = 1;
    int tog;
    int start;
    int level;
    label_gt:
    printf("\n1. Play against computer\n2. Multiplayer game\n(1/2): ");
    scanf("%d", &tog);
    if(tog == 1)
    {
      label_level:
      printf("\nWhich level would you like to play in?\n1. Easy (random)\n2. Medium (low-level AI)\n3. Hard (unbeatable AI)\n(1/2/3): ");
      scanf("%d", &level);
      if(level == 1)
      {
        label_start_1:
        printf("\nWould you like to start?\n1. Yes\n2. No\n(1/2): ");
        scanf("%d", &start);
        if(start == 1)
        {
          while (1)
          {
              int k;
              if (j == -1)
              {
                  printf("\nAI's turn: \n");
                  k = (rand() % 8) + 1;
                  j = gameplay(k,tokens,1,1);
                  j = j*(-1);
              }
              else
              {
                  printf("\nUser's turn: ");
                  scanf("%d", &k );
                  if(k > 0 && k < 10)
                  {
                      j = gameplay(k,tokens,-1,0);
                      j = j*(-1);
                  }
                  else
                  {
                      printf("Invalid\a\n");
                  }
              }
              if(wincheck(tokens) == 10)
              {
                printf("\nAI wins!\n");
                break;
              }
              else if(wincheck(tokens) == -10)
              {
                printf("\nUser wins!\n");
                break;
              }
              else if(isMovesLeft(tokens) == -20)
              {
                  printf("It's a draw!\n");
                  break;
              }
              else
              {
                  continue;
              }
          }
        }

        else if(start == 2)
        {
          while (1)
          {
              int k;
              if (j == 1)
              {
                  printf("\nAI's turn: \n");
                  k = (rand() % 8) + 1;
                  j = gameplay(k,tokens,j,1);
              }
              else
              {
                  printf("\nUser's turn: ");
                  scanf("%d", &k );
                  if(k > 0 && k < 10)
                  {
                      j = gameplay(k,tokens,j,0);
                  }
                  else
                  {
                      printf("Invalid\a\n");
                  }
              }
              if(wincheck(tokens) == 10)
              {
                printf("\nAI wins!\n");
                break;
              }
              else if(wincheck(tokens) == -10)
              {
                printf("\nUser wins!\n");
                break;
              }
              else if(isMovesLeft(tokens) == -20)
              {
                  printf("It's a draw!\n");
                  break;
              }
              else
              {
                  continue;
              }
          }
        }
        else
        {
          printf("\nPlease enter a valid option.\a\n");
          goto label_start_1;
        }
      }
      else if(level == 2)
      {
        label_start_2:
        printf("\nWould you like to start?\n1. Yes\n2. No\n(1/2): ");
        scanf("%d", &start);
        if(start == 1)
        {
          while (1)
          {
              int k;
              if (j == -1)
              {
                  printf("\nAI's turn: \n");
                  k = findBestMove(tokens, level);
                  tokens[k/10][k%10] = 'x';
                  box(tokens);
                  j = j*(-1);
              }
              else
              {
                  printf("\nUser's turn: ");
                  scanf("%d", &k );
                  if(k > 0 && k < 10)
                  {
                      j = gameplay(k,tokens,-1,0);
                      j = j*-1;
                  }
                  else
                  {
                      printf("Invalid\a\n");
                  }
              }
              if(wincheck(tokens) == 10)
              {
                printf("\nAI wins!\n");
                break;
              }
              else if(wincheck(tokens) == -10)
              {
                printf("\nUser wins!\n");
                break;
              }
              else if(isMovesLeft(tokens) == -20)
              {
                  printf("It's a draw!\n");
                  break;
              }
              else
              {
                  continue;
              }
          }
        }

        else if(start == 2)
        {
          while (1)
          {
              int k;
              if (j == 1)
              {
                  printf("\nAI's turn: \n");
                  k = findBestMove(tokens, level);
                  tokens[k/10][k%10] = 'x';
                  box(tokens);
                  j = j*-1;
              }
              else
              {
                  printf("\nUser's turn: ");
                  scanf("%d", &k );
                  if(k > 0 && k < 10)
                  {
                      j = gameplay(k,tokens,j,0);
                  }
                  else
                  {
                      printf("Invalid\a\n");
                  }
              }
              if(wincheck(tokens) == 10)
              {
                printf("\nAI wins!\n");
                break;
              }
              else if(wincheck(tokens) == -10)
              {
                printf("\nUser wins!\n");
                break;
              }
              else if(isMovesLeft(tokens) == -20)
              {
                  printf("It's a draw!\n");
                  break;
              }
              else
              {
                  continue;
              }
          }
        }
        else
        {
          printf("\nPlease enter a valid option.\a\n");
          goto label_start_2;
        }
      }
      else if(level == 3)
      {
        label_start_3:
        printf("\nWould you like to start?\n1. Yes\n2. No\n(1/2): ");
        scanf("%d", &start);
        if(start == 1)
        {
          while (1)
          {
              int k;
              if (j == -1)
              {
                  printf("\nAI's turn: \n");
                  k = findBestMove(tokens, level);
                  tokens[k/10][k%10] = 'x';
                  box(tokens);
                  j = j*(-1);
              }
              else
              {
                  printf("\nUser's turn: ");
                  scanf("%d", &k );
                  if(k > 0 && k < 10)
                  {
                      j = gameplay(k,tokens,-1,0);
                      j = j*-1;
                  }
                  else
                  {
                      printf("Invalid\a\n");
                  }
              }
              if(wincheck(tokens) == 10)
              {
                printf("\nAI wins!\n");
                break;
              }
              else if(wincheck(tokens) == -10)
              {
                printf("\nUser wins!\n");
                break;
              }
              else if(isMovesLeft(tokens) == -20)
              {
                  printf("It's a draw!\n");
                  break;
              }
              else
              {
                  continue;
              }
          }
        }

        else if(start == 2)
        {
          while (1)
          {
              int k;
              if (j == 1)
              {
                  printf("\nAI's turn: \n");
                  k = findBestMove(tokens, level);
                  tokens[k/10][k%10] = 'x';
                  box(tokens);
                  j = j*-1;
              }
              else
              {
                  printf("\nUser's turn: ");
                  scanf("%d", &k );
                  if(k > 0 && k < 10)
                  {
                      j = gameplay(k,tokens,j,0);
                  }
                  else
                  {
                      printf("Invalid\a\n");
                  }
              }
              if(wincheck(tokens) == 10)
              {
                printf("\nAI wins!\n");
                break;
              }
              else if(wincheck(tokens) == -10)
              {
                printf("\nUser wins!\n");
                break;
              }
              else if(isMovesLeft(tokens) == -20)
              {
                  printf("It's a draw!\n");
                  break;
              }
              else
              {
                  continue;
              }
          }
        }
        else
        {
          printf("\nPlease enter a valid option.\a\n");
          goto label_start_3;
        }
      }
      else
      {
        printf("\nPlease enter a valid option.\a\n");
        goto label_level;
      }
    }
    else if(tog == 2)
    {
        while (1)
        {
            int k;
            if (j == 1)
            {
                printf("\nPlayer 1's turn: ");
                scanf("%d", &k );
                if(k > 0 && k < 10)
                {
                    j = gameplay(k,tokens,j,0);
                }
                else
                {
                    printf("Invalid\a\n");
                }
            }
            else
            {
                printf("\nPlayer 2's turn: ");
                scanf("%d", &k );
                if(k > 0 && k < 10)
                {
                    j = gameplay(k,tokens,j,0);
                }
                else
                {
                    printf("Invalid\a\n");
                }
            }
            if(wincheck(tokens) == 10)
            {
              printf("\nPlayer 1 wins!\n");
              break;
            }
            else if(wincheck(tokens) == -10)
            {
              printf("\nPlayer 2 wins!\n");
              break;
            }
            else if(isMovesLeft(tokens) == -20)
            {
                printf("It's a draw!\n");
                break;
            }
            else
            {
                continue;
            }
        }
    }
    else
    {
        printf("\nPlease enter a valid option.\a\n\n");
        goto label_gt;
    }

    label_end:
    printf("Would you like to play again?\n1. Yes\n2. No\n(1/2): ");
    scanf("%d", &replay);
    if(replay == 1)
    {
        goto label_game;
    }
    else if(replay == 2)
    {
        printf("\nThank you for playing!\n");
        return 0;
    }
    else
    {
        printf("\nPlease enter a valid option.\a\n\n");
        goto label_end;
    }
}
