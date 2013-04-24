package com.zkteco.compress;
import android.util.Log;

/**
 * <code>Andro7za</code> provided the 7za JNI interface.
 *
 * @author <a href="mailto:tangyaguang@snda.com"></a>
 * @version 1.0
 */
public final class zk7z {
    private static String JNI_TAG = "7zaJNI";
    
    static public native int run(String argv);
        
    static {
        System.loadLibrary("zk7za");
    }
 }
