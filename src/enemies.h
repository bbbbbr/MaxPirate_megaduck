#ifndef __ENEMIES_H__
#define __ENEMIES_H__

/// @brief Initializes and spawns enemies
/// @param parNumberEnemies Number of enemies to spawn
void spawnEnemy(void);

/// @brief Spawn enemy in the next available slot.
void initEnemies(uint8_t numberEnemies);

/// @brief Draw and animate active enemies
void drawEnemies(void);

/// @brief Update method. Handles main enemy behaviour.
void updateEnemies(void);


#endif