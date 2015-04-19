/* board.h

   GNU Chess engine

   Copyright (C) 2001-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


// board.h

#ifndef BOARD_H
#define BOARD_H

// includes

#include "colour.h"
#include "piece.h"
#include "square.h"
#include "util.h"

namespace engine {

// constants

const int Empty = 0;
const int Edge = Knight64; // HACK: uncoloured knight

const int WP = WhitePawn256;
const int WN = WhiteKnight256;
const int WB = WhiteBishop256;
const int WR = WhiteRook256;
const int WQ = WhiteQueen256;
const int WK = WhiteKing256;

const int BP = BlackPawn256;
const int BN = BlackKnight256;
const int BB = BlackBishop256;
const int BR = BlackRook256;
const int BQ = BlackQueen256;
const int BK = BlackKing256;

const int FlagsNone = 0;
const int FlagsWhiteKingCastle  = 1 << 0;
const int FlagsWhiteQueenCastle = 1 << 1;
const int FlagsBlackKingCastle  = 1 << 2;
const int FlagsBlackQueenCastle = 1 << 3;

const int StackSize = 4096;

// macros

#define KING_POS(board,colour) ((board)->piece[colour][0])

// types

struct board_t {

   int square[SquareNb];
   int pos[SquareNb];

   sq_t piece[ColourNb][32]; // only 17 are needed
   int piece_size[ColourNb];

   sq_t pawn[ColourNb][16]; // only 9 are needed
   int pawn_size[ColourNb];

   int piece_nb;
   int number[16]; // only 12 are needed

   int pawn_file[ColourNb][FileNb];

   int turn;
   int flags;
   int ep_square;
   int ply_nb;
   int sp; // TODO: MOVE ME?

   int cap_sq;

   int opening;
   int endgame;

   uint64 key;
   uint64 pawn_key;
   uint64 material_key;

   uint64 stack[StackSize];
};

// functions

extern bool board_is_ok         (const board_t * board);

extern void board_clear         (board_t * board);
extern void board_copy          (board_t * dst, const board_t * src);

extern void board_init_list     (board_t * board);

extern bool board_is_legal      (const board_t * board);
extern bool board_is_check      (const board_t * board);
extern bool board_is_mate       (const board_t * board);
extern bool board_is_stalemate  (board_t * board);

extern bool board_is_repetition (const board_t * board);

extern int  board_material      (const board_t * board);
extern int  board_opening       (const board_t * board);
extern int  board_endgame       (const board_t * board);

}  // namespace engine

#endif // !defined BOARD_H

// end of board.h

