
#include <Windows.h>
#include <vector>
#include "RecoilTables.h"
#include "Recoil.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include "config.h"
#include <winbase.h>
#include <tchar.h>
#include <WinInet.h>

static bool codelock = false;
static bool autoloot = false;
static bool hip_active = false;
static bool BSound = true;
static int XSCALE = 1;
static int YSCALE = 1;
static bool resetbut, random_active, show_random, randomonline, randomxy_active, show_xycontrol, controlxy_active = false;
const char* Weapon = "NONE";
const char* Scope = "NONE";
const char* Barrel = "NONE";
const char* Mode = "NONE";
bool _showAnotherWindow3 = false;
static const char* priorty[] = { "Priorty REALTIME", "Priorty High", "Priorty Normal", "Priorty Low" };
static int selectedpriorty = 0;
bool hidetokernel = false;

bool bReload, bAK47, bLR300, bMP5, bCSMG, bSemi, Bhardak, bPhyton, bTHOMPSON, bm39, bM249, bSound, b8x, b16x, bHolo, bSimple, bSuppressor, bhýp, bMuzzleBoost, bHipFire, bLegitMode, brapidfire = false;


static int selectedItemBR = 0;
static int selectedItemSC = 0;
static int selectedItemWP = 0;

static const char* itemWP[]{ Weapon,
"AK47",
"LR300",
"MP5A4",
"CUSTOM",
"TOMMY",
"SEMI",
"M249",
"PYTHON"
};
static const char* itemSC[]{ Scope,
"8x",
"16x",
"HOLO",
"SIMPLE"
};
static const char* itemBR[]{ Barrel,
"Silencer",
};
static const char* code[] = { "7548", "2359","2485", "2747", "4568", "2565", "4353", "3178" };

float Sensitivity = 0.2;

namespace CurrentWeapon {
    double x(int Bullet) {
        if (randomxy_active == false) {

            if (bAK47 == true)
                return (((Recoil_Ak47[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else if (bLR300 == true)
                return (((Recoil_Lr300[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else if (bMP5 == true)
                return (((Recoil_Mp5a4[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else if (bTHOMPSON == true)
                return (((Recoil_Thompson_g[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else if (bCSMG == true)
                return (((Recoil_Custom_g[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else if (bM249 == true)
                return (((Recoil_M249[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else if (bSemi == true)
                return (((Recoil_Semi_r[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else if (bm39 == true)
                return (((Recoil_m39[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else if (bPhyton == true)
                return (((Recoil_Phyton[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / XCONTROL;
            else
                return 0;
        }
        if (randomxy_active == true) {                                                                 //X RANDOMIZATION ON AND OFF
            if (bAK47) {
                return ((Recoil_Ak47[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else if (bLR300) {
                return ((Recoil_Lr300[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else if (bMP5) {
                return ((Recoil_Mp5a4[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else if (bTHOMPSON) {
                return ((Recoil_Thompson_g[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else if (bCSMG) {
                return ((Recoil_Custom_g[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else if (bM249) {
                return ((Recoil_M249[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else if (bSemi) {
                return ((Recoil_Semi_r[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else if (bPhyton) {
                return ((Recoil_Phyton[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else if (bm39) {
                return ((Recoil_m39[Bullet].x * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / XCONTROL + rand() % (XSCALE + XSCALE) + (-XSCALE);
            }
            else
                return 0;
        }
    }
    double y(int Bullet) {
        if (randomxy_active == false) {

            if (bAK47 == true)
                return (((Recoil_Ak47[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else if (bLR300 == true)
                return (((Recoil_Lr300[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else if (bMP5 == true)
                return (((Recoil_Mp5a4[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else if (bTHOMPSON == true)
                return (((Recoil_Thompson_g[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else if (bCSMG == true)
                return (((Recoil_Custom_g[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else if (bM249 == true)
                return (((Recoil_M249[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else if (bSemi == true)
                return (((Recoil_Semi_r[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else if (bm39 == true)
                return (((Recoil_m39[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else if (Bhardak == true)
                return (((Recoil_Phyton[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4) / Sensitivity / YCONTROL;
            else
                return 0;
        }
        if (randomxy_active == true) {


            if (bAK47) {
                return ((Recoil_Ak47[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);
            }
            else if (bLR300) {
                return ((Recoil_Lr300[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
            }
            else if (bMP5) {
                return ((Recoil_Mp5a4[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
            }
            else if (bTHOMPSON) {
                return ((Recoil_Thompson_g[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
            }
            else if (bCSMG) {
                return ((Recoil_Custom_g[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
            }
            else if (bM249) {
                return ((Recoil_M249[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
            }
            else if (bSemi) {
                return ((Recoil_Semi_r[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
            }
            else if (Bhardak) {
                return ((Recoil_Phyton[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
            }
            else if (bm39) {
                return ((Recoil_m39[Bullet].y * ScopeAttachment()) * BarrelAttachment()) / 4 / Sensitivity / YCONTROL + rand() % (YSCALE + YSCALE) + (-YSCALE);;
            }
            else
                return 0;
        }

    }

    double Delay() {
        if (bAK47 == true)
            return WeaponData::AK47.Delay;
        else if (bLR300 == true)
            return WeaponData::LR300.Delay;
        else if (bMP5 == true)
            return WeaponData::MP5.Delay;
        else if (bTHOMPSON == true)
            return WeaponData::THOMPSON.Delay;
        else if (bCSMG == true)
            return WeaponData::CUSTOM_SMG.Delay;
        else if (bM249 == true)
            return WeaponData::M249.Delay;
        else if (bSemi == true)
            return WeaponData::SEMI.Delay;
        else if (bm39 == true)
            return WeaponData::m39.Delay;
        else if (bPhyton == true)
            return WeaponData::Phyton.Delay;

        else
            return 0;
    }
    double Control(int bullet) {
        if (bAK47 == true)
            return ControlTime_Ak47[bullet];
        else if (bLR300 == true)
            return ControlTime_Lr300[bullet];
        else if (bMP5 == true)
            return ControlTime_Mp5a4[bullet];
        else if (bTHOMPSON == true)
            return ControlTime_Recoil_Thompson_g[bullet];
        else if (bCSMG == true)
            return ControlTime_Recoil_Custom_g[bullet];
        else if (bM249 == true)
            return WeaponData::M249.Delay;
        else if (bSemi == true)
            return WeaponData::SEMI.Delay;
        else if (bm39 == true)
            return WeaponData::m39.Delay;
        else if (bPhyton == true)
            return WeaponData::Phyton.Delay;
        else
            return 0;
    }
    int Bullet() {
        if (bAK47 == true)
            return Recoil_Ak47.size() - 1;
        else if (bLR300 == true)
            return Recoil_Lr300.size() - 1;
        else if (bMP5 == true)
            return Recoil_Mp5a4.size() - 1;
        else if (bm39 == true)
            return Recoil_m39.size() - 1;
        else if (bTHOMPSON == true)
            return Recoil_Thompson_g.size() - 1;
        else if (bCSMG == true)
            return Recoil_Custom_g.size() - 1;
        else if (bM249 == true)
            return Recoil_M249.size() - 1;
        else if (bSemi == true)
            return Recoil_Semi_r.size() - 1;
        else if (bPhyton == true)
            return Recoil_Phyton.size() - 1;
        else
            return 0;
    }
    bool WeaponActive() {
        if (bAK47 == true || bLR300 == true || bMP5 == true || bTHOMPSON == true || bCSMG == true || bSemi == true || bM249 == true)
            return true;
        else
            return false;
    }
    void RecoilBreak(int count) {
        if (bSemi == true) {
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        else if (bM249 == true) {
        }
        else if (bSemi != true || bM249 != true) {
            if (count == CurrentWeapon::Bullet()) {
                if (bSound == true) {
                    Beep(1200, 90);
                    Beep(1500, 90);
                }
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            }
        }
    }
};

void Smoothing(double delay, double control_time, int x, int y) {
    int x_ = 0, y_ = 0, t_ = 0;
    for (int i = 1; i <= (int)control_time; ++i) {
        int xI = i * x / (int)control_time;
        int yI = i * y / (int)control_time;
        int tI = i * (int)control_time / (int)control_time;
        mouse_event(1, (int)xI - (int)x_, (int)yI - (int)y_, 0, 0);
        pQuerySleep((int)tI - (int)t_);
        x_ = xI; y_ = yI; t_ = tI;
    }
    pQuerySleep((int)delay - (int)control_time);
}

int IsMuzzleBoost(float Delay) {
    if (bMuzzleBoost == true) {
        float difference = Delay * 0.1f;
        Delay = Delay - difference;
        return (int)Delay + 2;
    }
    else
        return (int)Delay;
}

double BarrelAttachment() {
    if (bSuppressor == true) {
        if (bM249 == true)
            Multiplyer::Barrel.Suppressor = 0.75;
        if (bCSMG == true)
            Multiplyer::Barrel.Suppressor = 0.85;
        if (bSimple == true || bHolo == true)
            return 0.75;
        if (b8x == true && bSuppressor == true)
            return 1.46;
        else
            return Multiplyer::Barrel.Suppressor;
    }
    else if (bMuzzleBoost == true) {
        return Multiplyer::Barrel.None;
    }
    else
        return Multiplyer::Barrel.None;
}
double ScopeAttachment() {
    if (b8x == true) {
        if (bCSMG == true || bTHOMPSON == true) {
            if (b8x == true)
                return Multiplyer::Scope.x8 + 0.75;
        }
        return Multiplyer::Scope.x8;
    }
    if (b16x == true) {
        if (bCSMG == true || bTHOMPSON == true) {
            if (b16x == true)
                return Multiplyer::Scope.x16 + 0.75;
        }
        return Multiplyer::Scope.x16;
    }
    else if (bSimple == true) {
        if (bCSMG == true || bTHOMPSON == true) {
            if (bSimple == true)
                return Multiplyer::Scope.Simple + 0.1;
        }
        return Multiplyer::Scope.Simple;
    }

    else if (bHolo == true) {
        if (bCSMG == true || bTHOMPSON == true) {
            if (bHolo == true)
                return Multiplyer::Scope.Holo + 0.3;
        }
        return Multiplyer::Scope.Holo;
    }
    else
        return Multiplyer::Scope.None;
}

void pQuerySleep(int ms)
{
    LONGLONG timerResolution;
    LONGLONG wantedTime;
    LONGLONG currentTime;

    QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
    timerResolution /= 1000;

    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
    wantedTime = currentTime / timerResolution + ms;
    currentTime = 0;
    while (currentTime < wantedTime)
    {
        QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
        currentTime /= timerResolution;
    }
}

void script()
{
    if (GetAsyncKeyState(VK_NUMPAD0)) {
        if (bm39 == false) {
            Weapon = "NONE";
            bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bM249 = false; bAK47 = false;
        }
        if (GetAsyncKeyState(VK_NUMPAD0)) {
            Weapon = "NONE"; Scope = "NONE"; Barrel = "NONE"; Mode = "NONE";
            b8x = false; bHolo = false; bSimple = false; bSuppressor = false; b16x = false; bHipFire = false; bLegitMode = false;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(akbind)) {
        bAK47 = !bAK47;
        if (bAK47 == true) {
            selectedItemWP = 1;
            Weapon = "AK47";
            bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bM249 = false;
        }
        else if (bAK47 == false) {
            selectedItemWP = 0;
            Weapon = "NONE"; Scope = "NONE"; Barrel = "NONE";
            b8x = false; bHolo = false; bSimple = false; bSuppressor = false; b16x = false;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(lrbind)) {
        bLR300 = !bLR300;
        if (bLR300 == true) {
            selectedItemWP = 2;
            Weapon = "LR300";
            bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bM249 = false; bAK47 = false;
        }
        else if (bLR300 == false) {
            selectedItemWP = 0;
            Weapon = "NONE"; Scope = "NONE"; Barrel = "NONE";
            b8x = false; bHolo = false; bSimple = false; bSuppressor = false; b16x = false;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(mpbind)) {
        selectedItemWP = 3;
        bMP5 = !bMP5;
        if (bMP5 == true) {
            Weapon = "MP5A4";
            bLR300 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bM249 = false; bAK47 = false;
        }
        else if (bMP5 == false) {
            selectedItemWP = 0;
            Weapon = "NONE"; Scope = "NONE"; Barrel = "NONE";
            b8x = false; bHolo = false; bSimple = false; bSuppressor = false; b16x = false;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(csbind)) {
        bCSMG = !bCSMG;
        if (bCSMG == true) {
            selectedItemWP = 4;
            Weapon = "CUSTOM_SMG";
            bLR300 = false; bMP5 = false; bTHOMPSON = false; bSemi = false; bM249 = false; bAK47 = false;
        }
        else if (bCSMG == false) {
            selectedItemWP = 0;
            Weapon = "NONE"; Scope = "NONE"; Barrel = "NONE";
            b8x = false; bHolo = false; bSimple = false; bSuppressor = false; b16x = false;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(tmbind)) {
        bTHOMPSON = !bTHOMPSON;
        if (bTHOMPSON == true) {
            selectedItemWP = 5;
            Weapon = "THOMPSON";
            bLR300 = false; bMP5 = false; bCSMG = false; bSemi = false; bM249 = false; bAK47 = false;
        }
        else if (bTHOMPSON == false) {
            selectedItemWP = 0;
            Weapon = "NONE"; Scope = "NONE"; Barrel = "NONE";
            b8x = false; bHolo = false; bSimple = false; bSuppressor = false; b16x = false;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(smbind)) {
        bSemi = !bSemi;
        if (bSemi == true) {
            selectedItemWP = 6;
            Weapon = "SEMI AUTO";
            bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bM249 = false; bAK47 = false;
        }
        else if (bSemi == false) {
            selectedItemWP = 0;
            Weapon = "NONE"; Scope = "NONE"; Barrel = "NONE";
            b8x = false; bHolo = false; bSimple = false; bSuppressor = false; b16x = false;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(m2bind)) {
        bM249 = !bM249;
        if (bM249 == true) {
            selectedItemWP = 7;
            Weapon = "M249";
            bLR300 = false; bMP5 = false; bCSMG = false; bTHOMPSON = false; bSemi = false; bAK47 = false;
        }
        else if (bM249 == false) {
            selectedItemWP = 0;
            Weapon = "NONE"; Scope = "NONE"; Barrel = "NONE";
            b8x = false; bHolo = false; bSimple = false; bSuppressor = false; b16x = false;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(xxbind)) {
        b8x = !b8x;
        switch (b8x) {
        case(true):
            selectedItemSC = 1;
            Scope = "8x"; bHolo = false; bSimple = false; b16x = false;
            break;
        case(false):
            selectedItemSC = 0;
            Scope = "NONE";
            break;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(VK_NUMPAD8)) {
        bHipFire = !bHipFire;
        switch (bHipFire) {
        case(true):
            Mode = "HipFire"; bLegitMode = false;
            break;
        case(false):
            Mode = "NONE";
            break;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(VK_NUMPAD9)) {
        bLegitMode = !bLegitMode;
        switch (bLegitMode) {
        case(true):
            Mode = "LegitMode"; bHipFire = false;
            break;
        case(false):
            Mode = "NONE";
            break;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(yybind)) {
        b16x = !b16x;
        switch (b16x) {
        case(true):
            selectedItemSC = 2;
            Scope = "16x"; bHolo = false; bSimple = false; b8x = false;
            break;
        case(false):
            selectedItemSC = 0;
            Scope = "NONE";
            break;
        }
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(ssbind)) {
        bSimple = !bSimple;
        if (bSimple == true) {
            selectedItemSC = 4;
            Scope = "SIMPLE"; b8x = false; bHolo = false; b16x = false;
        }
        else if (bSimple == false)
            selectedItemSC = 0;
        Scope = "NONE";
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(hhbind)) {
        bHolo = !bHolo;
        if (bHolo == true) {
            selectedItemSC = 3;
            Scope = "HOLO"; b8x = false; bSimple = false; b16x = false;
        }
        else if (bHolo == false)
            selectedItemSC = 0;
        Scope = "NONE";
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(slbind)) {
        bSuppressor = !bSuppressor;
        if (bSuppressor == true) {
            selectedItemBR = 1;
            Barrel = "SILENCER"; bMuzzleBoost = false;
        }
        else if (bSuppressor == false)
            selectedItemBR = 0;
        Barrel = "NONE";
        if (BSound == true) {
            Beep(180, 200);
        }
    }
    if (GetAsyncKeyState(VK_F12)) {
        keybd_event(VK_F1, 0, 0, 0);
    }
    if (CurrentWeapon::WeaponActive() == true)
    {
        if (hip_active == false)
        {
            for (int i = 0; i <= CurrentWeapon::Bullet() && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000; i++)
            {
                Smoothing((int)IsMuzzleBoost((float)CurrentWeapon::Delay()), (int)IsMuzzleBoost(CurrentWeapon::Control(i)), (int)CurrentWeapon::x(i), (int)CurrentWeapon::y(i));
                CurrentWeapon::RecoilBreak(i);
            }
            Sleep(1); // Rest CPU
        }
        else
        {
            for (int i = 0; i <= CurrentWeapon::Bullet() && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && GetAsyncKeyState(VK_RBUTTON) & 0x8000; i++)
            {
                Smoothing((int)IsMuzzleBoost((float)CurrentWeapon::Delay()), (int)IsMuzzleBoost(CurrentWeapon::Control(i)), (int)CurrentWeapon::x(i), (int)CurrentWeapon::y(i));
                CurrentWeapon::RecoilBreak(i);
            }
            Sleep(1); // Rest CPU

            for (int i = 0; i <= CurrentWeapon::Bullet() && GetAsyncKeyState(VK_LBUTTON) & 0x8000 && hip_active; i++)
            {
                Smoothing((int)IsMuzzleBoost((float)CurrentWeapon::Delay()), (int)IsMuzzleBoost(CurrentWeapon::Control(i)), (int)CurrentWeapon::x(i) * 0.6, (int)CurrentWeapon::y(i) * 0.6);
                CurrentWeapon::RecoilBreak(i);
            }
            Sleep(1); // Rest CPU
        }
    }
    Sleep(1); // Rest CPU

}
