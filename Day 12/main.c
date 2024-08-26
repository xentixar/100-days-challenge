#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

Point snake[WIDTH * HEIGHT];
Point fruit;
int snakeLength;
int score;
int dir; // 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT
int gameOver;

void init();
void draw();
void input();
void logic();
void cleanup();

int main() {
    srand(time(NULL));
    init();

    while (!gameOver) {
        draw();
        input();
        logic();
        usleep(200000); // Sleep for 200 milliseconds
    }

    cleanup();
    return 0;
}

void init() {
    initscr(); // Initialize ncurses
    cbreak(); // Disable line buffering
    noecho(); // Don't echo input characters
    keypad(stdscr, TRUE); // Enable special keys
    timeout(100); // Set a 100 millisecond timeout for getch()

    // Initialize game state
    gameOver = 0;
    dir = 1; // Start moving to the right
    snakeLength = 1;
    score = 0;

    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;

    fruit.x = rand() % WIDTH;
    fruit.y = rand() % HEIGHT;
}

void draw() {
    clear(); // Clear the screen

    // Draw the border
    for (int i = 0; i < WIDTH + 2; i++) {
        mvaddch(0, i, '#');
        mvaddch(HEIGHT + 1, i, '#');
    }
    for (int i = 1; i < HEIGHT + 1; i++) {
        mvaddch(i, 0, '#');
        mvaddch(i, WIDTH + 1, '#');
    }

    // Draw the snake
    for (int i = 0; i < snakeLength; i++) {
        mvaddch(snake[i].y + 1, snake[i].x + 1, 'o');
    }

    // Draw the fruit
    mvaddch(fruit.y + 1, fruit.x + 1, 'F');

    // Display the score
    mvprintw(HEIGHT + 2, 0, "Score: %d", score);
    refresh(); // Refresh the screen to show the updates
}

void input() {
    int ch = getch();
    switch (ch) {
        case KEY_UP:
            if (dir != 2) dir = 0;
            break;
        case KEY_RIGHT:
            if (dir != 3) dir = 1;
            break;
        case KEY_DOWN:
            if (dir != 0) dir = 2;
            break;
        case KEY_LEFT:
            if (dir != 1) dir = 3;
            break;
        case 'q':
            gameOver = 1;
            break;
    }
}

void logic() {
    Point prevHead = snake[0];
    Point prev2;
    snake[0].x += (dir == 1) - (dir == 3);
    snake[0].y += (dir == 2) - (dir == 0);

    // Wrap around the screen
    if (snake[0].x >= WIDTH) snake[0].x = 0;
    if (snake[0].x < 0) snake[0].x = WIDTH - 1;
    if (snake[0].y >= HEIGHT) snake[0].y = 0;
    if (snake[0].y < 0) snake[0].y = HEIGHT - 1;

    // Check for collision with itself
    for (int i = 1; i < snakeLength; i++) {
        if (snake[i].x == snake[0].x && snake[i].y == snake[0].y) {
            gameOver = 1;
        }
    }

    // Move the tail
    for (int i = 1; i < snakeLength; i++) {
        prev2 = snake[i];
        snake[i] = prevHead;
        prevHead = prev2;
    }

    // Check if snake has eaten the fruit
    if (snake[0].x == fruit.x && snake[0].y == fruit.y) {
        score += 10;
        fruit.x = rand() % WIDTH;
        fruit.y = rand() % HEIGHT;
        snakeLength++;
    }
}

void cleanup() {
    endwin(); // End ncurses mode
}
