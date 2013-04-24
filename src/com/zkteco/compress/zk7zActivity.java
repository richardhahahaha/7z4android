package com.zkteco.compress;

import android.app.Activity;
import android.os.Bundle;

import com.zkteco.compress.R;
import com.zkteco.compress.zk7z;

public class zk7zActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        zk7z.run("x -p9990ppp0 -y -o/mnt/sdcard/Download/ /mnt/sdcard/Download/r.7z");
    }
}