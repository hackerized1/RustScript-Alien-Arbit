#include <fstream>
#include <direct.h>

using namespace std;

static int akbind = 97;
static int lrbind = 98;
static int hsbind = 0;
static int crossbind = 0;
static int mpbind = 99;
static int csbind = 100;
static int tmbind = 101;
static int smbind = 102;
static int m2bind = 103;
static int ptbind = 104;
static int xxbind = 113;//8x
static int yybind = 114;//16x
static int hhbind = 115;//holo
static int ssbind = 116;//simple
static int slbind = 117;//simple
static int bobind = 118;//simple
static int rpbind = 0;//simple
static int resbind = 0;
static float XCONTROL = 1;
static float YCONTROL = 1;

ofstream file_olusturma_yazma;
ofstream file_olusturma_yazma2;
ofstream file_olusturma_yazma3;
ofstream file_olusturma_yazma4;
ofstream file_olusturma_yazma5;
ofstream file_olusturma_yazma6;
ofstream file_olusturma_yazma7;
ofstream file_olusturma_yazma8;
ofstream file_olusturma_yazma9;
ofstream file_olusturma_yazma10;
ofstream file_olusturma_yazma11;
ofstream file_olusturma_yazma12;
ofstream file_olusturma_yazma13;
ofstream file_olusturma_yazma14;
ofstream file_olusturma_yazma15;
ofstream file_olusturma_yazma16;
ifstream file_olusturma_okuma("C:\\Config\\sensivity_1.txt");
ifstream file_olusturma_okuma2("C:\\Config\\akbind.txt");
ifstream file_olusturma_okuma3("C:\\Config\\lrbind.txt");
ifstream file_olusturma_okuma4("C:\\Config\\mpbind.txt");
ifstream file_olusturma_okuma5("C:\\Config\\csbind.txt");
ifstream file_olusturma_okuma6("C:\\Config\\tmbind.txt");
ifstream file_olusturma_okuma7("C:\\Config\\smbind.txt");
ifstream file_olusturma_okuma8("C:\\Config\\m2bind.txt");
ifstream file_olusturma_okuma9("C:\\Config\\ptbind.txt");
ifstream file_olusturma_okuma10("C:\\Config\\xxbind.txt");
ifstream file_olusturma_okuma11("C:\\Config\\yybind.txt");
ifstream file_olusturma_okuma12("C:\\Config\\hhbind.txt");
ifstream file_olusturma_okuma13("C:\\Config\\ssbind.txt");
ifstream file_olusturma_okuma14("C:\\Config\\slbind.txt");
ifstream file_olusturma_okuma15("C:\\Config\\xcontrol_1.txt");
ifstream file_olusturma_okuma16("C:\\Config\\ycontrol_1.txt");

void klasor_kontrol31() {

    if (_mkdir("C:\\Config") == 0) {


    }
    else {

    }

}

void config_reset() {


    file_olusturma_yazma.open("C:\\Config\\sensivity_1.txt");
    //   file_olusturma_yazma << "Sensivity: {}", weapon_sens; 
    file_olusturma_yazma << "" << std::fixed << "" << "\n";
    file_olusturma_yazma.close();
    akbind = 96;
    lrbind = 97;
    mpbind = 98;
    csbind = 99;
    tmbind = 100;
    smbind = 101;
    m2bind = 102;
    ptbind = 104;
    xxbind = 113;//8x
    yybind = 114;//16x
    hhbind = 115;//holo
    ssbind = 116;//simple
    slbind = 117;//simple
    rpbind = 0;//simple
    resbind = 0;
    XCONTROL = 1;
    YCONTROL = 1;
    file_olusturma_yazma2.open("C:\\Config\\akbind.txt");
    file_olusturma_yazma2 << "" << std::fixed << "" << "\n";
    file_olusturma_yazma2.close();
}
void config_create_kontrol231() {

    string path = "C:\\Config\\sensivity_1.txt";
    string path2 = "C:\\Config\\akbind.txt";
    string path3 = "C:\\Config\\lrbind.txt";
    string path4 = "C:\\Config\\mpbind.txt";
    string path5 = "C:\\Config\\csbind.txt";
    string path6 = "C:\\Config\\tmbind.txt";
    string path7 = "C:\\Config\\smbind.txt";
    string path8 = "C:\\Config\\m2bind.txt";
    string path9 = "C:\\Config\\ptbind.txt";
    string path10 = "C:\\Config\\xxbind.txt";
    string path11 = "C:\\Config\\yybind.txt";
    string path12 = "C:\\Config\\hhbind.txt";
    string path13 = "C:\\Config\\ssbind.txt";
    string path14 = "C:\\Config\\slbind.txt";
    string path15 = "C:\\Config\\xcontrol_1.txt";
    string path16 = "C:\\Config\\ycontrol_1.txt";
    ifstream fin(path);
    ifstream fin2(path2);
    ifstream fin3(path3);
    ifstream fin4(path4);
    ifstream fin5(path5);
    ifstream fin6(path6);
    ifstream fin7(path7);
    ifstream fin8(path8);
    ifstream fin9(path9);
    ifstream fin10(path10);
    ifstream fin11(path11);
    ifstream fin12(path12);
    ifstream fin13(path13);
    ifstream fin14(path14);
    ifstream fin15(path15);
    ifstream fin16(path16);

    if (fin.is_open()) {
    }
    else {
        file_olusturma_yazma.open("C:\\Config\\sensivity_1.txt");
    }
    if (fin2.is_open()) {
    }
    else {
        file_olusturma_yazma2.open("C:\\Config\\akbind.txt");
    }
    if (fin3.is_open()) {
    }
    else {
        file_olusturma_yazma3.open("C:\\Config\\lrbind.txt");
    }
    if (fin4.is_open()) {
    }
    else {
        file_olusturma_yazma4.open("C:\\Config\\mpbind.txt");
    }
    if (fin5.is_open()) {
    }
    else {

        file_olusturma_yazma5.open("C:\\Config\\csbind.txt");
    }
    if (fin6.is_open()) {
    }
    else {
        file_olusturma_yazma6.open("C:\\Config\\tmbind.txt");
    }
    if (fin7.is_open()) {
    }
    else {

        file_olusturma_yazma7.open("C:\\Config\\smbind.txt");
    }
    if (fin8.is_open()) {
    }
    else {
        file_olusturma_yazma8.open("C:\\Config\\m2bind.txt");
    }
    if (fin9.is_open()) {
    }
    else {

        file_olusturma_yazma9.open("C:\\Config\\ptbind.txt");
    }
    if (fin10.is_open()) {
    }
    else {

        file_olusturma_yazma10.open("C:\\Config\\xxbind.txt");
    }
    if (fin11.is_open()) {
    }
    else {

        file_olusturma_yazma11.open("C:\\Config\\yybind.txt");
    }
    if (fin12.is_open()) {
    }
    else {

        file_olusturma_yazma12.open("C:\\Config\\hhbind.txt");
    }
    if (fin13.is_open()) {
    }
    else {

        file_olusturma_yazma13.open("C:\\Config\\ssbind.txt");
    }
    if (fin14.is_open()) {
    }
    else {

        file_olusturma_yazma14.open("C:\\Config\\slbind.txt");
    }
    if (fin15.is_open()) {
    }
    else {

        file_olusturma_yazma15.open("C:\\Config\\xcontrol_1.txt");
    }
    if (fin16.is_open()) {
    }
    else {
        file_olusturma_yazma16.open("C:\\Config\\ycontrol_1.txt");
    }
    if (fin.fail()) {

        file_olusturma_yazma.open("C:\\Config\\sensivity_1.txt");
        file_olusturma_yazma2.open("C:\\Config\\akbind.txt");
        file_olusturma_yazma3.open("C:\\Config\\lrbind.txt");
        file_olusturma_yazma4.open("C:\\Config\\mpbind.txt");
        file_olusturma_yazma5.open("C:\\Config\\csbind.txt");
        file_olusturma_yazma6.open("C:\\Config\\tmbind.txt");
        file_olusturma_yazma7.open("C:\\Config\\smbind.txt");
        file_olusturma_yazma8.open("C:\\Config\\m2bind.txt");
        file_olusturma_yazma9.open("C:\\Config\\ptbind.txt");
        file_olusturma_yazma10.open("C:\\Config\\xxbind.txt");
        file_olusturma_yazma11.open("C:\\Config\\yybind.txt");
        file_olusturma_yazma12.open("C:\\Config\\hhbind.txt");
        file_olusturma_yazma13.open("C:\\Config\\ssbind.txt");
        file_olusturma_yazma14.open("C:\\Config\\slbind.txt");
        file_olusturma_yazma15.open("C:\\Config\\xcontrol_1.txt");
        file_olusturma_yazma16.open("C:\\Config\\ycontrol_1.txt");
    }
    else {
    }
}

void config_Write() {

    file_olusturma_yazma2.open("C:\\Config\\akbind.txt");
    file_olusturma_yazma2 << "" << std::fixed << akbind << "\n";
    file_olusturma_yazma3.open("C:\\Config\\lrbind.txt");
    file_olusturma_yazma3 << "" << std::fixed << lrbind << "\n";
    file_olusturma_yazma4.open("C:\\Config\\mpbind.txt");
    file_olusturma_yazma4 << "" << std::fixed << mpbind << "\n";
    file_olusturma_yazma5.open("C:\\Config\\csbind.txt");
    file_olusturma_yazma5 << "" << std::fixed << csbind << "\n";
    file_olusturma_yazma6.open("C:\\Config\\tmbind.txt");
    file_olusturma_yazma6 << "" << std::fixed << tmbind << "\n";
    file_olusturma_yazma7.open("C:\\Config\\smbind.txt");
    file_olusturma_yazma7 << "" << std::fixed << smbind << "\n";
    file_olusturma_yazma8.open("C:\\Config\\m2bind.txt");
    file_olusturma_yazma8 << "" << std::fixed << m2bind << "\n";
    file_olusturma_yazma9.open("C:\\Config\\ptbind.txt");
    file_olusturma_yazma9 << "" << std::fixed << ptbind << "\n";
    file_olusturma_yazma10.open("C:\\Config\\xxbind.txt");
    file_olusturma_yazma10 << "" << std::fixed << xxbind << "\n";
    file_olusturma_yazma11.open("C:\\Config\\yybind.txt");
    file_olusturma_yazma11 << "" << std::fixed << yybind << "\n";
    file_olusturma_yazma12.open("C:\\Config\\hhbind.txt");
    file_olusturma_yazma12 << "" << std::fixed << hhbind << "\n";
    file_olusturma_yazma13.open("C:\\Config\\ssbind.txt");
    file_olusturma_yazma13 << "" << std::fixed << ssbind << "\n";
    file_olusturma_yazma14.open("C:\\Config\\slbind.txt");
    file_olusturma_yazma14 << "" << std::fixed << slbind << "\n";
    file_olusturma_yazma15.open("C:\\Config\\xcontrol_1.txt");
    file_olusturma_yazma15 << "" << std::fixed << XCONTROL << "\n";
    file_olusturma_yazma16.open("C:\\Config\\ycontrol_1.txt");
    file_olusturma_yazma16 << "" << std::fixed << YCONTROL << "\n";
    file_olusturma_yazma.close();
    file_olusturma_yazma2.close();
    file_olusturma_yazma3.close();
    file_olusturma_yazma4.close();
    file_olusturma_yazma5.close();
    file_olusturma_yazma6.close();
    file_olusturma_yazma7.close();
    file_olusturma_yazma8.close();
    file_olusturma_yazma9.close();
    file_olusturma_yazma10.close();
    file_olusturma_yazma11.close();
    file_olusturma_yazma12.close();
    file_olusturma_yazma13.close();
    file_olusturma_yazma14.close();
    file_olusturma_yazma15.close();
    file_olusturma_yazma16.close();
}

void config_data() {
    ifstream file_olusturma_okuma;
    ifstream file_olusturma_okuma2;
    ifstream file_olusturma_okuma3;
    ifstream file_olusturma_okuma4;
    ifstream file_olusturma_okuma5;
    ifstream file_olusturma_okuma6;
    ifstream file_olusturma_okuma7;
    ifstream file_olusturma_okuma8;
    ifstream file_olusturma_okuma9;
    ifstream file_olusturma_okuma10;
    ifstream file_olusturma_okuma11;
    ifstream file_olusturma_okuma12;
    ifstream file_olusturma_okuma13;
    ifstream file_olusturma_okuma14;
    ifstream file_olusturma_okuma15;
    ifstream file_olusturma_okuma16;
    file_olusturma_okuma.open("C:\\Config\\sensivity_1.txt");
    file_olusturma_okuma2.open("C:\\Config\\akbind.txt");
    file_olusturma_okuma3.open("C:\\Config\\lrbind.txt");
    file_olusturma_okuma4.open("C:\\Config\\mpbind.txt");
    file_olusturma_okuma5.open("C:\\Config\\csbind.txt");
    file_olusturma_okuma6.open("C:\\Config\\tmbind.txt");
    file_olusturma_okuma7.open("C:\\Config\\smbind.txt");
    file_olusturma_okuma8.open("C:\\Config\\m2bind.txt");
    file_olusturma_okuma9.open("C:\\Config\\ptbind.txt");
    file_olusturma_okuma10.open("C:\\Config\\xxbind.txt");
    file_olusturma_okuma11.open("C:\\Config\\yybind.txt");
    file_olusturma_okuma12.open("C:\\Config\\hhbind.txt");
    file_olusturma_okuma13.open("C:\\Config\\ssbind.txt");
    file_olusturma_okuma14.open("C:\\Config\\slbind.txt");
    file_olusturma_okuma15.open("C:\\Config\\xcontrol_1.txt");
    file_olusturma_okuma16.open("C:\\Config\\ycontrol_1.txt");

    float cCc2;
    while (file_olusturma_okuma2 >> cCc2) {
        cout << cCc2;

        akbind = cCc2;
    }
    float cCc3;
    while (file_olusturma_okuma3 >> cCc3) {
        cout << cCc3;

        lrbind = cCc3;
    }
    float cCc4;
    while (file_olusturma_okuma4 >> cCc4) {
        cout << cCc4;

        mpbind = cCc4;
    }
    float cCc5;
    while (file_olusturma_okuma5 >> cCc5) {
        cout << cCc5;

        csbind = cCc5;
    }
    float cCc6;
    while (file_olusturma_okuma6 >> cCc6) {
        cout << cCc6;

        tmbind = cCc6;
    }
    float cCc7;
    while (file_olusturma_okuma7 >> cCc7) {
        cout << cCc7;

        smbind = cCc7;
    }
    float cCc8;
    while (file_olusturma_okuma8 >> cCc8) {
        cout << cCc8;

        m2bind = cCc8;
    }
    float cCc9;
    while (file_olusturma_okuma9 >> cCc9) {
        cout << cCc9;

        ptbind = cCc9;
    }
    float cCc10;
    while (file_olusturma_okuma10 >> cCc10) {
        cout << cCc10;

        xxbind = cCc10;
    }
    float cCc11;
    while (file_olusturma_okuma11 >> cCc11) {
        cout << cCc11;

        yybind = cCc11;
    }
    float cCc12;
    while (file_olusturma_okuma12 >> cCc12) {
        cout << cCc12;

        hhbind = cCc12;
    }
    float cCc13;
    while (file_olusturma_okuma13 >> cCc13) {
        cout << cCc13;

        ssbind = cCc13;
    }
    float cCc14;
    while (file_olusturma_okuma14 >> cCc14) {
        cout << cCc14;

        slbind = cCc14;
    }
    float cCc15;
    while (file_olusturma_okuma15 >> cCc15) {
        cout << cCc15;

        XCONTROL = cCc15;
    }
    float cCc16;
    while (file_olusturma_okuma16 >> cCc16) {
        cout << cCc16;

        YCONTROL = cCc16;
    }
    file_olusturma_okuma.close();
    file_olusturma_okuma2.close();
    file_olusturma_okuma3.close();
    file_olusturma_okuma4.close();
    file_olusturma_okuma5.close();
    file_olusturma_okuma6.close();
    file_olusturma_okuma7.close();
    file_olusturma_okuma8.close();
    file_olusturma_okuma9.close();
    file_olusturma_okuma10.close();
    file_olusturma_okuma11.close();
    file_olusturma_okuma12.close();
    file_olusturma_okuma13.close();
    file_olusturma_okuma14.close();
    file_olusturma_okuma15.close();
    file_olusturma_okuma16.close();
}
