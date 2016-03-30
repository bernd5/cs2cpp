#include "CoreLib.h"

#ifdef _MSC_VER
# include <windows.h>
# define __ATTR __stdcall
#else
# include <pthread.h>
# define __ATTR 
#endif

#ifndef GC_THREADS
# define GC_THREADS
#endif

#include "gc.h"

// Method : System.Threading.Thread.ManagedThreadId.get
int32_t CoreLib::System::Threading::Thread::get_ManagedThreadId()
{
	throw 3221274624U;
}

int32_t __ATTR __thread_inner_proc(void* params)
{
	auto __this = (CoreLib::System::Threading::Thread*)params;

	auto threadStart = as<CoreLib::System::Threading::ThreadStart*>(__this->m_Delegate);
	if (threadStart != nullptr)
	{
		threadStart->Invoke();
		return 0;
	}

	auto parameterizedThreadStart = as<CoreLib::System::Threading::ParameterizedThreadStart*>(__this->m_Delegate);
	if (parameterizedThreadStart != nullptr)
	{
		parameterizedThreadStart->Invoke(__this->m_ThreadStartArg);
		return 0;
	}

	throw __new<CoreLib::System::InvalidOperationException>();
}

// Method : System.Threading.Thread.StartInternal(System.Security.Principal.IPrincipal, ref System.Threading.StackCrawlMark)
void CoreLib::System::Threading::Thread::StartInternal_Ref(CoreLib::System::Security::Principal::IPrincipal* principal, CoreLib::System::Threading::enum_StackCrawlMark& stackMark)
{
	auto voidPtr = (void*)this->DONT_USE_InternalThread;
	if (voidPtr != nullptr)
	{
		throw __new<CoreLib::System::Threading::ThreadStateException>();
	}

	int32_t threadId;
#if _MSC_VER
	this->DONT_USE_InternalThread.m_value = CreateThread( 
		nullptr,                // default security attributes
		0,                      // use default stack size  
		(LPTHREAD_START_ROUTINE)__thread_inner_proc,    // thread function name
		this,					// argument to thread function 
		0,                      // use default creation flags 
		(LPDWORD)&threadId);	// returns the thread identifier 
#else
	auto t = __new_set0(sizeof(pthread_t));
	pthread_create(t, 0, __thread_inner_proc, this);
	this->DONT_USE_InternalThread.m_value = t;
#endif
}

// Method : System.Threading.Thread.InternalGetCurrentThread()
CoreLib::System::IntPtr CoreLib::System::Threading::Thread::InternalGetCurrentThread()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.AbortInternal()
void CoreLib::System::Threading::Thread::AbortInternal()
{
	auto voidPtr = (void*)this->DONT_USE_InternalThread;
	if (voidPtr == nullptr)
	{
		throw __new<CoreLib::System::InvalidOperationException>();
	}

#if _MSC_VER
	CloseHandle((HANDLE)voidPtr);
#else
	pthread_detach(*(pthread_t*)voidPtr);
#endif
}

// Method : System.Threading.Thread.GetPriorityNative()
int32_t CoreLib::System::Threading::Thread::GetPriorityNative()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.SetPriorityNative(int)
void CoreLib::System::Threading::Thread::SetPriorityNative(int32_t priority)
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.IsAlive.get
bool CoreLib::System::Threading::Thread::get_IsAlive()
{
	auto voidPtr = (void*)this->DONT_USE_InternalThread;
	if (voidPtr == nullptr)
	{
		throw __new<CoreLib::System::InvalidOperationException>();
	}

	return true;
}

// Method : System.Threading.Thread.IsThreadPoolThread.get
bool CoreLib::System::Threading::Thread::get_IsThreadPoolThread()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.JoinInternal(int)
bool CoreLib::System::Threading::Thread::JoinInternal(int32_t millisecondsTimeout)
{
	auto voidPtr = (void*)this->DONT_USE_InternalThread;
	if (voidPtr == nullptr)
	{
		throw __new<CoreLib::System::InvalidOperationException>();
	}

#if _MSC_VER
	return WaitForSingleObject((HANDLE)voidPtr, millisecondsTimeout == -1 ? INFINITE : millisecondsTimeout) == WAIT_OBJECT_0;
#else
	return pthread_join(*(pthread_t*)voidPtr, 0) == 0;
#endif
}

// Method : System.Threading.Thread.SleepInternal(int)
void CoreLib::System::Threading::Thread::SleepInternal(int32_t millisecondsTimeout)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsTimeout));
}

// Method : System.Threading.Thread.SpinWaitInternal(int)
void CoreLib::System::Threading::Thread::SpinWaitInternal(int32_t iterations)
{
	for (int i = 0; i < iterations; i++)
	{
		std::this_thread::yield();
	}
}

// Method : System.Threading.Thread.YieldInternal()
bool CoreLib::System::Threading::Thread::YieldInternal()
{
	std::this_thread::yield();
	return true;
}

// Method : System.Threading.Thread.GetCurrentThreadNative()
CoreLib::System::Threading::Thread* CoreLib::System::Threading::Thread::GetCurrentThreadNative()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.GetProcessDefaultStackSize()
uint64_t CoreLib::System::Threading::Thread::GetProcessDefaultStackSize()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.SetStart(System.Delegate, int)
void CoreLib::System::Threading::Thread::SetStart(CoreLib::System::Delegate* start, int32_t maxStackSize)
{
	this->m_Delegate = start;
}

// Method : System.Threading.Thread.InternalFinalize()
void CoreLib::System::Threading::Thread::InternalFinalize()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.IsBackgroundNative()
bool CoreLib::System::Threading::Thread::IsBackgroundNative()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.SetBackgroundNative(bool)
void CoreLib::System::Threading::Thread::SetBackgroundNative(bool isBackground)
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.GetThreadStateNative()
int32_t CoreLib::System::Threading::Thread::GetThreadStateNative()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.nativeInitCultureAccessors()
void CoreLib::System::Threading::Thread::nativeInitCultureAccessors()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.GetDomainInternal()
CoreLib::System::AppDomain* CoreLib::System::Threading::Thread::GetDomainInternal()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.GetFastDomainInternal()
CoreLib::System::AppDomain* CoreLib::System::Threading::Thread::GetFastDomainInternal()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.InformThreadNameChange(System.Threading.ThreadHandle, string, int)
void CoreLib::System::Threading::Thread::InformThreadNameChange(CoreLib::System::Threading::ThreadHandle t, string* name, int32_t len)
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.MemoryBarrier()
#undef MemoryBarrier
void CoreLib::System::Threading::Thread::MemoryBarrier()
{
	std::atomic_thread_fence(std::memory_order_relaxed);
}

// Method : System.Threading.Thread.SetAbortReason(object)
void CoreLib::System::Threading::Thread::SetAbortReason(object* o)
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.GetAbortReason()
object* CoreLib::System::Threading::Thread::GetAbortReason()
{
	throw 3221274624U;
}

// Method : System.Threading.Thread.ClearAbortReason()
void CoreLib::System::Threading::Thread::ClearAbortReason()
{
	throw 3221274624U;
}
