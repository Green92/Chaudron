#ifndef TEXT_RENDER_UTIL_HPP
#define TEXT_RENDER_UTIL_HPP

#include <sifteo/string.h>

#define Font Font8

#define LINE_HEIGHT 1
#define CHAR_WIDTH 1

#define SCREEN_TILE_NUMBER 16
#define SCREEN_CHAR_NUMBER SCREEN_TILE_NUMBER / CHAR_WIDTH

class TextRenderUtil {
	private:
		static void strcpy(char *dst, const char *src, unsigned char size) {
			unsigned char i;

			for (i = 0; i<size; i++) {
				dst[i] = src[i];
			}

			dst[i] = '\0';
		}

	public:
		static void drawTextMonoLine(VideoBuffer *videoBuffer, UInt2 pos, const char * str) {
			videoBuffer->bg1.fillMask(pos, vec((int)strnlen(str, SCREEN_CHAR_NUMBER) * CHAR_WIDTH, LINE_HEIGHT));
			videoBuffer->bg1.text(pos, Font, str);
		}

		static void drawCenteredTextMonoLine(VideoBuffer *videoBuffer, int line, const char * str) {
			drawTextMonoLine(videoBuffer, vec((int) (SCREEN_CHAR_NUMBER - strnlen(str, SCREEN_CHAR_NUMBER) * CHAR_WIDTH) / 2, line), str);
		}

		static unsigned char drawCenteredTextMultiLine(VideoBuffer *videoBuffer, int startLine, const char * str, unsigned char marginLeftRight = 0) {
			//Have the capacity to contain
			//as much character as the screen
			//and one more for the termination char ('\0')
			char line[SCREEN_CHAR_NUMBER + 1];

			//The len of the string to print
			unsigned char len = strnlen(str, 100);

			//An index used to browse the string.
			int strIndex = 0;

			//The number of line we have printed on.
			int nbLine = 0;

			//The maximum number of char by line.
			unsigned char maxCharByLine = SCREEN_CHAR_NUMBER-marginLeftRight*2;

			LOG("----------------------------------------\n");
			LOG("Let's print \"%s\" on multiple lines ! Youpi\n", str);
			LOG("Ok, we start to print on line number %d\n", startLine+1);

			while (strnlen(str+strIndex, 100) > maxCharByLine) {
				
				LOG("\"%s\" is bigger than %d\n", str+strIndex, maxCharByLine);
				
				for (int i=strIndex+maxCharByLine; i>strIndex; i--) {
					
					LOG("'str at index %d is %c'\n", i, str[i]);
					
					if (str[i] == ' ') {
						strcpy(line, str+strIndex, i-strIndex);
						
						LOG("Ok, printing \"%s\" on line %d\n", line, startLine+nbLine);
						
						drawCenteredTextMonoLine(videoBuffer, startLine+nbLine, line);
						strIndex += i-strIndex+1;
						nbLine+=LINE_HEIGHT;
						break;
					}
				}

				LOG("strIndex is %d and str is %d char long :  ", strIndex, len);

				if (strIndex >= len) {
					LOG("Stopping algorithm.\n");
					return nbLine;
				}

				LOG("We have still some work.\n");
			}

			LOG("\"%s\" is lower than 16\nOk, printing \"%s\" on line %d\n", str+strIndex, str+strIndex, startLine+nbLine);
			drawCenteredTextMonoLine(videoBuffer, startLine+nbLine, str+strIndex);
			return ++nbLine;
		}
};

#endif