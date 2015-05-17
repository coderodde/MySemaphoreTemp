package net.coderodde.util.concurrent;

import java.io.File;

/**
 * This class implements the semaphore type interfacing with MacOSX.
 * 
 * @author Rodion "rodde" Efremov
 * @version 1.6
 */
final class MacOSXSemaphoreImpl implements SemaphoreImpl {
    
    static {
        try {
            System.load(System.getProperty("user.dir") + 
                        File.separator + "src" + File.separator + 
                        "libsemaphore.jnilib");
        } catch (UnsatisfiedLinkError error) {
            System.err.println("Could not load a native library.");
            System.exit(1);
        }
    }
    
    /**
     * Holds the handle to a semaphore.
     */
    private int semaphoreHandle;

    /**
     * Constructs a semaphore with <code>counter</code> permits.
     * 
     * @param counter the amount of permits.
     */
    MacOSXSemaphoreImpl(int counter) {
        init(counter);
    }
    
    /**
     * Creates the semaphore and loads its handle into <code>semaphoreId</code>.
     */
    @Override
    public native void init(int counter);
    
    /**
     * Releases resources.
     */
    @Override
    public native void clean();
    
    /**
     * Acquires this semaphore. If the current counter of this semaphore is
     * zero, the calling thread is blocked.
     */
    @Override
    public native void lock();

    /**
     * Releases this semaphore. Effectively increments the counter of this 
     * semaphore so that other threads may acquire this semaphore.
     */
    @Override
    public native void unlock();
    
    @Override
    protected void finalize() {
        try {
            super.finalize();
        } catch (Throwable t) {}
        
        clean();
    }
}
