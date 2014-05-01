#ifndef CAPTURE_H
#define CAPTURE_H

#include <windows.h>
#include <stdio.h>

class capture
{
    public:
        capture(unsigned int _taille);
        unsigned decodeBMP(std::vector<unsigned char>& image, unsigned& w, unsigned& h, const std::vector<unsigned char>& bmp);
        HRESULT CaptureWindow(HWND hWnd, LPBITMAPINFO * pscr, LPVOID * pbits);
        int WINAPI WinMain ();
        void init();
        void bilinearScale(std::vector<unsigned char>& image,unsigned int w,unsigned int h)const;
        virtual ~capture();
    protected:
    private:
        unsigned int taille;
};

#endif // CAPTURE_H
