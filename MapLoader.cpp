#include "MapLoader.h"
#include <stdio.h>

MapLoader::MapLoader(Game* game) {
    this->game = game;
}

bool MapLoader::Load(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp) {
        Grid* grid = game->GetGrid();
        int rows = grid->GetRows(),
            cols = grid->GetCols();

        int players = 0;
        bool addedInfoBox = false;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                switch (fgetc(fp)) {
                    case CHAR_WALL:
                        game->AddWall(row, col);
                        break;
                    case CHAR_PLAYER:
                        game->AddPlayer(row, col);
                        players++;
                        break;
                    case CHAR_INFO_BOX:
                        if (!addedInfoBox) {
                            game->AddInfoBox(row, col);
                            addedInfoBox = true;
                        }
                        break;
                }
            }
            fgetc(fp); // Consume linebreak
        }

        Square* square;
        for (int i = players; i < MIN_NUM_PLAYERS; i++) {
            // Add additional players if needed
            square = game->GetValidDropSquare();
            game->AddPlayer(square);
        }

        fclose(fp);
        return true;
    }
    return false;
}