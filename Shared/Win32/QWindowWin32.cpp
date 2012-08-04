// QWindowWin32.cpp: implementation of the QWindowWin32 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "QWindowWin32.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QWindowWin32::QWindowWin32()
{

}

QWindowWin32::~QWindowWin32()
{

}



LRESULT CALLBACK DefaultWinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    PAINTSTRUCT ps;
		
	switch(message)
    {

		case WM_PAINT:
			BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
				return 0;

		case WM_KEYDOWN:

			if(wparam == VK_ESCAPE)
			{
			//	ChangeDisplayMode(0,0,true); // Always switch back to normal screen resolution
				PostQuitMessage(0);
			}
			
			return 0;
	
		case WM_CLOSE:
		case WM_DESTROY:

	//		ChangeDisplayMode(0,0,true); // Always switch back to normal screen resolution
			PostQuitMessage(0);
				return 0;
    
	} // end of switch(message)

	return DefWindowProc(hwnd, message, wparam, lparam);
}

void QWindowWin32::PreRender()
{

}

void QWindowWin32::PostRender()
{

}
