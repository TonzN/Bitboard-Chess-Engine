#include<bitset>
#include<iostream>

#ifndef B

using std::cout;
using Bitboard = std::bitset<64>;

Bitboard white_pawn_set = 0x000000000000FF00ULL;
Bitboard white_knight_set = 0x0000000000000042ULL;
Bitboard white_bishop_set = 0x0000000000000024ULL;
Bitboard white_rook_set = 0x0000000000000008ULL;
Bitboard white_queen_set = 0x0000000000000010ULL;
Bitboard white_king_set = 0x0000000000000008ULL;
Bitboard black_pawn_set = 0x00FF000000000000ULL;
Bitboard black_knight_set = 0x2400000000000000ULL;
Bitboard black_bishop_set = 0x4200000000000000ULL;
Bitboard black_roook_set = 0x8100000000000000ULL;
Bitboard black_queen_set = 0x2000000000000000ULL;
Bitboard black_king_set = 0x0800000000000000ULL;

//Files
Bitboard File_A = 0x8080808080808080ULL;
Bitboard File_B = 0x4040404040404040ULL;
Bitboard File_C = 0x2020202020202020ULL;
Bitboard File_D = 0x1010101010101010ULL;
Bitboard File_E = 0x0808080808080808ULL;
Bitboard File_F = 0x0404040404040404ULL;
Bitboard File_G = 0x0202020202020202ULL;
Bitboard File_H = 0x0101010101010101ULL;

Bitboard File_AB = File_A | File_B;
Bitboard File_GH = File_G | File_H;

bool white_first_move = true;
bool black_first_mvoer = true;

void print_bitboard(const Bitboard& bb) {
    for (int rank = 7; rank >= 0; --rank) {
        for (int file = 7; file >= 0; --file) {
            int square = rank * 8 + file;
            std::cout << (bb[square] ? '1' : '0') << ' ';
        }
        std::cout << std::endl;
    }
    cout << "\n";
}

Bitboard pawn_attacking_squares(Bitboard& bb) {
    Bitboard result = bb << 8;    
    if (white_first_move == true) {
        result |= bb << 16;
    }
    return result;
}

Bitboard knight_attacking_squares(Bitboard& bb) {
    Bitboard result = ((bb >> 6 | bb << 10) & ~File_GH) 
    | ((bb >> 10 | bb << 6) & ~File_AB)
    | ((bb >> 15 | bb << 17) & ~File_H)
    | ((bb >> 17 | bb << 15) & ~File_A);

    return result;
}

int main() { 
    print_bitboard(pawn_attacking_squares(white_pawn_set));
    cout << "\n";
    //printBitboard(white_knight_set);
    knight_attacking_squares(white_knight_set);
}