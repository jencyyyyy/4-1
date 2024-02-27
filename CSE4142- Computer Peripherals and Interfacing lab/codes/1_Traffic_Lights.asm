SSEG    SEGMENT STACK   'STACK'
        DW      100h    DUP(?)
SSEG    ENDS

CSEG    SEGMENT 'CODE'

;*******************************************

START   PROC    FAR

; Store return address to OS:
 	PUSH    DS
 	MOV     AX, 0
 	PUSH    AX


	MOV DX, 2070h

MAINLOOP:   
    MOV AL, 01h
	MOV CX, 7                   ;Red     CX=  7 (10 sec)
	                            ;Yellow  CX=  6 (5 sec)
	                            ;Green   CX=  5 (15 sec)
LED:                      
	
    OUT DX, AL
	ROL Al, 1 
	
	cmp cx,7
	je D10
	
	cmp cx,6
	je D5
	
	cmp cx,5
	je D15

	JMP MAINLOOP
	
	
	
D5: ;Yellow Light 5sec Delay
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h
    
    LOOP LED  


D10: ;Red Light 10 sec Delay
    mov bx,cx    
    mov CX,0098h
    mov DX,9680h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h
    
    LOOP LED    
    
    
D15: ;Green Light 15 sec Delay
    mov bx,cx    
    mov CX,004Ch
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    
    
    mov bx,cx    
    mov CX,0098h
    mov DX,9680h
    mov ah,86h
    int 15h

    mov cx,bx
    MOV DX, 2070h
    
    JMP MAINLOOP   
    
	

; return to operating system:
	RET
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point.

