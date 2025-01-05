#pragma once

#ifndef TRICKS_H
#define TRICKS_H

#include <imgui.h>
#include "randomizerTypes.h"

#include <map>
#include <set>
#include <string>

namespace Rando {
    class Tricks {
        public:
            enum class Tag {
                NOVICE,
                INTERMEDIATE,
                ADVANCED,
                EXPERT,
                EXTREME,
                EXPERIMENTAL,
                GLITCH,
            };

            static const std::string& GetAreaName(RandomizerArea area);
            static const bool CheckTags(const std::map<Tag, bool>& showTag, const std::set<Tag>& rtTags);
            static const std::string GetTagName(Tag tag);
            static const ImVec4 GetTextColor(Tag tag);
            static const ImVec4 GetTagColor(Tag tag);
            static void DrawTagChips(const std::set<Tag>& rtTags);
    };
}

#endif //TRICKS_H