 ///
 /// @file    MutexLock.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-04-15 14:47:10
 ///
 
#include "MutexLock.h"

#include <stdio.h>
#include <errno.h>

namespace wd
{

MutexLock::MutexLock()
: _isLocking(false)
{
	if(pthread_mutex_init(&_mutex, NULL)) {
		perror("pthread_mutex_init");
	}
}

MutexLock::~MutexLock()
{
	if(pthread_mutex_destroy(&_mutex)) {
		perror("pthread_mutex_destroy");
	}
}

void MutexLock::lock()
{
	if(pthread_mutex_lock(&_mutex)) {
		perror("pthread_mutex_lock");
		return;
	}
	_isLocking = true;
}

void MutexLock::unlock()
{
	if(pthread_mutex_unlock(&_mutex)) {
		perror("pthread_mutex_unlock");
		return;
	}
	_isLocking = false;
}

}//end of namespace wd
