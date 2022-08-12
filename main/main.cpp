#include <Windows.h>
#include <TlHelp32.h>
#include <Wingdi.h>
#include <iostream>
#include <string>
#include <chrono>

/*bool findAndOpenWin() {

	HWND hWnd = FindWindow( NULL, TEXT( "Безымянный - Paint" ) );
	bool check;
	POINT pt;
	if ( hWnd == NULL ) {

		MessageBox( hWnd, TEXT( "Need open Paint" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );
		check = 0;
	}
	else {
		//Разворачивает окно, елси оно свернуто 
		ShowWindow( hWnd, SW_RESTORE );
		//Функция делает активным необходимое окно
		SetForegroundWindow( hWnd );
		check = 1;
	}

	while ( 1 ) {

		GetCursorPos( &pt );
		//Берет координаты относительно выбранного окна 
		ScreenToClient( hWnd, &pt );

		std::cout << "X: " << pt.x << std::endl << "Y: " << pt.y << std::endl;
		std::cout << "==================" << std::endl;
		Sleep( 2000 );

	}

	return check;

}*/

/*/void mouseClick() {

	SetCursorPos( 30, 33 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 30, 33, 0, 0 );
	//=========
	Sleep( 500 );
	SetCursorPos( 84, 423 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 84, 423, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 851, 654 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 851, 654, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 993, 658 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 993, 658, 0, 0 );
	//=========
	SetCursorPos( 530, 64 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 530, 64, 0, 0 );
	//=========ЗАЖАТЬ
	SetCursorPos( 316, 331 );
	mouse_event( MOUSEEVENTF_LEFTDOWN, 316, 331, 0, 0 );
	//=========ОТПУСТИТЬ
	SetCursorPos( 526, 449 );
	mouse_event( MOUSEEVENTF_LEFTUP, 30, 33, 0, 0 );
	//=========



}*/

LRESULT CALLBACK WindowProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

int WINAPI wWinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow ) {

	const wchar_t CLASS_NAME[] = L"Sample Window Class";
	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	RegisterClass( &wc );

	//======
	int wHeight = 100; // Размер окна 
	
	//======

	HWND hWnd = CreateWindowEx( 0, CLASS_NAME, NULL, NULL, NULL, NULL, wHeight, wHeight, NULL, NULL, hInstance, NULL );

	if ( hWnd == NULL ) {

		MessageBox( hWnd, TEXT( "hWnd = LOL" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );
		return 0;

	}

	ShowWindow( hWnd, nCmdShow );
	while ( 1 ) {
	

	
	}
	
	MSG message;
	//while ( GetMessage( &message, NULL, 0, 0 ) > 0 ) {}
	
	/*//GetClientRect( hWnd, &rec );
		GetClientRect( hWnd, &rec );
		hdc = BeginPaint( hWnd, &ps );
		GetCursorPos( &pt );
		SetWindowPos( hWnd, HWND_TOPMOST, pt.x + 10, pt.y, NULL, NULL, NULL );
		str = "X: " + std::to_string( pt.x ) + " Y: " + std::to_string( pt.y );

		TextOutA( hdc, 10, 70, str.c_str(), str.size() );// ДОПИСАТЬ

		EndPaint( hWnd, &ps );*/
	
	return 0;
}



//===============
LRESULT CALLBACK WindowProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{

	POINT pt;
	RECT rec;
	
	//HDC hdc = GetDC( hWnd ); // Получение "контекста"
	std::string str;
	std::wstring wStr;
	LPCWSTR Lstr;
	HFONT wFont;
	HDC hdc;
	
	wFont = CreateFont( 90, 0, 0, 0, 0, 0, 0, 0,
						DEFAULT_CHARSET,
						0, 0, 0, 0,
						L"Arial Bold"
	);
	
		
		//GetClientRect( hWnd, &rec );
	/*	GetClientRect(hWnd, &rec);
		
		GetCursorPos( &pt );
		SetWindowPos( hWnd, HWND_TOPMOST, pt.x + 10, pt.y, NULL, NULL, NULL );
		str = "X: " + std::to_string( pt.x ) + " Y: " + std::to_string( pt.y );

		TextOutA( hdc, 10, 70, str.c_str(), str.size() );// ДОПИСАТЬ
		*/
		//EndPaint( hWnd, &ps );
		//TranslateMessage( &msg );
		//DispatchMessage( &msg );



	switch ( uMsg )
	{
	case WM_DESTROY:
		PostQuitMessage( 0 );
		return 0;

	case WM_PAINT:
	{

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint( hWnd, &ps );
		GetClientRect( hWnd, &rec );
		SetTextColor( hdc, NULL );
		SelectObject( hdc, wFont );
		GetCursorPos( &pt );
		str = "X: " + std::to_string( pt.x ) + " Y: " + std::to_string( pt.y );
		wStr = std::wstring( str.begin(), str.end() );
		Lstr = wStr.c_str();
		DrawText( hdc, Lstr, wStr.size(), &rec, DT_SINGLELINE | DT_CENTER | DT_VCENTER );
		EndPaint( hWnd, &ps );
		 

		//FillRect( hdc, &ps.rcPaint, (HBRUSH)( COLOR_WINDOW + 1 ) );

		EndPaint( hWnd, &ps );
	}

	return 0;

	}
	return DefWindowProc( hWnd, uMsg, wParam, lParam );

}