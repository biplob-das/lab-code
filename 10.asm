.model small
.stack 100h
.data
    number  db 90
    msgplus db 'A+$'
    msga    db 'A$'
    msgb    db 'B$'
    msgc    db 'C$'
.code
main proc
    mov ax, @data
    mov ds, ax

    mov al, number
    cmp al, 80
    jae aplus
    cmp al, 70
    jae a
    cmp al, 60
    jae b
    jmp c

aplus:
    lea dx, msgplus
    jmp print
a:
    lea dx, msga
    jmp print
b:
    lea dx, msgb
    jmp print
c:
    lea dx, msgc

print:
    mov ah, 09h
    int 21h

exit:
    mov ah, 4ch
    int 21h

main endp
end main