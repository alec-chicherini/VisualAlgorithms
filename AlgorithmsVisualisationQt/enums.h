#pragma once

namespace ENUMS_NAMESPACE {
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

   inline  std::underlying_type_t<GP> operator|(GP left, GP right)
    {
        return static_cast<std::underlying_type_t<GP>>(left) | static_cast<std::underlying_type_t<GP>>(right);
    };

   inline std::underlying_type_t<GP> operator|(std::underlying_type_t<GP> left, GP right)
    {
        return (left | (static_cast<std::underlying_type_t<GP>>(right)));
    };

   inline std::underlying_type_t<GP> operator|(GP left, std::underlying_type_t<GP> right)
    {
        return static_cast<std::underlying_type_t<GP>>(left) | right;
    };

    namespace to_string_helpers_
    {
        inline std::string graph_properties_to_string(GP gp) noexcept
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

        inline std::string graph_properties_to_string(std::underlying_type_t<GP> gp)
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

    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    enum class MeshType :int
    {
        CONE = 0,
        CUBOID = 1,
        CYLINDER =2,
        PLANE = 3,
        SPHERE =4,
        TORUS =5
    };

    using MeshType_under = std::underlying_type_t<MeshType>;

    namespace to_string_helpers_
    {
        inline std::string mesh_type_to_string(MeshType mt) noexcept
        {
            switch (static_cast<MeshType_under>(mt))
            {
                case static_cast<MeshType_under>(MeshType::CONE) : return "CONE";
                case static_cast<MeshType_under>(MeshType::CUBOID) : return "CUBOID";
                case static_cast<MeshType_under>(MeshType::CYLINDER) : return "CYLINDER";
                case static_cast<MeshType_under>(MeshType::PLANE) : return "PLANE";
                case static_cast<MeshType_under>(MeshType::SPHERE) : return "SPHERE";
                case static_cast<MeshType_under>(MeshType::TORUS) : return "TORUS";
            }
            return "YOU-SEE-IMPOSSIBLE-MSG-NERD";
        };

        inline std::string mesh_type_to_string(MeshType_under mt)
        {
            return mesh_type_to_string(static_cast<MeshType>(mt));
        }
    }//added to to_string_helpers_ namespace 

       ////////////////////////////////////////////////////////////////////////////////////////////////

    enum class MaterialType :int
    {
		PHONG = 0,
		DIFFUSE_MAP = 1,
		DIFFUSE_SPECULAR_MAP = 2,
		DIFFUSE_SPECULAR = 3,
		GOOCH = 4,
		METAL_ROUGH = 5,
		MORPH_PHONG = 6,
		NORMAL_DIFFUSE_MAP = 7,
		NORMAL_DIFFUSE_SPECULAR_MAP = 8,
		PHONG_ALPHA = 9,
		TEXTURE = 10
    };

    using MaterialType_under = std::underlying_type_t<MaterialType>;

    namespace to_string_helpers_
    {
        inline std::string Material_type_to_string(MaterialType mt) noexcept
        {
            switch (static_cast<MaterialType_under>(mt))
            {
				case static_cast<MaterialType_under>(MaterialType::PHONG) : return "PHONG";
					case static_cast<MaterialType_under>(MaterialType::DIFFUSE_MAP) : return "DIFFUSE_MAP";
						case static_cast<MaterialType_under>(MaterialType::DIFFUSE_SPECULAR_MAP) : return "DIFFUSE_SPECULAR_MAP";
							case static_cast<MaterialType_under>(MaterialType::DIFFUSE_SPECULAR) : return "DIFFUSE_SPECULAR";
								case static_cast<MaterialType_under>(MaterialType::GOOCH) : return "GOOCH";
									case static_cast<MaterialType_under>(MaterialType::METAL_ROUGH) : return "METAL_ROUGH";
										case static_cast<MaterialType_under>(MaterialType::MORPH_PHONG) : return "MORPH_PHONG";
											case static_cast<MaterialType_under>(MaterialType::NORMAL_DIFFUSE_MAP) : return "NORMAL_DIFFUSE_MAP";
												case static_cast<MaterialType_under>(MaterialType::NORMAL_DIFFUSE_SPECULAR_MAP) : return "NORMAL_DIFFUSE_SPECULAR_MAP";
														case static_cast<MaterialType_under>(MaterialType::PHONG_ALPHA) : return "PHONG_ALPHA";
															case static_cast<MaterialType_under>(MaterialType::TEXTURE) : return "TEXTURE";
            }
            return "YOU-SEE-IMPOSSIBLE-MSG-NERD";
        };

        inline std::string Material_type_to_string(MaterialType_under mt)
        {
            return Material_type_to_string(static_cast<MaterialType>(mt));
        }
    }//added to to_string_helpers_ namespace 
}

using namespace ENUMS_NAMESPACE;