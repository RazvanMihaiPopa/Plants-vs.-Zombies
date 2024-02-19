#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float cx, cy;
        int playerLives;
        float randomStarsNumber, starsCollected;
        glm::mat3 modelMatrix;
        float translateXHex, translateYHex, translateXStar, translateYStar;
        float scaleX, scaleY;
        float angularStep;
        float randomTimer, randomAxis, randomColor;
        int numberOfEnemies;
        float starX, starY, weaponX, weaponY;
        // TODO(student): If you need any other class variables, define them here.
        struct Star {
            glm::mat3 modelMatrix;
            glm::vec3 color;
            std::string starMesh;
            float cx, cy, rotation;
        };
        struct Weapon {
            bool isDragged;
            float initialX, initialY, movingX, movingY;
            glm::mat3 modelMatrix;
            glm::vec3 color;
            float cx, cy;
        };
        struct GameSquare {
            glm::mat3 modelMatrix, weaponMatrix;
            glm::vec3 weaponColor;
            std::string meshName, starMesh;
            glm::vector<Star> projectiles;
            bool hasWeapon, isShooting, isDestroyed;
            float counter, x, y, scaleX, scaleY, destroyTimer;
        };
        struct Enemy {
            glm::mat3 modelMatrix;
            int line;
            std::string enemyMesh;
            glm::vec3 color;
            int lives;
            float scaleX, scaleY;
            bool isDying, changesColor;
        };
        int changingColorEnemies;
        std::vector<Enemy> enemies;
        GameSquare gameTable[3][3];
        std::vector<Weapon> weapons;
        std::vector<Star> stars;
        std::vector<Star> randomStars;
        std::vector<Enemy> destroyedEnemies;

    private:
        void SetWeaponProperties(GameSquare square[3][3], glm::vec3& weaponColor, int x, int y, int i, int j);
    };
}   // namespace m1
