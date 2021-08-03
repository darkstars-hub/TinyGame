//! 
//! @file Common.h
//! @brief ���C�u�������ł̋��ʋ@�\��錾
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_COMMON_COMMON_H
#define LIBRARY_COMMON_COMMON_H


#include <Windows.h>

#include "../External/GLEW/glew.h"
#include "../External/GLFW/glfw3.h"
#include "../External/GLM/glm.hpp"
#include "../External/GLM/gtc/matrix_transform.hpp"
#include "../External/GLM/gtx/quaternion.hpp"
#include "../External/GLM/ext/quaternion_transform.hpp"

//#include "ft2build.h"
//#include FT_FREETYPE_H

#include "../External/AL/al.h"
#include "../External/AL/alc.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif // !STB_IMAGE_IMPLEMENTATION
#include "../External/sndfile/sndfile.h"


namespace library::common {
static void Mock(void) {
}
}
#endif // !LIBRARY_COMMON_COMMON_H