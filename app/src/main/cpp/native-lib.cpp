#include <jni.h>
#include <string>


void log(JNIEnv *env, jstring message);
void makeBeep(JNIEnv *env, jobject instance);

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mamba_ndktest_MainActivity_runCore(JNIEnv *env, jobject instance) {
    jstring string = env->NewStringUTF("Core started");
    log(env, string);
//    makeBeep(env, instance);
}

void log(JNIEnv *env, jstring message){
    jclass customLogClass = env->FindClass("com/example/mamba/ndktest/CustomLog");
    jmethodID logMethod = env->GetStaticMethodID(customLogClass, "log", "(Ljava/lang/String;)V");
    env->CallStaticVoidMethod(customLogClass, logMethod, message);
}

void makeBeep(JNIEnv *env, jobject instance){
    jclass mainActivity = env->FindClass("com/example/mamba/ndktest/CustomLog");
    jmethodID startMethod = env->GetMethodID(mainActivity, "makeBeep", "()V");
    env->CallObjectMethod(instance, startMethod);
}









