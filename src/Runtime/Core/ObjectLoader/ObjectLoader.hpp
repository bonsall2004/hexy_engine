/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>

class ObjectLoader {
  public:
    bool load(const std::string& filename);
    [[nodiscard]] const std::vector<glm::vec3>& get_vertices() const;
    [[nodiscard]] const std::vector<glm::vec2>& get_texcoords() const;
    [[nodiscard]] const std::vector<glm::vec3>& get_normals() const;
    [[nodiscard]] const std::vector<unsigned int>& get_indices() const;

  private:
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> texcoords;
    std::vector<glm::vec3> normals;
    std::vector<unsigned int> indices;

    void parse_vertex(const std::string& line);
    void parse_texcoord(const std::string& line);
    void parse_normal(const std::string& line);
    void parse_face(const std::string& line);
};
