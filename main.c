#include "main.h"
#include <stdio.h>

// GLOBALS
bool game_end = false;
bool is_player_one = true;
char nought = 'o';
char cross = 'x';
char grid[5][5] = {{' ', '|', ' ', '|', ' '},
                   {'-', '|', '-', '|', '-'},
                   {' ', '|', ' ', '|', ' '},
                   {'-', '|', '-', '|', '-'},
                   {' ', '|', ' ', '|', ' '}};

// VALID COORDINATES TO PLACE SYMBOLS:
// [0, 0], [0, 2], [0, 4]
// [2, 0], [2, 2], [2, 4]
// [4, 0], [4, 2], [4, 4]

int main(void)
{
	puts("Welcome to Tic-Tac-Toe!");
	game_loop();
	return EXIT_SUCCESS;
}

void game_loop(void)
{
	while (!game_end)
	{
		print_grid();
		turn(is_player_one);
		is_player_one = !is_player_one;
	}
}

void print_grid(void)
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			printf("%c", grid[row][col]);
		}
		printf("\n");
	}
}

void turn(bool is_player_one)
{

	int row, col = 0;
	char symbol;

	if(is_player_one)
		symbol = nought;
	else if(!is_player_one)
		symbol = cross;

	puts("Please enter the coordinates where you would like your piece to go.\n"
		 "Valid coordinates are:\n[0, 0], [0, 2], [0, 4]\n[2, 0], [2, 2], [2, 4]\n[4, 0], [4, 2], [4, 4]\n");

	// catch illegal coordinates, which is any coordinate that is odd or over 4
	while(true)
	{
		printf("Enter the row: ");
		scanf("%d", &row);
		printf("Enter the column: ");
		scanf("%d", &col);

		if((row % 2 == 0 && col % 2 == 0) && (row <= 4 && col <= 4) && (!is_space_full(row, col)))
			break;
		else
			puts("Invalid coordinates entered! Try again!");
	}

	printf("\nRow: %d\nColumn: %d\n\n", row, col);
	insert_symbol(symbol, row, col);
	check_for_game_end(symbol);
}

bool is_space_full(int row, int col)
{
	if(grid[row][col] != ' ')
		return true;
	else
		return false;
}

void insert_symbol(char symbol, int row, int col)
{
	for(int i = 0; i < 5; i++)
	{
		if(i == row)
		{
			for(int j = 0; j < 5; j++)
			{
				if(j == col)
					memcpy(&grid[i][j], &symbol, 1);
			}
		}
	}
}

// WINNING COORDINATES:
// HORIZONTAL:
// [[0, 0], [0, 2], [0, 4]]
// [[2, 0], [2, 2], [2, 4]]
// [[4, 0], [4, 2], [4, 4]]
//
// VERTICAL:
// [[0, 0], [2, 0], [4, 0]]
// [[0, 2], [2, 2], [4, 2]]
// [[0, 4], [2, 4], [4, 4]]
//
// DIAGONAL:
// [[0, 0], [2, 2], [4, 4]]
// [[0, 4], [2, 2], [4, 0]]

void check_for_game_end(char symbol)
{
	   // check horizontal
	if((grid[0][0] == symbol && grid[0][2] == symbol && grid[0][4] == symbol) ||
	   (grid[2][0] == symbol && grid[2][2] == symbol && grid[2][4] == symbol) ||
	   (grid[4][0] == symbol && grid[4][2] == symbol && grid[4][4] == symbol) ||

	   // check vertical
	   (grid[0][0] == symbol && grid[2][0] == symbol && grid[4][0] == symbol) ||
	   (grid[0][2] == symbol && grid[2][2] == symbol && grid[4][2] == symbol) ||
	   (grid[0][4] == symbol && grid[2][4] == symbol && grid[4][4] == symbol) ||

	   // check diagonal
	   (grid[0][0] == symbol && grid[2][2] == symbol && grid[4][4] == symbol) ||
	   (grid[0][4] == symbol && grid[2][2] == symbol && grid[4][0] == symbol))
	{
		puts("Winner!");
		game_end = true;
	}
	else
	{
		bool empty_spot_found = false;

		for(int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if(grid[i][j] == ' ')
					empty_spot_found = true;
			}
		}

		if(!empty_spot_found)
		{
			puts("Tie!");
			game_end = true;
		}
	}
}
