#include "Main.h"
#include <Windows.h>
#include <auth.hpp>
#include <string>
#include "script.h"
#include "Fonts.h"
#include <random>

using namespace KeyAuth;
bool antiafk = false;
std::string name = ("Rust");
std::string ownerid = ("sptpCVk6fG");
std::string secret = ("fd784c0c33e3ccce7145a1cec7a794cf4b833575dce878c33723a05892209694");
std::string version = ("1.0");

char key[255];

static int selectedcode = 0;
int titangui = 1;
api KeyAuthApp(name, ownerid, secret, version);


static std::string random_string(int length)
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(str.begin(), str.end(), generator);
    return str.substr(0, length);
}
static DWORDLONG random_number(DWORDLONG min, DWORDLONG max)
{
    srand(time(0));
    DWORDLONG out = min + rand() % (max - min + 1);
    return out;
}
static std::string randomclassname = random_string(random_number(4, 16));
// Main code
int APIENTRY WinMain1(HINSTANCE, HINSTANCE, LPSTR, int)
{

    // Create application window
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "Loader base", NULL };
    RegisterClassEx(&wc);
    main_hwnd = CreateWindow(wc.lpszClassName, randomclassname.c_str(), WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(main_hwnd)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ShowWindow(main_hwnd, SW_HIDE);
    UpdateWindow(main_hwnd);

    // Setup Dear ImGui context
    ImGui::CreateContext();



    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr; //crutial for not leaving the imgui.ini files
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle* style = &ImGui::GetStyle();
    ImVec4* colors = style->Colors;

    colors[ImGuiCol_Text] = ImVec4(0.92f, 0.92f, 0.92f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.44f, 0.44f, 0.44f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.47f, 0.47f, 0.47f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.81f, 0.83f, 0.81f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.93f, 0.65f, 0.14f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
    colors[ImGuiCol_Tab] = ImVec4(0.51f, 0.36f, 0.15f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.91f, 0.64f, 0.13f, 1.00f);
    colors[ImGuiCol_TabActive] = ImVec4(0.78f, 0.55f, 0.21f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

    style->FramePadding = ImVec2(4, 2);
    style->ItemSpacing = ImVec2(10, 2);
    style->IndentSpacing = 12;
    style->ScrollbarSize = 10;

    style->WindowRounding = 4;
    style->FrameRounding = 4;
    style->PopupRounding = 4;
    style->ScrollbarRounding = 6;
    style->GrabRounding = 4;
    style->TabRounding = 4;

    style->WindowTitleAlign = ImVec2(1.0f, 0.5f);
    style->WindowMenuButtonPosition = ImGuiDir_Right;

    style->DisplaySafeAreaPadding = ImVec2(4, 4);
    // Setup Platform/Renderer backends sss
    ImGui_ImplWin32_Init(main_hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    DWORD window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
    RECT screen_rect;
    GetWindowRect(GetDesktopWindow(), &screen_rect);
    auto x = float(screen_rect.right - 335) / 2.f;
    auto y = float(screen_rect.bottom - 450) / 2.f;

    ImFont* font = io.Fonts->AddFontFromMemoryCompressedTTF(Medium_compressed_data, Medium_compressed_size, 15.f);
    ImFont* pFont = io.Fonts->AddFontFromMemoryCompressedTTF(Medium_compressed_data, Medium_compressed_size, 50.f);


    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(300, 350));
            ImGui::SetNextWindowBgAlpha(1.0f);


            bool loader_active = true;

            ImGui::Begin(randomclassname.c_str(), &loader_active, window_flags);
            {
                if (titangui == 1) {
                    script();
                    ImGui::SetCursorPosX(82);
                    ImGui::PushFont(pFont);
                    ImGui::TextColored(ImVec4(0.91f, 0.64f, 0.13f, 1.00f), "TITAN");
                    ImGui::PopFont();
                    ImGui::SetCursorPosX(20);
                    if (ImGui::Button("Recoil", ImVec2(60, 20))) titangui = 1;
                    ImGui::SameLine();
                    if (ImGui::Button("Settings", ImVec2(60, 20))) titangui = 2;
                    ImGui::SameLine();
                    if (ImGui::Button("Config", ImVec2(60, 20))) titangui = 4;
                    ImGui::SameLine();
                    if (ImGui::Button("Keys", ImVec2(60, 20))) titangui = 3;
                    ImGui::Separator();
                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(90);
                    ImGui::Text("Weapon  Settings");
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(40);
                    ImGui::PushItemWidth(220);
                    ImGui::Combo("W", &selectedItemWP, itemWP, IM_ARRAYSIZE(itemWP));
                    if (selectedItemWP == 0) {
                        Weapon = "NONE";
                        bAK47 = false; bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false;
                        bM249 = false; bPhyton = false; bm39 = false;
                    }
                    if (selectedItemWP == 1) {
                        Weapon = "AK47";
                        bAK47 = true; bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false;
                        bM249 = false; bPhyton = false; bm39 = false;
                    }
                    if (selectedItemWP == 2) {
                        Weapon = "LR300";
                        bLR300 = true; bAK47 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false;
                        bM249 = false; bPhyton = false; bm39 = false;
                    }
                    if (selectedItemWP == 3) {
                        Weapon = "MP5A4";
                        bLR300 = false; bAK47 = false; bMP5 = true; bCSMG = false; bTHOMPSON = false; bSemi = false;
                        bM249 = false; bPhyton = false; bm39 = false;
                    }
                    if (selectedItemWP == 4) {
                        Weapon = "CUSTOM";
                        bCSMG = true; bAK47 = false; bMP5 = false; bLR300 = false; bTHOMPSON = false; bSemi = false;
                        bM249 = false; bPhyton = false; bm39 = false;
                    }
                    if (selectedItemWP == 5) {
                        Weapon = "THOMPSON";
                        bTHOMPSON = true; bAK47 = false; bMP5 = false; bCSMG = false; bLR300 = false; bSemi = false;
                        bM249 = false; bPhyton = false; bm39 = false;
                    }
                    if (selectedItemWP == 6) {
                        Weapon = "SAR";
                        bSemi = true; bAK47 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bLR300 = false;
                        bM249 = false; bPhyton = false; bm39 = false;
                    }
                    if (selectedItemWP == 7) {
                        Weapon = "M249";
                        bM249 = true; bAK47 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false;
                        bLR300 = false; bPhyton = false; bm39 = false;
                    }
                    if (selectedItemWP == 8) {
                        Weapon = "PYTHON";
                        bPhyton = true; bAK47 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false;
                        bM249 = false; bLR300 = false; bm39 = false;
                    }
                    ImGui::SetCursorPosX(40);
                    ImGui::PushItemWidth(220);
                    ImGui::Combo("S", &selectedItemSC, itemSC, IM_ARRAYSIZE(itemSC));
                    if (selectedItemSC == 0) {
                        Scope = "NONE";
                        b16x = false; bHolo = false; bSimple = false; b8x = false;
                    }
                    if (selectedItemSC == 1) {
                        Scope = "8X";
                        b8x = true; b16x = false; bHolo = false; bSimple = false;
                    }
                    if (selectedItemSC == 2) {
                        Scope = "16X";
                        b8x = false; b16x = true; bHolo = false; bSimple = false;
                    }
                    if (selectedItemSC == 3) {
                        Scope = "HOLO";
                        b16x = false; bHolo = true; bSimple = false; b8x = false;
                    }
                    if (selectedItemSC == 4) {
                        Scope = "SIMPLE";
                        b16x = false; bHolo = false; bSimple = true; b8x = false;
                    }
                    ImGui::SetCursorPosX(40);
                    ImGui::PushItemWidth(220);
                    ImGui::Combo("B", &selectedItemBR, itemBR, IM_ARRAYSIZE(itemBR));
                    if (selectedItemBR == 0) {
                        Barrel = "NONE";
                        bSuppressor = false;
                    }
                    if (selectedItemBR == 1) {
                        Barrel = "SILENCER";
                        bSuppressor = true;
                    }
                    ImGui::Spacing();
                    ImGui::Separator();
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(90);
                    ImGui::Text("Rust Sensitivity");
                    ImGui::SetCursorPosX(40);
                    ImGui::PushItemWidth(220);
                    ImGui::SliderFloat("##sensitivity", &Sensitivity, 0, 2, "% .2f");
                    ImGui::Spacing();
                    ImGui::Separator();
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(90);
                    ImGui::Text("Randomization");
                    ImGui::SetCursorPosX(40);
                    ImGui::SliderFloat("X##-", &XCONTROL, 1, 5, "% .2f");
                    ImGui::SetCursorPosX(40);
                    ImGui::SliderFloat("Y##-", &YCONTROL, 1, 5, "% .2f");
                    ImGui::Spacing();
                    ImGui::Separator();
                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(40);
                    if (antiafk == true) {
                        keybd_event(VK_SPACE, 0, 0, 0);
                        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
                        antiafk = true;
    
                }
                if (titangui == 2) {
                    script();
                    ImGui::SetCursorPosX(82);
                    ImGui::PushFont(pFont);
                    ImGui::TextColored(ImVec4(0.91f, 0.64f, 0.13f, 1.00f), "TITAN");
                    ImGui::PopFont();
                    ImGui::SetCursorPosX(20);
                    if (ImGui::Button("Recoil", ImVec2(60, 20))) titangui = 1;
                    ImGui::SameLine();
                    if (ImGui::Button("Settings", ImVec2(60, 20))) titangui = 2;
                    ImGui::SameLine();
                    if (ImGui::Button("Config", ImVec2(60, 20))) titangui = 4;
                    ImGui::SameLine();
                    if (ImGui::Button("Keys", ImVec2(60, 20))) titangui = 3;
                    ImGui::Separator();
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(40);
                    ImGui::Checkbox("CodeLock[HOME]", &codelock);
                    ImGui::Checkbox("Hipfire", &hip_active);
                    ImGui::Checkbox("Anti afk", &antiafk);
                    if (codelock == true)
                    {
                        ImGui::SameLine(200);
                        ImGui::SetNextItemWidth(80);
                        ImGui::Combo("  ", &selectedcode, code, IM_ARRAYSIZE(code));
                        if (selectedcode == 0) {
                            {
                                if (GetAsyncKeyState(VK_HOME) & 0x8000)
                                {
                                    keybd_event('7', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('5', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('4', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('8', 0, 0, NULL);
                                }
                            }
                        }
                        if (selectedcode == 1) {
                            {
                                if (GetAsyncKeyState(VK_HOME) & 0x8000)
                                {
                                    keybd_event('2', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('3', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('5', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('9', 0, 0, NULL);
                                }
                            }
                        }
                        if (selectedcode == 2) {
                            {
                                if (GetAsyncKeyState(VK_HOME) & 0x8000)
                                {
                                    keybd_event('2', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('4', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('8', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('5', 0, 0, NULL);
                                }
                            }
                        }
                        if (selectedcode == 3) {
                            {
                                if (GetAsyncKeyState(VK_HOME) & 0x8000)
                                {
                                    keybd_event('2', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('7', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('4', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('7', 0, 0, NULL);
                                }
                            }
                        }
                        if (selectedcode == 4) {
                            {
                                if (GetAsyncKeyState(VK_HOME) & 0x8000)
                                {
                                    keybd_event('4', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('5', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('6', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('8', 0, 0, NULL);
                                }
                            }
                        }
                        if (selectedcode == 5) {
                            {
                                if (GetAsyncKeyState(VK_HOME) & 0x8000)
                                {
                                    keybd_event('2', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('5', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('6', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('5', 0, 0, NULL);
                                }
                            }
                        }
                        if (selectedcode == 6) {
                            {
                                if (GetAsyncKeyState(VK_HOME) & 0x8000)
                                {
                                    keybd_event('4', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('3', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('5', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('3', 0, 0, NULL);
                                }
                            }
                        }
                        if (selectedcode == 7) {
                            {
                                if (GetAsyncKeyState(VK_HOME) & 0x8000)
                                {
                                    keybd_event('3', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('1', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('7', 0, 0, NULL);
                                    Sleep(70);
                                    keybd_event('8', 0, 0, NULL);
                                }
                            }
                        }
                    }
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(40);
                    ImGui::Checkbox("Auto Loot[CAPSLOCK]", &autoloot);
                    if (autoloot == true)
                    {

                        if (GetAsyncKeyState(VK_CAPITAL) & 0x8000)
                        {
                            if (autoloot == true)
                            {
                                keybd_event('H', 5, 5, 5);

                                SetCursorPos(1300, 310);
                                Sleep(25);
                                SetCursorPos(1400, 310);
                                Sleep(25);
                                SetCursorPos(1500, 310);
                                Sleep(25);
                                SetCursorPos(1600, 310);
                                Sleep(25);
                                SetCursorPos(1700, 310);
                                Sleep(25);
                                SetCursorPos(1800, 310);
                                Sleep(25);
                                SetCursorPos(1300, 310);
                                Sleep(25);

                                SetCursorPos(1300, 410);
                                Sleep(25);
                                SetCursorPos(1400, 410);
                                Sleep(25);
                                SetCursorPos(1500, 410);
                                Sleep(25);
                                SetCursorPos(1600, 410);
                                Sleep(25);
                                SetCursorPos(1700, 410);
                                Sleep(25);
                                SetCursorPos(1800, 410);
                                Sleep(25);
                                SetCursorPos(1300, 410);
                                Sleep(25);

                                SetCursorPos(1300, 510);
                                Sleep(25);
                                SetCursorPos(1400, 510);
                                Sleep(25);
                                SetCursorPos(1500, 510);
                                Sleep(25);
                                SetCursorPos(1600, 510);
                                Sleep(25);
                                SetCursorPos(1700, 510);
                                Sleep(25);
                                SetCursorPos(1800, 510);
                                Sleep(25);

                                SetCursorPos(1300, 610);
                                Sleep(25);
                                SetCursorPos(1400, 610);
                                Sleep(25);
                                SetCursorPos(1500, 610);
                                Sleep(25);
                                SetCursorPos(1600, 610);
                                Sleep(25);
                                SetCursorPos(1700, 610);
                                Sleep(25);
                                SetCursorPos(1800, 610);
                                Sleep(25);

                                SetCursorPos(1300, 710);
                                Sleep(25);
                                SetCursorPos(1400, 710);
                                Sleep(25);
                                SetCursorPos(1500, 710);
                                Sleep(25);
                                SetCursorPos(1600, 710);
                                Sleep(25);
                                SetCursorPos(1700, 710);
                                Sleep(25);
                                SetCursorPos(1800, 710);

                                SetCursorPos(1300, 810);
                                Sleep(25);
                                SetCursorPos(1400, 810);
                                Sleep(25);
                                SetCursorPos(1500, 810);
                                Sleep(25);
                                SetCursorPos(1600, 810);
                                Sleep(25);
                                SetCursorPos(1700, 810);
                                Sleep(25);
                                SetCursorPos(1800, 810);

                                SetCursorPos(1300, 910);
                                Sleep(25);
                                SetCursorPos(1400, 910);
                                Sleep(25);
                                SetCursorPos(1500, 910);
                                Sleep(25);
                                SetCursorPos(1600, 910);
                                Sleep(25);
                                SetCursorPos(1700, 910);
                                Sleep(25);
                                SetCursorPos(1800, 910);
                            }
                        }
                    }
                    ImGui::SetCursorPosX(250);
                    ImGui::SetCursorPosY(320);
                    if (ImGui::Button("Exit")) {
                        exit(1);    
                    }
                }
                if (titangui == 3) {
                    script();
                    ImGui::SetCursorPosX(82);
                    ImGui::PushFont(pFont);
                    ImGui::TextColored(ImVec4(0.91f, 0.64f, 0.13f, 1.00f), "TITAN");
                    ImGui::PopFont();
                    ImGui::SetCursorPosX(20);
                    if (ImGui::Button("Recoil", ImVec2(60, 20))) titangui = 1;
                    ImGui::SameLine();
                    if (ImGui::Button("Settings", ImVec2(60, 20))) titangui = 2;
                    ImGui::SameLine();
                    if (ImGui::Button("Config", ImVec2(60, 20))) titangui = 4;
                    ImGui::SameLine();
                    if (ImGui::Button("Keys", ImVec2(60, 20))) titangui = 3;
                    ImGui::Separator();
                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(80);
                    ImGui::Text("Weapon Keybinds:");
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(20);
                    ImGui::KeyBind("AK47", akbind, ImVec2(60, 20));
                    ImGui::SameLine(160);
                    ImGui::KeyBind("TOMMY", tmbind, ImVec2(60, 20));
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(20);
                    ImGui::KeyBind("LR300", lrbind, ImVec2(60, 20));
                    ImGui::SameLine(160);
                    ImGui::KeyBind("SAR", smbind, ImVec2(60, 20));
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(20);
                    ImGui::KeyBind("MP5A4", mpbind, ImVec2(60, 20));
                    ImGui::SameLine(160);
                    ImGui::KeyBind("M249", m2bind, ImVec2(60, 20));
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(20);
                    ImGui::KeyBind("CUSTOM", csbind, ImVec2(60, 20));
                    ImGui::SameLine(160);
                    ImGui::KeyBind("PYTHON", ptbind, ImVec2(60, 20));
                    ImGui::Spacing();
                    ImGui::Separator();
                    ImGui::Spacing();
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(80);
                    ImGui::Text("Scope Keybinds:");
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(20);
                    ImGui::KeyBind("HOLO", hhbind, ImVec2(60, 20));
                    ImGui::SameLine(160);
                    ImGui::KeyBind("8X", xxbind, ImVec2(60, 20));
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(20);
                    ImGui::KeyBind("SIMPLE", smbind, ImVec2(60, 20));
                    ImGui::SameLine(160);
                    ImGui::KeyBind("16X", yybind, ImVec2(60, 20));

                }
                if (titangui == 4) {
                    script();
                    ImGui::SetCursorPosX(82);
                    ImGui::PushFont(pFont);
                    ImGui::TextColored(ImVec4(0.91f, 0.64f, 0.13f, 1.00f), "TITAN");
                    ImGui::PopFont();
                    ImGui::SetCursorPosX(20);
                    if (ImGui::Button("Recoil", ImVec2(60, 20))) titangui = 1;
                    ImGui::SameLine();
                    if (ImGui::Button("Settings", ImVec2(60, 20))) titangui = 2;
                    ImGui::SameLine();
                    if (ImGui::Button("Config", ImVec2(60, 20))) titangui = 4;
                    ImGui::SameLine();
                    if (ImGui::Button("Keys", ImVec2(60, 20))) titangui = 3;
                    ImGui::Separator();
                    ImGui::Spacing();
                    ImGui::Text("");
                    ImGui::SameLine(50);
                    if (ImGui::Button("Config Save")) {
                        MessageBoxA(0, "Config created.", "INFO", MB_OK | MB_ICONINFORMATION);
                        config_create_kontrol231();
                        config_Write();
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("Config Load")) {
                        MessageBoxA(0, "Config loaded.", "INFO", MB_OK | MB_ICONINFORMATION);
                        config_data();
                    }
                    ImGui::Text("");
                    ImGui::SameLine(100);
                    if (ImGui::Button("Config Reset")) {
                        const int config_delete = MessageBox(NULL, "Reset config?", "INFO", MB_OKCANCEL | MB_ICONQUESTION);
                        switch (config_delete)
                        {
                        case IDOK:
                            MessageBoxA(0, "Config has been reset successfully!", "INFO", MB_OK | MB_ICONINFORMATION);
                            config_reset();
                            break;
                        case IDCANCEL:
                            MessageBoxA(0, "The transaction has been canceled.", "INFO", MB_OK | MB_ICONWARNING);
                            break;
                        }
                    }

                }
            }
            ImGui::End();
        }
        ImGui::EndFrame();

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        bool active = true;
        if (!active) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(main_hwnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

int main(); {
    KeyAuthApp.init();

    std::cout << "\n\n [1] Login\n\n Choose option: (Write 1)";

    int option;
    std::string key;

    std::cin >> option;
    switch (option)
    {
    case 1:
        std::cout << "\n Enter license: ";
        std::cin >> key;
        KeyAuthApp.license(key);
        break;
    default:
        std::cout << "\n\n Status: Failure: Invalid Selection";
        Sleep(3000);
        exit(0);
    }
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    WinMain1(0, 0, 0, 0);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu225
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}