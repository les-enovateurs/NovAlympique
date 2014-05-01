#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;



#include "../include/lodepng.h"
#include "../include/capture.h"



capture::capture(unsigned int _taille)
{
    taille = _taille;
    init();
}

unsigned capture::decodeBMP(std::vector<unsigned char>& image, unsigned& w, unsigned& h, const std::vector<unsigned char>& bmp)
{
  static const unsigned MINHEADER = 54; //minimum BMP header size

  if(bmp.size() < MINHEADER) return -1;
  if(bmp[0] != 'B' || bmp[1] != 'M') return 1; //It's not a BMP file if it doesn't start with marker 'BM'
  unsigned pixeloffset = bmp[10] + 256 * bmp[11]; //where the pixel data starts
  //read width and height from BMP header
  w = bmp[18] + bmp[19] * 256;
  h = bmp[22] + bmp[23] * 256;
  //read number of channels from BMP header
  if(bmp[28] != 24 && bmp[28] != 32) return 2; //only 24-bit and 32-bit BMPs are supported.
  unsigned numChannels = bmp[28] / 8;

  //The amount of scanline bytes is width of image times channels, with extra bytes added if needed
  //to make it a multiple of 4 bytes.
  unsigned scanlineBytes = w * numChannels;
  if(scanlineBytes % 4 != 0) scanlineBytes = (scanlineBytes / 4) * 4 + 4;

  unsigned dataSize = scanlineBytes * h;
  if(bmp.size() < dataSize + pixeloffset) return 3; //BMP file too small to contain all pixels

  /*if(w > taille || h > taille)
  {
    int ratio = 0;

    ratio = (h*taille)/w;

    w = taille;
    h = ratio;

    cout<<"H : "<<h<<" W : "<<w<<endl;

  }*/
  image.resize(w * h * 4);

  /*
  There are 3 differences between BMP and the raw image buffer for LodePNG:
  -it's upside down
  -it's in BGR instead of RGB format (or BRGA instead of RGBA)
  -each scanline has padding bytes to make it a multiple of 4 if needed
  The 2D for loop below does all these 3 conversions at once.
  */
  for(unsigned y = 0; y < h; y++)
  for(unsigned x = 0; x < w; x++)
  {
    //pixel start byte position in the BMP
    unsigned bmpos = pixeloffset + (h - y - 1) * scanlineBytes + numChannels * x;
    //pixel start byte position in the new raw image
    unsigned newpos = 4 * y * w + 4 * x;
    /*if(numChannels == 3)
    {*/
      image[newpos + 0] = bmp[bmpos + 2]; //R
      image[newpos + 1] = bmp[bmpos + 1]; //G
      image[newpos + 2] = bmp[bmpos + 0]; //B
      image[newpos + 3] = 255;            //A
    /*}
    else
    {
      image[newpos + 0] = bmp[bmpos + 3]; //R
      image[newpos + 1] = bmp[bmpos + 2]; //G
      image[newpos + 2] = bmp[bmpos + 1]; //B
      image[newpos + 3] = bmp[bmpos + 0]; //A
    }*/
  }
  return 0;
}


HRESULT capture::CaptureWindow(HWND hWnd, LPBITMAPINFO * pscr, LPVOID * pbits)
{
    // Get the required device contexts
    HDC          hDC;
    HDC          hDCCompatible;
    HBITMAP      hbmpDesktop;
    HBITMAP      hbmpOld;
    LPVOID       data;
    LPBITMAPINFO bitmap;
    if (hWnd == NULL) hDC = CreateDC(TEXT("DISPLAY" ), NULL, NULL, NULL);
    else              hDC = GetDC(hWnd);
    hDCCompatible = CreateCompatibleDC(hDC);
    hbmpDesktop   = CreateCompatibleBitmap(hDC, GetDeviceCaps(hDC, HORZRES), GetDeviceCaps(hDC, VERTRES));
    // Prepare to copy the desktop image
    hbmpOld = (HBITMAP)SelectObject(hDCCompatible, hbmpDesktop);
    // Copy the desktop DC in to hbmpDesktop
    BitBlt(hDCCompatible, 0, 0, GetDeviceCaps(hDC, HORZRES), GetDeviceCaps(hDC, VERTRES), hDC, 0, 0, SRCCOPY);
    SelectObject(hDCCompatible, hbmpOld);
    // Allocate the screenshot of the desktop
    bitmap = *pscr = (LPBITMAPINFO)malloc(sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD));
    if (NULL == bitmap)
        return E_OUTOFMEMORY;
    ZeroMemory(bitmap, sizeof(BITMAPINFOHEADER));
    bitmap->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    // Ask for the bitmap information about the desktop
    GetDIBits(hDCCompatible, hbmpDesktop, 0, GetDeviceCaps(hDC, VERTRES), NULL, bitmap, DIB_RGB_COLORS);
    // Allocate the image's data
    data = *pbits = malloc(bitmap->bmiHeader.biSizeImage);
    if (NULL == data)
        return E_OUTOFMEMORY;
    // And finally fill in our bitmap's bits
    GetDIBits(hDCCompatible, hbmpDesktop, 0, GetDeviceCaps(hDC, VERTRES), data, bitmap, DIB_RGB_COLORS);
    // Clean up after ourselves
    DeleteObject(hbmpDesktop);
    DeleteDC(hDCCompatible);
    if (hWnd == NULL)   DeleteDC(hDC);
    else                ReleaseDC(hWnd,hDC);
    return S_OK;
}

int WINAPI capture::WinMain()
{
    BITMAPFILEHEADER header = {0};
    LPBITMAPINFO     screen = NULL;
    LPVOID           data   = NULL;
    if (CaptureWindow(NULL, &screen, &data) == S_OK)
    {
        /* Pas la peine de faire ca, si tu manipules l'image avec gdi par la suite */
        FILE * out = fopen("capture.bmp", "wb" );
        header.bfType    = 0x4D42;
        header.bfSize    = sizeof header + sizeof (BITMAPINFOHEADER) + screen->bmiHeader.biSizeImage;
        header.bfOffBits = sizeof header + sizeof (BITMAPINFOHEADER);
        if (out)
        {
            screen->bmiHeader.biCompression = BI_RGB;
            fwrite(&header, 1, sizeof header, out);
            fwrite(screen,  1, sizeof (BITMAPINFOHEADER), out);
            fwrite(data,    1, screen->bmiHeader.biSizeImage, out);
            fclose(out);
        }
        else fprintf(stderr, "error writing capture.bmp\n" );
        free(screen);
        free(data);
    }
    return 0;
}

void capture::init()
{

      WinMain();
      std::vector<unsigned char> bmp;
      lodepng::load_file(bmp, "capture.bmp");
      std::vector<unsigned char> image;
      unsigned w, h;
      unsigned error = decodeBMP(image, w, h, bmp);

      if(error)
      {
        std::cout << "BMP decoding error " << error << std::endl;
        exit(1);
      }

      std::vector<unsigned char> png;

  /*    if(w > taille || h > taille)
      {
        int ratio = 0;

        ratio = (h*taille)/w;

        w = taille;
        h = ratio;

        cout<<"H : "<<h<<" W : "<<w<<endl;

      }*/

      error = lodepng::encode(png, image, w, h);


      if(error)
      {
        std::cout << "PNG encoding error " << error << ": " << lodepng_error_text(error) << std::endl;
        //return 0;
        exit(1);
      }

      lodepng::save_file(png, "output.png");
}



capture::~capture()
{
    //dtor
}
