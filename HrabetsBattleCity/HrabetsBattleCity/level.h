#pragma once


/////////////////////////////////////
// Include
#include "direction.h"
#include "Framework.h"
#include "rect.h"


/////////////////////////////////////
// Extern
extern Sprite* g_atlas00;


/////////////////////////////////////
// Level data
const int kScreenRows = 37;
const int kScreenColumns = 80;
const int kLevelRows = kScreenRows;
const int kLevelColumns = 50;
const int kPixelsPerCell = 16;

const unsigned char	CellSymbol_Player1 = '1';
const unsigned char	CellSymbol_Tank = 'T';
const unsigned char	CellSymbol_BrickWall = '#';
const unsigned char	CellSymbol_SteelWall = '@';
const unsigned char	CellSymbol_Base = 'B';
const unsigned char	CellSymbol_EnemySpawner = 'S';

const unsigned char kLevelData0[kLevelRows][kLevelColumns + 1] =
{
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
	"@S                           @@               S  @",
	"@                            @@                  @",
	"@                            @@                  @",
	"@   ##   ##   @@@##### S@@        @@@@   #  ##   @",
	"@   #######   @@@#####  @@        @@@@   #####   @",
	"@   #######             @@        @      #####   @",
	"@   ##   ##             @@@@@@@@@@@      #  ##   @",
	"@                            @@                  @",
	"@                @@          @@                  @",
	"@                @@          @@                  @",
	"@@@   @@@#####   ########             ####@@   @@@",
	"@@@   @@@#####   #####@@##        #   ####@@   @@@",
	"@@@   @@@#####   #####@@##        #   ####@@   @@@",
	"@                  ###@@##@@    @@#              @",
	"@                    #####@@@@@@@@#              @",
	"@                       ###########              @",
	"@   ##   ##               ########       #  ##   @",
	"@   #######                              #####   @",
	"@   #######   @@@#####             @@@   #####   @",
	"@   ##   ##   @@@#####             @@@   #  ##   @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                                                @",
	"@                       ##########  1            @",
	"@                       #B       #               @",
	"@                       #        #               @",
	"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
};


const Rect kBrickWallImage = Rect({ kPixelsPerCell * kPixelsPerCell, 0, kPixelsPerCell, kPixelsPerCell });
const Rect kSteelWallImage = Rect({ kPixelsPerCell * kPixelsPerCell, kPixelsPerCell, kPixelsPerCell, kPixelsPerCell });


/////////////////////////////////////
// Tanks data
const float kTankFireCooldownTime = 0.5;
const int kTankSize = 3;
const Rect kTankImage = Rect({ 0, 0, kPixelsPerCell, kPixelsPerCell });


/////////////////////////////////////
// Player data
const int kPlayerHealth = 16;
const int kPlayerSpeed = 10;


/////////////////////////////////////
// Enemy data
const int kEnemiesPerLevel = 24;
const int kEnemiesPerLevelInOneMoment = 6;
const int kEnemyHealth = 5;
const int kEnemySpeed = 5;
const float kEnemySpawnerSpawnTime = 10.0;
const float kEnemyAIAnalizeTime = 0.5;


/////////////////////////////////////
// Base data
const int kBaseColumns = 8;
const int kBaseRows = 2;
const int kBaseHealth = 3;
const Rect kBaseImage = Rect({ kPixelsPerCell * 19, 2 * kPixelsPerCell, kBaseColumns * kPixelsPerCell, kBaseRows * kPixelsPerCell });


/////////////////////////////////////
// Bullet data
const float kBulletSpeed = 30.0;
const Rect kBulletImage = Rect({ kPixelsPerCell * kPixelsPerCell, 6 * kPixelsPerCell, kPixelsPerCell, kPixelsPerCell });