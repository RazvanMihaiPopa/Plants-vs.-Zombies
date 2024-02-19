#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

using namespace std;
using namespace m1;

/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */

Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 130;
    // TODO(student): Compute coordinates of a square's center, and store
    // then in the `cx` and `cy` class variables (see the header). Use
    // `corner` and `squareSide`. These two class variables will be used
    // in the `Update()` function. Think about it, why do you need them?
    cx = corner.x + (squareSide) / 2;
    cy = corner.y + (squareSide) / 2;


    // Initialize tx and ty (the translation steps)
    translateXHex = 1350;
    translateYHex = 0;

    // Initialize sx and sy (the scale factors)
    scaleX = 1;
    scaleY = 1;

    // Initialize angularStep
    angularStep = 0;
    playerLives = 3;
    randomTimer = 1;
    numberOfEnemies = 0;
    enemies.clear();
    weapons.clear();

    Mesh* redSquare = object2D1::CreateSquare("redSquare", corner, 90, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(redSquare);

    Mesh* square2 = object2D1::CreateSquare("square2", corner, squareSide, glm::vec3(0.3, 0, 0.8));
    AddMeshToList(square2);

    Mesh* greenSquare = object2D1::CreateSquare("greenSquare", corner, squareSide, glm::vec3(0.6, 1, 0.8), true);
    AddMeshToList(greenSquare);
    // line 0
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(80, 15);
    gameTable[0][0].hasWeapon = false;
    gameTable[0][0].modelMatrix = modelMatrix;
    gameTable[0][0].counter = 3;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(230, 15);
    gameTable[0][1].hasWeapon = false;
    gameTable[0][1].modelMatrix = modelMatrix;
    gameTable[0][1].counter = 3;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(380, 15);
    gameTable[0][2].hasWeapon = false;
    gameTable[0][2].modelMatrix = modelMatrix;
    gameTable[0][2].counter = 3;
    
    // line 1
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(80, 165);
    gameTable[1][0].hasWeapon = false;
    gameTable[1][0].modelMatrix = modelMatrix;
    gameTable[1][0].counter = 3;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(230, 165);
    gameTable[1][1].hasWeapon = false;
    gameTable[1][1].modelMatrix = modelMatrix;
    gameTable[1][1].counter = 3;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(380, 165);
    gameTable[1][2].hasWeapon = false;
    gameTable[1][2].modelMatrix = modelMatrix;
    gameTable[1][2].counter = 3;

    // line 3
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(80, 315);
    gameTable[2][0].hasWeapon = false;
    gameTable[2][0].modelMatrix = modelMatrix;
    gameTable[2][0].counter = 3;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(230, 315);
    gameTable[2][1].hasWeapon = false;
    gameTable[2][1].modelMatrix = modelMatrix;
    gameTable[2][1].counter = 3;

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(380, 315);
    gameTable[2][2].hasWeapon = false;
    gameTable[2][2].modelMatrix = modelMatrix;
    gameTable[2][2].counter = 3;

    Mesh* rectangle = object2D1::CreateRectangle("rectangle", corner, 50, 430, glm::vec3(0.3, 0, 0.8), true);
    AddMeshToList(rectangle);

    Mesh* enemy1 = object2D1::CreateHexagon("enemy1", corner + glm::vec3(0,0,1), 40, glm::vec3(0.4, 0.1, 0.6), glm::vec3(0.8, 0.3, 1), true);
    AddMeshToList(enemy1);

    Mesh* enemy2 = object2D1::CreateHexagon("enemy2", corner + glm::vec3(0, 0, 1), 40, glm::vec3(0.4, 0.1, 0.6), glm::vec3(1, 0.5, 0.9), true);
    AddMeshToList(enemy2);

    Mesh* enemy3 = object2D1::CreateHexagon("enemy3", corner + glm::vec3(0, 0, 1), 40, glm::vec3(0.4, 0.1, 0.6), glm::vec3(1, 0.5, 0.4), true);
    AddMeshToList(enemy3);

    Mesh* enemy4 = object2D1::CreateHexagon("enemy4", corner + glm::vec3(0, 0, 1), 40, glm::vec3(0.4, 0.1, 0.6), glm::vec3(0.6, 0.8, 0.8), true);
    AddMeshToList(enemy4);

    Mesh* weapon1 = object2D1::CreateRhombus("weapon1", corner + glm::vec3(0, 0, 1), 130, glm::vec3(0.8, 0.3, 1), true);
    AddMeshToList(weapon1);

    Mesh* weapon2 = object2D1::CreateRhombus("weapon2", corner + glm::vec3(0, 0, 1), 130, glm::vec3(1, 0.5, 0.9), true);
    AddMeshToList(weapon2);

    
    Mesh* weapon3 = object2D1::CreateRhombus("weapon3", corner + glm::vec3(0, 0, 1), 130, glm::vec3(1, 0.5, 0.4), true);
    AddMeshToList(weapon3);

    Mesh* weapon4 = object2D1::CreateRhombus("weapon4", corner + glm::vec3(0, 0, 1), 130, glm::vec3(0.6, 0.8, 0.8), true);
    AddMeshToList(weapon4);

    struct Weapon weapon;
    weapon.isDragged = false;
    int x = 80;

    for (int i = 0; i < 4; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(x, 615);
        weapon.initialX = x;
        weapon.initialY = 615;
        if (i == 0) {
            weapon.color = glm::vec3(0.8, 0.3, 1);
        }
        else if (i == 1) {
            weapon.color = glm::vec3(1, 0.5, 0.9);
        }
        else if (i == 2) {
            weapon.color = glm::vec3(1, 0.5, 0.4);
        }
        else if (i == 3) {
            weapon.color = glm::vec3(0.6, 0.8, 0.8);
        }
        weapon.modelMatrix = modelMatrix;
        weapons.push_back(weapon);
        x += 180;
    }

    Mesh* star1 = object2D1::CreateStar("star1", 4, glm::vec3(0.8, 0.3, 1), true);
    AddMeshToList(star1);

    Mesh* star2 = object2D1::CreateStar("star2", 4, glm::vec3(1, 0.5, 0.9), true);
    AddMeshToList(star2);

    Mesh* star3 = object2D1::CreateStar("star3", 4, glm::vec3(1, 0.5, 0.4), true);
    AddMeshToList(star3);

    Mesh* star4 = object2D1::CreateStar("star4", 4, glm::vec3(0.6, 0.8, 0.8), true);
    AddMeshToList(star4);

    Mesh* star5 = object2D1::CreateStar("star5", 4, glm::vec3(1, 0.9, 0.3), true);
    AddMeshToList(star5);

    Mesh* heart = object2D1::CreateHeart("heart", 20, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(heart);

    starX = 55 * 4 / 11;
    starY = 49.2 * 4 / 11;
    randomStarsNumber = 5.0f + rand() % 3;
    starsCollected = 5;
    changingColorEnemies = 0;

    Mesh* G = object2D1::CreateG("G", corner, 50, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(G);

    Mesh* A = object2D1::CreateA("A", corner, 50, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(A);

    Mesh* M = object2D1::CreateM("M", corner, 50, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(M);

    Mesh* E = object2D1::CreateE("E", corner, 50, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(E);

    Mesh* O = object2D1::CreateO("O", corner, 50, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(O);

    Mesh* V = object2D1::CreateV("V", corner, 50, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(V);

    Mesh* R = object2D1::CreateR("R", corner, 50, glm::vec3(1, 0, 0.8), true);
    AddMeshToList(R);

}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();

    if (playerLives > 0) {
        // Create the rectangle
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(10, 15);
        RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);

        if (randomStarsNumber > 0) {
            randomStarsNumber -= deltaTimeSeconds;
        }
        else {
            randomStarsNumber = 5.0f + rand() % 3;
            for (int i = 0; i < 3; i++) {
                Star star;
                star.cx = rand() % (resolution.x - 20);
                star.cy = rand() % (resolution.y - 20);
                star.modelMatrix = glm::mat3(1) * transform2D::Translate(star.cx, star.cy);
                randomStars.push_back(star);
            }
        }

        for (auto& randomStar : randomStars) {
            RenderMesh2D(meshes["star5"], shaders["VertexColor"], randomStar.modelMatrix);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Create table square
                RenderMesh2D(meshes["greenSquare"], shaders["VertexColor"], gameTable[i][j].modelMatrix);
                // Create weapons in the squares in case they were previously dragged
                if (gameTable[i][j].hasWeapon) {
                    RenderMesh2D(meshes[gameTable[i][j].meshName], shaders["VertexColor"], gameTable[i][j].weaponMatrix);
                    if (gameTable[i][j].counter > 0) {
                        gameTable[i][j].counter -= deltaTimeSeconds;
                    }
                    else {
                        for (auto& enemy : enemies) {
                            if (enemy.line == i && enemy.color == gameTable[i][j].weaponColor) {
                                Star star;
                                star.color = enemy.color;
                                star.starMesh = gameTable[i][j].starMesh;
                                star.cx = gameTable[i][j].x + 80;
                                star.cy = gameTable[i][j].y + 70;
                                star.rotation = 0;

                                gameTable[i][j].projectiles.push_back(star);
                                gameTable[i][j].isShooting = true;
                                gameTable[i][j].counter = 3;
                                break;
                            }
                        }
                    }
                }
                if (gameTable[i][j].isDestroyed && !gameTable[i][j].hasWeapon) {
                    gameTable[i][j].scaleX -= 5 * deltaTimeSeconds;
                    gameTable[i][j].scaleY -= 5 * deltaTimeSeconds;
                    gameTable[i][j].weaponMatrix *= transform2D::Scale(gameTable[i][j].scaleX, gameTable[i][j].scaleY);
                    if (gameTable[i][j].scaleX <= 0.5) {
                        gameTable[i][j].isDestroyed = false;
                    }
                    RenderMesh2D(meshes[gameTable[i][j].meshName], shaders["VertexColor"], gameTable[i][j].weaponMatrix);
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameTable[i][j].isShooting) {
                    // Iterate over projectiles in the square
                    for (auto& shootingStar : gameTable[i][j].projectiles) {
                        float speed = 250.0f * deltaTimeSeconds;

                        shootingStar.cx += speed;
                        shootingStar.modelMatrix = transform2D::Translate(shootingStar.cx, shootingStar.cy) * transform2D::Rotate(shootingStar.rotation)
                            * transform2D::Scale(1.4, 1.4);

                        shootingStar.rotation += deltaTimeSeconds;
                        RenderMesh2D(meshes[shootingStar.starMesh], shaders["VertexColor"], shootingStar.modelMatrix);
                    }

                    // Check if there are no enemies of the corresponding color on the line
                    bool noEnemiesOfColor = true;
                    for (const auto& enemy : enemies) {
                        if (enemy.line == i && enemy.color == gameTable[i][j].weaponColor) {
                            noEnemiesOfColor = false;
                            break;
                        }
                    }

                    // Stop shooting and clear projectiles if no enemies of the color are on the line
                    if (noEnemiesOfColor) {
                        gameTable[i][j].isShooting = false;
                        gameTable[i][j].projectiles.clear();
                    }
                }
            }
        }

        angularStep += 0.3 * deltaTimeSeconds;

        // Squares that contain the weapons
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(50, 550);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(230, 550);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(410, 550);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(590, 550);
        RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

        int x = 830;
        for (int i = 0; i < playerLives; i++) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(x, 635);
            RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
            x += 140;
        }

        Enemy enemy;

        // Generating random enemies
        if (randomTimer > 0) {
            randomTimer -= deltaTimeSeconds;
        }
        else {
            randomTimer = 4 + rand() % 3;
            randomAxis = rand() % 3;
            randomColor = rand() % 4;
            enemy.line = randomAxis;
            enemy.lives = 3;

            if (randomAxis == 0) {
                translateYHex = 80;
            }
            else if (randomAxis == 1) {
                translateYHex = 230;
            }
            else {
                translateYHex = 380;
            }

            if (randomColor == 0) {
                enemy.color = glm::vec3(0.8, 0.3, 1);
                enemy.enemyMesh = "enemy1";
            }
            else if (randomColor == 1) {
                enemy.color = glm::vec3(1, 0.5, 0.9);
                enemy.enemyMesh = "enemy2";
            }
            else if (randomColor == 2) {
                enemy.color = glm::vec3(1, 0.5, 0.4);
                enemy.enemyMesh = "enemy3";
            }
            else {
                enemy.color = glm::vec3(0.6, 0.8, 0.8);
                enemy.enemyMesh = "enemy4";
            }

            int randomNumber = 1 + rand() % 5;
            if (randomNumber == 5) {
                enemy.changesColor = true;
            }
            else {
                enemy.changesColor = false;
            }

            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(1300, translateYHex);
            enemy.modelMatrix = modelMatrix;
            enemy.scaleX = 1;
            enemy.scaleY = 1;
            numberOfEnemies++;
            enemies.push_back(enemy);
        }

        // Conditions for erasure
        auto lostLife = [](const Enemy& badGuy) {
            return badGuy.lives == 0;
            };

        auto enemyDestroy = [](const Enemy& badGuy) {
            return badGuy.modelMatrix[2][0] <= 100;
            };

        for (auto it = enemies.begin(); it != enemies.end();) {
            if (enemyDestroy(*it)) {
                it = enemies.erase(it);
            }
            else {
                ++it;
            }
        }

        while (numberOfEnemies > enemies.size()) {
            numberOfEnemies--;
            playerLives--;
        }

        for (auto it = enemies.begin(); it != enemies.end();) {
            if (lostLife(*it)) {
                changingColorEnemies++;
                if (changingColorEnemies >= 5 && playerLives < 3) {
                    playerLives++;
                    changingColorEnemies = 0;
                }
                destroyedEnemies.push_back(*it);
                it = enemies.erase(it);
                numberOfEnemies--;
            }
            else {
                ++it;
            }
        }

        for (auto it = destroyedEnemies.begin(); it != destroyedEnemies.end();) {
            if ((*it).scaleX <= 0.5) {
                it = destroyedEnemies.erase(it);
            }
            else {
                (*it).scaleX -= deltaTimeSeconds;
                (*it).scaleY -= deltaTimeSeconds;
                (*it).modelMatrix *= transform2D::Scale((*it).scaleX, (*it).scaleY);
                RenderMesh2D(meshes[(*it).enemyMesh], shaders["VertexColor"], (*it).modelMatrix);
                ++it;
            }
        }


        for (auto& createEnemy : enemies) {
            float speed = 50.0f * deltaTimeSeconds;
            createEnemy.modelMatrix *= transform2D::Translate(-speed, 0);
            RenderMesh2D(meshes[createEnemy.enemyMesh], shaders["VertexColor"], createEnemy.modelMatrix);
        }

        // Creating the weapons
        for (auto& weapon : weapons) {
            std::string meshName;
            if (weapon.color == glm::vec3(0.8, 0.3, 1)) {
                meshName = "weapon1";
            }
            else if (weapon.color == glm::vec3(1, 0.5, 0.9)) {
                meshName = "weapon2";
            }
            else if (weapon.color == glm::vec3(1, 0.5, 0.4)) {
                meshName = "weapon3";
            }
            else if (weapon.color == glm::vec3(0.6, 0.8, 0.8)) {
                meshName = "weapon4";
            }
            RenderMesh2D(meshes[meshName], shaders["VertexColor"], weapon.modelMatrix);
            if (weapon.isDragged) {
                modelMatrix = glm::mat3(1);
                modelMatrix *= transform2D::Translate(weapon.movingX, -weapon.movingY);
                RenderMesh2D(meshes[meshName], shaders["VertexColor"], modelMatrix);
            }
        }

        // Creating the stars
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(50, 510);
        RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(230, 510);
        RenderMesh2D(meshes["star2"], shaders["VertexColor"], modelMatrix);
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(275, 510);
        RenderMesh2D(meshes["star2"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(410, 510);
        RenderMesh2D(meshes["star3"], shaders["VertexColor"], modelMatrix);
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(455, 510);
        RenderMesh2D(meshes["star3"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(590, 510);
        RenderMesh2D(meshes["star4"], shaders["VertexColor"], modelMatrix);
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(635, 510);
        RenderMesh2D(meshes["star4"], shaders["VertexColor"], modelMatrix);
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(680, 510);
        RenderMesh2D(meshes["star4"], shaders["VertexColor"], modelMatrix);

        int xStarsCollected = 800;
        for (int i = 0; i < starsCollected; i++) {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(xStarsCollected, 540);
            RenderMesh2D(meshes["star5"], shaders["VertexColor"], modelMatrix);
            xStarsCollected += 45;
        }

        // Check collisions
        for (auto& enemy : enemies) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (gameTable[i][j].hasWeapon && enemy.line == i) {
                        if (65.5 >= std::abs(enemy.modelMatrix[2][0] - gameTable[i][j].weaponMatrix[2][0] - 37.5)) {
                            gameTable[i][j].hasWeapon = false;
                            gameTable[i][j].isShooting = false;
                            gameTable[i][j].isDestroyed = true;
                            gameTable[i][j].destroyTimer = 0.5;
                        }

                        if (gameTable[i][j].weaponColor == enemy.color) {
                            for (auto it = gameTable[i][j].projectiles.begin(); it != gameTable[i][j].projectiles.end();) {
                                if (48 >= std::abs(enemy.modelMatrix[2][0] - it->modelMatrix[2][0])) {
                                    enemy.lives--;
                                    int newColor = 1 + rand() % 4;
                                    it = gameTable[i][j].projectiles.erase(it);
                                    if (enemy.changesColor) {
                                        starsCollected++;
                                        enemy.enemyMesh = "enemy" + std::to_string(newColor);
                                        if (enemy.enemyMesh == "enemy1") {
                                            enemy.color = glm::vec3(0.8, 0.3, 1);
                                        }
                                        else if (enemy.enemyMesh == "enemy2") {
                                            enemy.color = glm::vec3(1, 0.5, 0.9);
                                        }
                                        else if (enemy.enemyMesh == "enemy3") {
                                            enemy.color = glm::vec3(1, 0.5, 0.4);
                                        }
                                        else if (enemy.enemyMesh == "enemy4") {
                                            enemy.color = glm::vec3(0.6, 0.8, 0.8);
                                        }
                                        gameTable[i][j].projectiles.clear();
                                        gameTable[i][j].isShooting = false;
                                        gameTable[i][j].isDestroyed = true;
                                        gameTable[i][j].hasWeapon = false;
                                        break;
                                    }
                                }
                                else {
                                    ++it;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
     else {
         enemies.clear();
         stars.clear();
         randomStars.clear();


         modelMatrix = glm::mat3(1);
         modelMatrix *= transform2D::Translate(250, 510);
         RenderMesh2D(meshes["G"], shaders["VertexColor"], modelMatrix);

         modelMatrix = glm::mat3(1);
         modelMatrix *= transform2D::Translate(500, 510);
         RenderMesh2D(meshes["A"], shaders["VertexColor"], modelMatrix);

         modelMatrix = glm::mat3(1);
         modelMatrix *= transform2D::Translate(750, 510);
         RenderMesh2D(meshes["M"], shaders["VertexColor"], modelMatrix);

         modelMatrix = glm::mat3(1);
         modelMatrix *= transform2D::Translate(950, 510);
         RenderMesh2D(meshes["E"], shaders["VertexColor"], modelMatrix);

         modelMatrix = glm::mat3(1);
         modelMatrix *= transform2D::Translate(250, 200);
         RenderMesh2D(meshes["O"], shaders["VertexColor"], modelMatrix);
         modelMatrix = glm::mat3(1);
         modelMatrix *= transform2D::Translate(500, 200);
         RenderMesh2D(meshes["V"], shaders["VertexColor"], modelMatrix);
         modelMatrix = glm::mat3(1);
         modelMatrix *= transform2D::Translate(700, 200);
         RenderMesh2D(meshes["E"], shaders["VertexColor"], modelMatrix);
         modelMatrix = glm::mat3(1);
         modelMatrix *= transform2D::Translate(950, 200);
         RenderMesh2D(meshes["R"], shaders["VertexColor"], modelMatrix);
     }


}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{

}


void Tema1::OnKeyPress(int key, int mods)
{

}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
   glm::ivec2 resolution = window->GetResolution();
   float windowScaleX = resolution.x / 1280.0f;
   float windowScaleY = resolution.y / 720.0f;
   mouseX /= windowScaleX;

   mouseY = (mouseY - resolution.y) / windowScaleY;
   if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
     {
        // Add mouse move event
       for (int i = 0; i < 4; i ++) {
            if (weapons[i].isDragged) {
                weapons[i].movingX = mouseX;
                weapons[i].movingY = mouseY;
            }
        }
    }

}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    glm::ivec2 resolution = window->GetResolution();
    float windowScaleX = resolution.x / 1280.0f;
    float windowScaleY = resolution.y / 720.0f;
    mouseY = (resolution.y - mouseY);
    mouseX /= windowScaleX;
    mouseY /= windowScaleY;
    // Add mouse button press event
    if (button == 1)
    {
        int x = 50;
        for (int i = 0; i < 4; i++) {
            if (mouseX >= x && mouseX <= (x + 130) && mouseY >= 550 && mouseY <= 680 ) {
                weapons[i].isDragged = true;
            }
            x += 180;
        }
        for (auto it = randomStars.begin(); it != randomStars.end();) {
            if (mouseX >= it->cx - 20 && mouseX <= it->cx + 20 && mouseY >= it->cy - 20 && mouseY <= it->cy + 20) {
                starsCollected++;
                it = randomStars.erase(it);
                break;
            }
            else {
                ++it;
            }
        }
    }
    if (button == 2) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mouseX >= gameTable[i][j].x && mouseX <= gameTable[i][j].x + 130 &&
                    mouseY >= gameTable[i][j].y &&  mouseY <= gameTable[i][j].y + 130) {
                    gameTable[i][j].hasWeapon = false;
                    gameTable[i][j].isShooting = false;
                    gameTable[i][j].isDestroyed = true;
                    gameTable[i][j].destroyTimer = 0.5;
                }
            }
        }
    }

}

void Tema1::SetWeaponProperties(GameSquare square[3][3], glm::vec3& weaponColor, int x, int y, int i, int j)
{
    std::string meshName, starMesh;

    if (weaponColor == glm::vec3(0.8, 0.3, 1)) {
        meshName = "weapon1";
        starMesh = "star1";
        if (starsCollected < 1) {
            return;
        }
        starsCollected -= 1;
    }
    else if (weaponColor == glm::vec3(1, 0.5, 0.9)) {
        meshName = "weapon2";
        starMesh = "star2";
        if (starsCollected < 2) {
            return;
        }
        starsCollected -= 2;
    }
    else if (weaponColor == glm::vec3(1, 0.5, 0.4)) {
        meshName = "weapon3";
        starMesh = "star3";
        if (starsCollected < 2) {
            return;
        }
        starsCollected -= 2;
    }
    else if (weaponColor == glm::vec3(0.6, 0.8, 0.8)) {
        meshName = "weapon4";
        starMesh = "star4";
        if (starsCollected < 3) {
            return;
        }
        starsCollected -= 3;
    }

    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(x + 30, y + 60);

    square[i][j].weaponMatrix = modelMatrix;
    square[i][j].weaponColor = weaponColor;
    square[i][j].hasWeapon = true;
    square[i][j].isDestroyed = false;
    square[i][j].meshName = meshName;
    square[i][j].starMesh = starMesh;
    square[i][j].counter = 1;
    square[i][j].scaleX = 1;
    square[i][j].scaleY = 1;
    square[i][j].x = x;
    square[i][j].y = y;
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    bool ok = false;
    glm::ivec2 resolution = window->GetResolution();
    float windowScaleX = resolution.x / 1280.0f;
    float windowScaleY = resolution.y / 720.0f;
    mouseX /= windowScaleX;
    mouseY = (resolution.y - mouseY) / windowScaleY;
    if (button == 1) {
        for (int k = 0; k < 4; k++) {
            int x = 80, y;
            if (weapons[k].isDragged) {
                if (mouseX >= 80 && mouseX <= 210 && mouseY >= 15 && mouseY <= 145 && !gameTable[0][0].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 80, 15, 0, 0);
                }
                if (mouseX >= 230 && mouseX <= 360 && mouseY >= 15 && mouseY <= 145 && !gameTable[0][1].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 230, 15, 0, 1);
                }
                if (mouseX >= 380 && mouseX <= 510 && mouseY >= 15 && mouseY <= 145 && !gameTable[0][2].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 380, 15, 0, 2);
                }
                if (mouseX >= 80 && mouseX <= 210 && mouseY >= 165 && mouseY <= 295 && !gameTable[1][0].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 80, 165, 1, 0);
                }
                if (mouseX >= 230 && mouseX <= 360 && mouseY >= 165 && mouseY <= 295 && !gameTable[1][1].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 230, 165, 1, 1);
                }
                if (mouseX >= 380 && mouseX <= 510 && mouseY >= 165 && mouseY <= 295 && !gameTable[1][2].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 380, 165, 1, 2);
                }
                if (mouseX >= 80 && mouseX <= 210 && mouseY >= 315 && mouseY <= 445 && !gameTable[2][0].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 80, 315, 2, 0);
                }
                if (mouseX >= 230 && mouseX <= 360 && mouseY >= 315 && mouseY <= 445 && !gameTable[2][1].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 230, 315, 2, 1);
                }
                if (mouseX >= 380 && mouseX <= 510 && mouseY >= 315 && mouseY <= 445 && !gameTable[2][2].hasWeapon) {
                    SetWeaponProperties(gameTable, weapons[k].color, 380, 315, 2, 2);
                }
            
            }
            weapons[k].isDragged = false;
            weapons[k].movingX = weapons[k].initialX;
            weapons[k].movingY = weapons[k].initialY;
        }
    }
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
