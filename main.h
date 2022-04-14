#ifndef MAIN_H_
#define MAIN_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif // MAIN_H_

void game_loop(void);
void print_grid(void);
void turn(bool is_player_one);
bool is_space_full(int row, int col);
void insert_symbol(char symbol, int row, int column);
void check_for_game_end(char symbol);
