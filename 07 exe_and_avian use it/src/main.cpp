#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "jni.h"
#include <avian/util/runtime-array.h>
#include <avian/vm/system/system.h>
#include "avian/finder.h"



#ifdef BOOT_LIBRARY
extern "C" void __cxa_pure_virtual(void){}
#endif // BOOT_LIBRARY

int main(int argc, char const *argv[])
{
	/* code */
	return 1;
}

int printfFromJava(){
	JavaVMInitArgs vmArgs;
	vmArgs.version = JNI_VERSION_1_2;
	vmArgs.nOptions = 1;
	vmArgs.ignoreUnrecognized = JNI_TRUE;

	const char* class_ = "Main";
	const char* jar = 0;
	int argc = 0;
	const char** argv = 0;
	const char* classpath = ".";

	++vmArgs.nOptions;

	RUNTIME_ARRAY(JavaVMOption, options, vmArgs.nOptions);
	vmArgs.options = RUNTIME_ARRAY_BODY(options);

	unsigned optionIndex = 0;

	vmArgs.options[optionIndex++].optionString
	= const_cast<char*>("-Davian.bootimage=bootimageBin");

	vmArgs.options[optionIndex++].optionString
	= const_cast<char*>("-Davian.codeimage=codeimageBin");

#define CLASSPATH_PROPERTY "-Djava.class.path="

	unsigned classpathSize = strlen(classpath);
	unsigned classpathPropertyBufferSize
	= sizeof(CLASSPATH_PROPERTY) + classpathSize;

	RUNTIME_ARRAY(char, classpathPropertyBuffer, classpathPropertyBufferSize);
	memcpy(RUNTIME_ARRAY_BODY(classpathPropertyBuffer),
		CLASSPATH_PROPERTY,
		sizeof(CLASSPATH_PROPERTY) - 1);
	memcpy(RUNTIME_ARRAY_BODY(classpathPropertyBuffer)
		+ sizeof(CLASSPATH_PROPERTY) - 1,
		classpath,
		classpathSize + 1);

	vmArgs.options[optionIndex++].optionString
	= RUNTIME_ARRAY_BODY(classpathPropertyBuffer);

	JavaVM* vm;
	void* env;
	JNI_CreateJavaVM(&vm, &env, &vmArgs);
	//JNIEnv* e = static_cast<JNIEnv*>(env);
}