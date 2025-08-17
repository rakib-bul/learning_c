#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define G (4.0 * M_PI * M_PI)  // Gravitational constant in AU^3/(solar_mass * year^2)
#define N_BODIES 9              // Sun + 8 planets
#define DT (1.0 / 365.25)       // Time step (1 day in years)
#define OUTPUT_INTERVAL 10       // Output every 10 steps
#define TOTAL_YEARS 2            // Simulate 2 years
#define TOTAL_STEPS (int)(TOTAL_YEARS / DT)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
    char name[10];
    double mass;    // Solar masses
    double x, y, z; // Position (AU)
    double vx, vy, vz; // Velocity (AU/year)
    double ax, ay, az; // Acceleration (AU/year^2)
} Body;

Body bodies[N_BODIES] = {
    {"Sun", 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Mercury", 1.6601e-7, 0.387, 0.0, 0.0, 0.0, 6.2807, 0.0, 0.0, 0.0, 0.0},
    {"Venus", 2.4478e-6, 0.723, 0.0, 0.0, 0.0, 5.0562, 0.0, 0.0, 0.0, 0.0},
    {"Earth", 3.0035e-6, 1.0, 0.0, 0.0, 0.0, 4.7406, 0.0, 0.0, 0.0, 0.0},
    {"Mars", 3.2272e-7, 1.524, 0.0, 0.0, 0.0, 4.0937, 0.0, 0.0, 0.0, 0.0},
    {"Jupiter", 9.5459e-4, 5.203, 0.0, 0.0, 0.0, 2.7555, 0.0, 0.0, 0.0, 0.0},
    {"Saturn", 2.8583e-4, 9.537, 0.0, 0.0, 0.0, 2.0338, 0.0, 0.0, 0.0, 0.0},
    {"Uranus", 4.3662e-5, 19.19, 0.0, 0.0, 0.0, 1.4336, 0.0, 0.0, 0.0, 0.0},
    {"Neptune", 5.1514e-5, 30.07, 0.0, 0.0, 0.0, 1.1453, 0.0, 0.0, 0.0, 0.0}
};

void adjustCenterOfMass() {
    double total_mass = 0.0;
    double com_x = 0.0, com_y = 0.0, com_z = 0.0;
    double momentum_x = 0.0, momentum_y = 0.0, momentum_z = 0.0;

    for (int i = 0; i < N_BODIES; i++) {
        total_mass += bodies[i].mass;
        com_x += bodies[i].mass * bodies[i].x;
        com_y += bodies[i].mass * bodies[i].y;
        com_z += bodies[i].mass * bodies[i].z;
        momentum_x += bodies[i].mass * bodies[i].vx;
        momentum_y += bodies[i].mass * bodies[i].vy;
        momentum_z += bodies[i].mass * bodies[i].vz;
    }

    com_x /= total_mass;
    com_y /= total_mass;
    com_z /= total_mass;
    double vel_com_x = momentum_x / total_mass;
    double vel_com_y = momentum_y / total_mass;
    double vel_com_z = momentum_z / total_mass;

    for (int i = 0; i < N_BODIES; i++) {
        bodies[i].x -= com_x;
        bodies[i].y -= com_y;
        bodies[i].z -= com_z;
        bodies[i].vx -= vel_com_x;
        bodies[i].vy -= vel_com_y;
        bodies[i].vz -= vel_com_z;
    }
}

void computeAccelerations() {
    for (int i = 0; i < N_BODIES; i++) {
        bodies[i].ax = 0.0;
        bodies[i].ay = 0.0;
        bodies[i].az = 0.0;
    }

    for (int i = 0; i < N_BODIES; i++) {
        for (int j = i + 1; j < N_BODIES; j++) {
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dz = bodies[j].z - bodies[i].z;
            double r = sqrt(dx*dx + dy*dy + dz*dz);
            double r3 = r * r * r;
            double factor = G / r3;

            double factor_i = factor * bodies[j].mass;
            bodies[i].ax += factor_i * dx;
            bodies[i].ay += factor_i * dy;
            bodies[i].az += factor_i * dz;

            double factor_j = factor * bodies[i].mass;
            bodies[j].ax -= factor_j * dx;
            bodies[j].ay -= factor_j * dy;
            bodies[j].az -= factor_j * dz;
        }
    }
}

void velocityVerletStep() {
    for (int i = 0; i < N_BODIES; i++) {
        bodies[i].vx += 0.5 * DT * bodies[i].ax;
        bodies[i].vy += 0.5 * DT * bodies[i].ay;
        bodies[i].vz += 0.5 * DT * bodies[i].az;

        bodies[i].x += DT * bodies[i].vx;
        bodies[i].y += DT * bodies[i].vy;
        bodies[i].z += DT * bodies[i].vz;
    }

    computeAccelerations();

    for (int i = 0; i < N_BODIES; i++) {
        bodies[i].vx += 0.5 * DT * bodies[i].ax;
        bodies[i].vy += 0.5 * DT * bodies[i].ay;
        bodies[i].vz += 0.5 * DT * bodies[i].az;
    }
}

void displayInnerSystem(double time) {
    const int ROWS = 24;
    const int COLS = 80;
    const double x_min = -2.5, x_max = 2.5;
    const double y_min = -2.5, y_max = 2.5;

    char grid[ROWS][COLS+1];

    // Initialize grid with spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
        grid[i][COLS] = '\0';
    }

    // Symbols for the first 5 bodies (Sun + inner planets)
    char symbols[5] = { 'S', 'M', 'V', 'E', 'M' };

    // Plot each body
    for (int idx = 0; idx < 5; idx++) {
        double x = bodies[idx].x;
        double y = bodies[idx].y;

        // Calculate grid coordinates
        double x_frac = (x - x_min) / (x_max - x_min);
        double y_frac = (y_max - y) / (y_max - y_min);  // Flip y-axis

        int ix = (int)(x_frac * COLS);
        int iy = (int)(y_frac * ROWS);

        // Clamp to grid boundaries
        if (ix < 0) ix = 0;
        else if (ix >= COLS) ix = COLS-1;
        if (iy < 0) iy = 0;
        else if (iy >= ROWS) iy = ROWS-1;

        // Place symbol on grid
        grid[iy][ix] = symbols[idx];
    }

    // Clear screen
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    // Print header
    printf("Solar System Simulation (Inner Planets)\n");
    printf("Time: %.2f years | Controls: Sun(S) Mercury(m) Venus(V) Earth(E) Mars(M)\n", time);
    printf("----------------------------------------------------------------\n");

    // Print grid
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", grid[i]);
    }

    // Print footer
    printf("----------------------------------------------------------------\n");
    printf("X-range: [%.1f AU, %.1f AU] | Y-range: [%.1f AU, %.1f AU]\n",
           x_min, x_max, y_min, y_max);
    fflush(stdout);

    // Delay for animation effect
    #ifdef _WIN32
        Sleep(50);
    #else
        usleep(50000);
    #endif
}

int main() {
    adjustCenterOfMass();
    computeAccelerations();

    for (int step = 0; step <= TOTAL_STEPS; step++) {
        if (step % OUTPUT_INTERVAL == 0) {
            displayInnerSystem(step * DT);
        }
        velocityVerletStep();
    }

    return 0;
}
