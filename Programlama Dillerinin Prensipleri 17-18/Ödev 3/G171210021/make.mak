hepsi: derle calistir
derle:
gcc -I ./include/ -o ./lib/IMEI.o -c ./src/IMEI.c
gcc -I ./include/ -o ./lib/Telefon.o -c ./src/Telefon.c
gcc -I ./include/ -o ./lib/KimlikNo.o -c ./src/KimlikNo.c
gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
gcc -I ./include/ -o ./lib/RastgeleKisi.o -c ./src/RastgeleKisi.c
gcc -I ./include/ -o ./lib/Menu.o -c ./src/Menu.c
gcc -I ./include/ -o ./bin/Test ./lib/IMEI.o ./lib/Telefon.o ./lib/KimlikNo.o ./lib/Kisi.o ./lib/RastgeleKisi.o ./lib/Menu.o ./src/program.c
calistir:
./bin/Test