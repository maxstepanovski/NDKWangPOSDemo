//
// Created by mamba on 28.08.2017.
//

#ifndef NDKTEST_MAIN_H
#define NDKTEST_MAIN_H

#include <stdio.h>
#include <jni.h>

void log(JNIEnv *env, jstring message);
void makeBeep(JNIEnv *env, jobject instance);


#endif //NDKTEST_MAIN_H
