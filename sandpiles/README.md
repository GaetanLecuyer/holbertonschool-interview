# 0x04-sandpiles
For this interview practice algorithm, there are two 3x3 grids to sum. Each grid represents a sandpile. A sandpile is stable when none of its cells contains more than 3 grains of sand. When a sandpile is unstable, the cell containing more than 3 grains of sand gives 1 grain of sand to its neighbors (horizontal and vertical, not diagonal).

[0. Sandpiles Sum](/0x04-sandpiles/0-sandpiles.c)
* Sums two sandpiles with function `void sandpiles_sum(int grid1[3][3], int grid2[3][3])`
  * `grid1` and `grid2` are 3x3 grids with integers.
    * Both grids can be assumed to be individually stable.
  * Function sums `grid1` and `grid2` into `grid1` without dynamically allocating memory.
    * When function is complete, `grid1` must be stable.
    * `grid1` must be printed before each toppling round, only if unstable.

### test_files
The test_files/ directory contains files used to test the output of the algorithm locally.
