# SoLong_MapCreator
A map creator for the 42 school So Long project

## Compilation (already done)
```bash
gcc main.c
```

## Usage

- *nb_maps* : Number of maps to generate
- *x_max_size* : Max X size of the maps, value will be choosed randomly beetween 0 and x_max_size for each map
- *y_max_size* : Same as above but for the y size
- *add_enemies* : Do enemies have to be added to the map (default 0 -> no)

```bash
./a.out nb_maps x_max_size y_max_size add_enemies
```

*Sometimes the generator can timeout, but not my fault <3*