#include "prog.h"
#include <WinUser.h>
#include <Windows.h>
#include <iostream>

using prog::AutorunsRegKeyResource;
using prog::MutexResource;
using std::cout;
using std::endl;

static MutexResource mutexResource(MUTEX_NAME);

/// ensure the autoruns value is set for the program
void ensureAutoruns() {
    // path to the current process
    char path[MAX_PATH + 1];
    if (!GetModuleFileNameA(nullptr, path, MAX_PATH)) {
        cout << "Could not get the module filename" << endl;
        exit(FAILURE_EXIT_CODE);
    }

    prog::AutorunsRegKeyResource autorunsKey;
    if (!autorunsKey.ensureStringValue(AUTORUNS_VALUE_NAME, path)) {
        cout << "Could not set autoruns value" << endl;
        exit(FAILURE_EXIT_CODE);
    }
}

/// function for running the technician program
void prog::technician() {
    if (!mutexResource.acquireLock()) {
        cout << "Could not acquire lock" << endl;
        exit(FAILURE_EXIT_CODE);
    }
    ensureAutoruns();
    if (!MessageBoxA(nullptr, "MANAGEMENT PROGRAM IS UP", "Management Program", MB_OK)) {
        cout << "Could not set up message box" << endl;
        exit(FAILURE_EXIT_CODE);
    }
    Sleep(MS_IN_HOUR);
}

/// AutorunsRegKeyResource constructor
AutorunsRegKeyResource::AutorunsRegKeyResource() {
    LSTATUS openStatus = RegOpenKeyExA(HKEY_CURRENT_USER, AUTORUNS_RG_SUBKEY, 0, KEY_ALL_ACCESS, &m_hkey);
    if (openStatus != ERROR_SUCCESS) {
        cout << "Could not open the autorun registry key" << endl;
        exit(FAILURE_EXIT_CODE);
    }
}

/// AutorunsRegKeyResource distructor
AutorunsRegKeyResource::~AutorunsRegKeyResource() {
    RegCloseKey(m_hkey);
}

/// ensure that registry value with name 'valueName' is in the autoruns key
bool AutorunsRegKeyResource::ensureStringValue(const char* valueName, char* value) {
    LSTATUS valueExists = RegQueryValueExA(m_hkey, AUTORUNS_VALUE_NAME, nullptr, nullptr, nullptr, nullptr);
    if (valueExists != ERROR_SUCCESS) {
        LSTATUS createStatus = RegSetValueExA(m_hkey, AUTORUNS_VALUE_NAME, 0, REG_SZ,
                                              const_cast<const BYTE*>(reinterpret_cast<BYTE*>(value)),
                                              static_cast<DWORD>(strlen(value) + 1));
        if (createStatus != ERROR_SUCCESS) {
            return false;
        }
    }
    return true;
}

prog::MutexResource::MutexResource(const char* mutexName) : m_name(mutexName), m_handle(nullptr) {
    // intentionally empty
}

prog::MutexResource::~MutexResource() {
    if (m_handle) {
        ReleaseMutex(m_handle);
    }
}

bool prog::MutexResource::acquireLock() {
    HANDLE handle = CreateMutexA(nullptr, true, m_name);
    if (handle && GetLastError() != ERROR_ALREADY_EXISTS) {
        m_handle = handle;
        return true;
    }
    return false;
}
