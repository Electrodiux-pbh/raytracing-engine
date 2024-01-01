#include <iostream>

#include "RenderCanvas.h"
#include "Renderer.h"
#include "Camera.h"
#include <string>

int main()
{
	constexpr int width = 256 * 2;
	constexpr int height = 256 * 2;

	rtx::RenderCanvas* canvas = new rtx::RenderCanvas(width, height);
	rtx::Renderer renderer;
	Camera camera(45.0f, 0.01f, 100.0f);
	camera.resize(width, height);

	/*for (int i = 0; i < 10; i++) {
		camera.move(glm::vec3(0.1f, 0, 0));
		renderer.render(camera, canvas);
		std::string filename = std::string("image-") + std::to_string(i) + std::string(".png");
		rtx::writeImageToDisk(canvas, filename.c_str());
	}*/

	renderer.render(camera, canvas);
	rtx::writeImageToDisk(canvas, "image.png");

	return 0;
}