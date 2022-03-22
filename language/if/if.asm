#include <stdio.h>

enum {
    FALSE = 0,
    TRUE = 1
};
int main()
{
007C4500  push        ebp  
007C4501  mov         ebp,esp  
007C4503  sub         esp,0D0h  
007C4509  push        ebx  
007C450A  push        esi  
007C450B  push        edi  
007C450C  lea         edi,[ebp-10h]  
007C450F  mov         ecx,4  
007C4514  mov         eax,0CCCCCCCCh  
007C4519  rep stos    dword ptr es:[edi]  
007C451B  mov         ecx,offset _EFAA9CBE_if@c (07CC003h)  
007C4520  call        @__CheckForDebuggerJustMyCode@4 (07C1316h)  
    int is_true = TRUE;
007C4525  mov         dword ptr [is_true],1  

    if (is_true) {
007C452C  cmp         dword ptr [is_true],0  
007C4530  je          __$EncStackInitStart+35h (07C4541h)  
        printf("It's true!");
007C4532  push        offset string "It's true!" (07C7B30h)  
007C4537  call        _printf (07C10CDh)  
007C453C  add         esp,4  
    }
007C453F  jmp         __$EncStackInitStart+42h (07C454Eh)  
    else {
        printf("It's false!");
007C4541  push        offset string "It's false!" (07C7B40h)  
007C4546  call        _printf (07C10CDh)  
007C454B  add         esp,4  
    }

    is_true ? printf("It's true!") : printf("It's false!");
007C454E  cmp         dword ptr [is_true],0  
007C4552  je          __$EncStackInitStart+5Dh (07C4569h)  
007C4554  push        offset string "It's true!" (07C7B30h)  
007C4559  call        _printf (07C10CDh)  
007C455E  add         esp,4  
007C4561  mov         dword ptr [ebp-0D0h],eax  
007C4567  jmp         __$EncStackInitStart+70h (07C457Ch)  
007C4569  push        offset string "It's false!" (07C7B40h)  
007C456E  call        _printf (07C10CDh)  
007C4573  add         esp,4  
007C4576  mov         dword ptr [ebp-0D0h],eax  

    return 0;
007C457C  xor         eax,eax  
}
007C457E  pop         edi  
007C457F  pop         esi  
007C4580  pop         ebx  
007C4581  add         esp,0D0h  
007C4587  cmp         ebp,esp  
007C4589  call        __RTC_CheckEsp (07C123Fh)  
007C458E  mov         esp,ebp  
007C4590  pop         ebp  
007C4591  ret  