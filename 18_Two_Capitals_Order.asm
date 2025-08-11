org 100h

; Read first letter
mov ah, 1
int 21h
mov bl, al

; Read second letter
mov ah, 1
int 21h
mov bh, al

; Compare and swap if needed
cmp bl, bh
jbe no_swap
xchg bl, bh

no_swap:
; Print first letter
mov ah, 2
mov dl, bl
int 21h

; Print second letter
mov ah, 2
mov dl, bh
int 21h

mov ah, 4Ch
int 21h
