#include "tetris.hpp"
/*
***********************INFORMATIONS BEFORE USE*****************
- This is the classic version of the old-school-tetris project. It's less beautiful than the classic version but you can modify it as you want and run it on different command prompt
- Don't forget to respect the LICENCE.txt (the "licence") of the project before any change

1 fitted piece = 10 points
1 broken line = 100 points
2 lines = 300
3 lines = 500
4 lines (tetris) = 1000

***************************************************************
 ______   ______    ______   ______     __     ______
/\__  _\ /\  ___\  /\__  _\ /\  == \   /\ \   /\  ___\
\/_/\ \/ \ \  __\  \/_/\ \/ \ \  __<   \ \ \  \ \___  \
   \ \_\  \ \_____\   \ \_\  \ \_\ \_\  \ \_\  \/\_____\
    \/_/   \/_____/    \/_/   \/_/ /_/   \/_/   \/_____/ 57

//\033[5;1,31m ______\033[0m   \033[5;1,31m______\033[0m     \033[5;1,31m______\033[0m   \033[5;1,31m______\033[0m     \033[5;1,31m__\033[0m     \033[5;1,31m______\033[0m
//\033[5;1,31m/\\__  _\\\033[0m \033[5;1,31m/\\  ___\\\033[0m   \033[5;1,31m/\\__  _\\\033[0m \033[5;1,31m/\\  == \\\033[0m   \033[5;1,31m/\\ \\\033[0m   \033[5;1,31m/\\  ___\\\033[0m
//\033[5;1,31m\\/_/\\ \\/\033[0m \033[5;1,31m\\ \\  __\\\033[0m   \033[5;1,31m\\/_/\\ \\/\\033[0m \033[5;1,31m\\ \\  __<\033[0m   \033[5;1,31m\\ \\ \\\033[0m  \033[5;1,31m\\ \\___  \\\033[0m
//\033[5;1,31m   \\ \\_\\\033[0m  \033[5;1,31m\\ \\_____\\\033[0m    \033[5;1,31m\\ \\_\\\033[0m  \033[5;1,31m\\ \\_\\ \\_\\\033[0m  \033[5;1,31m\\ \\_\\\033[0m  \033[5;1,31m\\/\\_____\\\033[0m
//\033[5;1,31m    \\/_/\033[0m   \033[5;1,31m\\/_____/\\033[0m     \033[5;1,31m\\/_/\\033[0m   \033[5;1,31m\\/_/ /_/\033[0m   \033[5;1,31m\\/_/\033[0m   \033[5;1,31m\\/_____/\033[0m
* POLICE: Standard
  ___    _   ____    _____   _  _     ____     __     _____    ___     ___  
 / _ \  / | |___ \  |___ /  | || |   | ___|   / /_   |___  |  ( _ )   / _ \ 
| | | | | |   __) |   |_ \  | || |_  |___ \  | '_ \     / /   / _ \  | (_) |
| |_| | | |  / __/   ___) | |__   _|  ___) | | (_) |   / /   | (_) |  \__, |
 \___/  |_| |_____| |____/     |_|   |____/   \___/   /_/     \___/     /_/  
 ___  ___ ___  _ __ ___   _ 
/ __|/ __/ _ \| '__/ _ \ (_)
\__ \ (_| (_) | | |  __/  _ 
|___/\___\___/|_|  \___| (_)
 _                _ 
| | _____   _____| |
| |/ _ \ \ / / _ \ |
| |  __/\ V /  __/ |
|_|\___| \_/ \___|_|
 _ __   __ _ _   _ ___  ___        
| '_ \ / _` | | | / __|/ _ \       
| |_) | (_| | |_| \__ \  __/       
| .__/ \__,_|\__,_|___/\___|       
|_|                                
       _             _             
 _ __ | | __ _ _   _(_)_ __   __ _ 
| '_ \| |/ _` | | | | | '_ \ / _` |
| |_) | | (_| | |_| | | | | | (_| |
| .__/|_|\__,_|\__, |_|_| |_|\__, |
|_|            |___/         |___/ 
*/
const char* tetris_text[5]{
    "\033[5;31m ______\033[0m   \033[5;1;37m______\033[0m    \033[5;33m______\033[0m   \033[5;1;32m______\033[0m     \033[5;1;36m__\033[0m     \033[5;35m______\033[0m",
    "\033[5;31m/\\__  _\\\033[0m \033[5;1;37m/\\  ___\\\033[0m  \033[5;33m/\\__  _\\\033[0m \033[5;1;32m/\\  == \\\033[0m   \033[5;1;36m/\\ \\\033[0m   \033[5;35m/\\  ___\\\033[0m",
    "\033[5;31m\\/_/\\ \\/\033[0m \033[5;1;37m\\ \\  __\\\033[0m  \033[5;33m\\/_/\\ \\/\033[0m \033[5;1;32m\\ \\  __<\033[0m   \033[5;1;36m\\ \\ \\\033[0m  \033[5;35m\\ \\___  \\\033[0m",
    "\033[5;31m   \\ \\_\\\033[0m  \033[5;1;37m\\ \\_____\\\033[0m   \033[5;33m\\ \\_\\\033[0m  \033[5;1;32m\\ \\_\\ \\_\\\033[0m  \033[5;1;36m\\ \\_\\\033[0m  \033[5;35m\\/\\_____\\\033[0m",
    "\033[5;31m    \\/_/\033[0m   \033[5;1;37m\\/_____/\033[0m    \033[5;33m\\/_/\033[0m   \033[5;1;32m\\/_/ /_/\033[0m   \033[5;1;36m\\/_/\033[0m   \033[5;35m\\/_____/\033[0m"
};

const char* pagga_text[6][4] = {
"                            ", "                                   ", "       _             _             ", " _                _ ",
" ___  ___ ___  _ __ ___   _ ", " _ __   __ _ _   _ ___  ___        ", " _ __ | | __ _ _   _(_)_ __   __ _ ", "| | _____   _____| |",
"/ __|/ __/ _ \\| '__/ _ \\ (_)", "| '_ \\ / _` | | | / __|/ _ \\       ", "| '_ \\| |/ _` | | | | | '_ \\ / _` |", "| |/ _ \\ \\ / / _ \\ |",
"\\__ \\ (_| (_) | | |  __/  _ ", "| |_) | (_| | |_| \\__ \\  __/       ", "| |_) | | (_| | |_| | | | | | (_| |", "| |  __/\\ V /  __/ |",
"|___/\\___\\___/|_|  \\___| (_)", "| .__/ \\__,_|\\__,_|___/\\___|       ", "| .__/|_|\\__,_|\\__, |_|_| |_|\\__, |", "|_|\\___| \\_/ \\___|_|",
"                            ", "|_|                                ", "|_|            |___/         |___/ ", "                    "
};
const char* score_numbers_font[5][10] = {
"   ___  ", "    _   ", "  ____  ", "  _____ ", "  _  _   ", "  ____  ", "   __   ", "  _____ ", "   ___  ", "   ___  ",
"  / _ \\ ","   / |  ", " |___ \\ "," |___ / ", " | || |  ", " | ___| ", "  / /_  ", " |___  |", "  ( _ ) ", "  / _ \\ ",
" | | | |", "   | |  ", "   __) |", "   |_ \\ "," | || |_ ", " |___ \\ "," | '_ \\ ","    / / ", "  / _ \\ "," | (_) |",
" | |_| |", "  _| |_ ", "  / __/ ", "  ___) |", " |__   _|", "  ___) |", " | (_) |", "   / /  ", " | (_) |", "  \\__, |",
"  \\___/ "," |_____|", " |_____|", " |____/ ", "    |_|  ", " |____/ ", "  \\___/ ","  /_/   ", "  \\___/ ","    /_/ "
};
const char* ANSI_code[9] = {
    "\033[37m  \033[0m",
    "\033[36;1m[]\033[0m", // tetramino I
    "\033[34;1m[]\033[0m", // tetramino J
    "\033[37;1m[]\033[0m", // tetramino L
    "\033[33m[]\033[0m", // tetramino O
    "\033[32;1m[]\033[0m", // tetramino S
    "\033[35m[]\033[0m", // tetramino T
    "\033[31m[]\033[0m", // tetramino Z
    "\033[37;47m@@\033[0m"  // border
};

int tetraminos[7][4][4] = {
    {
        0, 0, 0, 0,
        0, 0, 0, 0,
        1, 1, 1, 1,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        2, 0, 0, 0,
        2, 2, 2, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 0, 3, 0,
        3, 3, 3, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 4, 4, 0,
        0, 4, 4, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 5, 5, 0,
        5, 5, 0, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 6, 0, 0,
        6, 6, 6, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        7, 7, 0, 0,
        0, 7, 7, 0,
        0, 0, 0, 0
    }
};

Tetris::Tetris() : board{ 0 }, current_tetramino{ 0 }, random_index_list{ 0 } {
    level = 1;
    game_mode = 1; // normal mode by default
    set_game_settings("Enter your starting level\n>>> ", 1, 10, &level);
    set_game_settings("Enter your gamemode:\n.1 = normal mode\n.2 = peaceful mode (no level increase)\n>>> ", 1, 2, &game_mode);
    posx = 4;
    posy = 0;
    highest_posy = 1;
    board_heigth = 22;
    board_length = 12;
    tetris_logo_posx = 5;
    tetris_logo_posy = 1;
    tetris_logo_length = 56;
    tetris_logo_heigth = 5;
    board_posx = tetris_logo_length/2 - board_length + tetris_logo_posx; // we center the board on the tetris logo
    board_posy = tetris_logo_heigth + tetris_logo_posy + 1;
    next_tetra_posx = board_posx + board_length + 15;
    next_tetra_posy = board_posy; // aligned with the score posy
    score_text_length = 28;
    score_text_posx = 15 + board_posx + board_length;
    score_text_posy = board_posy + 7;
    level_text_length = 20;
    level_text_posx = score_text_posx; // aligned with the score posx
    level_text_posy = score_text_posy + 5;
    game_state_text_length = 28;
    game_state_text_posx = score_text_posx; // aligned with the score posx
    game_state_text_posy = score_text_posy + 10;
    standard_font_heigth = 6;
    numbers_length = 8;
    numbers_heigth = 5;
    score = 0;
    broke_line = 0;
    broke_line_counter_posx = board_posx;
    broke_line_counter_posy = board_posy - 1;
    timer = 0;
    r_index = 0;
    random_index_list[9] = rand() % 7; // we initialize the last value
    is_key_up_pressed = false;
    is_key_enter_pressed = true;
    game_running = false;
    is_key_space_bar_pressed = false;
    srand(static_cast<unsigned>(time(NULL))); // random seed

    //___Game_starting___
    draw_tetris_logo();
    create_board();
    display_board();
    display_next_tetramino_board();
    get_random_index_list();
    set_tetramino();
    draw_tetramino();
    display_next_tetramino(1);
    draw_ascii_art(0, score_text_posx, score_text_posy); // score text display
    draw_ascii_art(3, level_text_posx, level_text_posy); // level text display
    draw_ascii_art(1, game_state_text_posx, game_state_text_posy); // game state display
    display_counter(0, &score, score_text_posx + score_text_length, score_text_posy);
    display_counter(0, &level, level_text_posx + level_text_length, level_text_posy);
    display_broken_line_counter();
    display_command_info();
}
void Tetris::goto_(int x, int y) {
    std::cout << "\033["<< y << ";" << x << "H"; // ANSI sequence to change the cursor position
}
void Tetris::get_random_index_list() {
    int index = 0;
    int i = 1;
    random_index_list[0] = random_index_list[9]; // we initialize the first value to the last value of the old list we haven't displayed
    while (i < 10){
        index = rand() % 7;
        if (random_index_list[i - 1] != index) {
            random_index_list[i] = index;
            i++;
        }
    }
}
void Tetris::set_tetramino() {
    if ((r_index + 1) == 10) { // check if we can reset to 0
        r_index = 0;
        get_random_index_list(); // regenerate the index list
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            current_tetramino[j][i] = tetraminos[random_index_list[r_index]][i][j]; // assign tetramino
        }
    }
}
void Tetris::set_game_settings(const char* message, int n1, int n2, int *var) {
    int entry;
    std::cout << message;
    while (1) {
        if (std::cin >> entry) {
            if (entry >= n1 && entry <= n2) {
                *var = entry;
                break;
            }
            else {
                std::cout << "Please type a number between "<< n1 << " and " << n2; 
            }
        }
        else {
            std::cin.clear(); // we delete the invalid entry
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please type a valid number: ";
        }
    }
    printf("\033[2J\033[1;1H"); // ANSI sequence to delete the console
}
void Tetris::create_board() {
    for (int y = 0; y < board_heigth; y++) {
        for (int x = 0; x < board_length; x++) {
            board[x][y] = 0; // we initialize all value to 0
            board[0][y] = board[board_length - 1][y] = board[x][0] = board[x][board_heigth - 1] = 8; // we initialise all edges to 8 (integer for the edge of the board)
        }
    }
}
// ugly, but it works :)
void Tetris::display_next_tetramino_board() {
    goto_(next_tetra_posx + 1, next_tetra_posy - 1);
    std::cout << "\033[31mNEXT PIECE :\033[0m";
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 6; x++) {
            goto_(next_tetra_posx, next_tetra_posy + y);
            std::cout << ANSI_code[8];
            goto_(next_tetra_posx + 12, next_tetra_posy + y + 1);
            std::cout << ANSI_code[8];
            goto_(next_tetra_posx + 2+ x*2, next_tetra_posy);
            std::cout << ANSI_code[8];
            goto_(next_tetra_posx + x*2, next_tetra_posy + 6);
            std::cout << ANSI_code[8];
        }
    }
}
void Tetris::display_command_info() {
    goto_(0, tetris_logo_posy + tetris_logo_heigth + board_heigth + 2);
    std::cout << "Move with right, left, down   Rotate with up   Pause/Play with entry   Down with space bar   Quit with ctrl + Back";
    goto_(tetris_logo_posx + 96, tetris_logo_posy);
    std::cout << "Made by Megalaxatif";
}
void Tetris::display_board(){
    for (int y = 0; y < board_heigth; y++) {
        for (int x = 0; x < board_length; x++) {
            goto_(board_posx + x*2, board_posy + y);
            std::cout << ANSI_code[board[x][y]];
        }
    }
}
bool Tetris::check_collision(int tetramino[4][4], int dirx, int diry, int posx_, int posy_) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[posx_ + dirx + x][posy_ + diry + y] != 0 && tetramino[x][y] != 0) {
                return true; // collision
            }
        }
    }
    return false; // no collision at the end of the loop
}
void Tetris::erase_tetramino() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_tetramino[x][y] != 0) {
                // we delete the projection
                goto_(board_posx + (posx + x) * 2, board_posy + highest_posy + y);
                std::cout << ANSI_code[0];
                // we delete the tetramino
                goto_(board_posx + (posx + x)*2,board_posy + posy + y);
                std::cout << ANSI_code[0];
            }
        }
    }
}
void Tetris::draw_tetramino() {
    get_tetramino_highest_posy();
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_tetramino[x][y] != 0) {
                // we draw the projection
                goto_(board_posx + (posx + x) * 2, board_posy + highest_posy + y);
                std::cout << "##";
                // we draw the tetramino
                goto_(board_posx + (posx + x)*2, board_posy + posy + y);
                std::cout << ANSI_code[random_index_list[r_index] + 1];
            }
        }
    }
}
void Tetris::display_next_tetramino(int n) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetraminos[random_index_list[r_index + 1]][y][x] != 0) {
                goto_(next_tetra_posx + 3 + x * 2, next_tetra_posy + 2 + y);
                if (n == 1) {
                    std::cout << ANSI_code[random_index_list[r_index + 1] + 1]; // we write
                }
                else std::cout << ANSI_code[0]; // we delete
            }
        }
    }
}
int Tetris::move_tetramino(int dirx, int diry) {
    if (!check_collision(current_tetramino, dirx, diry, posx, posy)) { // there is no collisions
        erase_tetramino(); //we delete the tetramino
        // we move it
        posx += dirx;
        posy += diry;
        draw_tetramino(); // we draw it
        return 0; // success there is no collision
    }
    return 1; // failure, collision detected
}
void Tetris::try_force_down() {
    timer += 50;
    timer = timer % (550 - level*50); 
    if (timer == 0 && move_tetramino(0, 1) != 0) { // reminder : if there is a collision move_tetramino return 1
        lock_tetramino();
    }
}
void Tetris::lock_tetramino() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_tetramino[x][y] != 0) {
                board[posx + x][posy + y] = current_tetramino[x][y];
            }
        }
    }
    try_break_line();// can we broke the line
    // we change the position of the tetramino because we want the next tetramino to appear at the top, in the middle. 
    posy = 0;
    posx = 4;
    display_next_tetramino(0); // we delete the tetramino projection
    r_index++; // we increment the random index
    set_tetramino(); // we choose the next tetramino
    if (check_collision(current_tetramino, 0, 0, posx, posy)) { // if there is a collision, we reset the board, the score and the level
        game_over();
    }
    display_board();  // we update the board
    draw_tetramino(); // we draw the tetramino
    display_next_tetramino(1); // we draw the tetramino projection
}
void Tetris::game_over() {
    create_board();
    display_counter(1, &score, score_text_posx + score_text_length, score_text_posy); // we delete
    display_counter(1, &level, level_text_posx + level_text_length, level_text_posy);
    score = 0;
    broke_line = 0;
    if (game_mode == 1) level = 1;
    display_broken_line_counter();
    display_counter(0, &score, score_text_posx + score_text_length, score_text_posy); // we write
    display_counter(0, &level, level_text_posx + level_text_length, level_text_posy);
    game_running = false;
    draw_ascii_art(1, game_state_text_posx, game_state_text_posy); // we set the game state on pause
}
void Tetris::check_input() {
    if (game_running) { // if the game is running we check the input
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            move_tetramino(-1, 0);
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            move_tetramino(1, 0);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            move_tetramino(0, 1);
        }
        if (!(GetAsyncKeyState(VK_UP) & 0x8000)) {
            is_key_up_pressed = false;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (!is_key_up_pressed) {
                rotate_tetramino();
                is_key_up_pressed = true;
            }
        }
        if (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) { // entry key
            is_key_enter_pressed = false;
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // entry key
            if (!is_key_enter_pressed) {
                game_running = false;
                draw_ascii_art(1, game_state_text_posx, game_state_text_posy); // pause
                is_key_enter_pressed = true;
            }
        }
        if (!(GetAsyncKeyState(VK_SPACE) & 0x8000)) {
            is_key_space_bar_pressed = false;
        }

        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (!is_key_space_bar_pressed) {
                set_tetramino_highest_posy();
                is_key_space_bar_pressed = true;
            }
        }
    }
    else { // else we just check if the game restarts
        if (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) { // entry key
            is_key_enter_pressed = false;
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // enter key
            if (!is_key_enter_pressed) {
                game_running = true;
                draw_ascii_art(2, game_state_text_posx, game_state_text_posy); // playing
                is_key_enter_pressed = true;
            }
        }
    }
}
void Tetris::rotate_tetramino() {
    // we check if there is no collisions at the future location
    int new_tetramino[4][4] = { 0 };
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            new_tetramino[x][y] = current_tetramino[y][3 - x];
        }
    }
    if (!check_collision(new_tetramino, 0, 0, posx, posy)) { // if there is no collisions we merge current_tetramino and new_tetramino
        erase_tetramino();
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                current_tetramino[x][y] = new_tetramino[x][y];
            }
        }
        draw_tetramino();
    }
}
void Tetris::try_break_line() {
    bool at_least_one_line_broken = false;
    int line_to_broke_list[4] = { 0 };
    int broke_line_ = 0;
    for (int y = 0; y < 4; y++) {
        if (posy + y < board_heigth - 1) { // execute that if we don't touch the bottom edge
            for (int x = 1; x < board_length - 1; x++) {
                if (board[x][posy + y] == 0) {
                    break; // there is an empty space, impossible to break the line, we check the next one
                }
                else if (x == board_length - 2) { // if x is the last of the line
                    at_least_one_line_broken = true;
                    line_to_broke_list[y] = posy + y;
                    broke_line_ ++;
                    broke_line ++; // we increment the counter
                    display_broken_line_counter();
                    if (broke_line % 10 == 0 && level < 10 && game_mode == 1) {
                        level ++;
                        display_counter(0, &level, level_text_posx + level_text_length, level_text_posy);
                    }
                }
            }
        }
        else break;
    }
    if (at_least_one_line_broken) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // we flash the line 3 times
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (line_to_broke_list[j] != 0) {
                    goto_(board_posx + 2, board_posy + line_to_broke_list[j]);
                    std::cout << std::string(board_length * 2 - 4, ' ');
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(12));
            display_board();
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
        // we reset the line
        for (int i = 0; i < 4; i++) {
            if (line_to_broke_list[i] != 0) {
                for (int x = 1; x < board_length - 1; x++) {
                    board[x][line_to_broke_list[i]] = 0;
                }
                display_board();
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                move_board_down(line_to_broke_list[i]); // we move the board down
            }
        }
    }
    add_score(broke_line_); // we add score
}
void Tetris::move_board_down(int line) {
    for (int y = 0; y < line - 1; y++) {
        for (int x = 1; x < board_length - 1; x++) {
            board[x][line - y] = board[x][line - y - 1]; // the top line is equal to the bottom line
        }
    }
    // we reset the first line because in all case it is equal to 0 when we move the board downwards
    for (int x = 1; x < board_length - 1; x++) {
        board[x][1] = 0;
    }
}
void Tetris::get_tetramino_highest_posy() {
    highest_posy = posy;
    while (1) {
        if (!check_collision(current_tetramino, 0, 1, posx, highest_posy)) highest_posy++;
        else break;
    }
}
void Tetris::set_tetramino_highest_posy(){
    erase_tetramino();
    posy = highest_posy;
    draw_tetramino();
    lock_tetramino();
}
bool Tetris::is_game_running() {
    return game_running;
}
void Tetris::draw_ascii_art(int n, int posx, int posy) {
    for (int i = 0; i < standard_font_heigth; i++) {
        goto_(posx, posy + i);
        std::cout << pagga_text[i][n];
    }
}
void Tetris::add_score(int score_) {
    switch (score_) {
    case 0:
        score += 10; // no line
        break;
    case 1:
        score += 100; // 1 line
        break;
    case 2:
        score += 300; // 2 lines
        break;
    case 3:
        score += 500; // 3 lines
        break;
    case 4: 
        score += 1000; // 4 lines (tetris)
        break;
    }
    display_counter(0, &score, score_text_posx + score_text_length, score_text_posy); // update the score
}
void Tetris::display_counter(int n, int *var, int counter_posx, int counter_posy) {
    std::string text = std::to_string(*var);
    int num_posx = 0;
    int num_posy = 0;
    int pos = 0;
    for (auto i = 0u; i < text.length(); i++) {
        for (int j = 0; j < numbers_heigth; j++) {
            num_posx = counter_posx + i * numbers_length;
            num_posy = counter_posy + j;
            goto_(num_posx, num_posy);
            if (n == 0) {
                pos = text[i] - '0'; // convert character in integer
                std::cout << score_numbers_font[j][pos]; // we write
            }
            else std::cout << std::string(numbers_length, ' '); // else we delete
        }
    }
}
void Tetris::display_broken_line_counter() {
    goto_(broke_line_counter_posx, broke_line_counter_posy);
    std::cout << "\033[31mBROKEN LINE: \033[0m" << broke_line;
}
void Tetris::draw_tetris_logo() {
    for (int i = 0; i < tetris_logo_heigth; i++) {
        goto_(tetris_logo_posx, tetris_logo_posy + i);
        std::cout << tetris_text[i];
    }
}