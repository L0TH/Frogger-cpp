# Οδηγίες για Linux

The command to compile the demo sample for Release should look like this:

g++ -O2 -Llib -Igraphics demo/demo.cpp -lsgg -lGL -lGLEW -lSDL2 -lSDL2_mixer -lfreetype -o bin/demo

and for Debug

g++ -Og -g -Llib -Igraphics demo/demo.cpp -lsggd -lGL -lGLEW -lSDL2 -lSDL2_mixer -lfreetype -o bin/demod

Τα path τα ψάχνει εκεί που είναι το cd, πρέπει να προσαρμόσω τα ονόματα βάση του project και να κάνω copy paste από την sgg τον φάκελο lib (που έχει τις βιβλιοθήκες) και τον φάκελο graphichs που να έχω τα 2 header
