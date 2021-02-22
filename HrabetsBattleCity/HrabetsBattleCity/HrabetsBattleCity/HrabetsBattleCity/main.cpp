/////////////////////////////////////
// Include
#include "MyFramework.h"
#include <stdio.h>


/////////////////////////////////////
// Pragma
#ifndef _DEBUG
#	pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif


/////////////////////////////////////
// Main

int main(int argc, char* argv[])
{
	return run(new MyFramework);
}