#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D1::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D1::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float width,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(width, 0, 0), color),
        VertexFormat(corner + glm::vec3(width, height, 0), color),
        VertexFormat(corner + glm::vec3(0, height, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D1::CreateHexagon(
    const std::string& name,
    glm::vec3 center,
    float length,
    glm::vec3 color,
    glm::vec3 collorSmall,
    bool fill)
{
    float smallerHexLength = length / 1.6;
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(center, color),
        VertexFormat(center + glm::vec3(length, 0, 0), color),
        VertexFormat(center + glm::vec3(0.5 * length, 0.87 * length, 0), color),
        VertexFormat(center + glm::vec3(-0.5 * length, 0.87 * length, 0), color),
        VertexFormat(center + glm::vec3(-length, 0, 0), color),
        VertexFormat(center + glm::vec3(-0.5 * length, -0.87 * length, 0), color),
        VertexFormat(center + glm::vec3(0.5 * length, -0.87 * length, 0), color),
        VertexFormat(center + glm::vec3(0,0,1), collorSmall),
        VertexFormat(center + glm::vec3(smallerHexLength, 0, 1), collorSmall),
        VertexFormat(center + glm::vec3(0.5 * smallerHexLength, 0.87 * smallerHexLength, 1), collorSmall),
        VertexFormat(center + glm::vec3(-0.5 * smallerHexLength, 0.87 * smallerHexLength, 1), collorSmall),
        VertexFormat(center + glm::vec3(-smallerHexLength, 0, 1), collorSmall),
        VertexFormat(center + glm::vec3(-0.5 * smallerHexLength, -0.87 * smallerHexLength, 1), collorSmall),
        VertexFormat(center + glm::vec3(0.5 * smallerHexLength, -0.87 * smallerHexLength, 1), collorSmall),
    };

    Mesh* hex = new Mesh(name);
    std::vector<unsigned int> indices = 
    { 
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        0, 6, 1,

        7, 8, 9,
        7, 9, 10,
        7, 10, 11,
        7, 11, 12,
        7, 12, 13,
        7, 13, 8,
    };
    
    hex->InitFromData(vertices, indices);

    return hex;
}

Mesh* object2D1::CreateRhombus(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(leftCorner, color),
        VertexFormat(leftCorner + glm::vec3(length / 5, length / 2.5, 0), color),
        VertexFormat(leftCorner + glm::vec3(length / 2.5 , 0, 0), color),
        VertexFormat(leftCorner + glm::vec3(length / 5, -length / 2.5, 0), color),
        VertexFormat(leftCorner + glm::vec3(length / 3 , length / 10, 0), color),
        VertexFormat(leftCorner + glm::vec3(length / 3 , -length / 10, 0), color),
        VertexFormat(leftCorner + glm::vec3(length / 1.75 , length / 10, 0), color),
        VertexFormat(leftCorner + glm::vec3(length / 1.75 , -length / 10, 0), color),
    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices = 
    { 
        0, 2, 1,
        0, 3, 2,
        4, 5, 7,
        6, 4, 7,
    };

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}

Mesh* object2D1::CreateStar(
    const std::string& name,
    float scale,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0 * scale, 0 * scale, 1), color),
        VertexFormat(glm::vec3(1 * scale, 1.53 * scale, 1), color),
        VertexFormat(glm::vec3(0 * scale, 4.53 * scale, 1), color),
        VertexFormat(glm::vec3(-1 * scale, 1.53 * scale, 1), color),
        VertexFormat(glm::vec3(-5 * scale, 1.53 * scale, 1), color),
        VertexFormat(glm::vec3(-2 * scale, -0.97 * scale, 1), color),
        VertexFormat(glm::vec3(-3 * scale, -4.47 * scale, 1), color),
        VertexFormat(glm::vec3(0 * scale, -2.47 * scale, 1), color),
        VertexFormat(glm::vec3(3 * scale, -4.47 * scale, 1), color),
        VertexFormat(glm::vec3(2 * scale, -0.97 * scale, 1), color),
        VertexFormat(glm::vec3(5 * scale, 1.53 * scale, 1), color),


    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = 
    {
        0, 2, 1,
        0, 3, 2,
        0, 4, 3,
        0, 5, 4,
        0, 6, 5,
        0, 7, 6,
        0, 8, 7,
        0, 9, 8,
        0, 10, 9,
        0, 1, 10,
    };


    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D1::CreateHeart(
    const std::string& name,
    float scale,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(0 * scale, -3 * scale, 1), color),
        VertexFormat(glm::vec3(1.8 * scale, -1.2 * scale, 1), color),
        VertexFormat(glm::vec3(2.5 * scale, 0, 1), color),
        VertexFormat(glm::vec3(2.55 * scale, 0.8 * scale, 1), color),
        VertexFormat(glm::vec3(2.1 * scale, 1.67 * scale, 1), color),
        VertexFormat(glm::vec3(1.2 * scale, 1.88 * scale, 1), color),
        VertexFormat(glm::vec3(0.5 * scale, 1.7 * scale, 1), color),
        VertexFormat(glm::vec3(0, scale, 1), color),
        VertexFormat(glm::vec3(-0.5 * scale, 1.7 * scale, 1), color),
        VertexFormat(glm::vec3(-1.2 * scale, 1.88 * scale, 1), color),
        VertexFormat(glm::vec3(-2.1 * scale, 1.67 * scale, 1), color),
        VertexFormat(glm::vec3(-2.55 * scale, 0.8 * scale, 1), color),
        VertexFormat(glm::vec3(-2.5 * scale, 0, 1), color),
        VertexFormat(glm::vec3(-1.8 * scale, -1.2 * scale, 1), color),
    };

    Mesh* heart = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        0, 2, 1,
        0, 3, 2,
        0, 4, 3,
        0, 5, 4,
        0, 6, 5,
        0, 7, 6,
        0, 8, 7,
        0, 9, 8,
        0, 10, 9,
        0, 11, 10,
        0, 12, 11,
        0, 13, 12
    };


    heart->InitFromData(vertices, indices);
    return heart;
}


Mesh* object2D1::CreateG(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(leftCorner, color),
        VertexFormat(leftCorner + glm::vec3(0, -length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , -length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length, 0, 0), color),

        VertexFormat(leftCorner + glm::vec3(2 * length, 0,  0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , -3 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(-2 * length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , -2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , -2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-2 * length , 3 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(- length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , 2 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(length , 2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , length, 0), color),
    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        0, 2, 1,
        0, 3, 2,
        3, 4, 5,
        3, 5, 6,
        10, 9, 6,
        10, 6, 7,
        11, 7, 8,
        11, 12, 7,
        12, 13, 16,
        12, 16, 15,
        13, 14, 17,
        13, 17, 18,
    };

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}


Mesh* object2D1::CreateA(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {

        VertexFormat(leftCorner + glm::vec3(2 * length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , 3 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(length , 0, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length, 2 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(-2 * length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-2 * length , 3 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(-length , 0, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length, 2 * length, 0), color),

    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        2, 0, 1,
        2, 3, 0,
        8, 7, 9,
        7, 10, 9,
        4, 11, 12,
        4, 12, 5,
        6, 13, 9,
        6, 9, 2,
    };

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}


Mesh* object2D1::CreateM(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(leftCorner, color),
        VertexFormat(leftCorner + glm::vec3(0, length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , 2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length, 2 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(-2 * length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-2 * length, 3 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(2 * length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , 3 * length, 0), color),
    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        1, 3, 6,
        0, 3, 1,
        0, 1, 2,
        1, 10, 2,
        5, 7, 6,
        4, 7, 5,
        8, 9, 10,
        8, 10, 11,


    };

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}


Mesh* object2D1::CreateE(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(leftCorner + glm::vec3(-length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0 , 2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0, 0.5 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0, -0.5 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0, -2 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(0, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , 2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length, 0.5 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , -0.5 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , -2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , -3 * length, 0), color),
    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        7, 0, 1,
        7, 1, 2,
        9, 3, 2,
        9, 2, 8,
        11, 5, 4,
        11, 4, 10,
        13, 7, 6,
        13, 6, 12,
    };

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}


Mesh* object2D1::CreateO(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(leftCorner + glm::vec3(-1.5 * length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(1.5 * length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(1.5 * length, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-1.5 * length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-0.5 * length, -2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0.5 * length, -2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0.5 * length, 2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-0.5 * length, 2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-0.5 * length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0.5 * length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0.5 * length, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-0.5 * length, 3 * length, 0), color),
    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        8, 0, 3,
        8, 3, 11,
        1, 9, 10,
        1, 10, 2,
        6, 7, 11,
        6, 11, 10,
        9, 8, 4,
        9, 4, 5,
    };

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}


Mesh* object2D1::CreateV(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(leftCorner + glm::vec3(-2 * length, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0, -2.5 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-0.5 * length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0.5 * length, -3 * length, 0), color),

    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        4, 5, 0,
        4, 0, 1,
        6, 5, 4,
        6, 4, 3,
        4, 2, 3,
    };

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}


Mesh* object2D1::CreateR(
    const std::string& name,
    glm::vec3 leftCorner,
    float length,
    glm::vec3 color,
    bool fill)
{

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(leftCorner + glm::vec3(-length, -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0 , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0, 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(-length , 3 * length, 0), color),

        VertexFormat(leftCorner, color),
        VertexFormat(leftCorner + glm::vec3(length, 0, 0), color),
        VertexFormat(leftCorner + glm::vec3(length, length, 0), color),
        VertexFormat(leftCorner + glm::vec3(0, length, 0), color),

        VertexFormat(leftCorner + glm::vec3(0 , 2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , 2 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length, 3 * length, 0), color),

        VertexFormat(leftCorner + glm::vec3(2 * length , 0, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , 3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(length , -3 * length, 0), color),
        VertexFormat(leftCorner + glm::vec3(2 * length , -3 * length, 0), color),
    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices =
    {
       0, 3, 1,
       1, 3, 2,
       9, 8, 2,
       9, 2, 10,
       5, 4, 7,
       5, 7, 6,
       11, 5, 10,
       11, 10, 12,
       14, 13, 4,
       14, 4, 5,
    };

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}