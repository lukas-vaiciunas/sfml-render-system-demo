#include "Config.h"

namespace Config
{
	namespace Window
	{
		unsigned int width = 800;
		unsigned int height = 800;
		unsigned int bitsPerPixel = 32;
	}

	namespace World
	{
		float scale = 8.0f;
	}

	namespace Interface
	{
		float scale = 8.0f;
	}

	namespace Text
	{
		namespace CharacterSize
		{
			unsigned int medium = 32;
		}

		float outlineScale = 0.1875f;
	}
}