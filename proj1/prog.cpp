#include "prog.h"
#include <WinUser.h>
#include <Windows.h>
#include <iostream>

using std::cout;
using std::endl;

static HANDLE mutexHandle;

/// ensure the autoruns value is set for the program
void ensureAutoruns() {
    // path to the current process
    LPSTR path = new char[MAX_PATH];
    if (!GetModuleFileNameA(nullptr, path, MAX_PATH)) {
        cout << "Could not get the module filename" << endl;
        exit(FAILURE_EXIT_CODE);
    }

    HKEY hkey;
    LSTATUS openStatus = RegOpenKeyExA(HKEY_CURRENT_USER, AUTORUNS_RG_SUBKEY, 0, KEY_ALL_ACCESS, &hkey);
    if (openStatus != ERROR_SUCCESS) {
        cout << "Could not open the autorun registry key" << endl;
        exit(FAILURE_EXIT_CODE);
    }

    LSTATUS valueExists = RegQueryValueExA(hkey, AUTORUNS_VALUE_NAME, nullptr, nullptr, nullptr, nullptr);
    if (valueExists != ERROR_SUCCESS) {
        LSTATUS createStatus =
            RegSetValueExA(hkey, AUTORUNS_VALUE_NAME, 0, REG_SZ, const_cast<const BYTE*>(reinterpret_cast<BYTE*>(path)),
                           static_cast<DWORD>(strlen(path) + 1));
        if (createStatus != ERROR_SUCCESS) {
            cout << "Could not set the autorun registry value" << endl;
            exit(FAILURE_EXIT_CODE);
        }
    }
    RegCloseKey(hkey);
    delete[] path;
}

/// initialize all the dependencies for the program
void initProgram() {
    mutexHandle = CreateMutexA(nullptr, true, MUTEX_NAME);

    if (!mutexHandle) {
        cout << "Lock creation has failed" << endl;
        exit(FAILURE_EXIT_CODE);
    }

    // although we do set bInitialOwner to be true, lets just be sure that we are the owners
    DWORD waitResult = WaitForSingleObject(mutexHandle, 0);
    if (waitResult != WAIT_OBJECT_0) {
        cout << "Taking ownership of the lock has failed" << endl;
        exit(FAILURE_EXIT_CODE);
    }
    atexit([]() { ReleaseMutex(mutexHandle); });
    ensureAutoruns();
}

/// function for running the technician program
void prog::technician() {

    initProgram();
    MessageBoxA(nullptr, "MANAGEMENT PROGRAM IS UP", "Management Program", MB_OK);
    Sleep(MS_IN_HOUR);
}
