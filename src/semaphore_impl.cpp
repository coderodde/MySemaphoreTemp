#include "semaphore_impl.h"
#include <mach/task.h>
#include <mach/semaphore.h>
#include <mach/mach.h>

static const char* CLASS = "net/coderodde/util/concurrent/MacOSXSemaphoreImpl";
static const char* FIELD = "semaphoreHandle";

static semaphore_t get_semaphore_handle(JNIEnv* env, jobject obj)
{
    jclass clazz = env->FindClass(CLASS);
    jfieldID fid = env->GetFieldID(clazz, FIELD, "I");
    return env->GetIntField(obj, fid);
}

JNIEXPORT void JNICALL 
Java_net_coderodde_util_concurrent_MacOSXSemaphoreImpl_init(JNIEnv* env, 
                                                            jobject obj, 
                                                            jint count)
{
    // Create a handle to a semaphore.
    semaphore_t semaphore;
    semaphore_create(current_task(), &semaphore, SYNC_POLICY_FIFO, count);

    // Get to the 'semaphoreHandle' field.
    const jclass clazz = 
          env->FindClass(CLASS);

    const jfieldID semaphore_field_id = env->GetFieldID(clazz, FIELD, "I");

    // Store the value of the semaphore to the Java semaphore object.
    env->SetIntField(obj, semaphore_field_id, semaphore);
}

JNIEXPORT void JNICALL 
Java_net_coderodde_util_concurrent_MacOSXSemaphoreImpl_clean(JNIEnv* env, 
                                                             jobject obj)
{
    semaphore_destroy(get_semaphore_handle(env, obj), current_task());
}

JNIEXPORT void JNICALL 
Java_net_coderodde_util_concurrent_MacOSXSemaphoreImpl_lock(JNIEnv* env, 
                                                            jobject obj)
{
    semaphore_wait(get_semaphore_handle(env, obj));
}

JNIEXPORT void JNICALL 
Java_net_coderodde_util_concurrent_MacOSXSemaphoreImpl_unlock(JNIEnv* env, 
                                                              jobject obj)
{
    semaphore_signal(get_semaphore_handle(env, obj));
}
