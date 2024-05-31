/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once

namespace hexy::runtime::core::rendering
{
  class IRenderer
  {
    public:
      virtual void init() = 0;
      virtual void render() = 0;
      virtual void bind() = 0;
      virtual void unbind() = 0;
      virtual void prepare() = 0;
      virtual void cleanup() = 0;
  };
} // hexy