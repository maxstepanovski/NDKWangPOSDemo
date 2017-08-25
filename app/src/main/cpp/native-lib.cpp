#include <jni.h>
#include <string>


extern "C"
JNIEXPORT void JNICALL
Java_com_example_mamba_ndktest_MainActivity_runCore(JNIEnv *env, jobject instance) {
//    jstring jstr = env->NewStringUTF("log message from c++");
//    jclass mainActivityClass = env->FindClass("com/example/mamba/ndktest/MainActivity");
//    jmethodID method = env->GetStaticMethodID(mainActivityClass, "log", "(Ljava/lang/String;)V");
//    env->CallStaticVoidMethod(mainActivityClass, method, jstr);

}

void log(jstring message, JNIEnv *env){
//    jstring jstr = env->NewStringUTF("log message from c++");
    jclass mainActivityClass = env->FindClass("com/example/mamba/ndktest/MainActivity");
    jmethodID method = env->GetStaticMethodID(mainActivityClass, "log", "(Ljava/lang/String;)V");
    env->CallStaticVoidMethod(mainActivityClass, method, message);
}






