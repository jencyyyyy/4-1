DSEG    SEGMENT 'DATA'
DSEG    ENDS
SSEG    SEGMENT STACK   'STACK'
        DW      100h    DUP(?)
SSEG    ENDS
CSEG    SEGMENT 'CODE'

START   PROC    FAR

; Store return address to OS:
    PUSH    DS
    MOV     AX, 0
    PUSH    AX

; set segment registers:
    MOV     AX, DSEG
    MOV     DS, AX
    MOV     ES, AX

	MOV DX, 2030h	; first Seven Segment Display

continue:
	MOV CX, 2

display: 

	;1
	MOV AL,00000110b
	out dx,al
	
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2030h
                 
                 
    ;2
    MOV AL,01011011b
	out dx,al
	
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2030h
    
    
    ;3
    MOV AL,01001111b
	out dx,al
	
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2030h                 
                 
	LOOP display
	
	JMP continue

; return to operating system:
    RET
START   ENDP

CSEG    ENDS 

END    START   

