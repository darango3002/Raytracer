#include "Material.hpp"
#include <algorithm>
#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

Material::Material(glm::vec3 color, float k_a, float k_d, float k_s, bool glazed) {
    this->color = color;
    this->k_a = k_a;
    this->k_d = k_d;
    this->k_s = k_s;
    this->glazed = glazed;
}

glm::vec3 Material::evaluateColor(glm::vec3 l, glm::vec3 v, glm::vec3 n) {

    float L_a = k_a;
    float L_d = k_d * std::max(0.0f,glm::dot(l,n));

    // glm::vec3 v_R = 2*(glm::dot(n,l))*n - l;
    glm::vec3 h = glm::normalize((l+v) / (float)(l+v).length());
    // std::cout << glm::to_string(h) << std::endl;

    float p = 12; // phong exponent
    float L_s = k_s * pow(std::max(0.0f,glm::dot(n, h)), p);

    float L = L_a + L_d + L_s;

    return color * L;
}