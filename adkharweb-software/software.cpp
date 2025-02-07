#include <iostream>
#include <windows.h>
#include <wrl.h>
#include <WebView2.h>

using namespace Microsoft::WRL;

// المتغيرات العامة
HWND hWnd;
ComPtr<ICoreWebView2Controller> webViewController;
ComPtr<ICoreWebView2> webView;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_SIZE:
        if (webViewController)
        {
            RECT bounds;
            GetClientRect(hwnd, &bounds);
            webViewController->put_Bounds(bounds);
        }
        return 0;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void InitializeWebView()
{
    CreateCoreWebView2EnvironmentWithOptions(nullptr, nullptr, nullptr,
                                             Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
                                                 [](HRESULT result, ICoreWebView2Environment *env) -> HRESULT
                                                 {
                                                     env->CreateCoreWebView2Controller(hWnd,
                                                                                       Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                                                                                           [](HRESULT result, ICoreWebView2Controller *controller) -> HRESULT
                                                                                           {
                                                                                               if (controller)
                                                                                               {
                                                                                                   webViewController = controller;
                                                                                                   webViewController->get_CoreWebView2(&webView);
                                                                                               }

                                                                                               RECT bounds;
                                                                                               GetClientRect(hWnd, &bounds);
                                                                                               webViewController->put_Bounds(bounds);

                                                                                               // تحميل صفحة الويب المطلوبة
                                                                                               webView->Navigate(L"index.html");

                                                                                               return S_OK;
                                                                                           })
                                                                                           .Get());
                                                     return S_OK;
                                                 })
                                                 .Get());
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"AdkharWB";

    RegisterClass(&wc);

    hWnd = CreateWindowEx(0, L"AdkharWB", L"AdkharWB",
                          WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                          800, 600, nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hWnd, nCmdShow);

    InitializeWebView();

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
