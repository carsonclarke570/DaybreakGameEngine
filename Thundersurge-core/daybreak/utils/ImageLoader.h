#include <string>
#include <FreeImage.h>
#include <GL/glew.h>

#ifndef _IMAGE_LOADER_H_
#define _IMAGE_LOADER_H_

namespace daybreak {

	static BYTE* loadImage(const char* filename, GLsizei* width, GLsizei* height) {
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP* dib = nullptr;
		fif = FreeImage_GetFileType(filename, 0);
		if (fif == FIF_UNKNOWN) {
			fif = FreeImage_GetFIFFromFilename(filename);
		}
		if (fif == FIF_UNKNOWN) {
			return nullptr;
		}

		if (FreeImage_FIFSupportsReading(fif)) {
			dib = FreeImage_Load(fif, filename);
		}
		if (!dib) {
			return nullptr;
		}
		FreeImage_FlipVertical(dib);
		BYTE* result = FreeImage_GetBits(dib);
		*width = FreeImage_GetWidth(dib);
		*height = FreeImage_GetHeight(dib);

		return result;
	}
}

#endif