#include <gb/gb.h>
#include <rand.h>
#include "../res/generalTiles.h"
#include "../res/heroTiles.h"
#include "../res/overlayMap.h"
#include "enemies.h"
#include "graphics.h"
#include "level.h"
#include "vars.h"

/// @brief Initialize level
void initLevel(void)
{
    gamestate = GAMESTATE_PLAYING;
    hero.state = HEROSTATE_NORMAL;
    hero.lastDirection = HERO_FACING_UP;

    hero.energy = HERO_ENERGYMAX;
    hero.x = 72;
    hero.y = 88;
    hero.health = HERO_STARTHEALTH;

    weapon.type = WEAPON_TYPE_INACTIVE;
    weapon.x = 200;
    weapon.y = 200;
    currentLevelId = GAME_MAPNUMBER - 2;

    killedEnemies = 0;
    roomsCleared = 255;

    loadLevel(0);
}

/// @brief Loads random level
/// @param numberEnemies Number of enemies to spawn
void loadLevel(uint8_t numberEnemies)
{
    // Load hitboxes from hitbox pool
    currentLevelHitboxes = &hitmapPool[hitMaps[currentLevelId]];

    // Load graphics
    initGfx(generalTiles, mapBGPool[currentLevelId], heroTiles, overlayMap);
    set_win_tile_xy(GAME_NUMBERSPRITEHEALTHX, 1, GAME_NUMBERSPRITEOFFSETPLAYING + hero.health);
    updateEnergyHUDGfx();
    updateEnemyHUDGfx();

    // Spawn enemies
    initEnemies(numberEnemies);
    SHOW_SPRITES;
}

/// @brief Selects a random level from the pool and loads it
void loadNextLevel(void)
{
    // Reset hero position after warp
    if (hero.x > 143)
        hero.x = 16;
    else if (hero.x <= 1)
        hero.x = 132;

    if (hero.y > 111)
        hero.y = 16;
    else if (hero.y <= 2)
        hero.y = 96;

    ++roomsCleared;

    // Load new level
    if (roomsCleared > 0 && (roomsCleared % GAME_HEALTHROOMNUMBER) == 0)
    {
        heartCollected = 0;
        hero.x = 72;
        hero.y = 96;
        currentLevelId = GAME_MAPNUMBER - 1;
        loadLevel(0);
    }
    else
    {
        // Select new random level from pool
        currentLevelId = (uint8_t)rand() % (GAME_MAPNUMBER - 2);
        loadLevel(ENEMY_DEFAULTENEMYNUMBER + ((uint8_t)rand() % 4));
    }
}
