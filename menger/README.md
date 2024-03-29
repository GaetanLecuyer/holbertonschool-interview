# 0x0B-menger
This interview practice algorithm utilizes the concept of a Menger Sponge (also known as Menger Cube, Menger Universal Cube, Sierpinski Cube, or Sierpinski Sponge).  The Menger Sponge starts as a cube (level 0), then with each subsequent layer, the face of the cube is divided into 9 squares (3 x 3), sub-diving the cube into 27 mini-cubes.  The smaller cube is removed from the middle of each face, leaving a hole, and the very center of the large cube is removed, leaving 20 mini-cubes.  This process of dividing into and removing mini-cubes is repeated for more levels.  While a typical Menger Sponge is 3-dimensional, this algorithm builds a 2D Menger sponge.  The idea is the same, but the dividing and removing is applied only to one face of the original cube, so each level divides the square into 9 mini-squares and the center square is always removed.

[2D Menger Sponge](/0x0B-menger/0-menger.c)
* Write a C function `void menger(int level)` that draws a 2D Menger Sponge:
  * `level` is the level of Menger Sponge to draw
  * if `level` is less than 0, the function does nothing
  * if `level` is 0, the sponge is represented by the `#` character
  * for `level == N` sponges, where `N` is greater than 0, the sponge is a 3x3 square of level `N - 1` sponges, except the center one which is left empty

### test_files
The test_files/ directory contains files used to test the output of the algorithm locally.
