#ifndef __HERO_H__
#define __HERO_H__

/// @brief Draw and animate hero sprite
void drawHero(void);

/// @brief Main hero routine
void updateHero(void);

/// @brief Handle knockback during hitstate
void handleHitstate(void);

/// @brief Main weapon routine
void updateWeapon(void);
#endif