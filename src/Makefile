libsemaphore.jnilib: semaphore_impl.o
	g++ -dynamiclib -o libsemaphore.jnilib semaphore_impl.o
	cp libsemaphore.jnilib /usr/local/lib

semaphore_impl.o: semaphore_impl.cpp
	g++ -std=c++11 -O3 -I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers/ -c semaphore_impl.cpp
