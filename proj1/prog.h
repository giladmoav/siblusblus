#ifndef __PROG_H__
#define __PROG_H__
#include <Windows.h>

constexpr char MUTEX_NAME[] = "GlobalManagementProgramMutex";
constexpr char AUTORUNS_RG_SUBKEY[] = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
constexpr char AUTORUNS_VALUE_NAME[] = "OurProg";
constexpr int FAILURE_EXIT_CODE = -1;

constexpr DWORD MS_IN_SECOND = 1000;
constexpr DWORD SECONDS_IN_HOUR = 3600;
constexpr DWORD MS_IN_HOUR = MS_IN_SECOND * SECONDS_IN_HOUR;

namespace prog {

void technician();

}

#endif // !__PROG_H__
