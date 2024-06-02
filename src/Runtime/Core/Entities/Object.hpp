/*
 * hexy_engine
 * Author: bonsall2004
 * Description:
 */
#pragma once
#include "ObjectBase.hpp"

namespace hexy::runtime::core
{
  class Object : public ObjectBase
  {
    protected:

      virtual void OnObjectLoad() = 0;
  };
}