#pragma once

namespace {
#include <type_traits>
    enum class GraphProperties :unsigned long long int
    {
        DIRECTED = ((unsigned long long int)1 << 0),
        WEIGHTED = ((unsigned long long int)1 << 1),
        LOOPS = ((unsigned long long int)1 << 2),
        CONNECTED = ((unsigned long long int)1 << 3),
        FULL = ((unsigned long long int)1 << 4),

        PROPERTY62 = ((unsigned long long int)1 << 62),
        NONE = (LLONG_MAX - 1)//2^63
    };

    using GP = GraphProperties;
    using under_GP = std::underlying_type_t<GraphProperties>;

    std::underlying_type_t<GP> operator|(GP left, GP right)
    {
        return static_cast<std::underlying_type_t<GP>>(left) | static_cast<std::underlying_type_t<GP>>(right);
    };

    std::underlying_type_t<GP> operator|(std::underlying_type_t<GP> left, GP right)
    {
        return (left | (static_cast<std::underlying_type_t<GP>>(right)));
    };

    std::underlying_type_t<GP> operator|(GP left, std::underlying_type_t<GP> right)
    {
        return static_cast<std::underlying_type_t<GP>>(left) | right;
    };

    namespace to_string_helpers_
    {
        std::string graph_properties_to_string(GP gp) noexcept
        {
            switch (static_cast<std::underlying_type_t<GP>>(gp))
            {
                case static_cast<std::underlying_type_t<GP>>(GP::DIRECTED) : return "DIRECTED";
                    case static_cast<std::underlying_type_t<GP>>(GP::WEIGHTED) : return "WEIGHTED";
                        case static_cast<std::underlying_type_t<GP>>(GP::LOOPS) : return "LOOPS";
                            case static_cast<std::underlying_type_t<GP>>(GP::CONNECTED) : return "CONNECTED";
                                case static_cast<std::underlying_type_t<GP>>(GP::FULL) : return "FULL";
                                    case static_cast<std::underlying_type_t<GP>>(GP::NONE) : return "NONE";
            }
            return "YOU-SEE-IMPOSSIBLE-MSG-NERD";
        };

        std::string graph_properties_to_string(std::underlying_type_t<GP> gp)
        {
            std::string res;
            bool counter = false;

            if ((gp & static_cast<std::underlying_type_t<GP>>(GP::DIRECTED)) == static_cast<std::underlying_type_t<GP>>(GP::DIRECTED))
            {
                res += "DIRECTED";
                counter = true;
            }
            if ((gp & static_cast<std::underlying_type_t<GP>>(GP::WEIGHTED)) == static_cast<std::underlying_type_t<GP>>(GP::WEIGHTED))
            {
                if (counter) { res += "|"; }
                res += "WEIGHTED";
                counter = true;
            }
            if ((gp & static_cast<std::underlying_type_t<GP>>(GP::LOOPS)) == static_cast<std::underlying_type_t<GP>>(GP::LOOPS))
            {
                if (counter) { res += "|"; }
                res += "LOOPS";
                counter = true;
            }
            if ((gp & static_cast<std::underlying_type_t<GP>>(GP::CONNECTED)) == static_cast<std::underlying_type_t<GP>>(GP::CONNECTED))
            {
                if (counter) { res += "|"; }
                res += "CONNECTED";
                counter = true;
            }
            if ((gp & static_cast<std::underlying_type_t<GP>>(GP::FULL)) == static_cast<std::underlying_type_t<GP>>(GP::FULL))
            {
                if (counter) { res += "|"; }
                res += "FULL";
                counter = true;
            }
            if ((gp & static_cast<std::underlying_type_t<GP>>(GP::NONE)) == static_cast<std::underlying_type_t<GP>>(GP::NONE))
            {
                if (counter) { res += "|"; }
                res += "NONE";
                counter = true;
            }

            return res;
        }
    }//added to to_string_helpers_ namespace 
}
