#include "CoreLib.h"

// Method : Microsoft.Win32.Win32Native.SetEvent(Microsoft.Win32.SafeHandles.SafeWaitHandle)
bool CoreLib::Microsoft::Win32::Win32Native::SetEvent(CoreLib::Microsoft::Win32::SafeHandles::SafeWaitHandle* handle)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.ResetEvent(Microsoft.Win32.SafeHandles.SafeWaitHandle)
bool CoreLib::Microsoft::Win32::Win32Native::ResetEvent(CoreLib::Microsoft::Win32::SafeHandles::SafeWaitHandle* handle)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.CreateEvent(Microsoft.Win32.Win32Native.SECURITY_ATTRIBUTES, bool, bool, string)
CoreLib::Microsoft::Win32::SafeHandles::SafeWaitHandle* CoreLib::Microsoft::Win32::Win32Native::CreateEvent(CoreLib::Microsoft::Win32::Win32Native_SECURITY_ATTRIBUTES* lpSecurityAttributes, bool isManualReset, bool initialState, string* name)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.GetFullPathName(char*, int, char*, System.IntPtr)
int32_t CoreLib::Microsoft::Win32::Win32Native::GetFullPathName(wchar_t* path, int32_t numBufferChars, wchar_t* buffer, CoreLib::System::IntPtr mustBeZero)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.GetStdHandle(int)
CoreLib::System::IntPtr CoreLib::Microsoft::Win32::Win32Native::GetStdHandle(int32_t nStdHandle)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.CreateFile(string, int, System.IO.FileShare, Microsoft.Win32.Win32Native.SECURITY_ATTRIBUTES, System.IO.FileMode, int, System.IntPtr)
CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* CoreLib::Microsoft::Win32::Win32Native::CreateFile(string* lpFileName, int32_t dwDesiredAccess, CoreLib::System::IO::enum_FileShare dwShareMode, CoreLib::Microsoft::Win32::Win32Native_SECURITY_ATTRIBUTES* securityAttrs, CoreLib::System::IO::enum_FileMode dwCreationDisposition, int32_t dwFlagsAndAttributes, CoreLib::System::IntPtr hTemplateFile)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.CloseHandle(System.IntPtr)
bool CoreLib::Microsoft::Win32::Win32Native::CloseHandle(CoreLib::System::IntPtr handle)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.GetFileType(Microsoft.Win32.SafeHandles.SafeFileHandle)
int32_t CoreLib::Microsoft::Win32::Win32Native::GetFileType(CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* handle)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.GetFileSize(Microsoft.Win32.SafeHandles.SafeFileHandle, out int)
int32_t CoreLib::Microsoft::Win32::Win32Native::GetFileSize_Out(CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* hFile, int32_t& highSize)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.ReadFile(Microsoft.Win32.SafeHandles.SafeFileHandle, byte*, int, out int, System.IntPtr)
int32_t CoreLib::Microsoft::Win32::Win32Native::ReadFile_Out(CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* handle, uint8_t* bytes, int32_t numBytesToRead, int32_t& numBytesRead, CoreLib::System::IntPtr mustBeZero)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.WriteFile(Microsoft.Win32.SafeHandles.SafeFileHandle, byte*, int, out int, System.IntPtr)
int32_t CoreLib::Microsoft::Win32::Win32Native::WriteFile_Out(CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* handle, uint8_t* bytes, int32_t numBytesToWrite, int32_t& numBytesWritten, CoreLib::System::IntPtr mustBeZero)
{
    throw 3221274624U;
}

// Method : Microsoft.Win32.Win32Native.GetFileAttributesEx(string, int, ref Microsoft.Win32.Win32Native.WIN32_FILE_ATTRIBUTE_DATA)
bool CoreLib::Microsoft::Win32::Win32Native::GetFileAttributesEx_Ref(string* name, int32_t fileInfoLevel, CoreLib::Microsoft::Win32::Win32Native_WIN32_FILE_ATTRIBUTE_DATA& lpFileInformation)
{
    throw 3221274624U;
}
