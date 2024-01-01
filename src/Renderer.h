#pragma once

#include "Camera.h"
#include "RenderCanvas.h"

namespace rtx {

	class Renderer {

		public:
		void render(const Camera& camera, RenderCanvas* canvas);

	};
}