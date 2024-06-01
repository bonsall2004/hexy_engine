/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "ObjectLoader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool ObjectLoader::load(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.substr(0, 2) == "v ") {
      parse_vertex(line);
    } else if (line.substr(0, 3) == "vt ") {
      parse_texcoord(line);
    } else if (line.substr(0, 3) == "vn ") {
      parse_normal(line);
    } else if (line.substr(0, 2) == "f ") {
      parse_face(line);
    }
  }

  return true;
}

void ObjectLoader::parse_vertex(const std::string& line) {
  std::istringstream s(line.substr(2));
  glm::vec3 vertex;
  s >> vertex.x >> vertex.y >> vertex.z;
  vertices.push_back(vertex);
}

void ObjectLoader::parse_texcoord(const std::string& line) {
  std::istringstream s(line.substr(3));
  glm::vec2 texcoord;
  s >> texcoord.x >> texcoord.y;
  texcoords.push_back(texcoord);
}

void ObjectLoader::parse_normal(const std::string& line) {
  std::istringstream s(line.substr(3));
  glm::vec3 normal;
  s >> normal.x >> normal.y >> normal.z;
  normals.push_back(normal);
}

void ObjectLoader::parse_face(const std::string& line) {
  std::istringstream s(line.substr(2));
  std::string vertex_info;
  while (s >> vertex_info) {
    std::istringstream vertex_stream(vertex_info);
    std::string v, t, n;
    std::getline(vertex_stream, v, '/');
    std::getline(vertex_stream, t, '/');
    std::getline(vertex_stream, n, '/');

    indices.push_back(std::stoi(v) - 1);
  }
}

const std::vector<glm::vec3>& ObjectLoader::get_vertices() const {
  return vertices;
}

const std::vector<glm::vec2>& ObjectLoader::get_texcoords() const {
  return texcoords;
}

const std::vector<glm::vec3>& ObjectLoader::get_normals() const {
  return normals;
}

const std::vector<unsigned int>& ObjectLoader::get_indices() const {
  return indices;
}