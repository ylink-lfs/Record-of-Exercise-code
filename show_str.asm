assume cs: code
data segment
	db 'Welcome to masm!', 0
data ends

;Calling Sample:
code segment
start:
	mov dh, 8
	mov dl, 3
	mov cl, 2
	mov ax, data
	mov ds, ax
	mov si, 0
	call show_str
	mov ax, 4c00h
	int 21h
	
;Calling Convention
;dh: Print line number(Range between 0 to 24)
;dl: Print column number(Range between 0 to 79)
;cl: Print style
;ds:[si]: Address of the string
;Note: This function changes the value of si.
show_str:
	mov bp, 0
	mov al, 0a0h
	mul dh
	add bp, ax
	mov al, 2h
	mul dl
	add bp, ax
	mov ax, 0b800h
	mov es, ax
	mov ah, cl
	mov al, ds:[si]
	iterate:
		test al, al
		je goodbye
		mov es:[bp], ax
		add bp, 2
		inc si
		mov al, ds:[si]
		jmp iterate
	goodbye:
		ret

code ends
end start