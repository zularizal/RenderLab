#include <CppUtil/Engine/Viewer.h>

#include "DirectIllumRaster.h"
#include <CppUtil/Engine/Roamer.h>
#include "Picker.h"

#include <CppUtil/Qt/RawAPI_OGLW.h>

#include <CppUtil/Basic/LambdaOp.h>

using namespace CppUtil::Engine;
using namespace CppUtil::QT;
using namespace CppUtil::Basic;

Viewer::Viewer(RawAPI_OGLW * pOGLW, Ptr<Scene> scene, RasterType rasterType)
	: pOGLW(pOGLW), scene(scene), roamer(Roamer::New(pOGLW)), picker(Picker::New(this)) {
	switch (rasterType)
	{
	case RasterType::DirectIllum:
		raster = DirectIllumRaster::New(pOGLW, scene, roamer->GetCamera());
		break;
	default:
		printf("ERROR::Viewer::Viewer:\n"
			"\t""not support RasterType(%s)\n", rasterType._to_string());
		break;
	}

	pOGLW->SetInitOp(LambdaOp_New([this]() {
		roamer->OGL_Init();
		raster->OGL_Init();
		picker->OGL_Init();
	}));

	pOGLW->SetPaintOp(LambdaOp_New([this]() {
		raster->Draw();
	}));

	pOGLW->SetResizeOp(LambdaOp_New([this]() {
		auto pOGLW = this->GetOGLW();

		int w = pOGLW->w;
		int h = pOGLW->h;

		roamer->SetWH(w, h);
	}));
}

void Viewer::SetLock(bool isLock) {
	roamer->SetLock(isLock);
}
