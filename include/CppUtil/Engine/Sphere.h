#ifndef _ENGINE_PRIMITIVE_SPHERE_H_
#define _ENGINE_PRIMITIVE_SPHERE_H_

#include <CppUtil/Engine/Primitive.h>
#include <CppUtil/Basic/UGM/BBox.h>
#include <CppUtil/Basic/UGM/Normal.h>

namespace CppUtil {
	namespace Engine {
		class Sphere final : public Primitive {
		public:
			Sphere() = default;
		public:
			static const Basic::Ptr<Sphere> New() { return Basic::New<Sphere>(); }

		protected:
			virtual ~Sphere() = default;

		public:
			virtual const BBoxf GetBBox() const override {
				return BBoxf(Point3(-1.f), Point3(1.f));
			}

			virtual const Basic::Ptr<Primitive> GetPrimitive() override {
				return This<Primitive>();
			}

		public:
			// 将法向转为纹理坐标
			// theta 对应 v，上 0 下 1
			// phi 对应 u，z 轴为 0，顺右手方向增大
			static const Point2 TexcoordOf(const Normalf & normal);

			// 将法向转为切向
			// u 方向
			static const Normalf TangentOf(const Normalf & normal);
		};
	}
}

#endif//!_ENGINE_PRIMITIVE_SPHERE_H_
