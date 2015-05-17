package net.coderodde.util.concurrent;

/**
 * This class implements the semaphore type interfacing with MacOSX.
 * 
 * @author Rodion "rodde" Efremov
 * @version 1.6
 */
final class MacOSXSemaphoreImpl implements SemaphoreImpl {

    static {
        try {
            System.loadLibrary("semaphore");
        } catch (UnsatisfiedLinkError error) {
            error.printStackTrace();
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

    /**
     * Release the resources associated with this semaphore.
     */
    @Override
    protected void finalize() {
        try {
            super.finalize();
        } catch (Throwable t) {}

        clean();
    }
}
