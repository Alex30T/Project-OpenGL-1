#include <windows.h>
#include<math.h>
#include<fstream>

const wchar_t windowClass[] = L"win32app";
const wchar_t windowTitle[] = L"Win32API - РџСЂРёРјРµСЂ РѕРєРЅР°";

int x, y;
int Lx, Ly;
int a = 0, b = 0, c = 0;
int period = 1;

HPEN pen, old_pen;
HBRUSH brush, old_brush;



void Line(HDC hdc, int x1, int y1, int x2, int y2) {
    MoveToEx(hdc, x1, y1, nullptr);
    LineTo(hdc, x2, y2);
}

void DrowGrafic(HDC hdc, RECT r) {

    int size_x = r.right - r.left;
    int size_y = r.bottom - r.top;

    Rectangle(hdc, size_x - size_x / 3, 0, size_x, size_y / 3);

    pen = CreatePen(PS_USERSTYLE, 1, RGB(0, 0, 0));
    old_pen = (HPEN)SelectObject(hdc, pen);


    for (int i = 0; i < size_y / 3 - 20; i = i + 20) {
        c = c + 20;
        Line(hdc, size_x - size_x / 3, c, size_x, c);
    }
    c = 0;



    for (int i = 0; i < size_x; i = i + 20) {
        c = c + 20;
        Line(hdc, (size_x - size_x / 3) + c, 0, (size_x - size_x / 3) + c, size_y / 3);
    }

    c = 0;
    SelectObject(hdc, old_pen);
    DeleteObject(pen);



    double A = size_y / 6;
    double T = 2 * 3.14 * period;
    double x1 = 0, y1 = 0;
    MoveToEx(hdc, size_x - size_x / 3, 0, nullptr);
    for (int i = size_x - size_x / 3; i <= (size_x); i++) {
        x1 = i * T / (size_x);
        y1 = A * cos(x1);
        LineTo(hdc, i, size_y / 6 - y1);



    }
}

void DrawGrid(HDC hdc, RECT r, bool picked) {

   


    int size_x = r.right - r.left;
    int size_y = r.bottom - r.top;



    if (picked) {
        brush = CreateSolidBrush(RGB(0, 0, 0));
        old_brush = (HBRUSH)SelectObject(hdc, brush);

        pen = CreatePen(PS_USERSTYLE, 1, RGB(255, 255, 255));
        old_pen = (HPEN)SelectObject(hdc, pen);
        Rectangle(hdc, x - 1, y - 1, x + 226, y + 426);
        SelectObject(hdc, old_pen);
        DeleteObject(pen);

        SelectObject(hdc, old_brush);
        DeleteObject(brush);
    }

    pen = CreatePen(PS_USERSTYLE, 1, RGB(220, 220, 220));
    old_pen = (HPEN)SelectObject(hdc, pen);

  

    for (int i = 0; i < size_y; i= i+40) {

        b = b + 40;

        Line(hdc, 0, b, size_x, b);

    }
    b = 0;

    Line(hdc, 0, 0, 0, size_y);
    

    for (int i = 0; i < size_x; i = i + 40) {

        a = a + 40;

        Line(hdc, a, 0, a, size_y);

    }
    a = 0;
    Line(hdc, size_x, 0, size_x, size_y);

    SelectObject(hdc, old_pen);
    DeleteObject(pen);



}



void DrawLayout(HDC hdc, bool picked) {


    brush = CreateSolidBrush(RGB(50, 205, 50));
    old_brush = (HBRUSH)SelectObject(hdc, brush);

    pen = CreatePen(PS_USERSTYLE, 1, RGB(50, 205, 50));
    old_pen = (HPEN)SelectObject(hdc, pen);

    Rectangle(hdc, x + 15, y, x + 215, y + 130);
    Rectangle(hdc, x + 150, y + 110, x + 215, y + 190);
    Rectangle(hdc, x + 150, y + 230, x + 215, y + 300);
    Rectangle(hdc, x + 15, y + 300, x + 215, y + 375);


    SelectObject(hdc, old_pen);
    DeleteObject(pen);

    SelectObject(hdc, old_brush);
    DeleteObject(brush);




    brush = CreateSolidBrush(RGB(255, 0, 0));
    old_brush = (HBRUSH)SelectObject(hdc, brush);

    pen = CreatePen(PS_USERSTYLE, 1, RGB(255, 0, 0));
    old_pen = (HPEN)SelectObject(hdc, pen);

    Rectangle(hdc, x + 52, y + 50, x + 70, y + 300);
    Rectangle(hdc, x + 107, y + 50, x + 125, y + 300);
    Rectangle(hdc, x + 165, y + 50, x + 185, y + 400);





    SelectObject(hdc, old_pen);
    DeleteObject(pen);

    SelectObject(hdc, old_brush);
    DeleteObject(brush);



    brush = CreateSolidBrush(RGB(16, 52, 166));
    old_brush = (HBRUSH)SelectObject(hdc, brush);

    pen = CreatePen(PS_USERSTYLE, 1, RGB(16, 52, 166));
    old_pen = (HPEN)SelectObject(hdc, pen);

    Rectangle(hdc, x, y, x + 225, y + 50);
    Rectangle(hdc, x, y, x + 30, y + 110);
    Rectangle(hdc, x + 80, y + 60, x + 100, y + 150);
    Rectangle(hdc, x + 80, y + 150, x + 155, y + 170);
    Rectangle(hdc, x + 155, y + 150, x + 175, y + 270);
    Rectangle(hdc, x + 15, y + 270, x + 175, y + 290);
    Rectangle(hdc, x + 15, y + 270, x + 35, y + 360);
    Rectangle(hdc, x + 140, y + 295, x + 160, y + 375);
    Rectangle(hdc, x + 190, y + 60, x + 215, y + 365);
    Rectangle(hdc, x + 30, y + 200, x + 70, y + 240);
    Rectangle(hdc, x + 85, y + 200, x + 125, y + 240);



    Rectangle(hdc, x, y + 375, x + 225, y + 425);




    SelectObject(hdc, old_pen);
    DeleteObject(pen);

    SelectObject(hdc, old_brush);
    DeleteObject(brush);



    


}


long __stdcall WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
   

    PAINTSTRUCT ps;
    HDC hdc;

    RECT r;
    GetClientRect(hWnd, &r);

    static bool picked = false;



    std::ofstream file;
    switch (message) {
    case WM_CREATE:
        SetTimer(hWnd, 34, 1000, nullptr);
        SetTimer(hWnd, 35, 2000, nullptr);
        break;

        
    case WM_DESTROY:
        file.open("config.txt");
        file << x << '\n';
        file << y << '\n';
        file << period << '\n';


        PostQuitMessage(0);
        break;

    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);

        DrawGrid(hdc,r, picked);
        DrawLayout(hdc, picked);
        DrowGrafic(hdc, r);




        EndPaint(hWnd, &ps);
        break;
    }
    case WM_LBUTTONDOWN:
    {

            if (wParam & MK_SHIFT && picked) {

                int size_x = r.right - r.left;
                int size_y = r.bottom - r.top;

                x = LOWORD(lParam);
                y = HIWORD(lParam);



                if ((x < (size_x - size_x / 3) - 225 && y < size_y - 425) or (x < size_x - 225 && y > size_y / 3 && y < size_y - 425)) {
                    InvalidateRect(hWnd, nullptr, true);
                }

            }
        

        break;
    }
    case WM_RBUTTONDOWN:
    {
        int click_x = LOWORD(lParam);
        int click_y = HIWORD(lParam);
        if (click_x > x && click_x < x + 225 && click_y > y && click_y < y + 425) {
            picked = true;
        }
        else {
            picked = false;
        }
        InvalidateRect(hWnd, nullptr, true);
        break;

    }
    case WM_CHAR:

        if (wParam == '+')
        {
            if (period >= 15)
            {
                break;
            }
            period++;
        }
        InvalidateRect(hWnd, nullptr, true);
        break;

    case WM_CLOSE:
        if (MessageBox(hWnd, L"Clicked", L"Info", MB_YESNO) == IDNO)
            return 0;
        break;



    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wcex;

    std::ifstream file;
    file.open("config.txt");
    file >> x;
    file >> y;
    file >> period;

    file.close();

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 3);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = windowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex)) {
        MessageBox(NULL, L"Can't register window class!", L"Win32 API Test", NULL);
        return 1;
    }

    HWND hWnd = CreateWindow(windowClass, windowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1350, 880, NULL, NULL, hInstance, NULL);

    if (!hWnd) {
        MessageBox(NULL, L"Can't create window!", L"Win32 API Test", NULL);
        return 1;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
