#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D1
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill = false);
    Mesh* CreateStar(const std::string& name, float scale, glm::vec3 color, bool fill = false);
    Mesh* CreateHeart(const std::string& name, float scale, glm::vec3 color, bool fill = false);
    Mesh* CreateHexagon(const std::string& name, glm::vec3 center, float length, glm::vec3 color, glm::vec3 collorSmall, bool fill = false);
    Mesh* CreateRhombus(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateG(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateA(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateM(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateE(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateO(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateV(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateR(const std::string& name, glm::vec3 center, float length, glm::vec3 color, bool fill = false);
}
