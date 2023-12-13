#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"


color_ray_color(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 *(unit_direction.y()+1.0);
    return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}
int main(){
    auto aspect_ratio= 16.0 / 9.0;
    int image_width= = 400;

    int image_height = static_cast<int>(image_width /aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    auto viewport_height = 2.0;
    auto viewport_width =viewport_height * (static_cast<double>(image_width)/image_height);

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel100_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_camera, ray_direction);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";

}