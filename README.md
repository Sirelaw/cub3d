Done in colaboration with ttokesi (@tomah56 on here).

This project’s objectives are: Rigor, use of C, use
of basic algorithms, information research etc.

As a graphic design project, cub3D will enable us to improve our skills in these
areas: windows, colors, events, fill shapes, etc.

To conclude cub3D is a remarkable playground to explore the playful practical appli-
cations of mathematics. With the help of the numerous documents available on the internet, we will use
mathematics as a tool to create elegant and efficient algorithms.

# cub3d 125/100 
### Done in colaboration with @ttokesi (@tomah56 on github).

This is our solution to the cub3d project of 42 school.<br>

![result](https://github.com/Sirelaw/fdf/blob/master/readme_addons/Screen%20Shot%202022-08-14%20at%202.54.19%20AM.png)

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

## raycasting
- ![Ray casting](https://en.wikipedia.org/wiki/Ray_casting) is the most basic of many computer graphics rendering algorithms that use the geometric algorithm of ray tracing. Ray tracing-based rendering algorithms operate in image order to render three-dimensional scenes to two-dimensional images. Geometric rays are traced from the eye of the observer to sample the light (radiance) travelling toward the observer from the ray direction. The speed and simplicity of ray casting comes from computing the color of the light without recursively tracing additional rays that sample the radiance incident on the point that the ray hit. The idea behind ray casting is to trace rays from the eye, one per pixel, and find the closest object blocking the path of that ray. The high speed of calculation made ray casting a handy rendering method in early real-time 3D video games.

## how to use the program
This will compile my code into an executable called `cub3d` and delete all unnecesarry files that were created during compilation.<br>

```
make
```

To visualize more maps like the one below.<br>

```
./cub3d maps/[other_map]
```

### movement
- Move with ```
 WASD ```
- Scan environment with ```
 mouse ```
- Open doors with ```
 space bar ```
- Shoot with ```
 left shift ```

## visualizing two maps from the maps/ folder.
more maps can be found in this folder.

### useful resource
![3DSage](https://www.youtube.com/watch?v=gYRrGTC7GtA)

![visualizer](https://github.com/Sirelaw/fdf/blob/master/readme_addons/sample.gif)