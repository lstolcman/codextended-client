#include "stdafx.h"
#include "shared.h"
#include "client.h"
#include "stdafx.h"

//0046319B E8 10 B1 FA FF                                      call    sub_40E2B0
void sub_40E2B0() {
	void(*o)();
	*(UINT32*)&o = 0x40E2B0;
	o();


	void Sys_Unload();
	Sys_Unload();
}

void Main_UnprotectModule(HMODULE hModule)
{
	PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

	// unprotect the entire PE image
	SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
	DWORD oldProtect;
	VirtualProtect((LPVOID)hModule, size, PAGE_EXECUTE_READWRITE, &oldProtect);
}

bool apply_hooks() {

	// allow alt tab - set dwExStyle from WS_EX_TOPMOST to WS_EX_LEFT (default), which allows minimizing
	XUNLOCK((void*)0x5083b1, 1);
	memset((void*)0x5083b1, 0x00, 1);

	HMODULE hModule;
	if (SUCCEEDED(GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)apply_hooks, &hModule)))
	{
		Main_UnprotectModule(hModule);
	}


	void patch_opcode_loadlibrary();
	patch_opcode_loadlibrary();
	
	if (codversion != COD_1)
		return true;
	
	   #define PATCH_PUSH_STRING_PTR_VALUE(offset, new_str) \
	XUNLOCK((void*)offset, 10); \
	*(const char **)(offset + 1) = new_str;

	PATCH_PUSH_STRING_PTR_VALUE(0x50847D, "Call of Duty 1.1x Multiplayer");

	__call(0x46319B, (int)sub_40E2B0); //cleanup exit

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	__call(0x528948, (int)WinMain);

	//__nop(0x437B39, 5); //call NET_Init we're gonna call it a bit sooner cuz we need it ;)

	void NET_Init();
	__call(0x437B39, (int)NET_Init);

	void Con_DrawSolidConsole(float);
	__call(0x40A21D, (int)Con_DrawSolidConsole);
	__call(0x40A234, (int)Con_DrawSolidConsole);
	__call(0x40A257, (int)Con_DrawSolidConsole);

	// void Con_Dump();
	// __call(0x408BBC, (int)Con_Dump);

	void CL_Connect_f();
	XUNLOCK((void*)0x41269B, 5);
	*(UINT32*)(0x41269B + 1) = (int)CL_Connect_f;

	void RB_ExecuteRenderCommands();

	unlock_client_structure(); // make some client cls_ structure members writeable etc

	void X_CL_NextDownload();
	__call(0x410316, (int)X_CL_NextDownload);
	__call(0x410376, (int)X_CL_NextDownload);
	__call(0x41656C, (int)X_CL_NextDownload);

	void CL_Frame(int msec);
	__call(0x43822C, (int)CL_Frame);

	LRESULT CALLBACK ConsoleWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	XUNLOCK((void*)0x466414, 4);
	*(int*)0x466414 = (int)ConsoleWndProc;

	void CL_CharEvent();
	__call(0x436643, (int)CL_CharEvent);

	void CL_KeyEvent(int, int, unsigned);
	__call(0x436635, (int)CL_KeyEvent);

	void CL_PacketEvent();
	__call(0x436794, (int)CL_PacketEvent);
	__call(0x436743, (int)CL_PacketEvent);

	void CL_Init();
	__call(0x437B4B, (int)CL_Init);
	__call(0x438178, (int)CL_Init);

	void SCR_DrawScreenField(stereoFrame_t stereoFrame);
	__call(0x41703A, (int)SCR_DrawScreenField);
	__call(0x417048, (int)SCR_DrawScreenField);
	
	char* __cdecl CL_SetServerInfo_HostnameStrncpy(char*, char*, size_t);
    __call(0x412A2C, (int)CL_SetServerInfo_HostnameStrncpy);

	void DrawTris(void*);
	__call(0x5028FD, (int)DrawTris);
	__nop(0x5028F6, 2);
	__nop(0x5028EE, 2); //if(r_showtris->integer and some other check

	void RB_ShowImages();
	__call(0x4D87F5, (int)RB_ShowImages);
	__nop(0x4D87F0, 5); //cmp and jz for r_showImages->integer

	void __stdcall RB_BeginSurface(); // crashes?
	__call(0x4D4A2C, (int)RB_BeginSurface);
	__call(0x4D6886, (int)RB_BeginSurface);
	__call(0x4D740B, (int)RB_BeginSurface);
	__call(0x4D7650, (int)RB_BeginSurface);
	__call(0x4D7852, (int)RB_BeginSurface);
	__call(0x4D7B20, (int)RB_BeginSurface);
	__call(0x4D8448, (int)RB_BeginSurface);
	__call(0x4D9588, (int)RB_BeginSurface);
	__call(0x4E0492, (int)RB_BeginSurface);
	__call(0x4E810E, (int)RB_BeginSurface);
	__call(0x4E847C, (int)RB_BeginSurface);
	__call(0x4E84FE, (int)RB_BeginSurface);
	__call(0x4E860B, (int)RB_BeginSurface);
	__call(0x50F9E2, (int)RB_BeginSurface);
	__jmp(0x50FA0F , (int)RB_BeginSurface);
	__call(0x50FA72, (int)RB_BeginSurface);
	__call(0x50FE75, (int)RB_BeginSurface);
	__call(0x511067, (int)RB_BeginSurface);
	__call(0x511D85, (int)RB_BeginSurface);
	__call(0x51269B, (int)RB_BeginSurface);

	void* ri_Hunk_AllocAlign(int size);
	XUNLOCK((void*)0x4FD6AF, 6);
	*(BYTE*)0x4FD6AF = 0xe8;
	__call(0x4FD6AF, (int)ri_Hunk_AllocAlign); //cannot call since it's 6 opcodes
	*(BYTE*)(0x4FD6AF + 5) = 0x90;

	void ScanAndLoadShaderFiles(void);
	__call(0x4FDB74, (int)ScanAndLoadShaderFiles);

	void AddCustomShader_w();
	__jmp(0x4FD735, (int)AddCustomShader_w);

	return true;
}