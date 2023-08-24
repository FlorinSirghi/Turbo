#include <windows.h>

namespace Turbo
{
    void printWorkArea()
    {
        RECT workArea = { 0 };
        if (SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0))
        {
            int width = workArea.right - workArea.left;
            int height = workArea.bottom - workArea.top;

            //std::cout << width << ' ' << height << '\n';
        }
    }
}