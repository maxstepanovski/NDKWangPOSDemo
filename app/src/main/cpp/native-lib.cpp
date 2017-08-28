#include <jni.h>
#include <string>


void log(JNIEnv *env, jstring message);
void makeBeep(JNIEnv *env, jobject instance);



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

JNIEXPORT jint JNI_OnLoad(JavaVM* pVM, void* reserved){
    JNIEnv *env;
    if(pVM -> GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK){
//        abort();
    }
    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_mamba_ndktest_MainActivity_runCore(JNIEnv *env, jobject instance, jobject callbackReceiver) {
    jstring string = env->NewStringUTF("Core started");
    log(env, string);
    jclass callbackReceiverClass = env->FindClass("com/example/mamba/ndktest/MainActivity");
    jmethodID callbackMethod = env->GetMethodID(callbackReceiverClass, "callback", "()V");
    env->CallVoidMethod(callbackReceiver, callbackMethod);
}