#include <jni.h>
#include <string>
#include "main.h"


void log(JNIEnv *env, jstring message){
    jclass customLogClass = env->FindClass("com/example/mamba/ndktest/CustomLog");
    jmethodID logMethod = env->GetStaticMethodID(customLogClass, "log", "(Ljava/lang/String;)V");
    env->CallStaticVoidMethod(customLogClass, logMethod, message);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* pVM, void* reserved){
    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mamba_ndktest_MainActivity_runCore(JNIEnv *env, jobject instance, jobject callbackReceiver) {
    jstring string = env->NewStringUTF("Core started");
    log(env, string);
    jclass callbackReceiverClass = env->FindClass("com/example/mamba/ndktest/MainActivity");
    jstring string2 = env->NewStringUTF("callback message");
    jmethodID callbackMethod = env->GetMethodID(callbackReceiverClass, "callback", "(Ljava/lang/String;)V");
    env->CallVoidMethod(callbackReceiver, callbackMethod, string2);
}