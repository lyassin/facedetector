package status.face.ensi.tn.facestatus;

import android.content.res.AssetManager;

public class ImageRecognitionFramework {
	
	static {
        System.loadLibrary("ImageRecognitionFramework");
    }
	private int instancePtr = 0;
	

	private native int DestroyIntance(int instance);
	private native int CreateIntance(AssetManager mgr);
	public native void ShowPreview (int instance,long matAddrGr, long matAddrRgba);
	
	public ImageRecognitionFramework(){
		
	}
	@Override
	public void finalize(){
		if ( instancePtr != 0 )
			DestroyIntance(instancePtr);
	}
	
	public void ShowPreviews (long matAddrGr, long matAddrRgba)
	{
		ShowPreview (instancePtr,matAddrGr,matAddrRgba);
	}
	public int Initialize(AssetManager mgr){
		instancePtr = CreateIntance(mgr);
		return 0;
	}
	
}
