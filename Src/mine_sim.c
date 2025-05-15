#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

typedef struct {
    int wallet;
    int xp;
    int level;
    int mine_speed;
    int xp_gain;
    int powerup_active;
    int powerup_ticks_left;
    int luck;
    int xp_threshold;
} GameState;

GameState game = {0, 0, 1, 1, 1, 0, 0, 0, 10};

const char *savefile = "save.dat";

void save_game() {
    FILE *f = fopen(savefile, "wb");
    if (f) {
        fwrite(&game, sizeof(GameState), 1, f);
        fclose(f);
    }
}

void load_game() {
    FILE *f = fopen(savefile, "rb");
    if (f) {
        fread(&game, sizeof(GameState), 1, f);
        fclose(f);
    }
}

void draw_ui() {
    clear();
    mvprintw(1, 2, "=== CRYPTO MINER SIM ===");
    mvprintw(3, 2, "Coins: %d", game.wallet);
    mvprintw(4, 2, "XP: %d / %d", game.xp, game.xp_threshold);
    mvprintw(5, 2, "Level: %d", game.level);
    mvprintw(6, 2, "Mine Speed: %d", game.mine_speed);
    mvprintw(7, 2, "Luck: %d%%", game.luck);

    if (game.powerup_active) {
        mvprintw(8, 2, "Power-Up: ACTIVE (%d ticks left)", game.powerup_ticks_left);
    } else {
        mvprintw(8, 2, "Power-Up: INACTIVE");
    }

    mvprintw(10, 2, "[S]hop | [Q]uit");
    refresh();
}

void level_up() {
    game.level++;
    game.xp = 0;
    game.xp_threshold += 10;
    mvprintw(12, 2, ">> LEVEL UP! You're now level %d!", game.level);
    refresh();
    sleep(1);
}

void mine_tick() {
    int earned = game.mine_speed;

    if ((rand() % 100) < game.luck) {
        earned *= 2;
        mvprintw(13, 2, ">> Lucky Mine! Coins doubled!");
    }

    game.wallet += earned;
    game.xp += game.xp_gain;

    if (game.xp >= game.xp_threshold) {
        level_up();
    }

    if (game.powerup_active) {
        game.powerup_ticks_left--;
        if (game.powerup_ticks_left <= 0) {
            game.powerup_active = 0;
            game.mine_speed /= 2;
            mvprintw(14, 2, ">> Power-Up expired.");
        }
    }
}

void shop() {
    echo();
    nocbreak();
    int ch;

    clear();
    mvprintw(2, 2, "-- SHOP --");
    mvprintw(4, 4, "1. Upgrade Speed (20 coins)");
    mvprintw(5, 4, "2. Increase Luck +5%% (30 coins)");
    mvprintw(6, 4, "3. Power-Up x2 Speed (50 coins)");
    mvprintw(7, 4, "0. Exit");

    mvprintw(9, 2, "Choice: ");
    refresh();

    ch = getch();
    noecho();
    cbreak();

    switch (ch) {
        case '1':
            if (game.wallet >= 20) {
                game.wallet -= 20;
                game.mine_speed++;
            }
            break;
        case '2':
            if (game.wallet >= 30) {
                game.wallet -= 30;
                game.luck += 5;
            }
            break;
        case '3':
            if (game.wallet >= 50 && !game.powerup_active) {
                game.wallet -= 50;
                game.powerup_active = 1;
                game.powerup_ticks_left = 10;
                game.mine_speed *= 2;
            }
            break;
        default:
            break;
    }
}

int main() {
    srand(time(NULL));
    load_game();

    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(0);

    int tick = 0;
    int input;

    while (1) {
        draw_ui();
        mine_tick();
        save_game();

        input = getch();
        if (input == 'q' || input == 'Q') {
            break;
        } else if (input == 's' || input == 'S') {
            shop();
        }

        refresh();
        sleep(1);
        tick++;
    }

    endwin();
    save_game();
    return 0;
}

