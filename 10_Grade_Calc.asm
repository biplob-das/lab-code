.model small
.stack 100h
.data
    marks db 85
.code
main:
    mov ax, @data
    mov ds, ax

    mov al, marks
    cmp al, 80
    jae Aplus
    cmp al, 70
    jae A
    cmp al, 60
    jae B
    jmp C

Aplus:
    mov dl, 'A'
    call print
    mov dl, '+'
    jmp print

A:
    mov dl, 'A'
    jmp print

B:
    mov dl, 'B'
    jmp print

C:
    mov dl, 'C'

print:
    mov ah, 02h
    int 21h

    mov ah, 4ch
    int 21h
end main