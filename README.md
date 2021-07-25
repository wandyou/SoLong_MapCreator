# SoLong_MapCreator
A map creator for the 42 school So Long project

## Compilation (already done)
```bash
gcc main.c
```

## Usage

nb_maps : Number of maps to generate
x_max_size : Max X size on the maps, value while be choosed randomly beetween 0 and x_max_size for each map
y_max_size : Same as above but for the y size
add_enemies : Do enemies have to be added to the maps (default 0 -> no)

```bash
./a.out nb_maps x_max_size y_max_size add_enemies
```