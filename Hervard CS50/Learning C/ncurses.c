#include <ncurses/curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DELAY 100000  // Delay between frames in microseconds
#define INITIAL_SNAKE_LENGTH 3

typedef struct {
    int y;
    int x;
} Position;

typedef struct {
    Position *body;
    int length;
    int direction;  // 0: up, 1: right, 2: down, 3: left
} Snake;

typedef struct {
    Position pos;
} Food;

// Global variables
Snake snake;
Food food;
int score = 0;
int max_y = 0, max_x = 0;
int game_over = 0;

// Function declarations
void init_game();
void generate_food();
void draw_border();
void update_snake();
void handle_input();
int check_collision();
void game_loop();
void cleanup();

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    // Check for color support
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support colors\n");
        return 1;
    }
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // Snake color
    init_pair(2, COLOR_RED, COLOR_BLACK);    // Food color
    init_pair(3, COLOR_WHITE, COLOR_BLACK);  // Border and text color

    // Get screen dimensions
    getmaxyx(stdscr, max_y, max_x);

    // Initialize game
    init_game();

    // Main game loop
    game_loop();

    // Cleanup
    cleanup();
    return 0;
}

void init_game() {
    // Initialize snake
    snake.length = INITIAL_SNAKE_LENGTH;
    snake.body = malloc(snake.length * sizeof(Position));
    snake.direction = 1;  // Start moving right

    // Initialize snake body in the middle of the screen
    int start_y = max_y / 2;
    int start_x = max_x / 2;
    for (int i = 0; i < snake.length; i++) {
        snake.body[i].y = start_y;
        snake.body[i].x = start_x - i;
    }

    // Generate first food
    generate_food();

    // Initialize score
    score = 0;
    game_over = 0;
}

void generate_food() {
    // Generate food at random position (within borders)
    food.pos.y = (rand() % (max_y - 2)) + 1;
    food.pos.x = (rand() % (max_x - 2)) + 1;

    // Make sure food doesn't spawn on snake
    for (int i = 0; i < snake.length; i++) {
        if (food.pos.y == snake.body[i].y && food.pos.x == snake.body[i].x) {
            generate_food();  // Try again
            break;
        }
    }
}

void draw_border() {
    attron(COLOR_PAIR(3));
    for (int i = 0; i < max_x; i++) {
        mvprintw(0, i, "-");
        mvprintw(max_y - 1, i, "-");
    }
    for (int i = 0; i < max_y; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, max_x - 1, "|");
    }
    attroff(COLOR_PAIR(3));
}

void update_snake() {
    // Move snake body (from tail to head)
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }

    // Move head based on direction
    switch (snake.direction) {
        case 0:  // Up
            snake.body[0].y--;
            break;
        case 1:  // Right
            snake.body[0].x++;
            break;
        case 2:  // Down
            snake.body[0].y++;
            break;
        case 3:  // Left
            snake.body[0].x--;
            break;
    }

    // Check if snake ate food
    if (snake.body[0].y == food.pos.y && snake.body[0].x == food.pos.x) {
        // Increase snake length
        snake.length++;
        snake.body = realloc(snake.body, snake.length * sizeof(Position));
        snake.body[snake.length - 1] = snake.body[snake.length - 2];

        // Increase score
        score += 10;

        // Generate new food
        generate_food();
    }
}

void handle_input() {
    int ch = getch();
    switch (ch) {
        case 'w':
        case KEY_UP:
            if (snake.direction != 2)  // Prevent 180-degree turn
                snake.direction = 0;
            break;
        case 'd':
        case KEY_RIGHT:
            if (snake.direction != 3)  // Prevent 180-degree turn
                snake.direction = 1;
            break;
        case 's':
        case KEY_DOWN:
            if (snake.direction != 0)  // Prevent 180-degree turn
                snake.direction = 2;
            break;
        case 'a':
        case KEY_LEFT:
            if (snake.direction != 1)  // Prevent 180-degree turn
                snake.direction = 3;
            break;
        case 'q':
            game_over = 1;
            break;
    }
}

int check_collision() {
    // Check wall collision
    if (snake.body[0].y <= 0 || snake.body[0].y >= max_y - 1 ||
        snake.body[0].x <= 0 || snake.body[0].x >= max_x - 1) {
        return 1;
    }

    // Check self collision (skip head)
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].y == snake.body[i].y && snake.body[0].x == snake.body[i].x) {
            return 1;
        }
    }

    return 0;
}

void game_loop() {
    while (!game_over) {
        clear();

        // Draw border
        draw_border();

        // Draw snake
        attron(COLOR_PAIR(1));
        for (int i = 0; i < snake.length; i++) {
            mvprintw(snake.body[i].y, snake.body[i].x, i == 0 ? "@" : "o");
        }
        attroff(COLOR_PAIR(1));

        // Draw food
        attron(COLOR_PAIR(2));
        mvprintw(food.pos.y, food.pos.x, "*");
        attroff(COLOR_PAIR(2));

        // Draw score
        attron(COLOR_PAIR(3));
        mvprintw(0, 2, " Score: %d ", score);
        attroff(COLOR_PAIR(3));

        // Handle input
        handle_input();

        // Update snake position
        update_snake();

        // Check for collisions
        if (check_collision()) {
            game_over = 1;
        }

        refresh();
        usleep(DELAY);
    }

    // Game over screen
    clear();
    draw_border();
    attron(COLOR_PAIR(3));
    mvprintw(max_y / 2 - 1, max_x / 2 - 5, "GAME OVER");
    mvprintw(max_y / 2, max_x / 2 - 5, "Score: %d", score);
    mvprintw(max_y / 2 + 1, max_x / 2 - 10, "Press any key to exit");
    attroff(COLOR_PAIR(3));
    refresh();

    nodelay(stdscr, FALSE);
    getch();
}

void cleanup() {
    free(snake.body);
    endwin();
}
