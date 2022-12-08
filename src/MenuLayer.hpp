#pragma once

#include "includes.hpp"

namespace MenuLayer {
    inline bool (__thiscall* init)(CCLayer* self);
    bool __fastcall init_hook(CCLayer* self);
}

