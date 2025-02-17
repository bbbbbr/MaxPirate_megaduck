#ifndef _LEVEL_DBG_H_
#define _LEVEL_DBG_H_
//#include <gbdk/platform.h>
#include <stdint.h>
#include "../include/hitmapsPool.h"
#include "../res/generalTilesIntro_map.h"
#include "../res/generalTilesOutro_map.h"
#include "../res/generalTiles_map.h"
#include "../res/generalTiles_map2.h"
#include "../res/generalTiles_map3.h"
#include "../res/generalTiles_map4.h"
#include "../res/generalTiles_map5.h"

/// @brief List of hitmaps by level id
static const uint8_t hitMaps[GAME_MAPNUMBER] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6
};

/// @brief Pool of tile maps for levels
static const uint8_t *mapBGPool[GAME_MAPNUMBER] = {
    generalTiles_Map,
    generalTiles_Map2,
    generalTiles_Map3,
    generalTiles_Map4,
    generalTiles_Map5,
    generalTilesIntro_Map,
    generalTilesOutro_Map
};

/// @brief Top x position for the gate in each level
static const uint8_t doorLocationsTopX[GAME_MAPNUMBER] = {
    8,
    28,
    28,
    8,
    2,
    28,
    28
};

/// @brief Left y position for the gate in each level
static const uint8_t doorLocationsLeftY[GAME_MAPNUMBER] = {
    28,
    6,
    28,
    6,
    28,
    28,
    28,
    };

/// @brief Bottom x position for the gate in each level
static const uint8_t doorLocationsBottomX[GAME_MAPNUMBER] = {
    8,
    28,
    28,
    8,
    14,
    28,
};

/// @brief Right y position for the gate in each level
static const uint8_t doorLocationsRightY[GAME_MAPNUMBER] = {
    28,
    6,
    8,
    6,
    28,
    28,
    28,
};

/// @brief Initialize level
void initLevel(void);

/// @brief Loads random level
/// @param numberEnemies Number of enemies to spawn
void loadLevel(uint8_t numberEnemies);

/// @brief Selects a random level from the pool and loads it
void loadNextLevel(void);

#endif // _LEVEL_DBG_H_