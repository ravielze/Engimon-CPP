#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <map>
#include <vector>
#include "lib/Map.hpp"

using namespace std;

class Game
{
private:
    Map gameMap;
    int round;
    bool gameEnd;
    void printMessage();
    void deadMessage();
    string askCommand();
    void processCommand(string command);
    void movePlayer(string command);
    void battle();
    void interact();
    void learn();
    void status();
    void swap();
    void breed();
    void cut();
    void quitGame();

public:
    Game();
    void startGame();
};

#endif
// List command terminal:
// w, a, s, d, battle, interact, learn, cut

// Command yang diperlukan:
// Jalan :
// w
// a
// s
// d

// startbattle dengan engimon sekeliling
// Di list engimon sekeliling siapa aja beserta statnya
// Pilih engimon yang mau dibattle
// Kalau menang, hapus engimon dari map
// Kalau kalah, engimon musuh masih ada di map dan ganti active engimon kita

// Switch active engimon player

// Use Skill Item
// List semua skill item yang ada
// Player pilih slot skill item
// List semua engimon yang ada
// Player pilih slot engimon
// skill item yang digunakan dicek terlebih dahulu apakaj=h kompatibel dengan elemen engimon
// skill yang baru dipelajari diberi mastery lvl 1
// jika skill engimon sudah penuh, player dapat mereplace skill baru dengan salah satu skill lama

// Bicara dengan engimon player
// template : [<NAMA_ENGIMON>]: <teks bebas>

// Melakukan breeding pokemon
// List semua engimon yang ada
// Pilih dua index
// Gagal kalau keduanya sama
// Memberi nama kepada engimon hasil breeding
// Engimon yang baru akan dimasukkan ke inventory
// Kalau inventory full gmna?? Engimon anak dibuang atau direplace ??

// OPTIONAL
// nebang pohon (T)
// syarat : active engimon harus memiliki elemen FIRE
// hancurin batu (R)
// syarat : active engimon harus memiliki elemen GROUND