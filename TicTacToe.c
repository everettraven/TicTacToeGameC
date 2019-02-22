#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This is a tic tac toe game made for the Poly Programming Club

void PrintBoard(char **array);
char EndCheck(char **array);
void PlayX(char **board);
void PlayO(char **board);
char CheckFull(char **array);


int main()
{
    char **board, winner = 'N';
    int i,j;
    
    //Create primary head of the array
    board = malloc(sizeof(char*) * 3);

    //Create individual heads of the array
    for(i = 0; i < 3; i++)
    {
        board[i] = malloc(sizeof(char) * 3);
    }


    //Fill the array
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            board[j][i] = ' ';
        }
    }

    //Print the board to the screen
    PrintBoard(board);


   while(winner == 'N')
   {

     PlayX(board);

     PrintBoard(board);

     winner = EndCheck(board);
     if(winner == 'N')
     {
         winner = CheckFull(board);
     }else{}
     
     if(winner != 'N')
     {
         break;
     }
     else
     {
         PlayO(board);


        PrintBoard(board);

        winner = EndCheck(board);
        if(winner == 'N')
        {
            winner = CheckFull(board);
        }

     }


   } 

    if(winner == 'X')
    {
        printf("\nX is the winner!\n");
    }
    else if(winner == 'O')
    {
        printf("\nO is the winner\n");
    }
    else
    {
        printf("The board is full, it's a scratch!");
    }
    
    for(i = 0; i < 3; i++)
    {
        free(board[i]);
    }

    free(board);

    printf("\nPress any key to close\n");

    scanf("%c");

    return 0;
}

void PrintBoard(char **array)
{
    printf("    0   1   2\n");
    printf("0  %c | %c | %c\n", array[0][0], array[1][0], array[2][0]);
    printf("   -------------\n");
    printf("1  %c | %c | %c\n", array[0][1], array[1][1], array[2][1]);
    printf("   -------------\n");
    printf("2  %c | %c | %c\n", array[0][2], array[1][2], array[2][2]);

}
char EndCheck(char **array)
{

    if(array[0][0] == 'X' && array[0][1] == 'X' && array[0][2] == 'X')
    {
        return 'X';
    }
    else if(array[1][0] == 'X' && array[1][1] == 'X' && array[1][2] == 'X')
    {
        return 'X';
    }
    else if(array[2][0] == 'X' && array[2][1] == 'X' && array[2][2] == 'X')
    {
        return 'X';
    }
    else if(array[0][0]=='X' && array[1][0] == 'X' && array[2][0] == 'X')
    {
        return 'X';
    }
    else if(array[0][1]=='X' && array[1][1] == 'X' && array[2][1] == 'X')
    {
        return 'X';
    }
    else if(array[0][2]=='X' && array[1][2] == 'X' && array[2][2] == 'X')
    {
        return 'X';
    }
    else if(array[0][0]=='X' && array[1][1] == 'X' && array[2][2] == 'X')
    {
        return 'X';
    }
    else if(array[0][2]=='X' && array[1][1] == 'X' && array[2][0] == 'X')
    {
        return 'X';
    }
    else if(array[0][0] == 'O' && array[0][1] == 'O' && array[0][2] == 'O')
    {
        return 'O';
    }
    else if(array[1][0] == 'O' && array[1][1] == 'O' && array[1][2] == 'O')
    {
        return 'O';
    }
    else if(array[2][0] == 'O' && array[2][1] == 'O' && array[2][2] == 'O')
    {
        return 'O';
    }
    else if(array[0][0] == 'O' && array[1][0] == 'O' && array[2][0] == 'O')
    {
        return 'O';
    }
    else if(array[0][1] == 'O' && array[1][1] == 'O' && array[2][1] == 'O')
    {
        return 'O';
    }
    else if(array[0][2] == 'O' && array[1][2] == 'O' && array[2][2] == 'O')
    {
        return 'O';
    }
    else if(array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O')
    {
        return 'O';
    }
    else if(array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O')
    {
        return 'O';
    }
    else
    {
        return 'N';
    }
}

void PlayX(char **board)
{
    char *token, input[256];
    int x,y;
    printf("\n Where would you like to place an X? Example : (1,1)\n");
    scanf("%s", input);

    token = strtok(input, "");

    while(token != NULL)
    {
        sscanf(token,"(%d,%d)", &x, &y );

        if(board[x][y] != ' ')
        {
            printf("That spot is already taken!\n");
            token = strtok(NULL, "");
            PlayX(board);
        }
        else
        {
            board[x][y] = 'X';
            token = strtok(NULL, "");
        }

    }

}
void PlayO(char **board)
{
    char *token, input[256];
    int x,y;
    printf("\n Where would you like to place an O? Example : (1,1)\n");
    scanf("%s", input);

    token = strtok(input, "");

    while(token != NULL)
    {
        sscanf(token,"(%d,%d)", &x, &y );

        if(board[x][y] != ' ')
        {
            printf("That spot is already taken!\n");
            token = strtok(NULL,"");
            PlayO(board);
        }
        else
        {
            board[x][y] = 'O';
            token = strtok(NULL, "");
        }

    }

}

char CheckFull(char **array)
{
    int i, j;
    int Check = 0;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(array[j][i] != ' ')
            {
                Check = Check + 1;
            }
            else 
            {
                Check = 0;
            }
        }
    }

    if(Check == 9)
    {
        return 'F';
    }
    else
    {
        return 'N';
    }

}


