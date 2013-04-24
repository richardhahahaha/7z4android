#include <jni.h>
#include "7za_log.h"


int Main2(
  int numArgs, const char *args[]
);

#ifdef EXE
int main(int argc, const char *argv[]){
    Main2(argc, argv);
}
#endif

int main2(const char *args){
    const char *argv[40]={"7za", NULL};
    char abuffer[1024]={0};
    int i, index=1;
    LOG_D("%s", args);
    if(args){
        argv[index++]=abuffer;
        for(i=0; i<sizeof(abuffer)-1; i++){
            char c=*args++;
            abuffer[i]=c;
            if(c==0){
                break;
            }else if(c==' '){
                abuffer[i]=0;
                argv[index++]=abuffer+i+1;
                if(index>=40) break;
            }
        }
    }
    LOG_D("%d, %s, %s", index, argv[1], argv[2]);
    return Main2(index, argv);
}

JNIEXPORT jint JNICALL Java_com_zkteco_compress_zk7z_run
  (JNIEnv *env, jclass cls, jstring args_){
    const char *args = (*env)->GetStringUTFChars(env, args_, 0);
    int i=main2(args);
    (*env)->ReleaseStringUTFChars(env, args_, args);
    return i;
}


