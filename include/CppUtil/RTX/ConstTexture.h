#ifndef _RTX_RT_TEXTURE_CONST_TEXTURE_H_
#define _RTX_RT_TEXTURE_CONST_TEXTURE_H_

#include <CppUtil/RTX/Texture.h>

namespace RTX {
	class ConstTexture : public Texture{
		TEXTURE_SETUP(ConstTexture)
	public:
		ConstTexture(const glm::vec3 & color);
		virtual glm::vec3 Value(float u = 0, float v = 0, const glm::vec3 & p = glm::vec3(0)) const;
		const glm::vec3 & GetColor() const { return color; }
	private:
		glm::vec3 color;
	};
}

#endif // !_RTX_RT_TEXTURE_CONST_TEXTURE_H_
