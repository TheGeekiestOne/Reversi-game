# Reversi-game
Reversi Game in C++ 

# Task. 
Design and implement a program allowing users to play the game Reversi (aka Othello, see
https://en.wikipedia.org/wiki/Reversi). This is a two-player game played on a board of (usually) 8*8
squares. Players take turns placing pieces on the board, or passing if they cannot do so.

The squares of the board are named A1 – H8, like on a chess board. Initially, there are black pieces
on D4 and E5, and white pieces on D5 and E4.

A piece must be placed in such a way that it, together with an existing piece, surrounds at least one
line of enemy pieces (like the white pieces are surrounded in BWWWWB). This can happen
horizontally, vertically, or diagonally. All pieces in each such surrounded group change colours to the
one of the surrounding piece (e.g. BWWWWB -> BBBBBB). The goal is to have more pieces of your
colour than the opponent at the end of the game.
