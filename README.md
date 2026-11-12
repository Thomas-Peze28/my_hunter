# my_hunter

A Duck Hunt–style shooting game written in C with CSFML.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![CSFML](https://img.shields.io/badge/CSFML-8CC445?style=flat&logo=sfml&logoColor=white)
![Epitech](https://img.shields.io/badge/Epitech-1st%20year-0B5AB4?style=flat)

> Epitech project · 1st year (2024–2025) · Solo project

## About

my_hunter is my first graphical project at Epitech. Ducks fly across the screen and the player shoots them with the mouse to score points. The goal was to learn the basics of a game loop: window and event handling, sprite animation, timing with clocks, and sound.

## Features

- Main menu with a play button
- Animated duck sprites moving across the screen
- Custom crosshair cursor
- Score counter and 3 lives, with a game over screen
- Background music
- `-h` option that prints the rules

## Screenshots

![Main menu](https://github.com/user-attachments/assets/ebbd3860-1ddc-439a-a280-664f46aa84cb)
![In game](https://github.com/user-attachments/assets/6c8001c1-bbe7-4e1a-8e4e-f8f2b3a62b22)
![Game over](https://github.com/user-attachments/assets/74355c69-823f-445a-9b9f-2dec3987afc0)

## Getting started

### Requirements

- GCC and Make
- [CSFML](https://www.sfml-dev.org/download/csfml/) (on Debian/Ubuntu: `sudo apt install libcsfml-dev`)

### Build

```bash
make
```

This builds the `libmy` helper library, then the `my_hunter` binary.

### Usage

```bash
./my_hunter       # start the game
./my_hunter -h    # print the rules
```

## Controls

| Action | Input |
|--------|-------|
| Shoot  | Left mouse click |

## Project structure

```
.
├── main.c, init.c, init_game.c, play.c, window.c   # game loop and logic
├── include/          # headers
├── lib/my/           # small C utility library (libmy)
└── src/              # assets: sprites, font, music
```

## Author

- Thomas Pezé ([@Thomas-Peze28](https://github.com/Thomas-Peze28))
