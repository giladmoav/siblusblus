#include "prog.h"
#include "server.h"
#include <iostream>

using prog::AutorunsRegKeyResource;
using prog::EnsureAutorunsFailed;
using prog::MutexAcquasitionFailed;
using prog::MutexResource;
using server::runServer;
using std::cout;
using std::endl;
using std::runtime_error;

/// ensure the autoruns value is set for the program
void ensureAutoruns() {
    // path to the current process
    char path[MAX_PATH + 1];
    if (!GetModuleFileNameA(nullptr, path, MAX_PATH)) {
        throw EnsureAutorunsFailed();
    }

    prog::AutorunsRegKeyResource autorunsKey;
    if (!autorunsKey.ensureStringValue(AUTORUNS_VALUE_NAME, path)) {
        throw EnsureAutorunsFailed();
    }
}

/// function for running the technician program
void prog::technician() {
    MutexResource mutexResource(MUTEX_NAME);
    ensureAutoruns();
    runServer();
}

/// AutorunsRegKeyResource constructor
AutorunsRegKeyResource::AutorunsRegKeyResource() {
    LSTATUS openStatus = RegOpenKeyExA(HKEY_CURRENT_USER, AUTORUNS_RG_SUBKEY, 0, KEY_ALL_ACCESS, &m_hkey);
    if (openStatus != ERROR_SUCCESS) {
        throw EnsureAutorunsFailed();
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

prog::MutexResource::MutexResource(const char* mutexName) : m_handle(CreateMutexA(nullptr, true, mutexName)) {
    if (!m_handle || GetLastError() == ERROR_ALREADY_EXISTS) {
        throw MutexAcquasitionFailed();
    }
}

prog::MutexResource::~MutexResource() {
    if (m_handle) {
        ReleaseMutex(m_handle);
    }
}

prog::MutexAcquasitionFailed::MutexAcquasitionFailed() : runtime_error(MUTEX_ACQUASITION_FAILED) {
    // intentionally empty
}

prog::EnsureAutorunsFailed::EnsureAutorunsFailed() : runtime_error(ENSURE_AUTORUNS_FAILED) {
    // intentionally empty
}
