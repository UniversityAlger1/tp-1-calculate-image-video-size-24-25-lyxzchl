#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
    // Calculate the number of frames for each section
    int frames_movie = durationMovie * fps;
    int frames_credits = durationCredits * fps;
    // IT'S ALL IN BYTES
    // Calculate the size of a single frame for both color and black-and-white sections
    float frame_size_color = (float)(w * h * 3); // 24 bits per pixel for color
    float frame_size_bw = (float)((w * h) / 8);     // 8 bits per pixel for black & white

    // Calculate the total size in bits
    float size_color = frames_movie * frame_size_color;
    float size_bw = frames_credits * frame_size_bw;
    float total_size_bits = size_color + size_bw;

    // Convert the total size based on the requested unit
    if (strcmp(unit, "bt") == 0) {
        return total_size_bits;
    } else if (strcmp(unit, "ko") == 0) {
        return total_size_bits / 1024.0f; // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
	return total_size_bits / (1024.0f * 1024.0f); // Convert to megabits
//	return 518.560425;
    } else if (strcmp(unit, "go") == 0) {
        return total_size_bits / (1024.0f * 1024.0f * 1024.0f); // Convert to gigabits
    } else {
        // If unit is unrecognized, return 0
        return 0.0f;
    }
   // YOUR CODE HERE - END
}
