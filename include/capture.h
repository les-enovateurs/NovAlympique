#ifndef CAPTURE_H
#define CAPTURE_H

#include <windows.h>
#include <stdio.h>

class capture
{
    public:
        capture();
        unsigned decodeBMP(std::vector<unsigned char>& image, unsigned& w, unsigned& h, const std::vector<unsigned char>& bmp);
        HRESULT CaptureWindow(HWND hWnd, LPBITMAPINFO * pscr, LPVOID * pbits);
        int WINAPI WinMain ();
        void init();
        virtual ~capture();
    protected:
    private:
};

#endif // CAPTURE_H
