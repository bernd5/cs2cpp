#include "CoreLib.h"
#if _WIN32 || _WIN64
#include <io.h>
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#else
#include <unistd.h>
#endif

#define O_RDONLY 0x0000	/* open for reading only */
#define O_WRONLY 0x0001	/* open for writing only */
#define O_RDWR 0x0002	/* open for reading and writing */
#define O_CREAT 0x0100		/* create if nonexistant */
#define O_TRUNC 0x0200		/* truncate to zero length */
#define O_EXCL 0x0040		/* error if already exists */
#define F_SETFD 2		/* set file descriptor flags */
#define LOCK_SH 0x01		/* shared file lock */
#define LOCK_EX 0x02		/* exclusive file lock */
#define LOCK_NB 0x04		/* don't block when locking */
#define LOCK_UN 0x08		/* unlock file */
/* access function */
#define F_OK 0	/* test for existence of file */
#define O_DIRECT 00040000
#define O_BINARY 0x8000
#define S_IRUSR 0000400			/* R for owner */
#define S_IWUSR 0000200			/* W for owner */
#define S_IROTH 0000004			/* R for other */
#define S_IRGRP 0000040			/* R for group */
#define GENERIC_READ 0x80000000
#define GENERIC_WRITE 0x40000000
#define FILE_ATTRIBUTE_HIDDEN 0x00000002
#define FILE_ATTRIBUTE_SYSTEM 0x00000004
#define FILE_ATTRIBUTE_DIRECTORY 0x00000010
#define FILE_ATTRIBUTE_ARCHIVE 0x00000020
#define FILE_ATTRIBUTE_DEVICE 0x00000040
#define FILE_ATTRIBUTE_NORMAL 0x00000080
#define FILE_FLAG_NO_BUFFERING 0x20000000

// Method : Microsoft.Win32.Win32Native.SetEvent(Microsoft.Win32.SafeHandles.SafeWaitHandle)
bool CoreLib::Microsoft::Win32::Win32Native::SetEvent(CoreLib::Microsoft::Win32::SafeHandles::SafeWaitHandle* handle)
{
	throw 0xC000C000;
}

// Method : Microsoft.Win32.Win32Native.ResetEvent(Microsoft.Win32.SafeHandles.SafeWaitHandle)
bool CoreLib::Microsoft::Win32::Win32Native::ResetEvent(CoreLib::Microsoft::Win32::SafeHandles::SafeWaitHandle* handle)
{
	throw 0xC000C000;
}

// Method : Microsoft.Win32.Win32Native.CreateEvent(Microsoft.Win32.Win32Native.SECURITY_ATTRIBUTES, bool, bool, string)
CoreLib::Microsoft::Win32::SafeHandles::SafeWaitHandle* CoreLib::Microsoft::Win32::Win32Native::CreateEvent(CoreLib::Microsoft::Win32::Win32Native_SECURITY_ATTRIBUTES* lpSecurityAttributes, bool isManualReset, bool initialState, string* name)
{
	throw 0xC000C000;
}

// Method : Microsoft.Win32.Win32Native.GetFullPathName(char*, int, char*, System.IntPtr)
int32_t CoreLib::Microsoft::Win32::Win32Native::GetFullPathName(wchar_t* path, int32_t numBufferChars, wchar_t* buffer, CoreLib::System::IntPtr mustBeZero)
{
	auto p = fs::path(path);
	auto full = fs::canonical(p);
	std::wcscpy(buffer, full.c_str());
	return p.wstring().length();
}

// Method : Microsoft.Win32.Win32Native.GetStdHandle(int)
CoreLib::System::IntPtr CoreLib::Microsoft::Win32::Win32Native::GetStdHandle(int32_t nStdHandle)
{
	return __init<CoreLib::System::IntPtr>(nStdHandle);
}

// Method : Microsoft.Win32.Win32Native.CreateFile(string, int, System.IO.FileShare, Microsoft.Win32.Win32Native.SECURITY_ATTRIBUTES, System.IO.FileMode, int, System.IntPtr)
CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* CoreLib::Microsoft::Win32::Win32Native::CreateFile(string* lpFileName, int32_t dwDesiredAccess, CoreLib::System::IO::enum_FileShare dwShareMode, CoreLib::Microsoft::Win32::Win32Native_SECURITY_ATTRIBUTES* securityAttrs, CoreLib::System::IO::enum_FileMode dwCreationDisposition, int32_t dwFlagsAndAttributes, CoreLib::System::IntPtr hTemplateFile)
{
	int32_t filed = -1;
	int32_t create_flags = (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	int32_t open_flags = 0;
	bool fFileExists = false;

	if (lpFileName == nullptr)
	{
		return __new<CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle>(((CoreLib::System::IntPtr)CoreLib::Microsoft::Win32::Win32Native::INVALID_HANDLE_VALUE), false);
	}

	switch ((uint32_t)dwDesiredAccess)
	{
	case GENERIC_READ:
		open_flags |= O_RDONLY;
		break;
	case GENERIC_WRITE:
		open_flags |= O_WRONLY;
		break;
	case GENERIC_READ | GENERIC_WRITE:
		open_flags |= O_RDWR;
		break;
	default:
		return __new<CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle>(((CoreLib::System::IntPtr)CoreLib::Microsoft::Win32::Win32Native::INVALID_HANDLE_VALUE), false);
	}

	switch ((CoreLib::System::IO::enum_FileMode)dwCreationDisposition)
	{
	case CoreLib::System::IO::enum_FileMode::c_Create:
		// check whether the file exists
		if (_waccess(&lpFileName->m_firstChar, F_OK) == 0)
		{
			fFileExists = true;
		}

		open_flags |= O_CREAT | O_TRUNC;
		break;
	case CoreLib::System::IO::enum_FileMode::c_CreateNew:
		open_flags |= O_CREAT | O_EXCL;
		break;
	case CoreLib::System::IO::enum_FileMode::c_Open:
		/* don't need to do anything here */
		break;
	case CoreLib::System::IO::enum_FileMode::c_OpenOrCreate:
		if (_waccess(&lpFileName->m_firstChar, F_OK) == 0)
		{
			fFileExists = true;
		}

		open_flags |= O_CREAT;
		break;
	case CoreLib::System::IO::enum_FileMode::c_Truncate:
		open_flags |= O_TRUNC;
		break;
	default:
		return __new<CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle>(((CoreLib::System::IntPtr)CoreLib::Microsoft::Win32::Win32Native::INVALID_HANDLE_VALUE), false);
	}

	if ((dwFlagsAndAttributes & FILE_FLAG_NO_BUFFERING) > 0)
	{
		open_flags |= O_DIRECT;
	}

	open_flags |= O_BINARY;

	filed = _wopen(&lpFileName->m_firstChar, open_flags, (open_flags & O_CREAT) > 0 ? create_flags : 0);
	if (filed < 0)
	{
		return __new<CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle>(__init<CoreLib::System::IntPtr>(0), false);
	}

#if flock
	auto lock_mode = (dwShareMode == 0 /* FILE_SHARE_NONE */) ? LOCK_EX : LOCK_SH;
	if (flock(filed, lock_mode | LOCK_NB) != 0)
	{
		return __new<CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle>(INVALID_HANDLE_VALUE, false);
	}
#endif

#if O_DIRECT
	if ((dwFlagsAndAttributes & FILE_FLAG_NO_BUFFERING) > 0)
	{
#if F_NOCACHE
		if (-1 == fcntl(filed, F_NOCACHE, 1))
		{
			return __new<CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle>(INVALID_HANDLE_VALUE, false);
		}
#else
////#error Insufficient support for uncached I/O on this platform
#endif
	}
#endif

#if fcntl
	/* make file descriptor close-on-exec; inheritable handles will get
	"uncloseonexeced" in CreateProcess if they are actually being inherited*/
	auto ret = fcntl(filed, F_SETFD, 1);
	if (-1 == ret)
	{
		return __new<CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle>(INVALID_HANDLE_VALUE, false);
	}
#endif

	return __new<CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle>(__init<CoreLib::System::IntPtr>(filed), false);
}

// Method : Microsoft.Win32.Win32Native.CloseHandle(System.IntPtr)
bool CoreLib::Microsoft::Win32::Win32Native::CloseHandle(CoreLib::System::IntPtr handle)
{
	throw 0xC000C000;
}

// Method : Microsoft.Win32.Win32Native.GetFileType(Microsoft.Win32.SafeHandles.SafeFileHandle)
int32_t CoreLib::Microsoft::Win32::Win32Native::GetFileType(CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* handle)
{
	const int FILE_TYPE_DISK = 0x0001;
	const int FILE_TYPE_CHAR = 0x0002;
	const int FILE_TYPE_PIPE = 0x0003;

	auto stdId = handle->DangerousGetHandle()->ToInt32();
	if (stdId == -11 || stdId == -12)
	{
		return FILE_TYPE_CHAR;
	}

	return FILE_TYPE_DISK;
}

// Method : Microsoft.Win32.Win32Native.GetFileSize(Microsoft.Win32.SafeHandles.SafeFileHandle, out int)
int32_t CoreLib::Microsoft::Win32::Win32Native::GetFileSize_Out(CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* hFile, int32_t& highSize)
{
	throw 0xC000C000;
}

// Method : Microsoft.Win32.Win32Native.ReadFile(Microsoft.Win32.SafeHandles.SafeFileHandle, byte*, int, out int, System.IntPtr)
int32_t CoreLib::Microsoft::Win32::Win32Native::ReadFile_Out(CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* handle, uint8_t* bytes, int32_t numBytesToRead, int32_t& numBytesRead, CoreLib::System::IntPtr mustBeZero)
{
	throw 0xC000C000;
}

// Method : Microsoft.Win32.Win32Native.WriteFile(Microsoft.Win32.SafeHandles.SafeFileHandle, byte*, int, out int, System.IntPtr)
int32_t CoreLib::Microsoft::Win32::Win32Native::WriteFile_Out(CoreLib::Microsoft::Win32::SafeHandles::SafeFileHandle* handle, uint8_t* bytes, int32_t numBytesToWrite, int32_t& numBytesWritten, CoreLib::System::IntPtr mustBeZero)
{
	auto fd = handle->DangerousGetHandle()->ToInt32();
	if (fd == -11)
	{
		numBytesWritten = _write(STDOUT_FILENO, bytes, numBytesToWrite);
		return numBytesWritten < numBytesToWrite ? 0 : 1;
	}
	else if (fd == -12)
	{
		numBytesWritten = _write(STDERR_FILENO, bytes, numBytesToWrite);
		return numBytesWritten < numBytesToWrite ? 0 : 1;
	}
	else
	{
		auto r = _write(fd, bytes, numBytesToWrite);
		if (r != -1)
		{
			numBytesWritten = r;
			return 1;
		}
	}

	numBytesWritten = 0;
	return 0;
}

// Method : Microsoft.Win32.Win32Native.GetFileAttributesEx(string, int, ref Microsoft.Win32.Win32Native.WIN32_FILE_ATTRIBUTE_DATA)
bool CoreLib::Microsoft::Win32::Win32Native::GetFileAttributesEx_Ref(string* name, int32_t fileInfoLevel, CoreLib::Microsoft::Win32::Win32Native_WIN32_FILE_ATTRIBUTE_DATA& lpFileInformation)
{
	throw 0xC000C000;
}
