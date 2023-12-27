#ifndef MAIN_HPP
#define MAIN_HPP
#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <ctime>
#include <string>
#include <limits>
#undef max // we undef the macro used by windows.h

class Tetris {
public:
	Tetris();
	void try_force_down();
	void check_input();
	bool is_game_running();
	void create_board();
	void display_command_info();
	void display_next_tetramino_board();
	void display_board();
	void goto_(int x, int y);
	void set_tetramino();
	void get_random_index_list();
	void set_game_settings(const char* message, int n1, int n2, int* var);
	int move_tetramino(int dirx, int diry);
	void get_tetramino_highest_posy();
	void set_tetramino_highest_posy();
	bool check_collision(int tetramino[4][4], int dirx, int diry, int posx, int posy);
	void rotate_tetramino();
	void erase_tetramino();
	void draw_tetramino();
	void display_next_tetramino(int number);
	void try_break_line();
	void lock_tetramino();
	void move_board_down(int line);
	void draw_ascii_art(int position, int posx, int posy);
	void draw_tetris_logo();
	void display_counter(int number, int* var, int posx_, int posy_);
	void display_broken_line_counter();
	void add_score(int score);
	void game_over();

private:
	int board[12][22];
	int current_tetramino[4][4];
	int random_index_list[10];
	int posx, posy;
	int highest_posy;
	int board_posx, board_posy, board_length, board_heigth;
	int next_tetra_posx, next_tetra_posy;
	int broken_lines_counter_posx, broken_lines_counter_posy;
	int score_text_length, score_text_posx, score_text_posy;
	int game_state_text_length, game_state_text_posx, game_state_text_posy;
	int level_text_length, level_text_posx, level_text_posy;
	int numbers_heigth;
	int numbers_length;
	int standard_font_heigth;
	int tetris_logo_posx, tetris_logo_posy;
	int tetris_logo_length;
	int tetris_logo_heigth;
	int game_mode;
	int score;
	int level;
	int broken_lines;
	int timer;
	int r_index;
	bool is_key_up_pressed;
	bool is_key_enter_pressed;
	bool is_key_space_bar_pressed;
	bool game_running;
};

#endif