#include <jni.h>

#ifndef MACOSX_SEMAPHORE_IMPL_H
#define MACOSX_SEMAPHORE_IMPL_H

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL 
Java_net_coderodde_util_concurrent_MacOSXSemaphoreImpl_init(JNIEnv*, 
                                                            jobject, 
                                                            jint);

JNIEXPORT void JNICALL 
Java_net_coderodde_util_concurrent_MacOSXSemaphoreImpl_clean(JNIEnv*, jobject);

JNIEXPORT void JNICALL 
Java_net_coderodde_util_concurrent_MacOSXSemaphoreImpl_lock(JNIEnv*, jobject);

JNIEXPORT void JNICALL 
Java_net_coderodde_util_concurrent_MacOSXSemaphoreImpl_unlock(JNIEnv*, jobject);

#ifdef __cplusplus
}
#endif

#endif // MACOSX_SEMAPHORE_IMPL_H
