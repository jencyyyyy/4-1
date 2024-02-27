TITLE   8086 Code Template (for EXE file)

;       AUTHOR          emu8086
;       DATE            ?
;       VERSION         1.00
;       FILE            ?.ASM

; Note: Set the delay to 100 ms in Emu 8086 and to 10 ms 
;       in I/O Emulation Kit to get best results for this sample
;       (i.e., the delay of I/O Emulation Kit is much smaller than
;        the delay of Emu8086).

; 8086 Code Template

; Directive to make EXE output:
       #MAKE_EXE#

DSEG    SEGMENT 'DATA'

; TODO: add your data here!!!!

DSEG    ENDS

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

; set segment registers:
	MOV     AX, DSEG
 	MOV     DS, AX
 	MOV     ES, AX


	MOV DX, 2070h

MAINLOOP:   
    MOV AL, 20H
	MOV CX, 6                   ;Red     CX=  4 (10 sec)
	                            ;Yellow  CX=  5 (2 sec)
	                            ;Green   CX=  6 (7 sec)
LED:                      
	
    OUT DX, AL
	ROR Al, 1 
	
	cmp cx,6
	je D10
	
	cmp cx,5
	je D2
	
	cmp cx,4
	je D7  
	
	cmp cx,3
	je D10
	
	cmp cx,2
	je D2
	
	cmp cx,1
	je D7L

	
	
D2: ;Yellow Light 2sec Delay
    mov bx,cx    
    mov CX,001Eh
    mov DX,8480h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h
    
    LOOP LED  
    
D7: ;red Light 7 sec Delay for loop to LED
    mov bx,cx    
    mov CX,4CH
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h  
    
    mov bx,cx    
    mov CX,1Eh
    mov DX,8480h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h
    
    LOOP LED        
    

    
D10: ;Green Light 10 sec Delay
    mov bx,cx    
    mov CX,0098h
    MOV DX,9680H
    mov ah,86h
    int 15h
    mov cx,bx    
    MOV DX, 2070h
    
    LOOP LED  
    
D7L: ;Red Light 7sec Delay
    mov bx,cx    
    mov CX,4CH
    mov DX,4B40h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h  
    
    mov bx,cx    
    mov CX,1Eh
    mov DX,8480h
    mov ah,86h
    int 15h
    mov cx,bx
    MOV DX, 2070h
    
    jmp MAINLOOP



       
; return to operating system:
	RET
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point.