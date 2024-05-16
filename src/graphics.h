#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

/// @brief Load intro card graphics
void initGfxIntro(void);

/// @brief Load main menu graphics
void initGfxMainMenu(void);

/// @brief Loads graphics for current level.
/// @param bgTiles Address to background tiles
/// @param bgMap Address to background map
/// @param objTiles Address to OAM tiles
/// @param overlayMap Address to window map
void initGfx(unsigned char *bgTiles, const unsigned char *bgMap, unsigned char *objTiles, unsigned char *overlayMap);

/// @brief Load score graphics
void initGfxScore(void);

/// @brief Update energy count on window
void updateEnergyHUDGfx(void);

/// @brief Update enemy count on window
void updateEnemyHUDGfx(void);

/// @brief Replace closed gate graphics with empty tiles
void openDoorsGfx(void);
#endif