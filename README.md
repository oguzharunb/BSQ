# BSQ
42 Kocaeli BSQ

This project is about the final project of 42 Piscine. The Biggest Square.

# Biggest Square Project

## Overview

The **Biggest Square** project is a challenge to find and represent the largest square possible on a given map, avoiding obstacles. This project requires reading a map from a file, processing it to find the largest square that can be formed using the "empty" spaces, and then outputting the modified map where the largest square is represented by "full" characters.

## Project Description

The map file has the following format:

1. **First Line**: Contains metadata about the map.
   - Number of lines in the map
   - "Empty" character
   - "Obstacle" character
   - "Full" character

2. **Subsequent Lines**: The map itself, composed of:
   - "Empty" characters
   - "Obstacle" characters

### Objectives

- **Find the Largest Square**: Identify the largest possible square that can be formed using the "empty" characters while avoiding the "obstacle" characters.
- **Replace "Empty" Characters**: Update the map to represent the identified square with "full" characters.
- **Handle Multiple Maps**: The program should support multiple map files as arguments and handle each file separately.

### Output Criteria

- If multiple solutions exist, choose the one closest to the top of the map, and if there's still a tie, the one closest to the left.
- Each map's result or error should be followed by a blank line when multiple maps are provided.

## Usage

### Command Line

To run the program with one or more map files, use the following command:

```bash
./biggest_square map1.txt map2.txt ...


%>cat example_file
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
%>./bsq example_file
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxx...o...........
.....xxxxxxx...............
......o..............o.....
..o.......o................
%>

obastug w/yusudemi