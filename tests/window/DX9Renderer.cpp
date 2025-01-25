#include "DX9Renderer.h"
#include <iostream>
#include <d3d9.h>

#pragma comment (lib, "d3d9.lib")

LPDIRECT3D9 d3d = NULL;
LPDIRECT3DDEVICE9 d3ddev = NULL;

void DX9Renderer::initialize() {
    std::cout << "Initializing DirectX 9..." << std::endl;
    d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (d3d == NULL) {
        std::cerr << "Failed to create Direct3D interface" << std::endl;
        return;
    }

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow = GetActiveWindow();

    if (FAILED(d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GetActiveWindow(),
                                 D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev))) {
        std::cerr << "Failed to create Direct3D device" << std::endl;
        return;
    }
}

void DX9Renderer::renderFrame() {
    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
    d3ddev->BeginScene();
    // Add rendering code here
    d3ddev->EndScene();
    d3ddev->Present(NULL, NULL, NULL, NULL);
}

void DX9Renderer::shutdown() {
    std::cout << "Shutting down DirectX 9..." << std::endl;
    if (d3ddev) d3ddev->Release();
    if (d3d) d3d->Release();
}
