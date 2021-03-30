;20h ile 40h arasindaki verilerden 
;a. en büyügünü bulan 41h adresine 
;b. en büyügünün tekrarlama sayisini 42h adresine 
;c. bu en büyük elemanin bulundugu adresleri de 
;50h adresinden itibaren yeni bir diziye yazan program
org 0000h
	sjmp basla
org 0030h
basla:
	MOV 20H,#00H
	MOV 21H,#06H
	MOV 22H,#05H
	MOV 23H,#06H
	MOV 24H,#05H
	MOV 25H,#06H
	MOV 26H,#06H
	MOV 27H,#05H
	MOV 28H,#06H
	MOV 31H,#06H
	MOV 32H,#08H
	MOV 33H,#08H
	MOV 34H,#05H
	MOV 35H,#08H
	MOV 36H,#08H
	MOV 37H,#08H
	MOV 38H,#06H
	MOV 39H,#05H
	mov 41h,20h ;dizinin ilk elemanini en buyuk kabul ettim
	mov r0,#21h ;dizinin indisini atadim
	mov 42h,#01h ;en büyük en az bir adet var
	mov r1,#50h ;yeni dizi indisi
tekrar:
	mov a,@r0
	cjne a,41h,esitdegil
	;esit bölgesi
	inc 42h ;en büyük frekansini bir artirdim
	inc r1
	mov @r1,00h ;r0 yazamadigimiz icin 00h yazdim
	sjmp dongukontrol
esitdegil:
	jc dongukontrol
	;yeni sayinin büyük oldugu bolge
	mov 41h,a ;yeni büyük sayiyi 41h a atadim
	mov 42h,#01h ;yeni en büyük bulundugu için frekans resetle
	mov 50h,r0
	mov r1,#50h
dongukontrol:
	inc r0	;bir sonraki döngüye hazirlik
	cjne r0,#41h,tekrar	 ;dongu sonu kontrolü

;en büyük elemanin frekansini bulma
//	mov 42h,#00h ;en az bir adet en  büyük mutlaka var
//	mov r0,#20h
//tekrar2:
//	mov a,@r0
//	cjne a,41h,esitdegil2
//	inc 42h
//esitdegil2:
//	inc r0
//	cjne r0,#41h,tekrar2

;dizi içinde en büyük elemanlarin indislerini 50h itibaren yazma.
//	mov r1,#50h ;yeni dizinin indisi
//	mov r0,#20h
//tekrar2:
//	mov a,@r0
//	cjne a,41h,esitdegil2
////	mov 60h,r0
////	mov @r1,60h
//	mov @r1,00h ;r0 yazamadigimiz icin 00 direk adresi yaz	
//	inc r1
//esitdegil2:
//	inc r0
//	cjne r0,#41h,tekrar2



	end













