#!/usr/bin/env bash
# tests N Queens program for 6x6 chessboard
echo "[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]" > 6-expected
echo "[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]" > 6-expected
echo "[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]" > 6-expected
echo "[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]" > 6-expected
./0-nqueens.py 6 > 6-output
diff 6-output 6-expected
