#!/usr/bin/env bash
# tests N Queens program for 4x4 chessboard
echo "[[0, 1], [1, 3], [2, 0], [3, 2]]" > 4-expected
echo "[[0, 2], [1, 0], [2, 3], [3, 1]]" >> 4-expected
./0-nqueens.py 4 > 4-output
diff 4-output 4-expected
