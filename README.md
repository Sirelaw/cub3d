# cub3d 125/100 
### Done in colaboration with @ttokesi (![tomah56](https://github.com/tomah56) on github).

This is our solution to the cub3d project of 42 school.<br>

![result](https://github.com/Sirelaw/cub3d/blob/master/readme_addons/Screen%20Shot%202022-08-15%20at%203.25.33%20PM.png)

## Input file must meet the following criteria
- file extension must be .cub
- file must contain paths to textures for <br>
 East wall (EA)<br>
 West wall (WE)<br>
 North wall (NO)<br>
 South wall (SO)<br>
 Floor      (F)<br>
 Ceiling    (C)<br>
- Included map must contain one character from NEWS. This states where the player is spun and which direction the character faces.
- The map must be bounded by 1s on all sides.

## Raycasting
- ![Ray casting](https://en.wikipedia.org/wiki/Ray_casting) is the most basic of many computer graphics rendering algorithms that use the geometric algorithm of ray tracing. Ray tracing-based rendering algorithms operate in image order to render three-dimensional scenes to two-dimensional images. Geometric rays are traced from the eye of the observer to sample the light (radiance) travelling toward the observer from the ray direction. The speed and simplicity of ray casting comes from computing the color of the light without recursively tracing additional rays that sample the radiance incident on the point that the ray hit. The idea behind ray casting is to trace rays from the eye, one per pixel, and find the closest object blocking the path of that ray. The high speed of calculation made ray casting a handy rendering method in early real-time 3D video games.

## How to use the program
This will compile the code into an executable called `cub3d` and delete all unnecesarry files that were created during compilation.<br>

```
make
```
To visualize more maps like the one below.<br>

```
./cub3d maps/[other_map]
```
### Movement
- Move with ```
 WASD ```
- Scan environment with ```
 mouse ```
- Open doors with ```
 space bar ```
- Shoot with ```
 left shift ```


### useful resource
![3DSage](https://www.youtube.com/watch?v=gYRrGTC7GtA)

more maps can be found in /maps

![visualizer](https://github.com/Sirelaw/cub3d/blob/master/readme_addons/sample1.gif)