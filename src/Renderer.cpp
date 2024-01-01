#include "Renderer.h"

#include <glm/glm.hpp>

#include "Ray.h"

#include <iostream>

namespace rtx {

	static glm::vec3 light_direction;

	Color traceRay(const Ray& ray) {
		float radius = 0.5f;
		glm::vec3 sphere_position(0, 0, 0);

		float a = glm::dot(ray.direction, ray.direction);
		float b = 2.0f * glm::dot(ray.origin, ray.direction);
		float c = glm::dot(ray.origin, ray.origin) - radius * radius;

		float discriminant = b * b - 4.0f * a * c;
		if (discriminant < 0.0f) {
			return glm::vec4(1, 1, 1, 1);
		}

		glm::vec3 sphere_color(1, 0, 0);

		float t0 = (-b + glm::sqrt(discriminant)) / (2.0f * a);
		float t1 = (-b - glm::sqrt(discriminant)) / (2.0f * a);

		glm::vec3 hitpoint = ray.origin + ray.direction * t1;
		glm::vec3 normal = glm::normalize(hitpoint - sphere_position);

		float diffuse = glm::max(glm::dot(normal, -light_direction), 0.0f);
		sphere_color = sphere_color * diffuse;

		//sphere_color = normal * 0.5f + 0.5f;

		return glm::vec4(sphere_color.x, sphere_color.y, sphere_color.z, 1.0f);
	}

	void Renderer::render(const Camera& camera, RenderCanvas* canvas) {
		light_direction = glm::normalize(glm::vec3(-1, -1, -1));

		Ray ray;
		ray.origin = camera.getPosition();

		for (int y = 0; y < canvas->getHeight(); y++) {
			for (int x = 0; x < canvas->getWidth(); x++) {
				ray.direction = camera.getRays()[x + y * canvas->getWidth()];

				Color color = traceRay(ray);
				color = glm::clamp(color, Color(0.0f), Color(1.0f));

				canvas->setPixel(x, y, calculateColorFromRGBF(color.r, color.g, color.b));
			}
		}
	}

}